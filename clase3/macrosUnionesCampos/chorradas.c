#include <stdio.h>
#include <stdint.h>

// Averiguar cómo hacer las dos funciones macros en una misma que funcione
#define CONVPRINT(c) do {    \
    if (c>96 && c<122) { \
        printf("%c %c\n",c,((c)-32)); \
    } \
    else {   \
        printf( "Eror en %s:%d\n",__FILE__, __LINE__); \
    } \
} while(0)

#define CONV(c) ((c)-32)

union cadena_entero {
    char cadena[4];
    uint64_t entero;
};

int main() {
    // Cadena en minúsculas
    union cadena_entero dato64 = {'a','b','c','d'};

    printf("%c %c %c %c\n", dato64.cadena[0], dato64.cadena[1], dato64.cadena[2], dato64.cadena[3]);
    printf("%llu\n\n", dato64.entero);

    // 3 caracteres en mayúsculas
    dato64.cadena[0] = CONV(dato64.cadena[0]);
    dato64.cadena[1] = CONV(dato64.cadena[1]);
    dato64.cadena[2] = CONV(dato64.cadena[2]);

    printf("%c %c %c %c\n", dato64.cadena[0], dato64.cadena[1], dato64.cadena[2], dato64.cadena[3]);
    printf("%llu\n\n", dato64.entero);

    // Guardamos un número en la estructura
    dato64.entero = 52458;
    CONVPRINT(dato64.cadena[0]);
    CONVPRINT(dato64.cadena[1]);
    CONVPRINT(dato64.cadena[2]);
    CONVPRINT(dato64.cadena[3]);

    return 0;
}
