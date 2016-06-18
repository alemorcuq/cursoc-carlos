#include <stdio.h>

#define TAM 3

int main()
{
    int matriz[TAM][TAM] = {{1,2,3},{4,5,6},{7,8,9}};
    int *pmatriz = matriz[0];   // Puntero apuntando al ppio de la matriz

    printf("Matriz accedida con doble puntero:\n");
    for (int i = 0; i < TAM; i++) {
        printf("\t");
        for (int j = 0; j < TAM; j++) {
            /* pmatriz+i => Apunta al principio de la fila i
            ((pmatriz+i)+j) => Apunta al elemento j de la fila i
            *((pmatriz+i)+j) => Obtenemos el contenido de ese elemento */
            printf("%d ",*((pmatriz+i)+j));
        }
        printf("\n");
    }
    return 0;
}
