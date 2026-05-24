# Actividad 6: Punteros y Gestión Dinámica de Memoria

## Estudiante
* **Nombre:** Ian Pablo Vilchis Armas
* **Código:** 325019822
* **Sección:** D04
* **Materia:** Programación Estructurada
* **Profesor:** Jorge Ernesto López Arce Delgado
* **Centro Universitario:** CUCEI

## Descripción
En esta actividad exploramos los fundamentos teóricos y prácticos de la gestión de memoria en el lenguaje C a bajo nivel. A través de dos prácticas de laboratorio, se analizó cómo el sistema operativo asigna bloques de memoria física a las variables y arreglos (mapeo en direcciones hexadecimales), y se implementó el paso de parámetros por referencia a través de punteros, concluyendo con la reserva y liberación de memoria en tiempo de ejecución de manera controlada.

## Temas Aplicados
* **Direccionamiento Físico:** Uso del operador de dirección (`&`) junto con el especificador de formato `%p` para extraer e interpretar las ubicaciones reales en formato hexadecimal dentro de la memoria RAM.
* **Paso por Referencia mediante Punteros:** Diseño de funciones modificadoras (`triple`) que reciben variables por referencia (`int *a`), permitiendo la alteración directa de los datos alojados en el ámbito de la función principal sin duplicar recursos en el Stack.
* **Gestión Dinámica de Memoria (Heap):** Asignación controlada de bloques de bytes utilizando la función nativa `malloc()` combinada con el operador `sizeof` para el dimensionamiento del vector en memoria.
* **Seguridad y Liberación de Recursos:** Implementación de validaciones contra punteros nulos (`NULL`) para prevenir fallos de segmentación (*segmentation fault*) y uso obligatorio de `free()` para evitar fugas de memoria (*memory leaks*).

## Elementos incluidos en esta carpeta
* **codigo/direcciones_memoria.c**: Código fuente enfocado en el mapeo e impresión de direcciones físicas de arreglos de caracteres.
* **codigo/punteros_y_memoria.c**: Código fuente que implementa funciones modificadoras con punteros y asignación con `malloc`.
* **documentacion/consola_punteros.png**: Captura de pantalla de la terminal con las direcciones físicas obtenidas y el resultado de la multiplicación por referencia.
