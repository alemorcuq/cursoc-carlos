all: main

main: main.o gol.o
	gcc -std=c99 main.o gol.o -o main.out

main.o: main.c
	gcc -std=c99 -c main.c

gol.o: gol.h gol.c
	gcc -std=c99 -c gol.c
