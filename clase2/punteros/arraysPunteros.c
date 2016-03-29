#include <stdio.h>

int main() {

    // TODO: Acabar estos ejercicios
    int vector1[] = {1, 2, 3, 4, 5};
    double vector2[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    float vector3[5];

    int *pvector1;       // Puntero para el primer vector
    double *pvector2;    // Puntero para el segundo vector
    float *pvector3;     // Puntero para el tercer vector

    pvector1 = vector1;  // Puntero al inicio del vector 1
    pvector2 = vector2;  // Puntero al inicio del vector 2

    printf("Forma 1:\n");
    printf("\tVector 1:\n\t");
    for (int i = 0; i < 5; i++) {
        printf("\t%d", *pvector1++);
    }

    printf("\n\tVector 2:\n\t");
    for (int i = 0; i < 5; i++) {
        printf("\t%f", *pvector2++);
    }

    pvector1 = vector1;  // Nuevamente puntero al inicio del vector 1
    pvector2 = vector2;  // Nuevamente puntero al inicio del vector 2
    pvector3 = vector3;  // Puntero al inicio del vector 3

    printf("\n\nForma 3:\n");
    printf("\tVector 1 por vector 2:\n\t");
    for (int i = 0; i < 5; i++) {
        pvector3[i] = pvector1[i]*pvector2[i];
        printf("\t%f", pvector3[i]);
    }

    char cadena[] = "Hola mundo";

    return 0;
}
