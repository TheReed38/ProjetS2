#include "structure.h"
#include <stdio.h>

int main() {
    L_ARC l1;
    T_ARC a;
    printf("Bienvenue dans ce test sur les listes !\n");
    char rep; int n;
    l1=creer_liste();
    do {
      printf("quitter(0); Ajouter en tete(1); Supprimer en tete(2); visualiser_liste(3); Supprimer en n (4); recherche d'un arc(5)"); fflush(stdout);
      rep=getchar();
      switch(rep) {
        case '1': printf("Valeur arrivée et cout\n"); scanf("%d %lf",&(a.arrivee),&(a.cout));
                  l1=ajout_tete(a,l1);
                  break;
        case '2': l1=supprimer_tete(l1); break;
        case '3': affiche_liste(l1); break;
        case '4': printf("Quelle est la position a supprimer ? \n");
              scanf("%d",&n);
              if (n>=0)
                  l1=supprimen(n,l1);
              break;
        case '5': printf("Valeur arrivée et cout\n"); scanf("%d %lf",&(a.arrivee),&(a.cout));
              if (in_liste(a,l1)) {
                  printf("Ok il est dedans !\n Le voici : \n");
                  affiche_liste(recherche_liste(a,l1));
              }
              else {
                  printf("Il n'est pas dedans ! \n");
              }
      }
      getchar();
    } while (rep !='0');
    printf("Liberation des listes\n");
    l1=liberer_liste(l1);
}
