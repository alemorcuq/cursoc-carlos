#ifndef _GOL_H_
#define _GOL_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "mundo.h"

#define TAM 8       // Tamaño del tablero (Cuadrado de TAMxTAM)
#define SIM 5      // Número de simulaciones

// Código colores para imprimir el mapa
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"

// Posibles estados de una célula
enum estado {
    MUERTA,     // Célula muerta (-)
    VIVA        // Célula viva (o)
};

// Imprime el tablero
void printTablero(struct mundo *m);

// Realiza la lógica del juego, determina el nuevo estado a partir del anterior
void transicion(struct mundo *a, struct mundo *f);

/* Recibe las coordenadas de una célula y comprueba el estado de sus vecinas
Devuelve el número de células vivas a su alrededor*/
int checkVecinas(struct mundo *a, int i, int j);

// Comprueba que las células vecinas están dentro del tablero
bool checkLimit(int x, int y);

#endif
