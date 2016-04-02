#include <stdio.h>

// TODO Añadir warning y pasar valor de la variable C
#define CONV(c) do {    \
    if (c>96 && c<122) { \
        printf("\t%c %c\n",c,((c)-32)); \
    } \
    else {   \
        printf( "\tEror en %s:%d\n",__FILE__, __LINE__); \
    } \
} while(0)

int main() {
    char c = 'h';
    char d = '$';

    printf("Pasamos carácter letra:\n");
    CONV(c);
    printf("\nPasamos carácter $:\n");
    CONV(d);

    return 0;
}
