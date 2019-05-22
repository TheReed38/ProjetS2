#include <stdio.h>
#include <stdlib.h>
#include "structure.h"

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

T_SOMMET depiler(L_SOMMET *l) {
    if (liste_vide_s(*l)) {
          printf("\n\nImpossible de dépiler une liste vide !\n");
          exit(EXIT_FAILURE);
    }
    T_SOMMET s=(*l)->val;
    *l=supprimer_tete_s(*l);
    return s;
}

void affiche_liste_sommet(L_SOMMET l) {
    L_SOMMET p=NULL;
    for (p=l; !liste_vide_s(p); p=p->suiv) {
        affiche_sommet(p->val);
    }
}

void affiche_arc(T_ARC a) {
    printf("Arrivee: %d, cout: %lf\n",a.arrivee,a.cout);
}

//Ajoute un arc en tête de liste
L_ARC ajout_tete(T_ARC t,L_ARC l) {
    L_ARC p=creer_liste();
    if (!(liste_vide(p=calloc( 1, sizeof (*p)))))  { p->val=t; p->suiv=l; }
    else {printf("\nErreur allocation\n");}
    return p;
}

L_SOMMET ajout_tete_s(T_SOMMET t,L_SOMMET l) {
    L_SOMMET p=creer_liste_s();
    if (!(liste_vide_s(p=calloc( 1, sizeof (*p)))))  { p->val=t; p->suiv=l; }
    else {printf("\nErreur allocation\n");}
    return p;
}

L_ARC creer_liste() {return NULL;}
L_SOMMET creer_liste_s() {return NULL;}

L_ARC supprimer_tete(L_ARC l) {
    if (liste_vide(l)) {
        return NULL;
    }
    L_ARC p=l;
    l=l->suiv;
    free(p);
    return l;
}

L_SOMMET supprimer_tete_s(L_SOMMET l) {
    if (liste_vide_s(l)) {
        return NULL;
    }
    L_SOMMET p=l;
    l=l->suiv;
    free(p);
    return l;
}

int liste_vide(L_ARC l) {return (l==NULL);}
int liste_vide_s(L_SOMMET l) {return (l==NULL);}

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
    }
    if (liste_vide(k)) {
        return l;
    }
    k->suiv=supprimer_tete(k->suiv);
    return l;
}

L_SOMMET supprimen_s(int n,L_SOMMET l) {
    int i=0;
    if (liste_vide_s(l)) {
        return NULL;
    }
    if (n==0) {
        return supprimer_tete_s(l);
    }
    L_SOMMET k=l;
    while ((!liste_vide_s(k))&&(i<(n-1))) {
      k=k->suiv;
      i+=1;
    }
    if (liste_vide_s(k)) {
        return l;
    }
    k->suiv=supprimer_tete_s(k->suiv);
    return l;
}

//libere la liste
L_ARC liberer_liste(L_ARC l) {
    if (liste_vide(l)) {
        return l;
    }
  L_ARC k=supprimer_tete(l);
  return liberer_liste(k);
}

L_SOMMET liberer_liste_s(L_SOMMET l) {
    if (liste_vide_s(l)) {
        return l;
    }
  L_SOMMET k=supprimer_tete_s(l);
  return liberer_liste_s(k);
}

//renvoie 1 si a est dans l, 0 sinon
int in_liste(T_ARC a,L_ARC l) {
    if (liste_vide(l)) {
        return 0;
    }
    if (compare_arc(a,l->val)) {
        return 1;
    }
    return in_liste(a,l->suiv);
}

//renvoie 1 si a est dans l, 0 sinon
int in_liste_s(T_SOMMET a,L_SOMMET l) {
    if (liste_vide_s(l)) {
        return 0;
    }
    if (compare_sommet(a,l->val)) {
        return 1;
    }
    return in_liste_s(a,l->suiv);
}

//Renvoie la taille de la liste
int taille_s(L_SOMMET l) {
    int i=0;
    L_SOMMET s=l;
    while (!liste_vide_s(s)) {
        s=s->suiv;
        i++;
    }
    return i;
}

//Renvoie l'indice de l'élèment a s'il est présent dans l -1 sinon
int indice_s(T_SOMMET a,L_SOMMET l) {
    if (in_liste_s(a,l)) {
        int i=0;
        L_SOMMET s=l;
        while (!(compare_sommet(a,s->val))) {
            s=s->suiv;
            i++;
        }
        return i;
    }
    return -1;
}

