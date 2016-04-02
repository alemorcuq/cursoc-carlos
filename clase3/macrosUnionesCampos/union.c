#include <stdio.h>
#include <stdint.h>

union cadena_entero {
    char cadena[4];
    uint64_t entero;
};

int main() {
    union cadena_entero dato64;
    uint64_t a = 18446744073709551;
    dato64.entero = a;

    printf("%d %d %d %d\n", dato64.cadena[1], dato64.cadena[2], dato64.cadena[3], dato64.cadena[4]);
    printf("%llu\n", dato64.entero);

    return 0;
}
