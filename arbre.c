#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "arbre.h"
#include "outilsArbre.h"

Arbre*	creerArbre()
{
	Arbre* arbre = NULL;

	arbre = (Arbre*) malloc(sizeof(Arbre));
	arbre->racine = NULL;

	return arbre;
}

void 	detruireArbre(Arbre ** _arbre)
{
	free((*_arbre)->racine);
	free((*_arbre));
}

void	inserer(Arbre* _arbre, Noeud* _noeud)
{
	Noeud* y = NULL;
	Noeud* x = NULL;

	x = rechercher(_arbre->racine, _noeud->mot);
	if(x != NULL)
	{
		return;
	}

	x = _arbre->racine;
	while( x != NULL)
	{
		y = x;
		fflush(stdout);
		if(strcmp(_noeud->mot, x->mot) < 0)
		{
			x = x->gauche;
		}
		else
		{
			x = x->droit;
		}
	}

	_noeud->pere = y;
	if(y == NULL)
	{
		_arbre->racine = _noeud;
	}
	else if(strcmp(_noeud->mot, y->mot) < 0)
	{
		y->gauche = _noeud;
	}
	else
	{
		y->droit = _noeud;
	}
}

Noeud*	rechercher(Noeud* _noeud, char* _mot)
{
	while( _noeud != NULL && strcmp(_mot, _noeud->mot))
	{
		if(strcmp(_mot, _noeud->mot) < 0)
		{
			_noeud = _noeud->gauche;
		}
		else
		{
			_noeud = _noeud->droit;
		}
	}
	
	return _noeud;
}

void	supprimer(Arbre* _arbre, Noeud* _noeud)
{
	Noeud* y = NULL;

	if(_noeud->gauche == NULL)
	{
		transplanter(_arbre, _noeud, _noeud->droit);
	}
	else if( _noeud->droit == NULL)
	{
		transplanter(_arbre, _noeud, _noeud->gauche);
	}
	else
	{
		y = arbreMinimum(_noeud->droit);
		if(y->pere != _noeud)
		{
			transplanter(_arbre, y, y->droit);
			y->droit = _noeud->droit;
			y->droit->pere = y;
		}

		transplanter(_arbre, _noeud, y);
		y->gauche = _noeud->gauche;
		y->gauche->pere = y;
	}
}