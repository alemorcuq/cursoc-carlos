#include <stdio.h>

struct person {
    char name[256];
    char surname[256];
    unsigned char age;
    unsigned int phone;
};

struct car {
    char marca[256];
    char modelo[256];
    int cc;
    int CV;
    int puertas;
    char color[256];
    struct person owner;
};

void print_car(struct car *c);

int main() {
    struct person persona1 = {"Carlos","Rodríguez", 23, 968789987};
    struct car coche1 = {"Renault","Megane", 1500, 105, 5, "blanco", persona1};
    struct car *pcar1 = &coche1;

    print_car(pcar1);

    return 0;
}

void print_car(struct car *c){
    printf("%s %s %d %d %d %s\n",c->marca, c->modelo, c->cc, c->CV, c->puertas, c->color);
    printf("%s %s %d %d\n", c->owner.name, c->owner.surname, c->owner.age, c->owner.phone);
}
