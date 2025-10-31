# Hash Finder - Multithreaded CRC32 Search

Autor: **Julian Esteban Romero Guzmán**

## Descripción
Programa educativo en **C** que genera combinaciones de una cadena base con `#` y calcula su **hash CRC32**.  
Cada hilo busca una combinación cuyo hash termine con cierta cantidad de ceros.

Compatible con **Windows y Linux**.

---

## Compilación

### En Linux o macOS:
```bash
'gcc main.c worker.c hash_utils.c -lpthread -lm -o hash_finder'


#### Crea un archivo entrada.txt con una línea que contenga el texto base:
La clave es ####

#### Ejecuta el programa:

'./hash_finder 4 entrada.txt 3'
