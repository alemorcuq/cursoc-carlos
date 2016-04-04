# Juego de la vida
[![Linkedin](https://img.shields.io/badge/LinkedIn-Carlos-blue.svg)](https://es.linkedin.com/in/carlosrodriguezhernandez)
[![Twitter](https://img.shields.io/badge/Twitter-carrodher-blue.svg)](https://twitter.com/carrodher)
[![License](https://img.shields.io/badge/License-BY/NC-yellow.svg)](https://github.com/carrodher/cursoc-carlos/blob/master/LICENSE.md)

#### Trabajo del curso: "C moderno" II edición que consiste en la simulación del _Juego de la vida_.

El **_Juego de la vida_** es un autómata celular diseñado por el matemático británico John Horton Conway en 1970. Es en realidad un juego de **cero jugadores**, lo que quiere decir que su evolución está determinada por el **estado inicial** y **no necesita ninguna entrada** de datos posterior. El "tablero de juego" es una malla formada por cuadrados ("células") que se extiende por el infinito en todas las direcciones. Cada célula tiene **8 células vecinas**, que son las que están próximas a ella, incluidas las diagonales. Las células tienen **dos estados**: están "vivas" o "muertas". El estado de la malla evoluciona a lo largo de unidades de tiempo discretas (se podría decir que por turnos). **El estado de todas las células se tiene en cuenta para calcular el estado de las mismas al turno siguiente**. Todas las células se actualizan simultáneamente.

Las **transiciones dependen del número de células vecinas vivas**:
- Una **célula muerta** con **exactamente 3 células vecinas vivas "nace"** (al turno siguiente estará viva).
- Una **célula viva** con **2 ó 3 células vecinas vivas sigue viva**, en **otro caso muere o permanece muerta** (por "soledad" o "superpoblación").
