#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "score.h"

int main() {

    char* ch1 = malloc(20*sizeof(char)); 
    char* ch2 = malloc(20*sizeof(char)); 


    printf("saisir une chaine de caractere :"); 
    scanf("%s", ch1); 
    printf("\n"); 
    printf("saisir une chaine de caractere : "); 
    scanf("%s", ch2); 
    printf("\n"); 
    // calcul du score Needleman
    int score = Needleman(ch1, ch2);


    // pourcentage d'inclusion 
    float inclusion = Pourcentage (ch1, ch2); 

    // affichage du score Needleman
    printf("Le score Needleman est : %d \n", score);

    // affichage du % d'inclusion 
    printf("Le pourcentage d'inclusion est %.2f %% ", inclusion);
    printf("\n");  

    return 0; 
}
