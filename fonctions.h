#include "structure.h"

GRAPHE lecture_fichier(char* nom_fichier);
double astar_mauvais(GRAPHE g,int dep, int arr,int * listePere);
double astar(GRAPHE g,int dep, int arr,int * listePere);
L_SOMMET plusCourtChemin(int arr,int dep,int * listePere,GRAPHE g);
