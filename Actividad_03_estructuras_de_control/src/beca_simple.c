#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int A; // Promedio
    int B; // Materias reprobadas

    printf("Ingrese su promedio \n");
    scanf("%d", &A);
    printf("Ingrese la cantidad de materias reprobadas \n");
    scanf("%d", &B);

    if (A >= 85 && B == 0) {
        printf("Obtiene la beca\n");
    } else {
        printf("No obtiene la beca\n");
    }

    return 0;
}
