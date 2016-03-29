#include <stdio.h>

int main() {
    char cadena[] = "holamundo";
    char cadena2[] = "hola mundo";

    /* Pasa cadena a mayúsculas restando 32 que es la diferencia ASCI
    entre minúsculas y mayúsculas */
    printf("Convierte \"%s\" a mayúsculas:\n", cadena);
    for (unsigned int i = 0; i < sizeof(cadena)-1; i++) {
        printf("%c",(cadena[i]-32));
    }

    /* Detecta la 1º palabra y los espacios, para poner la primera letra
    de la siguiente palabra (tras espacios) en mayúsculas */
    printf("\n\nSolo la primera letra de cada palabra en \"%s\":\n", cadena2);
    for (unsigned int i = 0; i < sizeof(cadena2)-1; i++) {
        // Convierte la primera letra en mayúscula
        if (i == 0) {
            printf("%c",(cadena2[i]-32));
        }
        // Convierte la letra siguiente a un espacio en mayúscula
        else if (cadena2[i-1] == ' ') {
            printf("%c",(cadena2[i]-32));
        }
        // El resto normales
        else {
            printf("%c",(cadena2[i]));
        }
    }
}
