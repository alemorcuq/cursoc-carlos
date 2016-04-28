#ifndef _GOL_H_
#define _GOL_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <getopt.h>
#include <time.h>
#include "mundo.h"

// Código colores para imprimir el mapa
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"

// Posibles estados de una célula
enum estado {
    MUERTA,     // Célula muerta (-)
    VIVA        // Célula viva (o)
};

// Estrcutura para getopt
static struct option long_options[] =
{
    {"tamaño",       required_argument,    0,  't'},
    {"simulaciones", required_argument,    0,  's'},
    {"conocido",     required_argument,    0,  'c'},
    {"random",       no_argument,          0,  'r'},
    {"fconfig",      required_argument,    0,  'f'},
    {"festado",      required_argument,    0,  'e'},
    {"help",         no_argument,          0,  'h'},
    {0, 0, 0, 0}
};

// Imprime el tablero
void printTablero(struct mundo *m);

// Realiza la lógica del juego, determina el nuevo estado a partir del anterior
void transicion(struct mundo *a, struct mundo *f);

// Accede al contenido de una célula
int getCelula(int i, int j, struct mundo *m);

/* Recibe las coordenadas de una célula y comprueba el estado de sus vecinas
Devuelve el número de células vivas a su alrededor*/
int checkVecinas(struct mundo *a, int i, int j);

// Comprueba que las células vecinas están dentro del tablero
bool checkLimit(int x, int y,int tam);

// Inicializa el mundo con un estado aleatorio
void mundoAleatorio(struct mundo *a);

// Inicializa el mundo con un estado conocido
void mundoConocido(struct mundo *m, char *c);

// Guarda el estado final
void printFinal(struct mundo *m);

#endif
