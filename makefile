.PHONY: clean

all: main

main: main.o gol.o
	gcc -std=c99 main.o gol.o -o main.out

main.o: src/main.c src/gol.h
	gcc -std=c99 -c src/main.c

gol.o: src/gol.h src/gol.c
	gcc -std=c99 -c src/gol.c

clean:
	rm -f *.o
