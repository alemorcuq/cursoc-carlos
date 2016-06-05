 Curso *Programación en C moderno* (II edición)
[![Build Status](https://travis-ci.org/carrodher/cursoc-carlos.svg?branch=master)](https://travis-ci.org/carrodher/cursoc-carlos)
[![Linkedin](https://img.shields.io/badge/LinkedIn-Carlos-blue.svg)](https://es.linkedin.com/in/carlosrodriguezhernandez)
[![Twitter](https://img.shields.io/badge/Twitter-carrodher-blue.svg)](https://twitter.com/carrodher)
[![License](https://img.shields.io/badge/License-GNU-yellow.svg)](https://github.com/carrodher/cursoc-carlos/blob/master/LICENSE.md)

## Juego de la vida

Como proyecto del curso *Programación en C moderno* (II edición) se realizará una implementación de este juego.

El **juego de la vida** es un autómata celular diseñado por el matemático británico John Horton Conway en 1970. El juego de la vida es en realidad un juego de **cero jugadores**, lo que quiere decir que su evolución está determinada por el **estado inicial** y **no necesita ninguna entrada** de datos posterior. El "tablero de juego" es una malla formada por cuadrados ("células") que se extiende por el infinito en todas las direcciones. Cada célula tiene **8 células vecinas**, que son las que están próximas a ella, incluidas las diagonales.

Las células tienen **dos estados**: están **"vivas" o "muertas"**. El estado de la malla evoluciona a lo largo de unidades de tiempo discretas (se podría decir que por turnos). El estado de todas las células se tiene en cuenta para calcular el estado de las mismas al turno siguiente. Todas las células se **actualizan simultáneamente**.

Las **transiciones** dependen del número de células vecinas vivas:
- Una **célula muerta con exactamente 3 células vecinas vivas "nace"** (al turno siguiente estará viva).
- Una **célula viva con 2 ó 3 células vecinas vivas sigue viva, en otro caso muere o permanece muerta** (por "soledad" o "superpoblación").

## Ejecución

```bash
╰─$ make all

╰─$ ./main.out -h
./main.out [opciones]
	 Opción 1: ./main.out -t tam -s sim [-c est ó -r]
		 -t tamaño: Tamaño del tablero
		 -s simulaciones: Número de simulaciones
		 -c [gli | bli | toa | row]: Estado incial conocido
		 -r: Inicializa el mundo con un estado aleatorio
	 Opción 2: ./main.out -f file
		 -f fichero_config: Fichero de configuración
	 Opción 3: ./main.out -e file
		 -e fichero_estado: Fichero de estado anterior
	 -h: Muestra esta ayuda
```
![alt tag](https://cloud.githubusercontent.com/assets/13216600/14388532/dac91774-fdae-11e5-91c8-4dafa88a84aa.png)
