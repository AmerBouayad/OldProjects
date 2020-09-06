#include "dlnode.h"
#include <errno.h>
#include <stddef.h>
#include <stdlib.h>

struct DLNode * newDLN(value_t value)
{
    struct DLNode * s = malloc(sizeof(struct DLNode));
    if (s == NULL)
    {
        errno = EDLNMEMORYFAIL;
        return NULL;
    }
    s -> previous = NULL;
    s -> next = NULL;
    s -> value = value;

    return s;
}
// TODO: check if everything has been freed correctly
void deleteDLN(struct DLNode ** adpDLN)
{
    free(*adpDLN);
    *adpDLN = NULL;
}

struct DLNode * getPreviousDLN(const struct DLNode * pDLN)
{
    return pDLN -> previous;
}

struct DLNode * getNextDLN(const struct DLNode * pDLN)
{
    return pDLN -> next;
}

value_t getValueDLN(const struct DLNode * pDLN)
{
    return pDLN -> value;
}

void setPreviousDLN(struct DLNode * pDLN,
                    struct DLNode * pNewPrevious)
{
    pDLN  -> previous = pNewPrevious;
}

void setNextDLN(struct DLNode * pDLN, struct DLNode * pNewNext)
{
    pDLN  -> next = pNewNext;
}

void setValueDLN(struct DLNode * pDLN, value_t newValue)
{
    pDLN -> value = newValue;
}
