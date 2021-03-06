#include "structure.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



static double absolu(double x){
  if (x<0) return -x;
  return x;
}


static double heuristic(T_SOMMET a, T_SOMMET b){
  double x = absolu (a.x - b.x);
  double y = absolu (b.y - b.y);
  return (x+y)/5;
}





GRAPHE lecture_fichier(char* nom_fichier){
  FILE* f;
  GRAPHE g;
  T_SOMMET temp;
  T_ARC arc;
  int numero,nbsommet,nbarc,depart,arrive;
  double lat,longi,prix;
  char line[128] ;
  char mot[512] ;
  char com[512];
  int i = 0;
  int j = 0;
  f=fopen(nom_fichier,"r");
  if (f==NULL) { printf("Impossible d’ouvrir le fichier\n"); exit(EXIT_FAILURE);}
  /* Lecture de la premiere ligne du fichier : nombre de sommet et nombre d’arcs */
  fscanf(f,"%d %d ",&nbsommet,&nbarc);
  printf("Il y a %d sommets et %d arcs \n",nbsommet,nbarc);
  g.tab = calloc(nbsommet, sizeof(temp)); /*Allocation mémoire pour le graphe */
  if (g.tab==NULL){printf("\nErreur allocation\n");}
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
    temp.nom = strdup(mot);
    temp.x = lat; /* On remplit les champs du noeud temporaire */
    temp.y = longi;
    temp.num=i;
    temp.voisins = creer_liste();
    g.tab[i] = temp; /*on ajoute le noeud au graphe*/
    i++;
    if ((int)(100*i/nbsommet) != (int)(100*j/nbsommet)) printf("sommets : %d \% \n", (int)(100*i/nbsommet));
    j=i;
  }

  fgets(com,511,f); /*ligne de commentaire*/
  i = 0;
  j = 0;
  while (i<nbarc){ /*on lit les arc */
    fscanf(f,"%d %d %lf", &(depart), &(arrive), &(prix));
    arc.arrivee = arrive;
    arc.cout = prix;
    g.tab[depart].voisins = ajout_tete(arc, g.tab[depart].voisins);
    i++;
    if ((int)(100*i/nbarc) != (int)(100*j/nbarc)) printf("arcs : %d \% \n", (int)(100*i/nbarc));
    j=i;
  }

  /* Ne pas oublier de fermer votre ficheir */
  fclose(f);
  return g;
}

double astar(GRAPHE g,int dep, int arr,int * listePere) {
    int best;
    L_SOMMET temp;
    L_ARC temp_a;
    int s;
    int* LF=calloc(g.n,sizeof(int));
    int* LO=calloc(g.n,sizeof(int));
    int tailleLo=0;
    int tailleLf=0;
    LO[tailleLo]=dep;
    tailleLo++;
    double * F=calloc(g.n,sizeof(double));
    double * G=calloc(g.n,sizeof(double));
    if ((F==NULL)||(G==NULL)){
        printf("\n\nERREUR ALLOCATION F OU G");
        exit(EXIT_FAILURE);
    }
    //Initialisation
    int i;
    for (i=0;i<g.n;i++) {
        F[i]=2000000000;
        G[i]=2000000000;
    }
    F[dep]=0;
    G[dep]=0;

    //Tant que le sommet d'arrivée n'est pas dans LF
    while (!in_tab_i(arr,LF,tailleLf)) {
        if (tailleLo==0) {
            return 2000000000;
        }
        triTas(LO,F,tailleLo);
        best=LO[0];              //On trouve le sommet ayant le plus court chemin de LO
        if (best==arr) {break;}
        supprimerTas(LO,F,tailleLo); //On l'enlève de LO
        tailleLo--;
        LF[tailleLf]=best;        //On l'ajoute à LF
        tailleLf++;
        temp_a=(g.tab[best]).voisins;

        while (!liste_vide(temp_a)) {
              s=(temp_a->val).arrivee;
              if (!(in_tab_i(s,LF,tailleLf))) {
                   if (!(in_tab_i(s,LO,tailleLo))) {
                        listePere[s]=best;
                        G[s]=G[best]+(temp_a->val).cout;
                        F[s]=G[s]+heuristic(g.tab[best],g.tab[arr]);
                        LO[tailleLo]=s;
                        tailleLo++;
                   }
                   else {
                        if ((G[best]+(temp_a->val).cout)<G[s]) {
                            listePere[s]=best;
                            G[s]=G[best]+(temp_a->val).cout;
                            F[s]=G[s]+heuristic(g.tab[best],g.tab[arr]);
                        }
                   }
              }
              temp_a=temp_a->suiv;
        }
    }
    return G[arr];
}


