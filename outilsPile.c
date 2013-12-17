#include <stdio.h>
#include <stdlib.h>

#include "pile.h"
#include "outilsPile.h"
#include "Noeud.h"

void afficherPile(Pile * _pile) /*Attention refaire la fonction pour qu'elle respecte la pile (empiler / depiler)*/
{
	int i;
	Noeud* temp;
	Pile * pileTemp;

	printf("\n La pile a les caractéristiques suivantes : \n");
	printf("\t Le dernier élément est à l'index : %d, \n", _pile->sommet);
	printf("\t La pile a une capacité de %d éléments. \n", _pile->capacite);
	printf("\t Les éléments de la pile sont :\n");

	pileTemp = creerPile(_pile->capacite);

	i = 0;
	while(!pileVide(_pile))
	{
		temp = depiler(_pile);
		printf("\t\t Elément n°%d : %s\n", i, temp->mot);
		empiler(pileTemp, temp);
		i++;
	}

	while(!pileVide(pileTemp))
	{
		empiler(_pile, depiler(pileTemp));
	}
}