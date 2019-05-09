#include "structure.h"
#include "fonctions.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
  char nom_fichier[256] = "metroetu.txt";
  GRAPHE graphe;
  graphe = lecture_fichier(nom_fichier);
  affiche_graphe(graphe);
}
