#include "value_t.h"
#include "dlnode.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>


struct DLNode * newDLN(value_t value)
{
    struct DLNode myStruct;
    myStruct.next = NULL;
    myStruct.previous = NULL;
    myStruct.value = value;
    struct DLNode * empM;
    empM = malloc(sizeof(struct DLNode));
    if (empM == NULL)
    {
        errno = EDLNMEMORYFAIL;
    }
    empM[0] = myStruct;
    return empM;

}

void deleteDLN(struct DLNode * * adpDLN)
{
    free(*adpDLN);
    *adpDLN = NULL;
}
struct DLNode * getPreviousDLN(const struct DLNode * pDLN)
{
    return pDLN->previous;
}
struct DLNode * getNextDLN(const struct DLNode * pDLN)
{
    return pDLN->next;
}
value_t getValueDLN(const struct DLNode * pDLN)
{
    return pDLN->value;
}

void setPreviousDLN(struct DLNode * pDLN,
                    struct DLNode * pNewPrevious)
{
    pDLN->previous = pNewPrevious;
}

void setNextDLN(struct DLNode * pDLN, struct DLNode * pNewNext)
{
    pDLN->next = pNewNext;
}
void setValueDLN(struct DLNode * pDLN, value_t newValue)
{
    pDLN->value = newValue;
}
