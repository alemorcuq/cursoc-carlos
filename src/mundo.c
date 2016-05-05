#include "mundo.h"

#define ATTR_SET(flags, attr)   (flags) |= (1 << (attr))
#define ATTR_IS_SET(flags, attr)   ((flags) & (1 << (attr)))

// Estructura del mundo
struct mundo {
    int *tablero;           // Tablero/Mapa del mundo
    int numCelVivas;        // Número de células vivas
    int numCelMuertas;      // Número de células muertas
    int tamanio;            // Tamaño del mundo

    int flags;              // Comprueba atributos
};

// Enumerado para tratar el flag
enum mundo_attr {
    TABLERO,
    CELMUERTAS,
    CELVIVAS,
    TAMAN
};

/* Constructor/Destructor */
// Constructor de mundo
int mundo_build2(struct mundo * a, struct mundo *f, int t){
    // Establece el tamaño de ambos mundos
    mundo_set_tam(a,t);
    mundo_set_tam(f,t);

    // Reserva memoria para el tablero y comprueba la reserva
    if (mundo_alloc_tablero(a) == -1 || mundo_alloc_tablero(f)  == -1) {
        perror("Error ");
        return -1;
    }

    return 0;
}

// Reserva el mundo
struct mundo *mundo_alloc(){
    struct mundo *m;

    // Reserva memoria para el objeto mundo e inicializa su flag
    m = (struct mundo *) malloc(sizeof(struct mundo));
    m->flags = 0;

    return m;
}

// Reserva el mundo cuando se le pasa en un fichero
struct mundo *mundo_falloc(char *filename){
    FILE *fpest;
    printf("Leyendo fichero de estado anterior %s...\n", filename);
    // Abre el fichero de estado y comprueba la apertura
    if (!(fpest = fopen(filename, "r"))) {
        perror("Error al abrir fichero ");
        printf("Configuración predeterminada\n");
    }

    struct mundo *m = mundo_alloc();

    // Lee el tamaño
    fread(&m->tamanio, sizeof(int), 1, fpest);
    if (ferror(fpest))
        perror("Error al leer");

    // Reserva el tablero
    mundo_alloc_tablero(m);

    // Lee el tablero
    fread(m->tablero, sizeof(int), m->tamanio, fpest);
    if (ferror(fpest))
        perror("Error al leer");

    fclose(fpest);
    return m;
}

// Libera el mundo
void mundo_free(struct mundo *m) {
    if (ATTR_IS_SET(m->flags, TABLERO))
        free(m->tablero);   // Si se ha reservado memoria para el tablero, la libera

    free(m);                // Libera la reserva del objeto
}

// Reserva el tablero
int mundo_alloc_tablero(struct mundo *m){
    m->tablero = (int*) calloc(m->tamanio*m->tamanio,sizeof(int));

    if(m->tablero == NULL)
        return -1;

    ATTR_SET(m->flags, TABLERO);

    return 0;
}

// Libera el tablero
void mundo_free_tablero(struct mundo *m) {
    if (ATTR_IS_SET(m->flags, TABLERO))
        free(m->tablero);   // Si se ha reservado memoria para el tablero, la libera
}

/* Métodos */
    /* Setters */
// Establece el número de células vivas
int mundo_set_vivas(struct mundo *m, int num) {
    if (num < 0)
        return -1;

    // Guarda el valor y lo registra en el flag
    m->numCelVivas = num;
    ATTR_SET(m->flags, CELVIVAS);

    return 0;
}

// Establece el número de células muertas
int mundo_set_muertas(struct mundo *m, int num) {
    if (num < 0)
        return -1;

    // Guarda el valor y lo registra en el flag
    m->numCelMuertas = num;
    ATTR_SET(m->flags, CELMUERTAS);

    return 0;
}

// Establece el tamaño del mundo
int mundo_set_tam(struct mundo *m, int num) {
    if (num < 0)
        return -1;

    // Guarda el valor y lo registra en el flag
    m->tamanio = num;
    ATTR_SET(m->flags, TAMAN);

    return 0;
}

    /* Getters */
// Obtiene el tablero
int *mundo_get_tablero(struct mundo *m) {
    if (ATTR_IS_SET(m->flags, TABLERO))
        return m->tablero;
    else
        return NULL;
}

// Devuelve el número de células vivas
int mundo_get_vivas(struct mundo *m) {
    if (ATTR_IS_SET(m->flags, CELVIVAS))
        return m->numCelVivas;
    else
        return -1;
}

// Devuelve el número de células muertas
int mundo_get_muertas(struct mundo *m) {
    if (ATTR_IS_SET(m->flags, CELMUERTAS))
        return m->numCelMuertas;
    else
        return -1;
}

// Devuelve el tamaño del mundo
int mundo_get_tam(struct mundo *m) {
    if (ATTR_IS_SET(m->flags, TAMAN))
        return m->tamanio;
    else
        return -1;
}

    /* Métodos extra */
/* Actualiza el mundo para la siguiente iteracción. Copia la memoria del
mundo futuro anterior, que será el actual en la siguiente */
struct mundo *mundo_clone(struct mundo *actual, struct mundo *futuro) {
    memcpy(actual, futuro, sizeof(struct mundo));

    return actual;
}

// Guarda el estado del mundo entre ejecuciones
void mundo_save(struct mundo *m) {
    // Abre el fichero de estado y comprueba la apertura
    FILE *fp;
    if (!(fp = fopen("state.txt", "w")))
        perror("Error ");

    // Guarda el tamaño
    int tam = mundo_get_tam(m);
    fwrite(&tam, sizeof(tam), 1, fp);
    if (ferror(fp))
        perror("Error al escribir");

    // Guarda el tablero
    fwrite(mundo_get_tablero(m), mundo_get_tam(m), sizeof(int), fp);
    if (ferror(fp))
        perror("Error al escribir");

    fclose(fp);
}
