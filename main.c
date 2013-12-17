#include <stdio.h>
#include <stdlib.h>
#include "noeud.h"
#include "arbre.h"
#include "outilsArbre.h"

int main()
{
	Noeud* noeud1 = NULL;
	Noeud* noeud2 = NULL;
	Noeud* noeud3 = NULL;
	Noeud* noeud4 = NULL;
	Arbre* arbre = NULL;

	noeud1 = creerNoeud("bonjour",10);
	noeud2 = creerNoeud("comment",10);
	noeud3 = creerNoeud("ca",10);
	noeud4 = creerNoeud("va",10);

	arbre = creerArbre();
	inserer(arbre, noeud1);
	inserer(arbre, noeud2);
	inserer(arbre, noeud3);
	inserer(arbre, noeud4);

	afficherArbreRecursif(arbre->racine);
	detruireArbre(&arbre);
	return 1;
}