#include <stdio.h>

int main() {
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    printf("Recorrer array:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d\n", array[i]);
    }

    printf("\n Orden inverso y solo pares:\n");
    for (int i = 9; i >= 0; i=i-2) {
        printf("%d\n", array[i]);
    }

    printf("\n Espejar el array:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d %d\n", array[i], array[9-i]);
    }

    return 0;
}
