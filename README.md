 # Programme A*

Un programme permettant de calculer le plus court chemin entre 2 sommets a sein d'un fichier.

* * *

## Utilisation :

Pour utiliser ce programme, il faut le complier, puis l'exécuter.

### Compilation : 

Grâce au MakeFile fourni, il suffit de taper "make pcc" pour automatiser la compilation. Cette commande crée un exécutable "pcc" utilisable directement.
Pour "désinstaller" pcc, il suffit de taper "make clean" et le terminal supprime tous les fichiers nouvellement crées.

### Execution :

Pour lancer le programme, il faut au préalable mettre le fichier à lire (.txt, .csv,...) dans le même dossier que l'exécutable. Ensuite il suffit de lancer l'exécutable, et de suivre les informations à l'écran.



- - -
#### Format des fichiers attendus :

Le format des fichiers est le suivant :
- Première ligne : deux entiers ; nombre de sommets (NBS) nombre d’arcs (NBA)
- Deuxième ligne : la chaîne de caractères "Sommets du graphe"
- NBS lignes dont le format est le suivant :
   - un entier : numéro de la station ;
   - deux réels indiquant la latitude et la longitude
   - une chaîne de caractères (sans séparateurs) contenant le « nom de la ligne » (par exemple
M1, M3bis, T3, A1 pour le fichier métro parisien)
   - une chaîne de caractères contenant le nom du nœud (qui peut contenir des séparateurs, par
exemple des espaces).
- 1 ligne : la chaîne de caractères "arc du graphe : départ arrivée valeur "
- NBA lignes dont le format est le suivant :
   - un entier : numéro du sommet de départ
   - un entier : numéro du sommet d’arrivée
   - un réel : valeur ou coût de l’arc
