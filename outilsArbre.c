#include "outilsArbre.h"
#include <stdlib.h>
#include <stdio.h>
#include "pile.h"
#include "outilsPile.h"

void 	transplanter(Arbre* _arbre, Noeud* _u, Noeud* _v)
{
	if(_u->pere == NULL)
	{
		_arbre->racine = _v;
	}
	else if(_u == _u->pere->gauche)
	{
		_u->pere->gauche = _v;
	}
	else
	{
		_u->pere->droit = _v;
	}

	if(_v != NULL)
	{
		_v->pere = _u->pere;
	}
}

Noeud* 	arbreMinimum(Noeud* _noeud)
{
	while(_noeud->gauche != NULL)
	{
		_noeud = _noeud->gauche;
	}

	return _noeud;
}

Noeud* 	arbreMaximum(Noeud* _noeud)
{
	while(_noeud->droit != NULL)
	{
		_noeud = _noeud->droit;
	}

	return _noeud;
}

Noeud* 	arbreSuccesseur(Noeud* _noeud)
{
	Noeud* y = NULL;

	if(_noeud->droit != NULL)
	{
		return arbreMinimum(_noeud->droit);
	}

	y = _noeud->pere;
	while(y != NULL && _noeud == y->droit)
	{
		_noeud = y;
		y = y->pere;
	}
	return y;
}

void	afficherArbreRecursif(Noeud* _noeud)
{
	if(_noeud != NULL)
	{
		afficherArbreRecursif(_noeud->gauche);
		printf("%s\n", _noeud->mot);
		afficherArbreRecursif(_noeud->droit);
	}
}

void	afficherArbreIteratif(Noeud* _noeud)
{
	Pile* pile = NULL;
	pile = creerPile(50);
	if(_noeud != NULL)
	{
		empiler(pile, _noeud);
		while(!pileVide(pile))
		{
			_noeud = depiler(pile);
			printf("%s\n", _noeud->mot);
			if(_noeud->droit != NULL)
			{
				empiler(pile, _noeud->droit);
			}

			if(_noeud->gauche != NULL)
			{
				empiler(pile, _noeud->gauche);
			}
		}
	}
}

int		lectureFichierArbre(Arbre** _arbre, const char* _fileName)
{
	int i = 1, totalCount = 0;
	FILE * file = NULL;
	char * word = (char *)malloc(sizeof(char) * 26);
	Noeud* noeud = NULL;
	(*_arbre) = creerArbre(15);
	if( (file = fopen(_fileName, "r")) == NULL)
		return 0;

	while(i)
	{
		i = (fscanf(file, "%s", word) != EOF);
		if (i != 0)
		{
			totalCount++;	
		}
		noeud = creerNoeud(word, 26);
		inserer((*_arbre), noeud);
	}
	fclose(file);
	return totalCount;
}

int		compterArbre(Noeud* _noeud)
{
	int nbMots = 0;
	if(_noeud != NULL)
	{
		nbMots += compterArbre(_noeud->gauche);
		nbMots++;
		nbMots += compterArbre(_noeud->droit);
	}
	return nbMots;
}

