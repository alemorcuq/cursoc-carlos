all: main

main: main.o cmplx.o
	gcc -std=c99 main.o cmplx.o -lm -o main.out

main.o: main.c
	gcc -std=c99 -c main.c

cmplx.o: cmplx.h cmplx.c
	gcc -std=c99 -c cmplx.c
