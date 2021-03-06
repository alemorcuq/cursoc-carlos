#include "gol.h"
#include "mundo.h"

// Imprime el tablero
void printTablero(struct mundo *m) {
    int tam = mundo_get_tam(m);
    // Recorre el tablero
    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            // Imprime "o" por célula viva
            if(getCelula(i,j,m) == VIVA)
                printf(ANSI_COLOR_GREEN " o " ANSI_COLOR_RESET);
            // Imprime "-" por célula muerta
            else
                printf(ANSI_COLOR_RED " - " ANSI_COLOR_RESET);
        }
        printf("\n");
    }
}

// Realiza la lógica del juego, determina el nuevo estado (f) a partir del anterior (a)
void transicion(struct mundo *a, struct mundo *f){
    int contador = 0;                       // Cuenta el número de células vivas para hacer transición
    int numCelVivas = 0;                    // Almacena el nº de células vivas
    int numCelMuertas = 0;                  // Almacena el nº de células muertas
    int tam = mundo_get_tam(a);             // Tamaño del mundo
    mundo_set_vivas(a,numCelVivas);
    mundo_set_muertas(a,numCelMuertas);

    // Recorre el tablero
    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            // Devuelve el número de vecinas vivas
            contador = checkVecinas(a,i,j);
            // Célula actual viva
            if (getCelula(i,j,a) == VIVA) {
                // Célula viva con 2 ó 3 células vecinas vivas sigue viva
                if (contador == 3 || contador == 2)
                    *(mundo_get_tablero(f) + i*tam + j) = VIVA; // Actualiza el estado en el tablero futuro
                // En otro caso muere
                else
                    *(mundo_get_tablero(f) + i*tam + j) = MUERTA; // Actualiza el estado en el tablero futuro
                numCelVivas++;
                mundo_set_vivas(a,numCelVivas);
            }
            // Célula actual muerta
            else if (getCelula(i,j,a) == MUERTA) {
                // Una célula muerta con exactamente 3 células vecinas vivas nace
                if (contador == 3)
                    *(mundo_get_tablero(f) + i*tam + j) = VIVA; // Actualiza el estado en el tablero futuro
                // En otro caso permanece muerta
                else
                    *(mundo_get_tablero(f) + i*tam + j) = MUERTA; // Actualiza el estado en el tablero futuro
                numCelMuertas++;
                mundo_set_muertas(a,numCelMuertas);
            }
            // Comportamiento no deseado
            else {
                printf(ANSI_COLOR_RED "\t [ERROR]\t Se ha detectado célula zombie (Ni viva ni muerta)\n" ANSI_COLOR_RESET);
                exit(-1);
            }
        }
    }
}

// Accede al contenido de una célula
int getCelula(int i, int j, struct mundo *m) {
    int tam = mundo_get_tam(m);

    return *(mundo_get_tablero(m) + i*tam + j);
}

/* Recibe el mundo y las coordenadas de una célula y comprueba el estado de sus vecinas
Devuelve el número de células vivas a su alrededor*/
int checkVecinas(struct mundo *a, int i, int j){
    int cuenta = 0;
    int tam = mundo_get_tam(a);

    int topi = i-1;     // Fila superior
    int boti = i+1;     // Fila inferior
    int leftj = j-1;    // Columna izquierda
    int rightj = j+1;   // Columna derecha

    /* Primero comprueba que la célula vecina está en el tablero (checkLimit)...
    ... en caso de estarlo comprueba su estado */
    if (checkLimit(topi,leftj,tam) && getCelula(topi,leftj,a) == VIVA)      // Diagonal superior izq
        cuenta++;
    if (checkLimit(topi,j,tam) && getCelula(topi,j,a) == VIVA)              // Superior central
        cuenta++;
    if (checkLimit(topi,rightj,tam) && getCelula(topi,rightj,a) == VIVA)    // Diagonal superior der
        cuenta++;
    if (checkLimit(i,leftj,tam) && getCelula(i,leftj,a) == VIVA)            // Izquierda
        cuenta++;
    if (checkLimit(i,rightj,tam) && getCelula(i,rightj,a) == VIVA)          // Derecha
        cuenta++;
    if (checkLimit(boti,leftj,tam) && getCelula(boti,leftj,a) == VIVA)      // Diagonal inferior izq
        cuenta++;
    if (checkLimit(boti,j,tam) && getCelula(boti,j,a) == VIVA)              // Inferior central
        cuenta++;
    if (checkLimit(boti,rightj,tam) && getCelula(boti,rightj,a) == VIVA)    // Diagonal superior der
        cuenta++;

    return cuenta;
}

