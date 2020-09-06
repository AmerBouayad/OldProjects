#ifndef TD3_H
#define TD3_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//exo 1
typedef int value_t;

enum DLNError
{
    EDLNMEMORYFAIL = 50
}DLNError;

struct DLNode
{
struct DLNode * previous;
struct DLNode * next;
value_t value;
};

struct DLNode * newDLN(value_t value);

void deleteDLN(struct DLNode * * adpDLN);

struct DLNode * getPreviousDLN(const struct DLNode * pDLN);

struct DLNode * getNextDLN(const struct DLNode * pDLN);

value_t getValueDLN(const struct DLNode * pDLN);

void setPreviousDLN(struct DLNode * pDLN,struct DLNode * pNewPrevious);

void setNextDLN(struct DLNode * pDLN, struct DLNode * pNewNext);

void setValueDLN(struct DLNode * pDLN, value_t newValue);

//exo 2
struct DLNode * forwardDLN(struct DLNode * pDLN, int value);

struct DLNode * backDLN(struct DLNode * pDLN, int value);

//exo 3
struct DLList
{
struct DLNode * head;
struct DLNode * tail;
};

struct DLList * newDLL();
void deleteDLL(struct DLList * * adpDLL);
void clearDLL(struct DLList * pDLL);
struct DLNode * getHeadDLL(const struct DLList * pDLL);
value_t getHeadValueDLL(const struct DLList * pDLL);
struct DLNode * getTailDLL(const struct DLList * pDLL);
value_t getTailValueDLL(const struct DLList * pDLL);
bool isEmptyDLL(const struct DLList * pDLL);
size_t getSizeDLL(const struct DLList * pDLL);
struct DLNode * insertHeadDLL(struct DLList * pDLL, value_t value);
struct DLNode * removeHeadDLL(struct DLList * pDLL);
struct DLNode * insertTailDLL(struct DLList * pDLL, value_t value);
struct DLNode * removeTailDLL(struct DLList * pDLL);
struct DLNode * insertAfterDLL(struct DLList * pDLL,
struct DLNode * pDLN,
value_t newValue);
struct DLNode * insertBeforeDLL(struct DLList * pDLL,
struct DLNode * pDLN,
value_t newValue);
struct DLNode * removeDLL(struct DLList * pDLL,
struct DLNode * pDLN);

#endif // TD3_H
