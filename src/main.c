#include "gol.h"
#include "mundo.h"

int main(int argc, char *argv[]) {
    int option_index, c;
    int tam = 8;                            // Tamaño del mundo (default 8)
    int sim = 25;                           // Número de simulaciones (default 25)
    bool help = false;                      // Muestra ayuda
    bool random = false;                    // Genera mundo aleatorio
    char estadoConocido[10] = "gli";        // Estado inicial conocido (default glider)

    // Fichero de configuración
    FILE *fp;
    bool configFile = false;
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
                configFile = true;
                filename = optarg;
                break;
            case 'c':
                strcpy(estadoConocido,optarg);
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
        printf("\t -c [gli | bli | toa | row]: Estado incial conocido\n");
        printf("\t -r: Inicializa el mundo con un estado aleatorio\n");
        printf("\t -h: Muestra esta ayuda\n");

        return 0;
    }

    if (configFile == true) {
        printf("Leyendo fichero de configuración %s...\n", filename);
        // Abre el fichero de configuración y comprueba la apertura
        if (!(fp = fopen(filename, "r"))) {
            perror("Error ");
            printf("Configuración predeterminada\n");
        }
        else {
            char str[3];
            int ret = fscanf(fp, "%s = %d\n%s = %d\n%s = %3s\n",str,&tam,str,&sim,str,estadoConocido);
            if (ferror(fp) || (ret != 6)) {
                perror("Error al leer");
                // Parámetros por defecto y continúa la ejecución
                tam = 8;
                sim = 25;
            }
            fclose(fp);
        }
    }

    // Abre el fichero de log y comprueba la apertura
    if (!(fp = fopen("file.log", "w")))
       perror("Error ");
    fprintf(fp, "Iter\tVivas\tMuertas\n");
    if (ferror(fp))
        perror("Error al escribir");

    printf("Tamaño: %d\n",tam);
    printf("Número de simulaciones: %d\n\n",sim);

    // Reserva y comprueba la memoria para las estructuras del mundo
    struct mundo *pactual = mundo_alloc();
    struct mundo *pfuturo = mundo_alloc();
    if (!pactual || !pfuturo) {
       perror("Error ");
       return -1;
    }

    // Establece el tamaño de ambos mundos
    mundo_set_tam(pactual,tam);
    mundo_set_tam(pfuturo,tam);

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
        printf("Iteracción %d\n", k+1);
        // Realiza la lógica del juego, determina el nuevo estado a partir del anterior
        transicion(pactual,pfuturo);

        // Imprime el mundo en cada iteracción
        printf(ANSI_COLOR_GREEN "Células vivas: %d " ANSI_COLOR_RESET
                ANSI_COLOR_RED "Células muertas: %d\n" ANSI_COLOR_RESET,
                mundo_get_vivas(pactual), mundo_get_muertas(pactual));
        printTablero(pactual);
        printf("\n");

        fprintf(fp, "<%d> \t<%d> \t<%d>\n",k+1,mundo_get_vivas(pactual), mundo_get_muertas(pactual));
        if (ferror(fp))
            perror("Error al escribir");

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

    // Cierra el fichero de logs
    fclose(fp);

    // Libera memoria
    mundo_free(pactual);
    mundo_free(pfuturo);

    return 0;
}
