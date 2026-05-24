# Actividad 5: Funciones y archivos

## Estudiante
* **Nombre:** Ian Pablo Vilchis Armas
* **Código:** 325019822
* **Sección:** D04
* **Materia:** Programación Estructurada
* **Profesor:** Jorge Ernesto López Arce Delgado
* **Centro Universitario:** CUCEI

## Descripción
En esta actividad aplicamos el concepto de modularidad en lenguaje C mediante el diseño e implementación de funciones con paso de parámetros por valor y por referencia (arreglos). El programa solicita al usuario un conjunto de números, los procesa a través de una función de filtrado para extraer únicamente los valores impares y utiliza funciones nativas para exportar y guardar de forma permanente el resultado en un archivo físico de texto.

## Temas Aplicados
* **Modularización:** División del problema principal en subtareas mediante prototipos y definiciones de funciones independientes (`capturar`, `mostrar` y `filtrar`).
* **Paso de Parámetros por Referencia:** Manipulación y modificación directa de arreglos numéricos (`int v[]`) dentro de las funciones sin necesidad de duplicar la información en memoria.
* **Lógica de Filtrado:** Uso del operador residuo (`%`) para discriminar números pares e identificar elementos impares, gestionando dinámicamente el tamaño del nuevo arreglo.
* **Persistencia en Archivos:** Uso de la estructura `FILE` y funciones como `fopen()`, `fprintf()` y `fclose()` para crear el archivo `resultado.txt` y escribir en él los datos procesados.

## Elementos incluidos en esta carpeta
* **codigo/filtrado_y_archivos.c**: Código fuente en C estructurado de forma modular con las funciones implementadas.
* **documentacion/consola.png**: Captura de pantalla de la terminal con las pruebas de entrada, el arreglo original y el arreglo filtrado.
* **documentacion/resultado.txt**: Archivo de texto generado de forma automática por el programa que contiene el resultado final de la ejecución.
