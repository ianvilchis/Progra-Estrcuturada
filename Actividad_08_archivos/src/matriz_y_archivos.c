#include <stdio.h>
#include <stdlib.h>

// Prototipos de funciones
void llenar(int m[3][3]);
void mostrar(int v[3][3]);
int diagonal(int d[3][3]);
void fmostrar(int m[3][3]);

void llenar(int m[3][3]) {
    printf("Introduce 9 numeros uno por uno para la matriz:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (scanf("%d", &m[i][j]) != 1) return;
        }
    }
}

void mostrar(int v[3][3]) {
    printf("\nMatriz en pantalla:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", v[i][j]);
        }
        printf("\n");
    }
}

int diagonal(int d[3][3]) {
    int suma = 0;
    for (int i = 0; i < 3; i++) {
        suma += d[i][i]; // Suma los elementos de la diagonal principal
    }
    return suma;
}

// Guarda la matriz en el archivo sin borrar lo anterior (Modo Append "a")
void fmostrar(int m[3][3]) {
    FILE *f;
    f = fopen("tablero.txt", "a");
    if (f == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }
    fprintf(f, "\nMatriz añadida:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            fprintf(f, "%d ", m[i][j]);
        }
        fprintf(f, "\n");
    }
    fclose(f);
    printf("\nMatriz guardada con exito en 'tablero.txt' (Modo Append).\n");
}

int main() {
    int matriz[3][3];
    
    llenar(matriz);
    mostrar(matriz);
    
    int suma_diagonal = diagonal(matriz);
    printf("La suma de la diagonal principal es: %d\n", suma_diagonal);
    
    fmostrar(matriz);
    
    return 0;
}
