#ifndef STRUCT_H
#define STRUCT_H

typedef struct { int arrivee; double cout; } T_ARC ;
typedef struct lsucc { T_ARC val; struct lsucc* suiv ; }* L_ARC;
typedef struct { char* nom; double x,y ; L_ARC voisins;} T_SOMMET ;
typedef struct _lsucc { T_SOMMET val; struct _lsucc* suiv ; }* L_SOMMET;
typedef struct {int n;T_SOMMET* tab;} GRAPHE;


//Fonctions d'affichage des structures
void affiche_graphe(GRAPHE g);
void affiche_sommet(T_SOMMET s);
void affiche_liste(L_ARC l);
void affiche_arc(T_ARC a);
void affiche_liste_sommet(L_SOMMET l);

//Fonctions sur les listes
L_ARC ajout_tete(T_ARC t,L_ARC l);
L_SOMMET ajout_tete_s(T_SOMMET t,L_SOMMET l);
L_ARC creer_liste();
L_SOMMET creer_liste_s();
L_ARC supprimer_tete(L_ARC l);
L_SOMMET supprimer_tete_s(L_SOMMET l);
int liste_vide(L_ARC l);
int liste_vide(L_SOMMET l);
L_ARC supprimen(int n,L_ARC l);
L_SOMMET supprimen_s(int n,L_SOMMET l);
L_ARC liberer_liste(L_ARC l);
L_SOMMET liberer_liste_s(L_SOMMET l);
int in_liste(T_ARC a,L_ARC l);
L_ARC recherche_liste(T_ARC a,L_ARC l);

//Fonctions sur les arcs
int compare_arc(T_ARC a,T_ARC b);

//Fonctions sur les Tas
void afficheTas(int* tas, int n);
void echangeTas(int* tas,int i,int j);
void augmenteTas(int* tas,double* listeCout, int i);
void constructionTas(int* tas, int n);
void descendreTas(int* tas,double* listeCout, int i);
void suppresionTas(int* tas,int i);
void triTas(int* tas,int n);

#endif
