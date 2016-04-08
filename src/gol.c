#include <stdio.h>
#include "gol.h"

// Imprime el tablero
void printTablero(struct mundo *m) {
    // Recorre el tablero
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            // Imprime "o" por célula viva
            if(m->tablero[i][j] == VIVA) {
                printf("\to ");
            }
            // Imprime "-" por célula muerta
            else {
                printf("\t- ");
            }
        }
        printf("\n");
    }
}

// Realiza la lógica del juego, determina el nuevo estado (f) a partir del anterior (a)
void transicion(struct mundo *a, struct mundo *f, FILE *fp){
    int contador = 0;   // Cuenta el número de células vivas para hacer transición

    // Recorre el tablero
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            // Devuelve el número de vecinas vivas
            contador = checkVecinas(a,i,j,fp);
            // Célula actual viva
            if (a->tablero[i][j] == VIVA) {
                // Célula viva con 2 ó 3 células vecinas vivas sigue viva
                if (contador == 3 || contador == 2) {
                    // Actualiza el estado en el tablero futuro
                    f->tablero[i][j] = VIVA;
                    // +1 viva | -1 muerta
                    f->numCelVivas++;
                    f->numCelMuertas--;
                }
                // En otro caso muere
                else {
                    // Actualiza el estado en el tablero futuro
                    f->tablero[i][j] = MUERTA;
                    // +1 muerta | -1 viva
                    f->numCelMuertas++;
                    f->numCelVivas--;
                }
            }
            // Célula actual muerta
            else if (a->tablero[i][j] == MUERTA) {
                // Una célula muerta con exactamente 3 células vecinas vivas nace
                if (contador == 3) {
                    // Actualiza el estado en el tablero futuro
                    f->tablero[i][j] = VIVA;
                    // +1 viva | -1 muerta
                    f->numCelVivas++;
                    f->numCelMuertas--;
                }
                // En otro caso permanece muerta
                else {
                    // Actualiza el estado en el tablero futuro
                    f->tablero[i][j] = MUERTA;
                    // +1 muerta | -1 viva
                    f->numCelMuertas++;
                    f->numCelVivas--;
                }
            }
            // Comportamiento no deseado
            else {
                printf("\t [ERROR]\t Se ha detectado célula zombie (Ni viva ni muerta)\n");
            }
        }
    }
}

/* Recibe el mundo y las coordenadas de una célula y comprueba el estado de sus vecinas
Devuelve el número de células vivas a su alrededor*/
int checkVecinas(struct mundo *a, int i, int j, FILE *fp){
    int cuenta = 0;
    int fila = i-1;
    int columna = j-1;

    fprintf(fp,"Mirando célula [%d,%d]:\n",i,j);

    for (int k = 0; k < 3; k++) {
        for (int l = 0; l < 3; l++) {
            // Protege de comprobar fuera del mundo y contarse a si misma como vecina
            if (columna < TAM && columna >= 0 && (fila != i || columna != j) && fila >= 0 && fila < TAM ) {
                fprintf(fp,"\t¿Check con [%d,%d]?\n",fila,columna);
                // ¿Célula vecina válida viva?
                if (a->tablero[fila][columna] == VIVA){
                    fprintf(fp,"\t\t Vecina viva en [%d,%d]\n",fila,columna);
                    cuenta++;
                }
                else {
                    fprintf(fp,"\t\t Vecina muerta en [%d,%d]\n",fila,columna);
                }
            }
            columna++;
        }
        columna = j-1;
        fila++;
    }

    fprintf(fp,"\tCélula [%d,%d] => %d vecinas vivas\n\n",i,j,cuenta);
    return cuenta;
}
