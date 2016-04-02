#include <stdio.h>

// Estructura person con 4 campos
struct person {
    char name[256];         // Nombre
    char surname[256];      // Apellido
    unsigned char age;      // Edad
    unsigned int phone;     // Teléfono
};

// Estructura car con 7 campos
struct car {
    char marca[256];        // Marca
    char modelo[256];       // modelo
    int cc;                 // Centímetros Cúbicos
    int CV;                 // CV de potencia
    int puertas;            // # puertas
    char color[256];        // Color
    struct person owner;    // Propietario
};

// Imprime todos los campos de la estructura car (incluido propietario)
void print_car(struct car *c);

int main() {
    // Declara e inicializa la estructura person
    struct person persona1 = {"Carlos","Rodríguez", 23, 968789987};
    // Declara e inicializa la estructura car
    struct car coche1 = {"Renault","Megane", 1500, 105, 5, "blanco", persona1};
    // Puntero a la estructura car
    struct car *pcar1 = &coche1;

    // Se imprimen todos los campos de car (incluyendo person)
    print_car(pcar1);

    return 0;
}

// Imprime todos los campos de la estructura car (incluído propietario)
void print_car(struct car *c){
    // Imprime lo relativo al coche
    printf("%s %s %d %d %d %s\n",c->marca, c->modelo, c->cc, c->CV, c->puertas, c->color);
    // Imprime lo relatio al propietario
    printf("%s %s %d %d\n", c->owner.name, c->owner.surname, c->owner.age, c->owner.phone);
}
