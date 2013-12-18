#include <stdio.h>
#include <stdlib.h>
#include "noeud.h"
#include "arbre.h"
#include "outilsArbre.h"
#include "outilsPresentation.h"
#include "outilsSaisie.h"

int main()
{
	int choix;

	printf("/************************************************/ \n");
	printf("\\*\t\t\t TP4 \t\t\t*\\\n");
	printf("/************************************************/ \n");

	printf("Choisissez ce que vous souhaitez faire : \n");
	printf("\t1 - Comparer des fichiers\n");
	printf("\t2 - Implementer un arbre binaire de recherche\n");
	printf("\t0 - Quitter le programme\n");

	choix = choixInt(2);
	printf("choix : %d\n", choix);
	switch(choix)
	{
		case 0:
			printf("Au revoir !\n");
			return 1;
			break;
		case 1:
			comparaisonFichier(saisieNomFichier());
			break;
		case 2:
			saisieArbre();
			break;
	}
	return 1;
}