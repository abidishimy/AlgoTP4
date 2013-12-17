#ifndef DEF_ARBRE
#define DEF_ARBRE

	#include "noeud.h"

	typedef struct Arbre
	{
		Noeud* racine;		
	} Arbre;

	Arbre*	creerArbre();
	void 	detruireArbre(Arbre ** _arbre);
	void	inserer(Arbre* _arbre, Noeud* _noeud);
	Noeud*	rechercher(Noeud* _noeudArbre, char* _mot);
	void	supprimer(Arbre* _arbre, Noeud* _noeud);
#endif