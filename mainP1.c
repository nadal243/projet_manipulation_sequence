#include "individu.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    t_indiv* Ppers = malloc(10*sizeof(t_indiv));
    if (Ppers == NULL) {
        printf("Erreur lors de l'allocation memoire.\n");
        return 1;
    }

    FILE* Pfichier = malloc(sizeof(FILE));
    Pfichier = fopen("ADN.txt", "r");
    if (Pfichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        free(Ppers);
        exit(1);
    }

    for (int i = 0; i < 10; i++) {
    IdentifieIndividu(Pfichier, &Ppers[i]);
    }

    for (int i = 9; i >= 0; i--) {
        AfficheIndividu(&Ppers[i]);
    }

    for (int i = 0; i < 10; i++) {
        libereIndividu(&Ppers[i]);
    }
    
    fclose(Pfichier);
    free(Ppers);

    return 0;
}