#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int N;
    printf("Ingrese un numero \n");
    scanf("%d", &N);

    if (N % 2 == 1) {
        printf("Es impar\n");
    }

    return 0;
}
