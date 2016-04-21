#include "gol.h"
#include "mundo.h"

int main() {
    // Reserva memoria para las estructuras del mundo
    struct mundo *pactual = mundo_alloc();
    struct mundo *pfuturo = mundo_alloc();

    // Comprueba la reserva
    if(!pactual || !pfuturo)
        return -1;

    // Reserva memoria para el tablero y comprueba la reserva
    if(mundo_alloc_tablero(pactual, TAM) == -1 || mundo_alloc_tablero(pfuturo, TAM)  == -1)
        return -1;

    // Células formando Glider
    *(mundo_get_tablero(pactual) + 0*TAM + 1) = VIVA;
    *(mundo_get_tablero(pactual) + 1*TAM + 2) = VIVA;
    *(mundo_get_tablero(pactual) + 2*TAM + 0) = VIVA;
    *(mundo_get_tablero(pactual) + 2*TAM + 1) = VIVA;
    *(mundo_get_tablero(pactual) + 2*TAM + 2) = VIVA;

    // Bucle de simulaciones
    for (int k = 0; k < SIM; k++) {
        printf("Estado %d\n", k+1);
        // Realiza la lógica del juego, determina el nuevo estado a partir del anterior
        transicion(pactual,pfuturo);

        // Imprime el mundo en cada iteracción
        printf(ANSI_COLOR_GREEN "Células vivas: %d " ANSI_COLOR_RESET
                ANSI_COLOR_RED "Células muertas: %d\n" ANSI_COLOR_RESET,
                mundo_get_vivas(pactual), mundo_get_muertas(pactual));
        printTablero(pactual);
        printf("\n");

        /* Actualiza el mundo para la siguiente iteracción. Copia la memoria del
        mundo futuro anterior, que será el actual en la siguiente, se hace en
        tres pasos:
            1.- Libera el tablero actual (se va a sobreescribir)
            2.- Copia la estructura futuro en la actual
            3.- Reserva memoria para el nuevo futuro
         */
        mundo_free_tablero(pactual);
        pactual = mundo_clone(pactual, pfuturo);
        mundo_alloc_tablero(pfuturo, TAM);
    }

    // Libera memoria
    mundo_free_tablero(pactual);
    mundo_free_tablero(pfuturo);
    mundo_free(pactual);
    mundo_free(pfuturo);

    return 0;
}
