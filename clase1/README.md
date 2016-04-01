# Clase 1
[![Build Status](https://travis-ci.org/carrodher/cursoc-carlos.svg?branch=master)](https://travis-ci.org/carrodher/cursoc-carlos)
[![Linkedin](https://img.shields.io/badge/LinkedIn-Carlos-blue.svg)](https://es.linkedin.com/in/carlosrodriguezhernandez)
[![Twitter](https://img.shields.io/badge/Twitter-carrodher-blue.svg)](https://twitter.com/carrodher)
[![License](https://img.shields.io/badge/License-BY/NC-yellow.svg)](https://github.com/carrodher/cursoc-carlos/blob/master/LICENSE.md)

###### Fecha: Viernes 18/03
### Resumen
En este primer día de curso hemos visto algo de historia sobre los inicios de C, posteriormente hemos instalado las herramientas necesarias para seguir el curso.

Entre estas herramientas cabe destacar **vim** (o cualquier otro editor de texto) y **Git/GitHub**. Este _sistema de control de versiones_ se usará durante todo el curso para realizar los ejercicios y las prácticas. Después de crear nuestro repositorio hicimos un ejemplo sencillo de código en C, el típico _Hola mundo_.

Diapositivas [Tema 1](https://github.com/carrodher/cursoc-carlos/blob/master/Transparencias/T1.pdf)

Diapositivas [Tema 2](https://github.com/carrodher/cursoc-carlos/blob/master/Transparencias/T2.pdf)

### Anexo Clase 1
#### Travis CI
[Travis CI](https://travis-ci.com/) es una herramienta que se utiliza para testear de manera automática y continua nuestro código alojado en GitHub, para ello clona nuestro repositorio en un contenedor de [Docker](https://www.docker.com/).

De tal manera que, mediante un fichero YAML situado en la **raíz de nuestro repositorio**, podemos configurar una serie de test que la herramienta Travis CI pasa **automáticamente** cada vez que se realiza un **nuevo commit** en nuestro repositorio (CI viene de Continuous Integration).

El fichero _.travis.yml_ usado para esta primera clase es el siguiente:
```
language: c
compiler:
  - gcc
script:
  - cd ./clase1 && gcc helloworld.c -o helloworld.out
```

Como se puede observar, primero se indica el **lenguaje** y el **compilador**, y posteriormente en el apartado _script_ se indican las **instrucciones** que se ejecutan para testear el código. Travis determina que nuestro programa pasa los tests si todas las instrucciones que hay en _script_ acaban devolviendo **0 (success)**, en cambio, si alguna de ellas devuelve **1 (error)**, Travis determina que los tests no han pasado.

En este caso el test simplemente comprueba que la aplicación compila de manera correcta, para ello primer hace ```cd clase1``` para situarnos en ese directorio (recordar que el fichero travis.yml se sitúa en el raíz del repositorio) y posteriormente compila el programa con ```gcc helloworld.c -o helloworld.out```.

Como se puede ver al principio de este README, hay un _badge_ titulado _"Build"_ en el que se indica el estado de los tests. Si este _badge_ luce de la siguiente manera ![badge](https://img.shields.io/badge/build-passing-green.svg) indica que los tests han pasado satisfactoriamente. En caso de que los test de integración continua de Travis no fueran satisfactorios tendríamos el siguiente _badge_ ![badge](https://img.shields.io/badge/build-failed-red.svg). Recordad, que esto se realiza de manera automática cada vez que se realiza un nuevo commit en el repositorio.

Cabe destacar que los **tests** se realizan **por repositorio** y no por carpeta, de tal manera que en caso de que el repositorio esté compuesto por varios ejecutables diferentes, como puede ser el caso de este curso, en el que en cada práctica haya un ejercicio diferentes; el fichero _.travis.yml_ es el mismo para todos, por tanto bajo la sección _script_ habría que ir poniendo la secuencia de órdenes para cambiar ```cd ruta_directorio``` y compilar ```gcc ...``` los diferentes programas. De igual modo, el resultado del test y por tanto el _badge_ hace referencia al conjunto de todos los ejecutables.

En el siguiente enlace se puede **validar** que la **sintaxis** del fichero _.travis.yml_ es correcta: http://lint.travis-ci.org/

#### Gitignore
Al igual que ocurre con Travis, Gitignore funciona mediante un fichero de configuración que se sitúa en el raíz de un repositorio.

En este fichero _.gitignore_ se encuentran el nombre de archivos y directorios a los cuales **NO se les realiza el control de versiones** con Git, es decir, ficheros que aunque estén en el sistema de ficheros de nuestro equipo no se añaden al repositorio ni se realiza un seguimiento de ellos.

El fichero _.gitignore_ usado para este repositorio es:
```
# Gitignore típico para C
# Object files
*.o
*.ko
*.obj
*.elf

# Precompiled Headers
*.gch
*.pch

# Libraries
*.lib
*.a
*.la
*.lo

# Shared objects (inc. Windows DLLs)
*.dll
*.so
*.so.*
*.dylib

# Executables
*.exe
*.out
*.app
*.i*86
*.x86_64
*.hex
```
Como se puede observar se realiza un filtrado por extensiones típicas que se desean ignorar, usando patrones tipo _expresiones regulares_. De esta manera se ignoran todos aquellos ficheros que son fruto de compilaciones, ejecutables, librerías, etc; los cuales son necesarios para la ejecución pero no aporta ninguna ventaja el hecho de compartirlos y realizar su seguimiento.

#### Comandos básicos
![alt tag](https://github.com/carrodher/cursoc-carlos/blob/master/clase1/comandosGit.png "Comandos Git")
