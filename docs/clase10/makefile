.PHONY: clean debug

all: main

# Establece la variable DEBUG en este objetivo y todos sus subobjetivos
debug: DEBUG = -ggdb
debug: main

main: srv.o cln.o

srv.o:
	gcc $(DEBUG) server.c -o srv.out

cln.o:
	gcc $(DEBUG) client.c -o cln.out

clean:
	rm -f *.o

valgrind: debug
	valgrind --leak-check=full ./srv.out
	valgrind --leak-check=full ./cln.out

gdb: debug
	gdb ./main.out
