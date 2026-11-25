#ifndef __individu__
#define __individu__

#include <stdio.h>

typedef struct 
{
    char* nom; 
    char* prenom; 
    char* sequence; 
}t_indiv;



void IdentifieIndividu(FILE* Pfichier, t_indiv* Ppers); 
void AfficheIndividu(t_indiv* Ppers); 
void libereIndividu(t_indiv* Ppers); 
#endif