#include <stdio.h>
#include <stdlib.h>
#include "stucture.h"

void affiche_graphe(GRAPHE g) {
  int i;
  for (i=0;i<g.n;i++) {
      affiche_sommet(g.tab[i]);
  }
}

void affiche_sommet(T_SOMMET s) {
    printf("%s (%lf,%lf):\n",s.nom,s.x,s.y);
    affiche_liste(s.voisins);
}

void affiche_liste(L_ARC l) {
    L_ARC p=NULL;
    for (p=l; !liste_vide(p); p=p->suiv) {
        affiche_arc(p->val);
    }
}

void affiche_arc(T_ARC a) {
    printf("Arrivee: %d, cout: %lf\n",a.arrivee,a.cout);
}

//Ajoute un arc en tête de liste
L_ARC ajout_tete(T_ARC t,L_ARC l) {
    L_ATC p=creer_liste();
    if (!(liste_vide(p=calloc( 1, sizeof (*p)))))  { p->val=t; p->suiv=l; }
    return p;
}

L_ARC creer_liste() return NULL;

L_ARC supprimer_tete(L_ARC l) {
    if (liste_vide(l)) {
        return NULL;
    }
    L_ARC p=l;
    l=l->suiv;
    free(p);
    return l;
}

int liste_vide(L_ARC l) return (l==NULL);

//Supprimer le nième élément de la liste (on compte à partir de 0)
L_ARC supprimen(int n,L_ARC l) {
    int i=0;
    if (liste_vide(l)) {
        return NULL;
    }
    if (n==0) {
        return supprimer_tete(l);
    }
    L_ARC k=l;
    while ((!liste_vide(k))&&(i<(n-1))) {
      k=k->suiv;
      i+=1;
    }in_liste
    if (liste_vide(k)) {
        return l;
    }
    k->suiv=supprimer_tete(k->suiv);
    return l;void affiche_graphe(GRAPHE g);
}

//libere la liste
L_ARC liberer_liste(L_ARC l) {
    if (liste_vide(l)) {
        return l;
    }
  L_ARC k=supprimer_tete(l);
  return liberer_liste(k);
}

//renvoie 1 si a est dans l, 0 sinon
int in_liste(T_ARC a,L_ARC l) {
    if liste_vide(l) {
        return 0;
    }
    if compare_arc(a,l->val) {
        return 1;
    }
    return in_liste(a,l->suiv);
}

//renvoie la liste commencant par a si celui-ci est présent, null sinon
L_ARC recherche_liste(T_ARC a,L_ARC l) {
    if liste_vide(l) {
        return NULL;
    }
    if compare_arc(a,l->val) {
        return l;
    }
    return recherche_liste(a,l->suiv);
}

//renvoie 1 si a et b sont identiques 0 sinon
int compare_arc(T_ARC a,T_ARC b) {
    return ((a.arrivee==b.arrivee)&&(a.cout==b.cout));
}
