#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char tablero[5][5];
    FILE *archivo;
    char nombre[10];
    char nombre2[50]; // <-- Aumentado a 50 para que quepa "Nombre: Jorge..." sin cortarse

    printf("Ingrese su nombre: \n");
    fgets(nombre, sizeof(nombre), stdin);
    nombre[strcspn(nombre, "\n")] = 0; // Quita el salto de línea del teclado

    // 1. Inicializar la matriz con guiones
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            tablero[i][j] = '-';
        }
    }

    // Colocamos algunos barcos de prueba como en tu apunte
    tablero[1][2] = 'B';
    tablero[3][4] = 'X';
    tablero[2][1] = '0';

    // 2. Abrir archivo en modo escritura ("w") y guardar datos
    archivo = fopen("tablero.txt", "w");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    // Escribimos los datos formateados en el archivo físico
    fprintf(archivo, "Nombre: %s\n", nombre);
    fprintf(archivo, "Ian Vilchis\n\n");

    // Guardar la matriz en el archivo físico
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            fprintf(archivo, "%c ", tablero[i][j]);
        }
        fprintf(archivo, "\n");
    }
    fclose(archivo); // Cerramos el archivo para asegurar que todo se escriba en el disco duro
    printf("Tablero guardado con exito en 'tablero.txt'.\n\n");

    // 3. Abrir archivo en modo lectura ("r") para comprobar
    archivo = fopen("tablero.txt", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo para lectura.\n");
        return 1;
    }

    // Leemos la primera línea del archivo 
    if (fgets(nombre2, sizeof(nombre2), archivo) != NULL) {
        // CORREGIDO: printf estándar para mostrar el resultado en la consola
        printf("--- Comprobacion de lectura desde el archivo .txt ---\n");
        printf("Leido del archivo: %s", nombre2); 
    }
    fclose(archivo);

    return 0;
}
