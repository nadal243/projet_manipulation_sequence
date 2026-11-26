# Modèle de fichier Makefile, à adapter pour le TP

# options de compilation
CC = gcc
CCFLAGS = -Wall

# fichiers du projet
SRC = score.c mainP3.c individu.c
OBJ = $(SRC:.c=.o)
EXEC = mainP3.out


# règle initiale
all: $(EXEC)

# dépendance des .h
score.o: score.h
individu.o: individu.h
mainP3.o: individu.h score.h
# règles de compilation
%.o: %.c
	$(CC) $(CCFLAGS) -o $@ -c $<
	
# règles d'édition de liens
$(EXEC): $(OBJ)
	$(CC) $(CCFLAGS) -o $@ $^ -lm
	

# règles supplémentaires
clean:
	rm -f *.o
mproper:
	rm -f $(EXEC) *.o