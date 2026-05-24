#include <stdio.h>

void capturar(int v[], int n);
void mostrar(int v[], int n);
int filtrar(int origen [], int destino [], int n);

int main() {
    int n = 6;
    int original[6];
    int filtrado[6];
    int tam_filtrado;
    FILE *f;

    capturar(original, n);

    printf("\narreglo original\n");
    mostrar(original, n);

    tam_filtrado = filtrar(original, filtrado, n);

    printf("\narreglo filtrado\n");
    mostrar(filtrado, tam_filtrado);

    f = fopen("resultado.txt", "w");
    if (f != NULL) {
        for (int i = 0; i < tam_filtrado; i++) {
            fprintf(f, "%d", filtrado[i]);
        }
        fclose(f);
    }

    return 0;
}

void capturar(int v[], int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
}

void mostrar(int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int filtrar(int origen [], int destino [], int n) {
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (origen[i] % 2 != 0) {
            destino[j] = origen[i];
            j++;
        }
    }
    return j;
}
