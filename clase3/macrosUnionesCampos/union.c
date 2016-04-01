#include <stdio.h>
#include <stdint.h>

union cadena_entero {
    char cadena[4];
    uint64_t entero;
};

int main() {
    union cadena_entero dato64;

    return 0;
}
