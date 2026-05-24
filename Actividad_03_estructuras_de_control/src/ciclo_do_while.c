#include <stdio.h>
#include <stdlib.h>

int main() {
    int opcion;

    do {
        printf("1. Continuar\n");
        printf("2. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        
    } while (opcion != 2);

    return 0;
}
