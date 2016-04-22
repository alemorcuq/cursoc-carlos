#include "gol.h"
#include "mundo.h"

int main(int argc, char *argv[]) {
    int option_index, c, tam, sim;
    bool help = false;
    bool random = false;

    while ((c = getopt_long(argc, argv, "t:s:rh", long_options, &option_index)) != -1) {
        switch (c) {
            case 'h':
                help = true;
                break;
            case 't':
                tam = strtol(optarg, NULL, 0);
                break;
            case 's':
                sim = strtol(optarg, NULL, 0);
                break;
            case 'r':
                random = true;
                break;
            case '?':
                help = true;
                break;
        }
    }

    if (help == true) {
        printf("./main.out -t tamaño -s simulaciones [-r -h]\n");
        printf("\t -t tamaño: Tamaño del tablero\n");
        printf("\t -s simulaciones: Número de simulaciones\n");
        printf("\t -r: Inicializa el mundo con un estado aleatorio\n");
        printf("\t -h: Muestra esta ayuda\n");
    }
    else if (tam == 0 || sim == 0) {
        printf("Uso: ./main.out -t tamaño -s simulaciones [-r -h]\n");
        printf("                      |          |-> Mayor que 0\n");
        printf("                      |-> Mayor que 0\n");
    }

    // Reserva memoria para las estructuras del mundo
    struct mundo *pactual = mundo_alloc();
    struct mundo *pfuturo = mundo_alloc();

    // Comprueba la reserva
    if (!pactual || !pfuturo)
        return -1;

    // Reserva memoria para el tablero y comprueba la reserva
    if (mundo_alloc_tablero(pactual, tam) == -1 || mundo_alloc_tablero(pfuturo, tam)  == -1)
        return -1;

    if (random == false) {
        // Células formando Glider
        *(mundo_get_tablero(pactual) + 0*tam + 1) = VIVA;
        *(mundo_get_tablero(pactual) + 1*tam + 2) = VIVA;
        *(mundo_get_tablero(pactual) + 2*tam + 0) = VIVA;
        *(mundo_get_tablero(pactual) + 2*tam + 1) = VIVA;
        *(mundo_get_tablero(pactual) + 2*tam + 2) = VIVA;
    }
    else {
        mundoAleatorio(pactual,tam);
    }

    // Bucle de simulaciones
    for (int k = 0; k < sim; k++) {
        printf("Estado %d\n", k+1);
        // Realiza la lógica del juego, determina el nuevo estado a partir del anterior
        transicion(pactual,pfuturo,tam);

        // Imprime el mundo en cada iteracción
        printf(ANSI_COLOR_GREEN "Células vivas: %d " ANSI_COLOR_RESET
                ANSI_COLOR_RED "Células muertas: %d\n" ANSI_COLOR_RESET,
                mundo_get_vivas(pactual), mundo_get_muertas(pactual));
        printTablero(pactual,tam);
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
        mundo_alloc_tablero(pfuturo, tam);
    }

    // Libera memoria
    mundo_free_tablero(pactual);
    mundo_free_tablero(pfuturo);
    mundo_free(pactual);
    mundo_free(pfuturo);

    return 0;
}
