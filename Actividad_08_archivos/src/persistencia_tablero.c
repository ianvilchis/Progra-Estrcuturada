#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char tablero[5][5];
    FILE *archivo;
    char nombre[10];
    char nombre2[10];

    printf("Ingrese su nombre: \n");
    fgets(nombre, sizeof(nombre), stdin);
    nombre[strcspn(nombre, "\n")] = 0; // Quita el salto de línea

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

    fprintf(archivo, "Nombre: %s\n", nombre);
    fprintf(archivo, "Ian Vilchis\n\n");

    // Guardar la matriz en el archivo físico
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            fprintf(archivo, "%c ", tablero[i][j]);
        }
        fprintf(archivo, "\n");
    }
    fclose(archivo);
    printf("Tablero guardado con exito en 'tablero.txt'.\n");

    // 3. Abrir archivo en modo lectura ("r") para comprobar
    archivo = fopen("tablero.txt", "r");
    if (archivo != NULL) {
        if (fgets(nombre2, sizeof(nombre2), archivo) != NULL) {
            printf("Leido del archivo: %s\n", nombre2);
        }
        fclose(archivo);
    }

    return 0;
}