double astar_mauvais(GRAPHE g,int dep, int arr,int * listePere) {
    T_SOMMET best;
    L_SOMMET temp;
    L_ARC temp_a;
    int s;
    L_SOMMET LF=creer_liste_s();
    L_SOMMET LO=creer_liste_s();
    int * lo;
    int tailleLo;
    LO=ajout_tete_s(g.tab[dep],LO);
    double * F=calloc(g.n,sizeof(double));
    double * G=calloc(g.n,sizeof(double));
    if ((F==NULL)||(G==NULL)){
        printf("\n\nERREUR ALLOCATION F OU G");
        exit(EXIT_FAILURE);
    }

    //Initialisation
    int i;
    for (i=0;i<g.n;i++) {
        F[i]=2000000000;
        G[i]=2000000000;
    }
    F[dep]=0;
    G[dep]=0;
    //Tant que le sommet d'arrivée n'est pas dans LF
    while (!in_liste_s(g.tab[arr],LF)) {
        if (liste_vide_s(LO)) {
            return 2000000000;
        }
        tailleLo=taille_s(LO);
        lo=calloc(tailleLo,sizeof(int));
        if (lo==NULL) {
            printf("\nImpossible de creer lo");
            exit(EXIT_FAILURE);
        }
        temp=LO;
        for (i=0;i<tailleLo;i++) {
            lo[i]=(temp->val).num;
            temp=temp->suiv;
        }
        triTas(lo,F,tailleLo);
        best=g.tab[lo[0]];              //On trouve le sommet ayant le plus court chemin de LO
        if (compare_sommet(best,g.tab[arr])) {break;}
        LO=supprimen_s(indice_s(best,LO),LO); //On l'enlève de LO
        LF=ajout_tete_s(best,LF);        //On l'ajoute à LF
        temp_a=best.voisins;

        while (!liste_vide(temp_a)) {
              s=(temp_a->val).arrivee;
              if (!(in_liste_s(g.tab[s],LF))) {
                   if (!(in_liste_s(g.tab[s],LO))) {
                        listePere[s]=best.num;
                        G[s]=G[best.num]+(temp_a->val).cout;
                //Tant que le sommet d'arrivée n'est pas dans LF

                        F[s]=G[s]+heuristic(best,g.tab[arr]);
                        LO=ajout_tete_s(g.tab[s],LO);
                   }
                   else {
                        if ((G[best.num]+(temp_a->val).cout)<G[s]) {
                            listePere[s]=best.num;
                            G[s]=G[best.num]+(temp_a->val).cout;
                            F[s]=G[s]+heuristic(best,g.tab[arr]);
                        }
                   }
              }
              temp_a=temp_a->suiv;
        }
        free(lo);
    }
    return G[arr];
}

L_SOMMET plusCourtChemin(int arr,int dep,int * listePere,GRAPHE g) {
    L_SOMMET l=creer_liste_s();
    T_SOMMET s=g.tab[arr];
    T_SOMMET depart=g.tab[dep];
    while (!(compare_sommet(s,depart))) {
        l=ajout_tete_s(s,l);
        s=g.tab[listePere[s.num]];
    }
    return l;
}