//renvoie la liste commencant par a si celui-ci est présent, null sinon
L_ARC recherche_liste(T_ARC a,L_ARC l) {
    if (liste_vide(l)) {
        return NULL;
    }
    if (compare_arc(a,l->val)) {
        return l;
    }
    return recherche_liste(a,l->suiv);
}
//renvoie 1 si a et b sont identiques 0 sinon
int compare_liste(L_ARC a,L_ARC b) {
    if (liste_vide(a)&&liste_vide(b)) {
        return 1;
    }
    if ((liste_vide(a))||(liste_vide(b))) {
        return 0;
    }
    if (!compare_arc(a->val,b->val)) {
        return 0;
    }
    return compare_liste(a->suiv,b->suiv);
}

//renvoie 1 si a et b sont identiques 0 sinon
int compare_arc(T_ARC a,T_ARC b) {
    return ((a.arrivee==b.arrivee)&&(a.cout==b.cout));
}

//renvoie 1 si a et b sont identiques 0 sinon
int compare_sommet(T_SOMMET a,T_SOMMET b) {
    //return ((!strcmp(a.nom,b.nom))&&(a.x==b.x)&&(a.y==b.y)&&(a.num==b.num)&&(compare_liste(a.voisins,b.voisins)));
    return (a.num==b.num);
}

//Affiche un tas de taille n
void afficheTas(int* tas,int n) {
    int i;
    if (n!=0) {
        printf("[%d",tas[0]);
        for (i=1;i<n;i++) {
            printf(",%d",tas[i]);
        }
        printf("]");
    }
    else {
        printf("[]");
    }
}

//Echange les éléments i et j du tableau tas
void echangeTas(int* tas,int i,int j) {
    int tmp;
    tmp=tas[i];
    tas[i]=tas[j];
    tas[j]=tmp;
}

//Ajoute le nombre d'indice i au tas
void augmenteTas(int* tas,double* listeCout, int i) {
    int k=i;
    while ((k!=0) && (listeCout[tas[k]]>listeCout[tas[(k-1)/2]])) {
        echangeTas(tas,k,(k-1)/2);
        k=(k-1)/2;
    }
}

//Construit un tas à partir d'un tableau de n éléments
void constructionTas(int* tas,double* listeCout, int n) {
    int i;
    for (i=0;i<n;i++) {
        augmenteTas(tas,listeCout,i);
    }
}

//Permet de placer la racine à sa place dans le tas (qui est limité à i-1)
void descendreTas(int* tas,double* listeCout, int i) {
    int k=0;
    int maxk;
    double max;
    while ((((2*(k+1))<i)&&(listeCout[tas[k]]<listeCout[tas[2*(k+1)]]))||((((2*(k+1))-1)<i)&&(listeCout[tas[k]]<listeCout[tas[(2*(k+1))-1]]))) {
        if ((2*(k+1))>=i) {
            echangeTas(tas,k,2*(k+1)-1);
            k=2*(k+1)-1;
        }
        else {
            if (listeCout[tas[2*(k+1)-1]]>listeCout[tas[2*(k+1)]]) {
                echangeTas(tas,k,2*(k+1)-1);
                k=2*(k+1)-1;
            }
            else {
                echangeTas(tas,k,2*(k+1));
                k=2*(k+1);
            }
        }
    }
}

//Permet de supprimer la racine d'un tas de taille i-1
void supprimerTas(int* tas,double* listeCout, int i) {
    echangeTas(tas,i-1,0);
    descendreTas(tas,listeCout,i-1);
}

//Trie le tableau de taille n par le tri Tas
void triTas(int* tas,double* listeCout, int n) {
    int i;
    constructionTas(tas,listeCout,n);
    for (i=n;i>1;i--) {
        supprimerTas(tas,listeCout,i);
    }
}

//Affiche un tableau de double
void afficheTabDouble(double* tas,int n) {
    int i;
    if (n!=0) {
        printf("[%lf",tas[0]);
        for (i=1;i<n;i++) {
            printf(",%lf",tas[i]);
        }
        printf("]");
    }
    else {
        printf("[]");
    }
}

//renvoie 1 si a est dans l, 0 sinon
int in_tab_i(int a,int * l,int t) {
    int i=0;
    while ((i<t)&&(l[i]!=a)) {
        i++;
    }
    if (i==t) return 0;
    return 1;
}
