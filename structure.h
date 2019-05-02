typedef *T_SOMMET GRAPHE;
typedef struct { char* nom; double x,y ; L_ARC voisins;} T_SOMMET ;
typedef struct { int arrivee; double cout; } T_ARC ;
typedef struct lsucc { T_ARC val; struct lsucc* suiv ; }* L_ARC;


//Fonctions d'affichage des structures
void affiche_sommet(T_SOMMET s);
void affiche_liste(L_ARC l);
void affiche_arc(T_ARC a);

//Fonctions sur les listes
L_ARC ajout_tete(L_ARC l);
L_ARC creer_liste();
int liste_vide(L_ARC l);
L_ARC supprimen(int n,L_ARC l);
L_ARC liberer_liste(L_ARC l);
int in_liste(T_ARC a,L_ARC l);
L_ARC recherche_liste(T_ARC a,L_ARC l);
