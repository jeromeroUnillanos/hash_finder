#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "hash_utils.h"

#ifdef _WIN32
#include <windows.h>
#define THREAD_RETURN DWORD WINAPI
#else
#include <pthread.h>
#define THREAD_RETURN void*
#endif

typedef struct {
    char *cadena_base;
    int ceros;
    int id;
    int total_hilos;
} Parametros;

static int encontrado = 0;

THREAD_RETURN buscar(void *arg) {
    Parametros *p = (Parametros *)arg;
    int len = strlen(p->cadena_base);
    char copia[256];

    for (char a = 'a'; a <= 'z' && !encontrado; a++) {
        for (char b = 'a'; b <= 'z' && !encontrado; b++) {
            strcpy(copia, p->cadena_base);
            for (int i = 0; i < len; i++) {
                if (copia[i] == '#')
                    copia[i] = (i + p->id) % 2 ? a : b;
            }
            uint32_t h = crc32((unsigned char *)copia, len);
            if (h % (int)pow(10, p->ceros) == 0) {
                printf("[Hilo %d] Encontrado: %s  →  Hash: %u\n", p->id, copia, h);
                encontrado = 1;
                break;
            }
        }
    }
    return 0;
}

void iniciar_trabajadores(char *cadena_base, int num_hilos, int ceros) {
#ifdef _WIN32
    HANDLE *hilos = malloc(num_hilos * sizeof(HANDLE));
#else
    pthread_t *hilos = malloc(num_hilos * sizeof(pthread_t));
#endif
    Parametros *param = malloc(num_hilos * sizeof(Parametros));

    for (int i = 0; i < num_hilos; i++) {
        param[i].cadena_base = cadena_base;
        param[i].ceros = ceros;
        param[i].id = i;
        param[i].total_hilos = num_hilos;
#ifdef _WIN32
        hilos[i] = CreateThread(NULL, 0, buscar, &param[i], 0, NULL);
#else
        pthread_create(&hilos[i], NULL, buscar, &param[i]);
#endif
    }

#ifdef _WIN32
    WaitForMultipleObjects(num_hilos, hilos, TRUE, INFINITE);
#else
    for (int i = 0; i < num_hilos; i++)
        pthread_join(hilos[i], NULL);
#endif

    free(hilos);
    free(param);
}
