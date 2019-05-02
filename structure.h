typedef struct { int arrivee; double cout; } T_ARC ;
typedef struct lsucc { T_ARC val; struct lsucc* suiv ; }* L_ARC;
typedef struct { char* nom; double x,y ; L_ARC voisins;} T_SOMMET ;
typedef struct {int n;T_SOMMET* tab;} GRAPHE;


//Fonctions d'affichage des structures
void affiche_graphe(GRAPHE g);
void affiche_sommet(T_SOMMET s);
void affiche_liste(L_ARC l);
void affiche_arc(T_ARC a);

//Fonctions sur les listes
L_ARC ajout_tete(T_ARC t,L_ARC l);
L_ARC creer_liste();
L_ARC supprimer_tete(L_ARC l);
int liste_vide(L_ARC l);
L_ARC supprimen(int n,L_ARC l);
L_ARC liberer_liste(L_ARC l);
int in_liste(T_ARC a,L_ARC l);
L_ARC recherche_liste(T_ARC a,L_ARC l);

//Fonctions sur les arcs
int compare_arc(T_ARC a,T_ARC b);
