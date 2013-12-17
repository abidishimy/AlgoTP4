#include "pile.h"
#include <stdlib.h>
#include <stdio.h>

Pile * creerPile(int _capacite)
{
	Pile * pile;

	pile = (Pile *) malloc(sizeof(Pile));
	pile->capacite = _capacite;
	pile->sommet = 0;
	pile->tableau = (Noeud**) malloc(sizeof(Noeud*) * pile->capacite);

	return pile;
}

void detruirePile(Pile ** _pile)
{
	int i;
	for(i = 0; i < (*_pile)->sommet; i++)
	{
		free(&((*_pile)->tableau[i]));
	}
	free((*_pile)->tableau);
	free(*_pile);
}

int capacitePile(Pile * _pile)
{
	return _pile->capacite;
}

int pileVide(Pile * _pile)
{
	return (_pile->sommet == 0);
}

int pilePleine(Pile * _pile)
{
	return (_pile->sommet >= _pile->capacite);
}

void empiler(Pile * _pile, Noeud* _noeud)
{
	if(!pilePleine(_pile))
	{
		_pile->tableau[_pile->sommet] = _noeud; 
		_pile->sommet++;
	}
	else
	{
		printf("La pile est pleine ! Impossible d'ajouter un élément \n");
	}

}

Noeud* depiler(Pile * _pile)
{
	if(!pileVide(_pile))
	{
		_pile->sommet--;
		return _pile->tableau[_pile->sommet];
	}
	printf("La pile est vide ! Impossible de dépiler. \n");
	return NULL;
}

Noeud* sommet(Pile * _pile)
{
	return _pile->tableau[_pile->sommet];
}