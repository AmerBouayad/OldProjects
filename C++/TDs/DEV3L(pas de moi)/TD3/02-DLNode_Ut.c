#include "dlnode.h"

struct DLNode * forwardDLN(struct DLNode * pDLN, int value)
{
    struct DLNode * current = pDLN;
    if (value < 0)
    {
        for (int i = -1; i >= value; i--)
        {
            current = getPreviousDLN(pDLN);
        }
    }
    else
    {
        for (int i = 1; i <= value; i++)
        {
            current = getNextDLN(pDLN);
        }
    }
    return current;
}

struct DLNode * backDLN(struct DLNode * pDLN, int value)
{
    return forwardDLN(pDLN, -value);
}
