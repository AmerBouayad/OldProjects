#include <charactere.h>

int nbChar(const char c[]){
    //compte les espaces
    return strlen(c);
}

void compareChar(const char *lhs, const char *rhs){

    int comp = strcmp(lhs,rhs);
    if(comp ==0)
        printf("%s est egal a %s \n", lhs, rhs);
    else if (comp<0)
        printf("%s est plus petit que %s \n", lhs,rhs);
    else
        printf("%s est plus grand que %s \n", lhs, rhs);
}

void copyChar(char *str1, char *str2){
    strcpy(str2,str1);
    printf("%s \n", str2);
}
