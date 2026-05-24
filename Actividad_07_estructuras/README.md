# Actividad 7: Estructuras y Tipos de Datos Personalizados (Structs)

## Estudiante
* **Nombre:** Ian Pablo Vilchis Armas
* **Código:** 325019822
* **Sección:** D04
* **Materia:** Programación Estructurada
* **Profesor:** Jorge Ernesto López Arce Delgado
* **Centro Universitario:** CUCEI

## Descripción
En esta actividad aplicamos el modelado de información heterogénea mediante el uso de estructuras (`struct`) en C, permitiendo agrupar múltiples variables de diferentes naturalezas (enteros, flotantes y cadenas de caracteres) bajo un único molde de datos. El programa simula un sistema de control de alumnos, gestionando la lectura secuencial de fichas estudiantiles, la manipulación de arreglos compuestos y la impresión ordenada de los registros recopilados.

## Temas Aplicados
* **Definición de Estructuras:** Creación del molde personalizado `struct alumne` para unificar variables de tipo texto (`char nombre[]`), punto flotante (`float cal`) y enteros numéricos (`int act`, `int derecho`).
* **Arreglos de Estructuras:** Implementación de colecciones indexadas complejas (`struct alumne grupo[3]`) para el almacenamiento matricial de los registros recolectados de forma consecutiva en memoria.
* **Lectura Segura de Flujos de Texto:** Uso adaptativo de `fgets()` para capturar cadenas de texto completas con espacios integrados, adicionando la remoción del salto de línea residual (`\n`) mediante indexación con `strcspn()`.
* **Sincronización y Limpieza de Buffers:** Uso estratégico de la función `getchar()` para vaciar el buffer del teclado físico (`stdin`), previniendo el error común de omisión de lecturas tras la captura de datos numéricos con `scanf()`.

## Elementos incluidos en esta carpeta
* **codigo/practica_estructuras.c**: Código fuente en C que define la estructura del alumno, gestiona el ciclo de captura y despliega la tabla informativa.
* **documentacion/consola_estructuras.png**: Captura de pantalla de la terminal mostrando el llenado secuencial del grupo y el despliegue final de las fichas de los estudiantes.
