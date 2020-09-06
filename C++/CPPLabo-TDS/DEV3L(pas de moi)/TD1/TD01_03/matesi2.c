#include <stdbool.h>
#include <stdio.h>
#include "matesi.h"
#include "/home/rey/ESI/DEV3L/TD01_01/matesi.h"
//#include "/home/rey/DEV3L/TD01_01/matesi.c"
void printPrimeFactor2(unsigned int number, bool showPower){
    printf("%u = ",number);
    unsigned numDiv,cpt=1,iB=0;
    if (isPrime(number==true)){
        printf("%u\n",number);
    }else{
        numDiv = number;
        unsigned i = 2;
        while(numDiv != 1 && i<=numDiv){
            if(numDiv%i==0){
                numDiv = numDiv/i;
                if(!showPower){ //si showPower est FAUX.
                    printf("%u",i);
                    if(numDiv != 1)     //si on est pas à la fin alors on peut encore multiplier.
                        printf(" x ");
                }else{      //si showPower est VRAI.
                    if(i==iB){  //si le nombre se repete.
                        cpt++;
                        if(numDiv==1 || numDiv%i!=0){ //si on est a la fin de la division OU il peut encore se multiplier par lui meme
                            printf("^%u",cpt);  //affiche les occurences du facteur/diviseur.
                            i++; //on augmente le compteur i pour checker le numero suivant.
                        }

                    }else{
                        if(iB!=0)       //si on est au debut alors on affiche pas x.
                            printf(" x ");
                        printf("%u",i);
                        iB=i;       // on garde le diviseur utilisé.
                        cpt=1;      //on reinitialise le compteur des occurences.
                    }
                }
            }else{      // le compteur i augmente ssi le nombre n'est pas divisible par i.
                i++;
            }
        }

    }
    printf("\n");
}


//void printShowTrue(unsigned numDiv,unsigned i,unsigned iB,unsigned cpt){



//}
