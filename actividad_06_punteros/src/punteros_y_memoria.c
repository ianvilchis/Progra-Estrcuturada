#include <stdio.h>
#include <stdlib.h>

void triple(int *a) {
    *a *= 3; // Multiplica el valor original por 3 usando su dirección de memoria
}

int main() {
    int a;
    printf("Ingresa un valor entre 1 y 100: \n");
    if (scanf("%d", &a) != 1) return 1;

    triple(&a); // Enviamos la dirección de memoria de 'a'
    printf("El triple del valor es: %i\n\n", a);

    // Apartado de Gestión Dinámica de Memoria (malloc)
    int *v;
    v = (int *) malloc(5 * sizeof(int)); // Reserva memoria dinámica para 5 enteros
    if (v == NULL) {
        printf("Error al asignar memoria.\n");
        return 1;
    }
    
    printf("Memoria dinamica para el vector asignada correctamente.\n");
    free(v); // Buena práctica: liberar la memoria asignada
    return 0;
}
