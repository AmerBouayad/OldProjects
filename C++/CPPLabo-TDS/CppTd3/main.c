#include "td3.h"

int main(int argc, char *argv[])
{
    struct DLNode * prevDln = newDLN(5);
    struct DLNode * dln = newDLN(10);
    struct DLNode * nextDln = newDLN(20);
    struct DLNode * nextNextDln = newDLN(13);

    setPreviousDLN(dln, prevDln);
    setNextDLN(dln, nextDln);
    setNextDLN(nextDln, nextNextDln);

    printf("%d \n", getValueDLN(dln));
    setValueDLN(dln, 50);
    printf("%d \n", getValueDLN(dln));
    printf("%d %d %d\n", getValueDLN(dln->previous), getValueDLN(dln), getValueDLN(dln->next));

    printf("Exo 2 : %d \n", getValueDLN(backDLN(dln, 1)));
    if(backDLN(dln, 2) == NULL){
        printf("tu es nul\n");
        printf("%p\n", backDLN(dln, 2));
    }


    return 0;
}
