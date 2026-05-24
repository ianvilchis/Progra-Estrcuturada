#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int A;   // Edad
    float B; // Promedio
    int C;   // Materias reprobadas

    printf("Ingrese su edad \n");
    scanf("%d", &A);
    printf("Ingrese su promedio \n");
    scanf("%f", &B);
    printf("Ingrese la cantidad de materias reprobadas \n");
    scanf("%d", &C);

    if (B >= 90 && C == 0) {
        printf("Obtiene la beca\n");
    } else {
        if (C <= 2) {
            printf("Puede reinscribirse\n");
        } else {
            printf("Situación critica\n");
        }
    }

    return 0;
}
