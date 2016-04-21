### [v1.0](https://github.com/carrodher/cursoc-carlos/releases/tag/v1.0 "1.0"): Versión inicial del juego de la vida
- Utiliza una programación modular y crea un makefile para automatizar la compilación
- Representa el mundo mediante un array bidimensional de tamaño fijo
- Ejecuta un numero fijo de iteraciones
- Muestra el estado inicial y final del mundo mediante printf
- Comprueba los resultados obtenidos con uno de los simuladores enlazados

En esta primera versión se almacena el mundo (tablero + algunas variables) en una estructura. Se puede modificar el tamaño del mapa y el número de iteracciones.
Se incializan dos estructuras para almacenar el mundo, una en la que se guarda el estado actual y otra sobre la que se va iterando para guardar el estado futuro.

Para realizar la lógica del juego se usa la función _transicion()_ la cual recorre todas las células del tablero para comprobar su estado, a su vez, llama a la función _checkVecinas()_ que comprueba el número de células vecinas vivas que hay con respecto a la célula que se le pasa, teniendo en cuenta la frontera del mundo (no comprueba casillas fuera de la matriz) y no se cuenta a ella misma como vecina viva.

Todo el proceso guarda logs en un fichero, donde se puede observar el resultado de todas las comprobaciones realizadas para determinar el estado de las células vecinas.

Finalmente se muestra por pantalla la matriz que representa el mundo en cada iteracción.

### [v2.0](https://github.com/carrodher/cursoc-carlos/releases/tag/v2.0 "2.0"): Utilizar reserva dinámica de memoria y objetos

- El tamaño del mundo debe poder elegirse en tiempo de ejecución
- Descompón tu programa en los módulos y objeto(s) que creas convenientes.

Se han creado el "objeto" para almacenar el mundo, con su constructor y destructor para tratar la reserva de memoria, en la versión 1.0 se realizaba de manera estática dentro de la estructura, en cambio ahora se realiza de manera dinámica con calloc (así por defecto están todas muertas), se reservan dos bloques diferentes, uno para el estado actual y otro para el futuro

Para hacer el cambio del estado N al N+1 se copia el bloque de memoria futuro del estado N como el actual del N+1.

### [v3.0](https://github.com/carrodher/cursoc-carlos/releases/tag/v3.0 "3.0"): Argumentos de main y listas encadenadas

- Haz que el tamaño de tu mundo se pueda pasar como argumentos al lanzar tu programa. Utiliza getoptlong
- Utiliza las listas encadenadas del núcleo de linux para optimizar el recorrer las células vivas. Por cada una de las células vivas debes inspeccionar ésta y sus vecinas.
