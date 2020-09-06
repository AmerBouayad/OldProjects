#include "td3.h"
#include <errno.h>
//exo 1
struct DLNode * newDLN(value_t value){
   struct DLNode * dln = malloc(sizeof(struct DLNode));
   if (dln == NULL)
   {
       errno = EDLNMEMORYFAIL;
       return dln;
   }
   dln->next = NULL;
   dln->previous = NULL;
   dln->value = value;
   return dln;

}

void deleteDLN(struct DLNode * * adpDLN){
    free(*adpDLN);
    *adpDLN = NULL;
}

struct DLNode * getPreviousDLN(const struct DLNode * pDLN){
    return pDLN->previous;
}

struct DLNode * getNextDLN(const struct DLNode * pDLN){
    return pDLN->next;
}

value_t getValueDLN(const struct DLNode * pDLN){
    return pDLN->value;
}

void setPreviousDLN(struct DLNode * pDLN,struct DLNode * pNewPrevious){
    pDLN->previous = pNewPrevious;
}

void setNextDLN(struct DLNode * pDLN, struct DLNode * pNewNext){
    pDLN->next = pNewNext;
}

void setValueDLN(struct DLNode * pDLN, value_t newValue){
    pDLN->value = newValue;
}

//exo 2
struct DLNode * forwardDLN(struct DLNode * pDLN, int value){
    struct DLNode * dln = pDLN;
    if(value > 0){
        for(int i = 0; i < value; i++){
            dln = getNextDLN(dln);
        }
    }
    if(value < 0){
        for(int i = 0; i > value; i--){
            dln = getPreviousDLN(dln);
        }
    }
    return dln;
}

struct DLNode * backDLN(struct DLNode * pDLN, int value){
    struct DLNode * dln = pDLN;
    if(value < 0){
        for(int i = 0; i > value; i--){
            dln = getNextDLN(dln);
        }
    }
    if(value > 0){
        for(int i = 0; i < value; i++){
            dln = getPreviousDLN(dln);
        }
    }
    return dln;
}

