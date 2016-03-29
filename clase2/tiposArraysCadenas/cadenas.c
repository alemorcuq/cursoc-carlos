#include <stdio.h>

int main() {
    char cadena[] = "holamundo";
    char cadena2[] = "hola mundo";

    printf("Convierte \"%s\" a mayúsculas:\n", cadena);
    for (unsigned int i = 0; i < sizeof(cadena)-1; i++) {
        printf("%c",(cadena[i]-32));
    }

    printf("\n\nSolo la primera letra de cada palabra en \"%s\":\n", cadena2);
    for (unsigned int i = 0; i < sizeof(cadena2)-1; i++) {
        // Convierte la primera letra
        if (i == 0) {
            printf("%c",(cadena2[i]-32));
        }
        // Convierte la posterior a un espacio
        else if (cadena2[i-1] == ' ') {
            printf("%c",(cadena2[i]-32));
        }
        // El resto normales
        else {
            printf("%c",(cadena2[i]));
        }
    }
}
