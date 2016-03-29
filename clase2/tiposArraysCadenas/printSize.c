#include <stdio.h>

int main() {
    int entero = 3;         // Variable entera
    char c = 'c';           // Variable caracter

    printf("int\n\tvalor = %d\n\ttamaño %lu bytes \n\n",entero, sizeof(entero));
    printf("char\n\tvalor = %c\n\ttamaño %lu bytes \n\n",c, sizeof(char));

    return 0;
}
