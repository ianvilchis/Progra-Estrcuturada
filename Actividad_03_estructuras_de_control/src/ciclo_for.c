#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;          
    int valor = 10; // Valor que se suma en cada vuelta
    int suma = 0;   // Acumulador

    printf("Ingresa el limite del ciclo (N): ");
    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        suma += valor;
        
        // Print para ver el funcionamiento interno
        printf("Iteracion: %d | Sumando: %d | Total acumulado: %d\n", i, valor, suma);
    }

    return 0;
}
