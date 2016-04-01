#include <stdio.h>

struct person {
    char name[256];
    char surname[256];
    unsigned char age;
    unsigned int phone;
};

enum person_attr {
    NAME,
    SURNAME,
    AGE,
    PHONE
};

void print_person(struct person *p);

void print_attr(struct person *p, enum person_attr attr);

int main() {
    struct person persona1 = {"Carlos","Rodríguez", 23, 968789987};
    struct person *ppersona1 = &persona1;
    enum person_attr atributo = AGE;

    print_person(ppersona1);
    print_attr(ppersona1, atributo);

    return 0;
}

void print_person(struct person *p){
    printf("%s %s %d %d\n",p->name, p->surname, p->age, p->phone);
}

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
