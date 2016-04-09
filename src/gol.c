#include <stdio.h>
#include <stdlib.h>
#include "gol.h"

// Imprime el tablero
void printTablero(struct mundo *m) {
    // Recorre el tablero
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            // Imprime "o" por célula viva
            if(m->tablero[i][j] == VIVA)
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
    int contador = 0;   // Cuenta el número de células vivas para hacer transición
    f->numCelVivas = 0;
    f->numCelMuertas = 0;

    // Recorre el tablero
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            // Devuelve el número de vecinas vivas
            contador = checkVecinas(a,i,j);
            // Célula actual viva
            if (a->tablero[i][j] == VIVA) {
                // Célula viva con 2 ó 3 células vecinas vivas sigue viva
                if (contador == 3 || contador == 2)
                    f->tablero[i][j] = VIVA; // Actualiza el estado en el tablero futuro
                // En otro caso muere
                else
                    f->tablero[i][j] = MUERTA; // Actualiza el estado en el tablero futuro
                f->numCelVivas++;
            }
            // Célula actual muerta
            else if (a->tablero[i][j] == MUERTA) {
                // Una célula muerta con exactamente 3 células vecinas vivas nace
                if (contador == 3)
                    f->tablero[i][j] = VIVA; // Actualiza el estado en el tablero futuro
                // En otro caso permanece muerta
                else
                    f->tablero[i][j] = MUERTA; // Actualiza el estado en el tablero futuro
                f->numCelMuertas++;
            }
            // Comportamiento no deseado
            else {
                printf(ANSI_COLOR_RED "\t [ERROR]\t Se ha detectado célula zombie (Ni viva ni muerta)\n" ANSI_COLOR_RESET);
                exit(0);
            }
        }
    }
}

/* Recibe el mundo y las coordenadas de una célula y comprueba el estado de sus vecinas
Devuelve el número de células vivas a su alrededor*/
int checkVecinas(struct mundo *a, int i, int j){
    int cuenta = 0;
    int fila = i-1;
    int columna = j-1;

    for (int k = 0; k < 3; k++) {
        for (int l = 0; l < 3; l++) {
            // Protege de comprobar fuera del mundo y contarse a si misma como vecina
            if (columna < TAM && columna >= 0 && (fila != i || columna != j) && fila >= 0 && fila < TAM ) {
                // ¿Célula vecina válida viva?
                if (a->tablero[fila][columna] == VIVA)
                    cuenta++;
            }
            columna++;
        }
        columna = j-1;
        fila++;
    }

    return cuenta;
}
