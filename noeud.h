#ifndef DEF_NOEUD
#define DEF_NOEUD

	typedef struct Noeud2
	{
		char* mot;
		struct Noeud2 * pere;
		struct Noeud2 * gauche;
		struct Noeud2 * droit;
	} Noeud;

	Noeud*	creerNoeud(char* mot, int _tailleMot);
	void 	detruireNoeud(Noeud ** _noeud);
#endif