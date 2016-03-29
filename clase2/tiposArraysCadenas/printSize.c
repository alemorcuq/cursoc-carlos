#include <stdio.h>

/* Hemos hecho pruebas con diferentes tipos de datos, superando los límites
para ver los warnings por overflow y ver qué valor devuelven
*/
int main() {
    int entero = 3;
    char c;
    c = 'c';

    printf("int\n\tvalor = %d\n\ttamaño %lu bytes \n\n",entero, sizeof(entero));
    printf("char\n\tvalor = %c\n\ttamaño %lu bytes \n\n",c, sizeof(char));

    return 0;
}
