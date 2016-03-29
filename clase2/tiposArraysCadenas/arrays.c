#include <stdio.h>

#define TAM 10

int main() {
    int array[TAM] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};   // Vector de 10 elementos

    // Recorre el vector e imprime sus elementos
    printf("Recorrer array:\n");
    for (int i = 0; i < TAM; i++) {
        printf("%d\n", array[i]);
    }

    // Empieza por el final y decrementa en saltos de 2
    printf("\n Orden inverso y solo pares:\n");
    for (int i = TAM-1; i >= 0; i=i-2) {
        printf("%d\n", array[i]);
    }

    // Uno normal y otro inverso
    printf("\n Espejar el array:\n");
    for (int i = 0; i < TAM; i++) {
        printf("%d %d\n", array[i], array[(TAM-1)-i]);
    }

    return 0;
}
