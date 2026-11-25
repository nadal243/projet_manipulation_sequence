#include <stdio.h>
#include <stdlib.h>
#include "individu.h"

// fonction pour lire les informations d'un individu depuis un fichier
void IdentifieIndividu(FILE* Pfichier, t_indiv* Ppers) {

    // Pfichier = malloc(sizeof(FILE));
    // Pfichier = fopen("ADN.txt", "r");
    if (Pfichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        exit(1);
    }
    Ppers->nom = malloc(50*(sizeof(char))); 
    Ppers->prenom = malloc(50*(sizeof(char))); 
    Ppers->sequence = malloc(100000*(sizeof(char)));

    // Lecture du nom et du prénom depuis le fichier
    fscanf(Pfichier, "%s %s %s", Ppers->nom, Ppers->prenom, Ppers->sequence);

}

// fonction pour afficher les informations d'un individu
void AfficheIndividu(t_indiv* Ppers) {
    printf("Nom : %s\n", Ppers->nom);
    printf("Prénom : %s\n", Ppers->prenom);
    printf("Séquence : %s\n", Ppers->sequence);
}


// fonction pour libérer la mémoire allouée pour un individu
void libereIndividu(t_indiv* Ppers) {
    free(Ppers->nom);
    free(Ppers->prenom);
    free(Ppers->sequence);
}