// Comprueba que las células vecinas están dentro del tablero
bool checkLimit(int x, int y, int tam) {
    if (y >= 0 && y < tam && x >= 0 && x < tam)
        return true;
    else
        return false;
}

// Inicializa el mundo con un estado aleatorio
void mundoAleatorio(struct mundo *a) {
    // Semilla en función de la hora
    time_t t;
    srand((unsigned) time(&t));
    int tam = mundo_get_tam(a);

    // Recorre el tablero
    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            // Número aleatorio entre 0 y 1
            // Si sale un 1, ponemos esa célula viva. Si sale 0, la ponemos viva
            if (rand()%2 == 1)
                *(mundo_get_tablero(a) + i*tam + j) = VIVA;
            else
                *(mundo_get_tablero(a) + i*tam + j) = MUERTA;
        }
    }
    printf("RANDOM\n");

    return;
}

// Inicializa el mundo con un estado conocido
void mundoConocido(struct mundo *m, char *c) {
    int tam;
    if (strcmp(c,"gli") == 0) {
        if (mundo_get_tam(m) < 5)
            mundo_set_tam(m,6);
        tam = mundo_get_tam(m);
        // Células formando Glider
        *(mundo_get_tablero(m) + 0*tam + 1) = VIVA;
        *(mundo_get_tablero(m) + 1*tam + 2) = VIVA;
        *(mundo_get_tablero(m) + 2*tam + 0) = VIVA;
        *(mundo_get_tablero(m) + 2*tam + 1) = VIVA;
        *(mundo_get_tablero(m) + 2*tam + 2) = VIVA;
        printf("GLIDER\n");
    }
    else if (strcmp(c,"bli") == 0) {
        if (mundo_get_tam(m) < 3)
            mundo_set_tam(m,4);
        tam = mundo_get_tam(m);
        // Células formando Blinker
        *(mundo_get_tablero(m) + 2*tam + 2) = VIVA;
        *(mundo_get_tablero(m) + 2*tam + 3) = VIVA;
        *(mundo_get_tablero(m) + 2*tam + 4) = VIVA;
        printf("BLINKER\n");
    }
    else if (strcmp(c,"toa") == 0) {
        if (mundo_get_tam(m) < 4)
            mundo_set_tam(m,5);
        tam = mundo_get_tam(m);
        // Células formando Toad
        *(mundo_get_tablero(m) + 2*tam + 2) = VIVA;
        *(mundo_get_tablero(m) + 2*tam + 3) = VIVA;
        *(mundo_get_tablero(m) + 2*tam + 4) = VIVA;
        *(mundo_get_tablero(m) + 3*tam + 1) = VIVA;
        *(mundo_get_tablero(m) + 3*tam + 2) = VIVA;
        *(mundo_get_tablero(m) + 3*tam + 3) = VIVA;
        printf("TOAD\n");
    }
    else if (strcmp(c,"row") == 0) {
        if (mundo_get_tam(m) < 10)
            mundo_set_tam(m,11);
        tam = mundo_get_tam(m);
        // Células formando ten-Row
        *(mundo_get_tablero(m) + 2*tam + 1) = VIVA;
        *(mundo_get_tablero(m) + 2*tam + 2) = VIVA;
        *(mundo_get_tablero(m) + 2*tam + 3) = VIVA;
        *(mundo_get_tablero(m) + 2*tam + 4) = VIVA;
        *(mundo_get_tablero(m) + 2*tam + 5) = VIVA;
        *(mundo_get_tablero(m) + 2*tam + 6) = VIVA;
        *(mundo_get_tablero(m) + 2*tam + 7) = VIVA;
        *(mundo_get_tablero(m) + 2*tam + 8) = VIVA;
        *(mundo_get_tablero(m) + 2*tam + 9) = VIVA;
        *(mundo_get_tablero(m) + 2*tam + 10) = VIVA;
        printf("10-ROW\n");
    }
    else {
        // Si ha habido un error => random
        mundoAleatorio(m);
    }

    return;
}


// Imprime en un fichero el último estado
void printFinal(struct mundo *m) {
    int tam = mundo_get_tam(m);
    // Abre el fichero de estado y comprueba la apertura
    FILE *fp;
    if (!(fp = fopen("state.txt", "w")))
        perror("Error ");

    // Guarda el tamaño del mundo actual
    fprintf(fp,"%d\n",tam);
    if (ferror(fp))
        perror("Error al escribir");

    // Recorre el tablero
    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            fprintf(fp,"%d ",*(mundo_get_tablero(m) + i*tam + j));
            if (ferror(fp))
                perror("Error al escribir");
        }
        fprintf(fp,"\n");
        if (ferror(fp))
            perror("Error al escribir");
    }
}
