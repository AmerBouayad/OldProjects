#include "mathesi.h"
#include <stdio.h>
#include <math.h>

//1.1
bool isPrime(unsigned int number){
    if(number<=1 || (number%2==0 && number != 2))
        return false;
    if(number== 2 || number==3)
        return true;

    unsigned int diviseur=3;
    unsigned int limite=(unsigned int)(sqrt(number));
    while(diviseur<=limite){
        if(number%diviseur==0)
            return false;
        diviseur=diviseur+2;
    }
    return true;
}

//1.2
void affPrime(unsigned int bInf, unsigned int bSup){
    printf("Les nombres premiers entre %d et %d :\n ", bInf, bSup);

    unsigned int cpt = 0;
    for (unsigned int nb = bInf; nb<=bSup; nb++){
        cpt++;
       if(isPrime(nb)){
            printf("%4d",nb);
       }else{
            printf("%4c",'.');
       }
       if (cpt==10){
        cpt = 0;
        printf("\n");
       }
    }
}
//1.3
void printPrimeFactor(unsigned int number, bool showPower){
    printf("%d = ", number);
    unsigned int restant = number;
    unsigned int nb = 2;
    unsigned int cpt = 0;
    unsigned int prevNb;
    while(nb<restant){
        if(restant%nb==0 && showPower == false){
            printf("%d x ", nb);
            restant = restant/nb;
        }else if(restant%nb==0 && showPower == true){
            prevNb = nb;
            while(prevNb == nb && restant%nb==0){
                cpt++;
                restant = restant/nb;
            }
            if(cpt>1){
                printf("%d^%d", prevNb, cpt);
            }else{
               printf("%d", nb);
            }
            cpt=0;
            if(restant > 1){
                printf(" x ");
            }
        }else{
            nb++;
        }
    }
    if(restant > 1){
        printf("%d ", restant);
    }
    printf("\n");
}

//1.4
unsigned gcd(unsigned a, unsigned b){
    unsigned int pgcd;
    unsigned int rest;
    if(b == 0){
        pgcd = a;
    }else if (a == 0){
        pgcd = b;
    }else{
        if(a < b){
        rest = b;
        b = a;
        a = rest;
        }
        while(a%b != 0){
            rest = a%b;
            a = b;
            b = rest;
        }
        pgcd = b;
    }
    return pgcd;
}

//1.5
void td1ex5(){
    unsigned pgcd;
    unsigned a = 423;
    for(unsigned i = 0; i < 6; i++){
        for(unsigned b = 135; b >= 125 ; b = b-5){
            pgcd = gcd(a,b);
             printf(" gcd(%d,%d) = %d ",a, b, pgcd);
             if(pgcd < 10){
                 printf(" ");
             }
             if(b > 125){
                  printf("|");
             }
        }
        a = a+3;
        printf("\n");
    }
}

//1.6
void arrayIntPrint(const int data [], unsigned nbElem){
    unsigned i = 0;
    while(nbElem > i){
         printf("%d ",data[i]);
        i++;
    }
    printf("\n");
}

//1.7
void arrayIntSort(int data [], unsigned nbElem, bool ascending){
    unsigned saveVal;
    for(unsigned i = 0; i < nbElem-1; i++){
        for(unsigned y = 0; y < nbElem-1; y++){
            if(ascending){
                if(data[y] > data[y+1]){
                    saveVal = data[y+1];
                    data[y+1] = data[y];
                    data[y] = saveVal;
                }
            }else{
                if(data[y] < data[y+1]){
                    saveVal = data[y+1];
                    data[y+1] = data[y];
                    data[y] = saveVal;
                }
            }
        }
    }
    arrayIntPrint(data ,nbElem);
}
//1.8-a
int compare_ints(const void* a, const void* b)
{
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;

    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;

    // return (arg1 > arg2) - (arg1 < arg2); // possible shortcut
    // return arg1 - arg2; // erroneous shortcut (fails if INT_MIN is present)
}

//1.8-b
int compare_intDec(const void* a, const void* b)
{
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;

    if (arg1 < arg2) return 1;
    if (arg1 > arg2) return -1;
    return 0;
}

//1.8-c
int compare_intsMod3(const void* a, const void* b)
{
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;

    if (arg1%3 < arg2%3) return 1;
    if (arg1%3 > arg2%3) return -1;
    return 0;
}
//1.10)strlen : retourne le nombre de char d'un tableau de char sans compter
//              le 0 terminé('\0')

//1.10) strcmp
void demo(const char* lhs, const char* rhs)
{
    int rc = strcmp(lhs, rhs);
    if(rc == 0)
        printf("[%s] equals [%s]\n", lhs, rhs);
    else if(rc < 0)
        printf("[%s] precedes [%s]\n", lhs, rhs);
    else if(rc > 0)
        printf("[%s] follows [%s]\n", lhs, rhs);
    //Comparaison par rapport au caractère ASCII exemple : ! > space
    //ordre lexicographique
}

//1.10)
//      -strcpy:  copie une chaine de caractère dans une autre
//      -strncpy: Copie mais en donnant le nombre de char à copier et si le nb est
//                > au nb de char on rajoute des '\0'.
