#include "structure.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

GRAPHE lecture_fichier(char* nom_fichier){
  FILE* f;
  GRAPHE g;
  T_SOMMET temp;
  T_ARC arc;
  int numero,nbsommet,nbarc,arrive,prix;
  double lat,longi ;
  char line[128] ;
  char mot[512] ;
  int i = 0;
  f=fopen(nom_fichier,"r");
  if (f==NULL) { printf("Impossible d’ouvrir le fichier\n"); exit(EXIT_FAILURE);}
  /* Lecture de la premiere ligne du fichier : nombre de sommet et nombre d’arcs */
  fscanf(f,"%d %d ",&nbsommet,&nbarc);
  g.tab = calloc(nbsommet, sizeof(temp)); /*Allocation mémoire pour le graphe */
  g.n = nbsommet;
  /* Ligne de texte "Sommets du graphe" qui ne sert a rien */
  fgets(mot,511,f);
  /* lecture d’une ligne de description d’un sommet  */
  /* on lit d’abord numero du sommet, la position,  le nom de la ligne */
  while (i<nbsommet){ /*on lit autant de ligne qu'il y a de sommets*/
    fscanf(f,"%d %lf %lf %s", &(numero), &(lat), &(longi), line);
    /* numero contient alors l’entier ou numero du sommet, lat et longi la position, line le nom de la
    ligne */
    /* Le nom de la station peut contenir des separateurs comme l’espace. On utilise plutot fgets dans ce
    cas */
    fgets(mot,511,f);
    if (mot[strlen(mot)-1]<32) mot[strlen(mot)-1]=0;
    /* mot contient le nom du sommet. */
    /*Pour sauter les lignes de commentaires, on peut simplement utiliser la fonction fgets sans utiliser
    la chaine de caracteres lue dans le fichier par */
    temp.nom = mot;
    temp.x = lat; /* On remplit les champs du noeud temporaire */
    temp.y = longi;
    temp.voisins = creer_liste();
    g.tab[i] = temp; /*on ajoute le noeud au graphe*/
    i++;
  }

  fgets(mot,511,f); /*ligne de commentaire*/
  i = 0;
  while (i<nbarc){ /*on lit les arc */
    fscanf(f,"%d %d %d", &(numero), &(arrive), &(prix));
    arc.arrivee = arrive;
    arc.cout = prix;
    g.tab[numero].voisins = ajout_tete(arc, g.tab[numero].voisins);
    i++;
  }

  /* Ne pas oublier de fermer votre ficheir */
  fclose(f);
  return g;
}
