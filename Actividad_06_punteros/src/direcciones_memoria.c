#include <stdio.h>
#include <stdlib.h>

int main()
{
    char nombre[4][10];
    
    // Captura de datos
    for (int i = 0; i < 4; i++)
    {
        printf("Ingresa el nombre/apellido no.%d: ", i);
        fgets(nombre[i], sizeof(nombre[i]), stdin);
    }

    // Impresión de valores
    for (int j = 0; j < 4; j++)
    {
        printf("%s", nombre[j]);
    }

    // Demostración de direcciones de memoria físicas en la RAM
    printf("\n--- DIRECCIONES DE MEMORIA DEL ARREGLO '---\n");
    printf("La direccion de nombre[0] es: %p\n", (void*)&nombre[0]);
    printf("La direccion de nombre[1] es: %p\n", (void*)&nombre[1]);
    printf("La direccion de nombre[2] es: %p\n", (void*)&nombre[2]);
    printf("La direccion de nombre[3] es: %p\n", (void*)&nombre[3]);

    char arregloC[5] = {'A', 'B', 'C', 'D', 'E'};
    printf("\nLa direccion base de arregloC es: %p\n", (void*)arregloC);
    printf("La direccion de arregloC[0] es: %p\n", (void*)&arregloC[0]);
    printf("La direccion de arregloC[1] es: %p\n", (void*)&arregloC[1]);
    printf("La direccion de arregloC[2] es: %p\n", (void*)&arregloC[2]);

    return 0;
}
