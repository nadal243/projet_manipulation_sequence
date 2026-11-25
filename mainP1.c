#include "individu.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    t_indiv* Ppers = malloc(sizeof(t_indiv));
    if (Ppers == NULL) {
        printf("Erreur lors de l'allocation memoire.\n");
        return 1;
    }

    FILE* Pfichier; 
    Pfichier = fopen("ADN.txt", "r");
    if (Pfichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        free(Ppers);
        exit(1);
    }

    IdentifieIndividu(Pfichier, Ppers);

    AfficheIndividu(Ppers);
    libereIndividu(Ppers);
    fclose(Pfichier);
    free(Ppers);

    return 0;
}