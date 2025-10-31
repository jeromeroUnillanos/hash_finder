#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "worker.h"

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Uso: %s <num_hilos> <archivo_texto> <ceros_finales>\n", argv[0]);
        return 1;
    }

    int num_hilos = atoi(argv[1]);
    char *archivo = argv[2];
    int ceros = atoi(argv[3]);

    FILE *f = fopen(archivo, "r");
    if (!f) {
        perror("No se pudo abrir el archivo");
        return 1;
    }

    char buffer[256];
    fgets(buffer, sizeof(buffer), f);
    fclose(f);
    buffer[strcspn(buffer, "\n")] = '\0';

    printf("Texto base: %s\n", buffer);
    printf("Buscando hash que termine con %d ceros usando %d hilos...\n", ceros, num_hilos);

    clock_t inicio = clock();
    iniciar_trabajadores(buffer, num_hilos, ceros);
    clock_t fin = clock();

    double tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;
    printf("Tiempo total: %.3f segundos\n", tiempo);
    return 0;
}
