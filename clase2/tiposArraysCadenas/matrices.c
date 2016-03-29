#include <stdio.h>

int main() {
    int matriz1[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int matriz2[3][3] = {{11,22,33},{44,55,66},{77,88,99}};

    printf("Matriz 1:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d\n",matriz1[i][j]);
        }
    }

    printf("\nMatriz 2:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d\n",matriz2[i][j]);
        }
    }

    printf("\nMatriz 1 por 2:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d\n",matriz1[i][j]*2);
        }
    }

    printf("\nMatriz 1 por Matriz 2:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d\n",matriz1[i][j]*matriz2[i][j]);
        }
    }

}
