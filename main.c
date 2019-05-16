#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"


int main(){
    char nomFichier[128];
    GRAPHE graphe;
    int dep,arr,i,choix;
    int* listePere;
    double ppc;
    int encore = 1;
    L_SOMMET chemin;
    T_SOMMET s;
    printf("\nBonjour et bienvenue dans cet algorithme qui se charge de trouver\nle plus court chemin dans un graphe (grâce à l'algorithme Astar) !");
    printf("\n\nRenseignez le nom du fichier du graphe :");
    scanf("%s",nomFichier);
    printf("\nChargement du graphe ...\n");
    graphe = lecture_fichier(nomFichier);
    printf("\nGraphe chargé !\n\n");
    while (encore) {
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
        printf("\nVoulez vous rechercher un nouveau chemin dans ce graphe ?\n1.Oui 2.Non\n");
        scanf("%d",&choix);
        if (choix!=1) {
            encore=0;
        }
    }
    printf("\n\nAu revoir !!\n");
}
