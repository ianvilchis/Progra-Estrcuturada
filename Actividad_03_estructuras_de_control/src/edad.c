#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int A;
    printf("Ingrese su edad: ");
    scanf("%d", &A);

    if (A >= 18) {
        printf("Es mayor de edad\n");
    } else {
        printf("Es menor de edad\n");
    }

    return 0;
}
