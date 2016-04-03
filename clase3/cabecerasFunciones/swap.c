#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);

int main() {
    int a = 4;
    int b = 8;

    printf("Antes de swap(): a=%d y b=%d\n", a, b);
    swap(&a,&b);
    printf("Después de swap(): a=%d y b=%d\n", a, b);

    return 0;
}

void swap(int *a, int *b){
    int swap = *a;  // Swap = a
    *a = *b;        // a = b
    *b = swap;      // b = swap = a
}
