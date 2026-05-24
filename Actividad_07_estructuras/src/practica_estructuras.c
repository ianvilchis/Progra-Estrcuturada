#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct alumne {
    char nombre[20];
    float cal;
    int act;
    int derecho;
};

int main() {
    struct alumne grupo[3];

    // Ciclo para capturar los datos de los 3 alumnos
    for (int i = 0; i < 3; i++) {
        printf("Ingrese el nombre del alumno %d:\n", i + 1);
        // Limpiamos el buffer antes de fgets si es necesario
        if (i > 0) getchar(); 
        fgets(grupo[i].nombre, 20, stdin);
        // Eliminar el salto de línea que mete fgets
        grupo[i].nombre[strcspn(grupo[i].nombre, "\n")] = 0;

        printf("Ingrese la calificacion:\n");
        if (scanf("%f", &grupo[i].cal) != 1) return 1;

        printf("Ingrese act:\n");
        if (scanf("%d", &grupo[i].act) != 1) return 1;

        printf("Ingrese derecho:\n");
        if (scanf("%d", &grupo[i].derecho) != 1) return 1;
    }

    printf("\n--- DATOS DE LOS ALUMNOS ---\n");
    for (int i = 0; i < 3; i++) {
        printf("Alumno %d: %s | Cal: %.2f | Act: %d | Derecho: %d\n", 
               i + 1, grupo[i].nombre, grupo[i].cal, grupo[i].act, grupo[i].derecho);
    }

    return 0;
}
