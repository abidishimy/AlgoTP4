#ifndef DEF_OUTILSARBRE
#define DEF_OUTILSARBRE

	#include "arbre.h"
	#include "noeud.h"

	void 	transplanter(Arbre* _arbre, Noeud* _u, Noeud* _v);
	Noeud* 	arbreMinimum(Noeud* _noeud);
	Noeud* 	arbreMaximum(Noeud* _noeud);
	Noeud* 	arbreSuccesseur(Noeud* _noeud);
	void	afficherArbreRecursif(Noeud* _noeud);

#endif