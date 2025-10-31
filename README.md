🧠 Hash Finder Multithreaded

Autor: Julian Esteban Romero Guzmán
Lenguaje: C
Compatibilidad: Windows 🪟 | Linux 🐧
Tema: Programación Concurrente y Sistemas Distribuidos

📘 Descripción General

Hash Finder es un programa desarrollado en C que utiliza procesamiento multihilo para generar y evaluar combinaciones de texto a partir de un patrón definido por el usuario.
Cada hilo ejecuta un conjunto de combinaciones posibles y calcula su hash CRC32, buscando coincidencias que cumplan una condición específica (por ejemplo, que el hash termine con cierto número de ceros).

Este proyecto demuestra conceptos fundamentales de la programación concurrente, balanceo de carga, y coordinación entre hilos, aplicados en el contexto de sistemas distribuidos.

⚙️ Objetivos del Proyecto

Implementar procesamiento paralelo mediante hilos en C.

Evaluar el impacto del paralelismo en la eficiencia computacional.

Aplicar el cálculo de hashes CRC32 como función de verificación y búsqueda.

Desarrollar un programa portable y multiplataforma.

🧩 Arquitectura del Sistema

El sistema está dividido en tres módulos principales:

Módulo	Descripción
main.c	Control principal del programa. Gestiona los parámetros, crea los hilos y coordina los resultados.
worker.c	Define la lógica de trabajo de cada hilo. Cada uno genera combinaciones, calcula el hash y evalúa coincidencias.
hash_utils.c	Contiene las funciones auxiliares para el cálculo del CRC32 y la manipulación de cadenas.

El flujo de ejecución distribuye las tareas de búsqueda entre varios hilos, maximizando el uso del procesador.

🧮 Funcionamiento Conceptual

El usuario define un patrón de entrada (por ejemplo: a#c#), donde el carácter # representa una posición variable.

El sistema genera todas las combinaciones posibles reemplazando los #.

Cada hilo recibe un subconjunto de combinaciones para procesar en paralelo.

Se calcula el hash CRC32 de cada cadena.

El programa busca coincidencias que cumplan una condición (como hashes con ceros al final).

Finalmente, muestra el resultado y el tiempo total de ejecución.

💻 Compatibilidad y Entorno

El código está diseñado para ejecutarse tanto en Windows como en Linux, usando:

GCC como compilador principal.

Pthreads o su equivalente nativo según el sistema operativo.

Sin dependencias externas, solo la librería estándar de C.

📈 Ejemplo de Aplicación

Este proyecto puede emplearse para:

Simulaciones de fuerza bruta controlada.

Pruebas de rendimiento multihilo.

Ejercicios de distribución de carga en sistemas concurrentes.

Demostraciones académicas en asignaturas de Sistemas Distribuidos o Arquitectura de Computadores.

🧠 Conceptos Clave Implementados

Concurrencia y paralelismo.

Sincronización de hilos.

Gestión de recursos compartidos.

Hashing y funciones de dispersión.

Optimización de rendimiento.

🧾 Licencia

Este proyecto se distribuye con fines académicos y educativos.
Puede modificarse o reutilizarse citando al autor original:
Julian Esteban Romero Guzmán
