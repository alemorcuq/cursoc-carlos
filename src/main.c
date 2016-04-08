#include <stdio.h>
#include "gol.h"

int main() {
    // Estructura que guarda el mundo en su estado actual
    struct mundo actual = {{{MUERTA,VIVA,MUERTA},{MUERTA,MUERTA,VIVA},{VIVA,VIVA,VIVA}},5,TAM*TAM-5,TAM*TAM};
    // Puntero a la estructura del mundo actual
    struct mundo *pactual = &actual;

    // Estructura en la que se va guardando las modificaciones
    struct mundo futuro = actual;
    // Puntero a la estructura del mundo futuro
    struct mundo *pfuturo = &futuro;

    FILE *fp;           // Fichero de log para guardar el resultado de las transiciones
    if ((fp = fopen("log.txt", "w")) == NULL) {
        printf("Cannot open file.\n");
    }

    // Imprime el mundo al inicio
    printf("Estado incial\n");
    printTablero(pactual);

    // Bucle de simulaciones
    for (int k = 0; k < SIM; k++) {
        printf("Transición %d\n", k+1);
        printf(ANSI_COLOR_GREEN "Células vivas: %d " ANSI_COLOR_RESET
                ANSI_COLOR_RED "Células muertas: %d\n" ANSI_COLOR_RESET,
                actual.numCelVivas, actual.numCelMuertas);
        fprintf(fp,"\n####### Transición %d ####### \n\n", k+1);
        // Realiza la lógica del juego, determina el nuevo estado a partir del anterior
        transicion(pactual,pfuturo,fp);

        // Imprime el mundo en cada iteracción
        printTablero(pfuturo);
        printf("\n");

        /* Actualiza el mundo para la siguiente iteracción
        El actual de ahora es el futuro de antes */
        actual = futuro;
    }
    fclose(fp);

    return 0;
}
