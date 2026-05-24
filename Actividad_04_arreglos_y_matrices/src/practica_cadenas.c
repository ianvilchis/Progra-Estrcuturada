#include <stdio.h>
#include <string.h>

int main() {
    char saludo[30] = "Hola ";
    char nombre[20];
    char lista_comida[2][20];
    char clave_secreta[] = "1234";
    char intento[20];

    printf("Escribe tu clave: ");
    scanf("%s", intento);

    if (strcmp(intento, clave_secreta) == 0) {
        printf("Clave correcta.\n");
    } else {
        printf("Clave incorrecta.\n");
    }

    getchar();

    printf("Escribe tu nombre completo: ");
    fgets(nombre, sizeof(nombre), stdin);

    printf("Tu nombre mide: %ld caracteres.\n", strlen(nombre) - 1);

    strcat(saludo, nombre);
    
    printf("%s\n", saludo);

    strcpy(lista_comida[0], "Tacos");
    strcpy(lista_comida[1], "Pizza");

    printf("Hoy cenaremos: %s y %s\n", lista_comida[0], lista_comida[1]);

    return 0;
}
