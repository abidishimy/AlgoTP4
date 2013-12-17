#include <stdlib.h>
#include <string.h>
#include "noeud.h"

Noeud*	creerNoeud(char* _mot, int _tailleMot)
{
	Noeud* noeud = NULL;
	noeud = (Noeud*) malloc(sizeof(Noeud));

	noeud->pere = NULL;
	noeud->droit = NULL;
	noeud->gauche = NULL;
	noeud->mot = (char*)malloc(sizeof(char) * _tailleMot);
	strcpy(noeud->mot, _mot);

	return noeud;
}

void 	detruireNoeud(Noeud ** _noeud)
{
	free((*_noeud)->mot);
	free((*_noeud));
}