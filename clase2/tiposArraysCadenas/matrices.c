#include <stdio.h>

#define TAM 3

int main() {
    int matriz1[TAM][TAM] = {{1,2,3},{4,5,6},{7,8,9}};
    int matriz2[TAM][TAM] = {{11,22,33},{44,55,66},{77,88,99}};

    /* Imprime ambas matrices normal */
    printf("Matriz 1:\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ",matriz1[i][j]);
        }
        printf("\n");
    }

    printf("\nMatriz 2:\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ",matriz2[i][j]);
        }
        printf("\n");
    }

    /* Multiplica la matriz 1 por 2 */
    printf("\nMatriz 1 por 2:\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ",matriz1[i][j]*2);
        }
        printf("\n");
    }

    /* Multiplica la matriz 1 por la matriz 2*/
    printf("\nMatriz 1 por Matriz 2:\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ",matriz1[i][j]*matriz2[i][j]);
        }
        printf("\n");
    }

    return 0;
}
