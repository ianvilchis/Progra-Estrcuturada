#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 0;
    float cal = 0;
    float prom = 0;
    float sum = 0;
    float opcion;
    int r = 0;          // Reprobadas
    int a = 0;          // Aprobadas
    float porc_a, porc_r;

    do {
        printf("\nIngresa la cantidad de materias (0 para salir): ");
        scanf("%f", &opcion);

        if (opcion == 0) {
            printf("Vuelva pronto.\n");
        } 
        else {
            for (n = 0; n < (int)opcion; n++) {
                // Validación de rango entre 0 y 100
                do {
                    printf("Ingrese la calificacion de la materia %d (0-100): ", n + 1);
                    scanf("%f", &cal);
                    if (cal < 0 || cal > 100) {
                        printf("Error: Nota invalida. Intenta de nuevo.\n");
                    }
                } while (cal < 0 || cal > 100);

                if (cal >= 60) {
                    a++;
                } else {
                    r++;
                }
                sum = sum + cal;
            }

            // Cálculos
            prom = sum / opcion;
            porc_a = (a / opcion) * 100;
            porc_r = (r / opcion) * 100;

            // Resultados
            printf("\n Tu Promedio es de : %.2f con : %d (%.1f%%) materias aprobadas y : %d (%.1f%%) reprobadas\n", prom, a, porc_a, r, porc_r);

            // Reinicio de variables para la siguiente ejecución
            n = 0;
            cal = 0;
            prom = 0;
            sum = 0;
            r = 0;
            a = 0;
        }
    } while (opcion != 0);

    return 0;
}
