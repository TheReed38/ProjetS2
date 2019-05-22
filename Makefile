#$@  	Le nom de la cible
#$< 	Le nom de la première dépendance
#$^ 	La liste des dépendances
#$* 	Le nom du fichier sans suffixe

CFLAGS=-c -g

LDFLAGS=

ppc: main.o structure.o fonctions.o
	gcc -o $@ $^ $(LDFLAGS)


%.o: %.c
	gcc $< $(CFLAGS)

clean :
	rm *.o ppc




