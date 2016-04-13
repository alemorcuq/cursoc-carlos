# Curso *Programación en C moderno* (II edición)
[![Build Status](https://travis-ci.org/carrodher/cursoc-carlos.svg?branch=master)](https://travis-ci.org/carrodher/cursoc-carlos)
[![Linkedin](https://img.shields.io/badge/LinkedIn-Carlos-blue.svg)](https://es.linkedin.com/in/carlosrodriguezhernandez)
[![Twitter](https://img.shields.io/badge/Twitter-carrodher-blue.svg)](https://twitter.com/carrodher)
[![License](https://img.shields.io/badge/License-BY/NC-yellow.svg)](https://github.com/carrodher/cursoc-carlos/blob/master/LICENSE.md)

## Juego de la vida

Como proyecto del curso *Programación en C moderno* (II edición) se realizará una implementación de este juego.

El **juego de la vida** es un autómata celular diseñado por el matemático británico John Horton Conway en 1970. El juego de la vida es en realidad un juego de **cero jugadores**, lo que quiere decir que su evolución está determinada por el **estado inicial** y **no necesita ninguna entrada** de datos posterior. El "tablero de juego" es una malla formada por cuadrados ("células") que se extiende por el infinito en todas las direcciones. Cada célula tiene **8 células vecinas**, que son las que están próximas a ella, incluidas las diagonales.

Las células tienen **dos estados**: están **"vivas" o "muertas"**. El estado de la malla evoluciona a lo largo de unidades de tiempo discretas (se podría decir que por turnos). El estado de todas las células se tiene en cuenta para calcular el estado de las mismas al turno siguiente. Todas las células se **actualizan simultáneamente**.

Las **transiciones** dependen del número de células vecinas vivas:
- Una **célula muerta con exactamente 3 células vecinas vivas "nace"** (al turno siguiente estará viva).
- Una **célula viva con 2 ó 3 células vecinas vivas sigue viva, en otro caso muere o permanece muerta** (por "soledad" o "superpoblación").

### v1.0: Versión inicial del juego de la vida
```
- Utiliza una programación modular y crea un makefile para automatizar la compilación
- Representa el mundo mediante un array bidimensional de tamaño fijo
- Ejecuta un numero fijo de iteraciones
- Muestra el estado inicial y final del mundo mediante printf
- Comprueba los resultados obtenidos con uno de los simuladores enlazados
```

En esta primera versión se almacena el mundo (tablero + algunas variables) en una estructura. Se puede modificar el tamaño del mapa y el número de iteracciones.
Se incializan dos estructuras para almacenar el mundo, una en la que se guarda el estado actual y otra sobre la que se va iterando para guardar el estado futuro.

Para realizar la lógica del juego se usa la función _transicion()_ la cual recorre todas las células del tablero para comprobar su estado, a su vez, llama a la función _checkVecinas()_ que comprueba el número de células vecinas vivas que hay con respecto a la célula que se le pasa, teniendo en cuenta la frontera del mundo (no comprueba casillas fuera de la matriz) y no se cuenta a ella misma como vecina viva.

Todo el proceso guarda logs en un fichero, donde se puede observar el resultado de todas las comprobaciones realizadas para determinar el estado de las células vecinas.

Finalmente se muestra por pantalla la matriz que representa el mundo en cada iteracción.

### v2.0: Utilizar reserva dinámica de memoria y objetos
```
- El tamaño del mundo debe poder elegirse en tiempo de ejecución
- Descompón tu programa en los módulos y objeto(s) que creas convenientes.
```

A la versión anterior se ha modificado la reserva de memoria, antes se realizaba de manera estática dentro de la estructura, en cambio ahora se realiza de manera dinámica con calloc (así por defecto están todas muertas), se reservan dos bloques diferentes, uno para el estado actual y otro para el futuro.

Para hacer el cambio del estado N al N+1 se copia el bloque de memoria futuro del estado N como el actual del N+1.

```
$ make all

$ ./main.out
```
![alt tag](https://cloud.githubusercontent.com/assets/13216600/14388532/dac91774-fdae-11e5-91c8-4dafa88a84aa.png)
