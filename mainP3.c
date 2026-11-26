#include "individu.h"
#include <stdio.h>
#include <stdlib.h>
#include "score.h"
#include <string.h>

int main() {

    // saisir une sequence ADN à comparer
    printf("Saisir une sequence ADN à comparer : ");
    char sequence3[100000];
    scanf("%s", sequence3);

    // 1. Allocation pour un seul individu (réutilisé à chaque itération)
    t_indiv* Ppers = malloc(sizeof(t_indiv));
    if (Ppers == NULL) {
        printf("Erreur lors de l'allocation memoire.\n");
        return 1;
    }

    // 2. Ouverture du fichier (pas besoin de malloc pour un FILE*)
    FILE* Pfichier = fopen("ADN.txt", "r");
    if (Pfichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        free(Ppers);
        return 1;
    }

    float maxSimilarite = 0.0;
    char maxIndividu[100]; // Pour stocker le nom de l'individu avec la similarité maximale

    // 3. Lecture, affichage et libération individu par individu jusqu'à la fin du fichier
    while (!feof(Pfichier)) {
        IdentifieIndividu(Pfichier, Ppers);

        float similarite = calculeSimilarite(Ppers, sequence3);
        printf("Similarité avec %s : %.2f %%\n", Ppers->nom, similarite);
        if (similarite > maxSimilarite) {
            maxSimilarite = similarite;
            strcpy(maxIndividu, Ppers->nom);
        }

        // Vérifie que la lecture n'a pas échoué sur une ligne vide en fin de fichier
        if (!feof(Pfichier)) {
           // AfficheIndividu(Ppers);
            libereIndividu(Ppers);
        }
    }

    printf("L'individu avec la similarité maximale est : %s avec %.2f %%\n", maxIndividu, maxSimilarite);

    // 4. Fermeture du fichier et libération de la structure
    fclose(Pfichier);
    free(Ppers);

    return 0;
}
