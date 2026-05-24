#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int N;
    printf("Ingrese un numero \n");
    scanf("%d", &N);

    if (N % 2 == 0) {
        printf("Es par\n");
    }

    return 0;
}
