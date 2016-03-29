#include <stdio.h>

#define TAM 5

int main() {
    /* Declaramos 3 arrays y 3 punteros */
    int vector1[] = {1, 2, 3, 4, 5};
    double vector2[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    float vector3[TAM];

    /* En arrays es igual:
        int *p = array;
        int *p = &array[0]
    */
    int *pvector1 = vector1;       // Puntero a entero para el primer vector
    double *pvector2 = vector2;    // Puntero a double para el segundo vector
    float *pvector3;               // Puntero a float para el tercer vector

    /* Vamos a recorrerlos y acceder de 3 modos diferentes */
    printf("Forma 1:\n");
    printf("\tVector 1:\n\t");
    for (int i = 0; i < TAM; i++) {
        printf("\t%d", *pvector1++);
    }

    printf("\n\tVector 2:\n\t");
    for (int i = 0; i < TAM; i++) {
        printf("\t%f", *pvector2++);
    }

    pvector1 = vector1;  // Nuevamente puntero al inicio del vector 1
    pvector2 = vector2;  // Nuevamente puntero al inicio del vector 2
    pvector3 = vector3;  // Puntero al inicio del vector 3

    printf("\n\nForma 3:\n");
    printf("\tVector 1 por vector 2:\n\t");
    for (int i = 0; i < TAM; i++) {
        pvector3[i] = pvector1[i]*pvector2[i];
        printf("\t%f", pvector3[i]);
    }

    char cadena[11] = "Hola mundo";
    char *pcadena1, *pcadena2;      // Dos punteros a char para cadena
    pcadena1=cadena;                // Puntero al inicio de la cadena
    printf("\n\nForma 2:\n");
    printf("\tCadena \"%s\" invertida:\n\t\t",cadena);
    for (pcadena2 = &cadena[10]; pcadena1<=&cadena[10]; pcadena1++, pcadena2--){
        printf("%c", *pcadena2);
    }

    return 0;
}
