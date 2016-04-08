#ifndef _GOL_H_
#define _GOL_H_

#define TAM 8   // Tamaño del tablero (Cuadrado de TAMxTAM)
#define SIM 25   // Número de simulaciones

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"

// Posibles estados de una célula
enum estado {
    MUERTA,
    VIVA
};

// Estructura del mundo
struct mundo {
    int tablero[TAM][TAM];  // Tablero/Mapa del mundo
    int numCelVivas;        // Número de células vivas
    int numCelMuertas;      // Número de células muertas
    int numCelTotales;      // Tamaño del mundo = Número células totales
};

// Imprime el tablero
void printTablero(struct mundo *m);

// Realiza la lógica del juego, determina el nuevo estado a partir del anterior
void transicion(struct mundo *a, struct mundo *f, FILE *fp);

/* Recibe las coordenadas de una célula y comprueba el estado de sus vecinas
Devuelve el número de células vivas a su alrededor*/
int checkVecinas(struct mundo *a, int i, int j, FILE *fp);

#endif
