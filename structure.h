typedef struct { char* nom; double x,y ; L_ARC voisins;} T_SOMMET ;
typedef struct { int arrivee; double cout; } T_ARC ;
typedef struct lsucc { T_ARC val; struct lsucc* suiv ; }* L_ARC;
