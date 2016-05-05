#ifndef _MUNDO_H_
#define _MUNDO_H_

#include "gol.h"

struct mundo;

/* Constructor/Destructor */
// Estructura mundo
int mundo_build2(struct mundo * a, struct mundo *f, int t);
struct mundo *mundo_alloc();
struct mundo *mundo_falloc(char *filename);
void mundo_free(struct mundo *m);
// Tablero
int mundo_alloc_tablero(struct mundo *m);
void mundo_free_tablero(struct mundo *m);

/* Métodos */
// Setters
int mundo_set_vivas(struct mundo *m, const int num);
int mundo_set_muertas(struct mundo *m, const int num);
int mundo_set_tam(struct mundo *m, const int num);

// Getters
int *mundo_get_tablero(struct mundo *m);
int mundo_get_vivas(struct mundo *m);
int mundo_get_muertas(struct mundo *m);
int mundo_get_tam(struct mundo *m);

// Clonar
struct mundo *mundo_clone(struct mundo *actual, struct mundo *futuro);
void mundo_save(struct mundo *m);

#endif
