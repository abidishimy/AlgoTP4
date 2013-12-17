CC = gcc -Wall -O3 -ansi -pedantic

all: main clean

main: main.o noeud.o arbre.o outilsArbre.o
	$(CC) -o main main.o noeud.o arbre.o outilsArbre.o -lm

main.o: main.c
	$(CC) -o main.o -c main.c

noeud.o: noeud.c noeud.h
	$(CC) -o noeud.o -c noeud.c

arbre.o: arbre.c arbre.h
	$(CC) -o arbre.o -c arbre.c

outilsArbre.o: outilsArbre.c outilsArbre.h
	$(CC) -o outilsArbre.o -c outilsArbre.c

clean:
	rm -rf *.o
			
