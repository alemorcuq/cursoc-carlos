#include <stdio.h>

// Estructura person con 4 campos
struct person {
    char name[256];         // Nombre
    char surname[256];      // Apellido
    unsigned char age;      // Edad
    unsigned int phone;     // Teléfono
};

// Enumerado para elegir el atributo a imprimir
enum person_attr {
    NAME,
    SURNAME,
    AGE,
    PHONE
};

// Imprime todos los campos de la estructura persona
void print_person(struct person *p);

// Imprime solo el atributo especificado de la estructura persona
void print_attr(struct person *p, enum person_attr attr);

int main() {
    // Declara e inicializa la estructura
    struct person persona1 = {"Carlos","Rodríguez", 23, 968789987};
    // Puntero a la estructura
    struct person *ppersona1 = &persona1;
    // Atributo que queremos imprimir
    enum person_attr atributo = AGE;

    // Se imprimen todos los campos
    print_person(ppersona1);
    // Se imprime solo el atributo elegido antes
    print_attr(ppersona1, atributo);

    return 0;
}

// Imprime todos los campos de la estructura persona
void print_person(struct person *p){
    printf("%s %s %d %d\n",p->name, p->surname, p->age, p->phone);
}

// Imprime solo el atributo especificado de la estructura persona
void print_attr(struct person *p, enum person_attr attr){
    switch (attr) {
        case NAME:
            printf("%s\n",p->name);
            break;
        case SURNAME:
            printf("%s\n",p->surname);
            break;
        case AGE:
            printf("%d\n",p->age);
            break;
        case PHONE:
            printf("%d\n",p->phone);
            break;
    }
}
