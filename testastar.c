#include "structure.h"
#include "fonctions.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    char nom_fichier[256] = "graphe2.txt";
    GRAPHE graphe;
    int dep,arr,i;
    int* listePere;
    double ppc;
    L_SOMMET chemin;
    T_SOMMET s;
    graphe = lecture_fichier(nom_fichier);
    affiche_graphe(graphe);
    printf("\nRenseignez le noeud de départ et le noeud d'arrivée\n");
    scanf("%d %d",&dep,&arr);
    listePere=calloc(graphe.n,sizeof(int));
    for (i=0;i<graphe.n;i++) {
        listePere[i]=dep;
    }
    printf("\nLancement de astar !\n");
    ppc=astar(graphe,dep,arr,listePere);
    if (ppc>=2000000000) {
        printf("\n\nIl n'y a pas de chemin entre %s et %s !\nNous nous excusons pour le désagrément causé !",(graphe.tab[dep]).nom,(graphe.tab[arr]).nom);
    }
    else {
        printf("\nLe plus court chemin a un coût de %lf\n",ppc);
        chemin=plusCourtChemin(arr,dep,listePere,graphe);
        printf("\n%s\n",(graphe.tab[dep]).nom);
        while (!(liste_vide_s(chemin))) {
            s=depiler(&chemin);
            printf("  |\n");
            printf("  v\n");
            printf("%s\n",s.nom);
        }
    }
    printf("\n\nAu revoir !!\n");
}
