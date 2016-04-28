#include "gol.h"
#include "mundo.h"

int main(int argc, char *argv[]) {
    int option_index, c;
    int tam = 8;                            // Tamaño del mundo (default 8)
    int sim = 25;                           // Número de simulaciones (default 25)
    char estadoConocido[10] = "gli";        // Estado inicial conocido (default glider)

    // Flags para comprobar entrada
    bool help = false;
    bool random = false;
    bool configFile = false;
    bool estadoFile = false;

    // Nombre del fichero recibido
    char *filename;

    while ((c = getopt_long(argc, argv, "t:s:c:rf:e:h", long_options, &option_index)) != -1) {
        switch (c) {
            case 't':
                tam = strtol(optarg, NULL, 0);
                break;
            case 's':
                sim = strtol(optarg, NULL, 0);
                break;
            case 'c':
                strcpy(estadoConocido,optarg);
                break;
            case 'r':
                random = true;
                break;
            case 'f':
                configFile = true;
                filename = optarg;
                break;
            case 'e':
                estadoFile = true;
                filename = optarg;
                break;
            case 'h':
            case '?':
                help = true;
                break;
        }
    }

    if (help == true) {
        printf("./main.out [opciones]\n");
        printf("\t Opción 1: ./main.out -t tam -s sim [-c est ó -r]\n");
        printf("\t\t -t tamaño: Tamaño del tablero\n");
        printf("\t\t -s simulaciones: Número de simulaciones\n");
        printf("\t\t -c [gli | bli | toa | row]: Estado incial conocido\n");
        printf("\t\t -r: Inicializa el mundo con un estado aleatorio\n");
        printf("\t Opción 2: ./main.out -f file\n");
        printf("\t\t -f fichero_config: Fichero de configuración\n");
        printf("\t Opción 3: ./main.out -e file\n");
        printf("\t\t -e fichero_estado: Fichero de estado anterior\n");
        printf("\t -h: Muestra esta ayuda\n");
        return 0;
    }

    if (configFile == true) {
        FILE *fpconf;
        printf("Leyendo fichero de configuración %s...\n", filename);
        // Abre el fichero de configuración y comprueba la apertura
        if (!(fpconf = fopen(filename, "r"))) {
            perror("Error ");
            printf("Configuración predeterminada\n");
        }
        else {
            char str[3];
            int ret = fscanf(fpconf, "%s = %d\n%s = %d\n%s = %3s\n",str,&tam,str,&sim,str,estadoConocido);
            if (ferror(fpconf) || (ret != 6)) {
                perror("Error al leer");
                // Parámetros por defecto y continúa la ejecución
                tam = 8;
                sim = 25;
            }
            fclose(fpconf);
        }
    }

    // Abre el fichero de log y comprueba la apertura
    FILE *fplog;
    if (!(fplog = fopen("file.log", "w")))
       perror("Error ");
    fprintf(fplog, "Iter\tVivas\tMuertas\n");
    if (ferror(fplog))
        perror("Error al escribir");

    // Reserva y comprueba la memoria para las estructuras del mundo
    struct mundo *pactual = mundo_alloc();
    struct mundo *pfuturo = mundo_alloc();

    if (!pactual || !pfuturo) {
       perror("Error ");
       return -1;
    }

    if (random == false && estadoFile == false) {
        // Establece el tamaño de ambos mundos
        mundo_set_tam(pactual,tam);
        mundo_set_tam(pfuturo,tam);

        // Reserva memoria para el tablero y comprueba la reserva
        if (mundo_alloc_tablero(pactual) == -1 || mundo_alloc_tablero(pfuturo)  == -1) {
            perror("Error ");
            return -1;
        }

        mundoConocido(pactual,estadoConocido);
    }
    else if (estadoFile == true) {
        FILE *fpest;
        printf("Leyendo fichero de estado anterior %s...\n", filename);
        // Abre el fichero de estado y comprueba la apertura
        if (!(fpest = fopen(filename, "r"))) {
            perror("Error ");
            printf("Configuración predeterminada\n");
            mundoConocido(pactual,estadoConocido);
        }
        else {
            // Leer tamaño mundo anterior
            int ret = fscanf(fpest, "%d",&tam);
            if (ferror(fpest) || (ret != 1))
                perror("Error al leer");

            // Establece el tamaño de ambos mundos
            mundo_set_tam(pactual,tam);
            mundo_set_tam(pfuturo,tam);

            // Reserva memoria para el tablero y comprueba la reserva
            if (mundo_alloc_tablero(pactual) == -1 || mundo_alloc_tablero(pfuturo)  == -1) {
                perror("Error ");
                return -1;
            }

            // Recorre el tablero guardado en el fichero e inicializa el nuevo mundo
            for (int i = 0; i < tam; i++) {
                for (int j = 0; j < tam; j++) {
                    int var;

                    ret = fscanf(fpest, "%d",&var);
                    if (ferror(fpest) || (ret != 1))
                        perror("Error al leer");

                    // Crea el nuevo tablero con los datos obtenidos
                    if (var == VIVA)
                        *(mundo_get_tablero(pactual) + i*tam + j) = VIVA;
                    else
                        *(mundo_get_tablero(pactual) + i*tam + j) = MUERTA;
                }
            }
            fclose(fpest);
        }
    }
    else {
        // Establece el tamaño de ambos mundos
        mundo_set_tam(pactual,tam);
        mundo_set_tam(pfuturo,tam);

        // Reserva memoria para el tablero y comprueba la reserva
        if (mundo_alloc_tablero(pactual) == -1 || mundo_alloc_tablero(pfuturo)  == -1) {
            perror("Error ");
            return -1;
        }

        mundoAleatorio(pactual);
    }
    
    printf("Tamaño: %d\n",tam);
    printf("Número de simulaciones: %d\n\n",sim);

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

        // Escribe fichero histórico
        fprintf(fplog, "<%d> \t<%d> \t<%d>\n",k+1,mundo_get_vivas(pactual), mundo_get_muertas(pactual));
        if (ferror(fplog))
            perror("Error al escribir");

        // Imprime en un fichero el último estado
        if (k == sim-1)
            printFinal(pactual);

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
    fclose(fplog);

    // Libera memoria
    mundo_free(pactual);
    mundo_free(pfuturo);

    return 0;
}
