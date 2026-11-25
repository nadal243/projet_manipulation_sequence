#include <stdio.h>
#include <stdlib.h>

int strcmp1( char* s1, char* s2) {
    int i=0; 
    while(s1[i]!='\0' && s2[i]!='\0'){

        if (s1[i]!= s2[i]) {
            return s1[i] - s2[i]; 
        }
        i++; 

    }
    return s1[i] - s2[i]; 


}

int strcmp2(char *s1, char *s2)
{
    while (*s1 != '\0' && *s2 != '\0')
    {
        if (*s1 != *s2)
            return *s1 - *s2;

        s1++;
        s2++;
    }

    return *s1 - *s2;
}


int main() {
    char* s1 = malloc(100*sizeof(char)); 
    char* s2 = malloc(100*sizeof(char)); 

    printf("saisir une chaine de caractere : "); 
    scanf("%s", s1); 

    printf("saisir une chaine de caractere :");
    scanf("%s", s2); 

    int resultat1 = strcmp1(s1, s2); 
    int resultat2 = strcmp2(s1, s2); 


    printf("resultat 1 : %d", resultat1); 
    printf("\n"); 
    printf("resultat 2 : %d\n", resultat2); 

    free(s1);
    free(s2);

    return 0; 






}