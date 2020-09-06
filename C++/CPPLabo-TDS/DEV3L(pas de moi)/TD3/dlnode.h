#ifndef DLNODE_H
#define DLNODE_H

#include "value_t.h"


enum DLNError
{
    EDLNMEMORYFAIL = 50
}DLNError;
struct DLNode
{
    struct DLNode * previous;
    struct DLNode * next;
    value_t     value;
}DLNode ;


struct DLNode * newDLN(value_t value);


void deleteDLN(struct DLNode * * adpDLN);


struct DLNode * getPreviousDLN(const struct DLNode * pDLN);


struct DLNode * getNextDLN(const struct DLNode * pDLN);

value_t getValueDLN(const struct DLNode * pDLN);

void setPreviousDLN(struct DLNode * pDLN,
                    struct DLNode * pNewPrevious);

void setNextDLN(struct DLNode * pDLN, struct DLNode * pNewNext);

void setValueDLN(struct DLNode * pDLN, value_t newValue);

#endif // DLNODE_H

