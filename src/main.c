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

    // Bucle de simulaciones
    for (int k = 0; k < SIM; k++) {
        printf("Estado %d\n", k+1);
        // Realiza la lógica del juego, determina el nuevo estado a partir del anterior
        transicion(pactual,pfuturo);

        // Imprime el mundo en cada iteracción
        printf(ANSI_COLOR_GREEN "Células vivas: %d " ANSI_COLOR_RESET
                ANSI_COLOR_RED "Células muertas: %d\n" ANSI_COLOR_RESET,
                actual.numCelVivas, actual.numCelMuertas);
        printTablero(pactual);
        printf("\n");

        /* Actualiza el mundo para la siguiente iteracción
        El actual de ahora es el futuro de antes */
        actual = futuro;
    }

    return 0;
}
