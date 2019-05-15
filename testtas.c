#include "structure.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  int* tableauSommet;
  double* listeCout;
  int n;
  printf("Renseignez la taille du tableau de sommet\n");
  scanf("%d",&n);
  int i;
  tableauSommet=calloc(n,sizeof(int));
  listeCout=calloc(n,sizeof(double));
  for (i=0;i<n;i++) {
    printf("Renseignez le sommet et son coût\n");
    scanf("%d",tableauSommet+i);
    scanf("%lf",listeCout+tableauSommet[i]);
  }
  printf("Voici les tableaux avant le tri \n");
  afficheTas(tableauSommet,n);
  afficheTabDouble(listeCout,n);
  printf("\nTRI EN COURS\n");
  triTas(tableauSommet,listeCout,n);
  printf("\nTRI EFFECTUE résultat :\n");
  afficheTas(tableauSommet,n);
  afficheTabDouble(listeCout,n);
  printf("\nLibération du tas\n");
  free(listeCout);
  free(tableauSommet);
}
