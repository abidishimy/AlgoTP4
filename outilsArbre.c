#include "outilsArbre.h"
#include <stdlib.h>
#include <stdio.h>

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