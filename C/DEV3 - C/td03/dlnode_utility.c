#include "dlnode_utility.h"
#include <stddef.h>

struct DLNode * forwardDLN(struct DLNode * pDLN, int value)
{
    if (value >= 0)
    {
        while (pDLN != NULL && value > 0)
        {
            pDLN = pDLN -> next;
            value --;
        }
    }
    else
    {
        while (pDLN != NULL && value < 0)
        {
            pDLN = pDLN -> previous;
            value++;
        }
    }
    return pDLN;
}

struct DLNode * backDLN(struct DLNode * pDLN, int value)
{
    if (value >= 0)
    {
        while (pDLN != NULL && value > 0)
        {
            pDLN = pDLN -> previous;
            value --;
        }
    }
    else
    {
        while (pDLN != NULL && value < 0)
        {
            pDLN = pDLN -> next;
            value++;
        }
    }
    return pDLN;
}
