#include "outilsPresentation.h"
#include "arbre.h"
#include "noeud.h"
#include "outilsArbre.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "outilsSaisie.h"

void comparaisonFichier(const char* _nomFichier)
{
	Arbre* arbre = NULL;
	int nbMots = 0;
	double tempsArbre;
	time_t debutArbre, finArbre;

	printf("\nLe fichier à comparer est : %s \n", _nomFichier);

	printf("\nDébut de la comparaison avec un arbre binaire de recherche\n");


	debutArbre = time(NULL);
	if((nbMots = lectureFichierArbre(&arbre, _nomFichier)))
	{
		printf("\nIl y a %d mot(s) dans ce fichier", nbMots);
		printf("\nIl y a %d mot(s) différents dans ce fichier \n", compterArbre(arbre->racine));
	}
	finArbre = time(NULL);

	tempsArbre = difftime(finArbre,debutArbre);

	printf("Pour ce fichier, l'arbre a mis %f secondes pour le traiter.\n", tempsArbre);
}

int saisieArbre()
{
	int resultat = 1;

	int choix = 0;
	char * mot = (char*) malloc(sizeof(char) * 26);
	Noeud* noeud = NULL;
	Arbre* arbre = creerArbre();

	while(1)
	{
		printf("\nBienvenue dans l'assistant de création d'un arbre binaire de recherche de mots (un mot est composé de moins de 50 caractères! \n");
		printf("1 - Ajouter un mot \n");
		printf("2 - Rechercher un mot \n");
		printf("3 - Supprimer un mot \n");
		printf("4 - Afficher la liste \n");
		printf("0 - Quitter \n\n");

		choix = choixInt(4);
		
		switch(choix)
		{
			case 1:
				printf("\nVeuillez saisir un mot : ");
				scanf("%s", mot);
				noeud = creerNoeud(mot, 50);
				inserer(arbre, noeud);
				break;
			case 2:
				printf("\nVeuillez saisir le mot à rechercher : ");
				scanf("%s", mot);
				noeud = rechercher(arbre->racine, mot);
				if (noeud == NULL)
				{
					printf("\n Le mot recherché n'est pas dans l'arbre' !");
				}
				else
				{
					printf("\n Le mot est présent dans l'arbre'.");
				}
				break;

			case 3:
				printf("\nVeuillez saisir le mot à supprimer : ");
				scanf("%s", mot);
				noeud = rechercher(arbre->racine, mot);
				if (noeud == NULL)
				{
					printf("\n Le mot recherché n'est pas dans l'arbre' !");
				}
				else
				{
					supprimer(arbre, noeud);
				}
				break;
			case 4:
				afficherArbreRecursif(arbre->racine);
				break;
			case 0:
				return 0;
		}
	}

	return resultat;
}