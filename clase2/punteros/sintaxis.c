#include <stdio.h>

int main() {
    int i = 0;         // Variable entera i
    char c = 'c';       // Variable char c

    int *pi = &i;       // Puntero a entero apuntando a i
    char *pc = &c;      // Puntero a char apuntando a c

    // Cambia el valor de la variable a través del puntero
    *pi = 18;

    printf("Entero con puntero =>\n\tDirección:%p\n\tValor:%d\n", pi, *pi);
    printf("Entero con variable =>\n\tDirección:%p\n\tValor:%d\n", &i, i);
    printf("Carácter con puntero =>\n\tDirección:%p\n\tValor:%c\n", pc, *pc);
    printf("Carácter con variable =>\n\tDirección:%p\n\tValor:%c\n", &c, c);
    
    return 0;
}
