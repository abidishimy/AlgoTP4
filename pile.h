#ifndef DEF_PILE
#define DEF_PILE

	#include "Noeud.h"

	typedef struct
	{
		int capacite;
		int sommet;
		Noeud** tableau;
	} Pile;

	Pile * creerPile(int _capacite);
	void detruirePile(Pile ** p);
	int capacitePile(Pile * _pile);
	int pileVide(Pile * _pile);
	int pilePleine(Pile * _pile);
	void empiler(Pile * _pile, Noeud* _noeud);
	Noeud* depiler(Pile * _pile);
	Noeud* sommet(Pile * _pile);


#endif