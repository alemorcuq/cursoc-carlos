#include <stdio.h>
#include <math.h>
#include "cmplx.h"

// Suma dos números complejos
struct cmplx cmplx_sum(const struct cmplx *a, const struct cmplx *b) {
    // Declara la estructura
    struct cmplx result;

    // Suma real con real e imaginario con imaginario
    result.real = a->real + b->real;
    result.img = a->img + b->img;

    return result;
}

// Resta dos números complejos
struct cmplx cmplx_sub(const struct cmplx *a, const struct cmplx *b) {
    // Declara la estructura
    struct cmplx result;

    // Resta real con real e imaginario con imaginario
    result.real = a->real - b->real;
    result.img = a->img - b->img;

    return result;
}

// Valor absoluto de un número complejo
double cmplx_abs(const struct cmplx *c) {
    double result = sqrt((c->real*c->real) + (c->img*c->img));

    return result;
}


int cmplx_norm(struct cmplx *c) {
    int result = (c->real*c->real) + (c->img*c->img);

    return result;
}

// Imprime el número complejo
void cmplx_print(const struct cmplx *c) {
    printf("%f + %fi\n", c->real, c->img);
}
