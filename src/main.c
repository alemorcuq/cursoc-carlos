#include "gol.h"

int main() {

    // Estructuras que guardan el mundo en su estado actual y futuro
    struct mundo actual;
    struct mundo futuro;

    // Reservamos dinámicamente el tablero actual y futuro
    actual.tablero = (int*) calloc(TAM*TAM,sizeof(int));
    futuro.tablero = (int*) calloc(TAM*TAM,sizeof(int));
    if (!actual.tablero || !futuro.tablero) {
        printf(ANSI_COLOR_RED "\t [ERROR]\t Fallo en la reserva de memoria \n" ANSI_COLOR_RESET);
        return -1;
    }

    // Células formando Glider
    *(actual.tablero + 0*TAM + 1) = VIVA;
    *(actual.tablero + 1*TAM + 2) = VIVA;
    *(actual.tablero + 2*TAM + 0) = VIVA;
    *(actual.tablero + 2*TAM + 1) = VIVA;
    *(actual.tablero + 2*TAM + 2) = VIVA;

    // Puntero a las estructuras del mundo
    struct mundo *pactual = &actual;
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

        /* Actualiza el mundo para la siguiente iteracción. Copia la memoria del
        mundo futuro anterior, que será el actual en la siguiente */
        memcpy(actual.tablero, futuro.tablero, TAM*TAM*sizeof(int));
    }
    // Libera memoria
    free(actual.tablero);
    free(futuro.tablero);

    return 0;
}
