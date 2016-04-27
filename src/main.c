#include "gol.h"
#include "mundo.h"

int main(int argc, char *argv[]) {
    int option_index, c;
    int tam = 8;                        // Tamaño del mundo (default 8)
    int sim = 25;                       // Número de simulaciones (default 25)
    bool help = false;                  // Muestra ayuda
    bool random = false;                // Genera mundo aleatorio
    char *estadoConocido = "glider";    // Estado inicial conocido

    // Fichero de configuración
    FILE *fp;
    bool file = false;
    char *filename;

    while ((c = getopt_long(argc, argv, "t:s:f:c:rh", long_options, &option_index)) != -1) {
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
            case 'f':
                file = true;
                filename = optarg;
                break;
            case 'c':
                estadoConocido = optarg;
                break;
            case '?':
                help = true;
                break;
        }
    }

    if (help == true) {
        printf("./main.out -t tamaño -s simulaciones -f fichero_config [-r -h]\n");
        printf("\t -t tamaño: Tamaño del tablero\n");
        printf("\t -s simulaciones: Número de simulaciones\n");
        printf("\t -f fichero_config: Fichero de configuración\n");
        printf("\t -c [glider | blinker | toad | row]: Estado incial conocido\n");
        printf("\t -r: Inicializa el mundo con un estado aleatorio\n");
        printf("\t -h: Muestra esta ayuda\n");

        return 0;
    }

    if (file == true) {
        printf("Leyendo fichero de configuración...\n");
        // Abre el fichero de configuración
        fp = fopen(filename, "r");
    }

    // Reserva memoria para las estructuras del mundo
    struct mundo *pactual = mundo_alloc();
    struct mundo *pfuturo = mundo_alloc();

    // Establece el tamaño de ambos mundos
    mundo_set_tam(pactual,tam);
    mundo_set_tam(pfuturo,tam);

    // Comprueba la reserva
    if (!pactual || !pfuturo) {
       perror("Error ");
       return -1;
   }
    // Reserva memoria para el tablero y comprueba la reserva
    if (mundo_alloc_tablero(pactual) == -1 || mundo_alloc_tablero(pfuturo)  == -1) {
        perror("Error ");
        return -1;
    }

    if (random == false) {
        mundoConocido(pactual,estadoConocido);
    }
    else {
        mundoAleatorio(pactual);
    }

    // Bucle de simulaciones
    for (int k = 0; k < sim; k++) {
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
        mundo_alloc_tablero(pfuturo);
    }

    // Libera memoria
    if (file == true)
        fclose(fp);
    mundo_free(pactual);
    mundo_free(pfuturo);

    return 0;
}
