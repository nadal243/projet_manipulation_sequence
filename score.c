#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "score.h"




int Needleman (char* ch1, char *ch2) {

    int l1 = strlen(ch1) +1;
    int l2 = strlen(ch2) +1; 
    int max = 0; 
    
    int d[l1*l2];

    for (int i=0; i<l1; i++) {
        d[i*l2] = 0; 
    }

    for (int j=0; j<l2; j++) {
        d[j] = 0; 
    }

    for (int i=1; i<l1; i++) {
        for (int j=1; j<l2; j++) {
            int cout = 0;

            if (ch1[i-1] == ch2[j-1]) {
                cout += 1;
            } 
            else {
                cout -= 1;
            }

            d[i*l2+j] = fmax(fmax(d[(i-1)*l2+j]-1, d[i*l2+(j-1)]-1), d[(i-1)*l2+(j-1)]+cout);

            if (d[i*l2+j] > max) {
                max = d[i*l2+j];
            }
        }
    }

    return max;

}


int Pourcentage (char* ch1, char *ch2) {
    int l1 = strlen(ch1);
    int l2 = strlen(ch2);

    int score = Needleman(ch1, ch2);

    return (score * 100) / fmin(l1, l2);
}