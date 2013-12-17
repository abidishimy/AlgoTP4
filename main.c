#include <stdio.h>
#include <stdlib.h>
#include "noeud.h"
#include "arbre.h"
#include "outilsArbre.h"

int main()
{
	Arbre* arbre = NULL;
	int nbMots = 0;
	if((nbMots = lectureFichierArbre(&arbre, "texte1.txt")))
	{
		printf("\nIl y a %d mot(s) dans ce fichier", nbMots);
		printf("\nIl y a %d mot(s) différents dans ce fichier \n", compterArbre(arbre->racine));
	}

	return 1;
}