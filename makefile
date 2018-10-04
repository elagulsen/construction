all: construction.o
	gcc construction.o
	
construction.o: construction.c
	gcc -c construction.c
