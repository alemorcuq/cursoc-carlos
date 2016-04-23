#include "gol.h"
#include "mundo.h"

// Imprime el tablero
void printTablero(struct mundo *m) {
    // Recorre el tablero
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            // Imprime "o" por célula viva
            if(*(mundo_get_tablero(m) + i*TAM + j) == VIVA)
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
    int contador = 0;                   // Cuenta el número de células vivas para hacer transición
    int numCelVivas = 0;                // Almacena el nº de células vivas
    int numCelMuertas = 0;              // Almacena el nº de células muertas
    mundo_set_vivas(a,numCelVivas);
    mundo_set_muertas(a,numCelMuertas);

    // Recorre el tablero
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            // Devuelve el número de vecinas vivas
            contador = checkVecinas(a,i,j);
            // Célula actual viva
            if (getCelula(i,j,a) == VIVA) {
                // Célula viva con 2 ó 3 células vecinas vivas sigue viva
                if (contador == 3 || contador == 2)
                    *(mundo_get_tablero(f) + i*TAM + j) = VIVA; // Actualiza el estado en el tablero futuro
                // En otro caso muere
                else
                    *(mundo_get_tablero(f) + i*TAM + j) = MUERTA; // Actualiza el estado en el tablero futuro
                numCelVivas++;
                mundo_set_vivas(a,numCelVivas);
            }
            // Célula actual muerta
            else if (getCelula(i,j,a) == MUERTA) {
                // Una célula muerta con exactamente 3 células vecinas vivas nace
                if (contador == 3)
                    *(mundo_get_tablero(f) + i*TAM + j) = VIVA; // Actualiza el estado en el tablero futuro
                // En otro caso permanece muerta
                else
                    *(mundo_get_tablero(f) + i*TAM + j) = MUERTA; // Actualiza el estado en el tablero futuro
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
    return *(mundo_get_tablero(m) + i*TAM + j);
}

/* Recibe el mundo y las coordenadas de una célula y comprueba el estado de sus vecinas
Devuelve el número de células vivas a su alrededor*/
int checkVecinas(struct mundo *a, int i, int j){
    int cuenta = 0;

    int topi = i-1;     // Fila superior
    int boti = i+1;     // Fila inferior
    int leftj = j-1;    // Columna izquierda
    int rightj = j+1;   // Columna derecha

    /* Primero comprueba que la célula vecina está en el tablero (checkLimit)...
    ... en caso de estarlo comprueba su estado */
    if (checkLimit(topi,leftj) && getCelula(topi,leftj,a) == VIVA)      // Diagonal superior izq
        cuenta++;
    if (checkLimit(topi,j) && getCelula(topi,j,a) == VIVA)              // Superior central
        cuenta++;
    if (checkLimit(topi,rightj) && getCelula(topi,rightj,a) == VIVA)    // Diagonal superior der
        cuenta++;
    if (checkLimit(i,leftj) && getCelula(i,leftj,a) == VIVA)            // Izquierda
        cuenta++;
    if (checkLimit(i,rightj) && getCelula(i,rightj,a) == VIVA)          // Derecha
        cuenta++;
    if (checkLimit(boti,leftj) && getCelula(boti,leftj,a) == VIVA)      // Diagonal inferior izq
        cuenta++;
    if (checkLimit(boti,j) && getCelula(boti,j,a) == VIVA)              // Inferior central
        cuenta++;
    if (checkLimit(boti,rightj) && getCelula(boti,rightj,a) == VIVA)    // Diagonal superior der
        cuenta++;

    return cuenta;
}

// Comprueba que las células vecinas están dentro del tablero
bool checkLimit(int x, int y) {
    if (y >= 0 && y < TAM && x >= 0 && x < TAM)
        return true;
    else
        return false;
}
