# Actividad 8: Persistencia de Datos y Gestión de Archivos Externos

## Estudiante
* **Nombre:** Ian Pablo Vilchis Armas
* **Código:** 325019822
* **Sección:** D04
* **Materia:** Programación Estructurada
* **Profesor:** Jorge Ernesto López Arce Delgado
* **Centro Universitario:** CUCEI

## Descripción
En esta actividad final consolidamos los conocimientos de manipulación matricial acoplándolos con el concepto de **Persistencia de Datos**. Desarrollamos programas capaces de romper la volatilidad de la memoria RAM mediante la comunicación con el almacenamiento secundario del ordenador. Se implementaron flujos para crear, escribir desde cero, leer y anexar datos matemáticos y matrices de juego de forma permanente dentro de un archivo físico con formato de texto plano.

## Temas Aplicados
* **Modo de Apertura de Sobrescritura ("w"):** Empleo de `fopen()` con el atributo de escritura limpia para la inicialización y construcción estructurada del archivo de texto `tablero.txt` desde su base.
* **Modo de Apertura de Adición Incremental ("a"):** Uso del modo *Append* para abrir flujos de datos sobre archivos preexistentes, permitiendo concatenar reportes y tablas al final del documento físico sin dañar o truncar la información guardada con anterioridad.
* **Procesamiento de Matrices y Análisis Diagonal:** Implementación de funciones modulares para llenar e inspeccionar arreglos bidimensionales, abstrayendo algoritmos de coincidencia de índices (`m[i][i]`) para computar la suma acumulada de la diagonal principal.
* **Escritura Formateada en Disco:** Canalización de flujos de salida mediante `fprintf()` para transferir cadenas formateadas, saltos de línea e interfaces visuales de matrices de caracteres directamente hacia el archivo físico, garantizando el cierre seguro mediante `fclose()`.

## Elementos incluidos en esta carpeta
* **codigo/persistencia_tablero.c**: Código fuente que inicializa una matriz de juego $5 \times 5$ y la guarda por primera vez en almacenamiento secundario.
* **codigo/matriz_y_archivos.c**: Código fuente modular que computa la suma de la diagonal de una matriz $3 \times 3$ y la añade secuencialmente al archivo existente.
* **documentacion/consola_archivos.png**: Captura de pantalla de la terminal con las confirmaciones de escritura y lectura de los flujos de persistencia.
* **codigo/tablero.txt**: Archivo de texto final generado e intervenido por ambos programas, que muestra las matrices y cálculos guardados.
