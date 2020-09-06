
#include "value_t.h"
#include "dllist.h"
#include "dlnode.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

struct DLList * newDLL()
{
    struct DLList myStruct = {NULL, NULL};
    struct DLList * empM;
    empM = malloc(sizeof(struct DLList));
    if (empM == NULL)
    {
        errno = EDLNMEMORYFAIL;
    }
    *empM = myStruct;
    return empM;
}

void deleteDLL(struct DLList * * adpDLL)
{
    clearDLL(*adpDLL);
    free( *adpDLL );
    *adpDLL == NULL;
}


void clearDLL(struct DLList * pDLL)
{
    for (unsigned i = 0; i < getSizeDLL(pDLL); ++i)
    {
        removeHeadDLL(pDLL);
    }

}

struct DLNode * getHeadDLL(const struct DLList * pDLL)
{
    return pDLL->head;
}


value_t getHeadValueDLL(const struct DLList * pDLL)
{
    if (isEmptyDLL(pDLL))
    {
        errno = EDLLEMPTY;
    }
    return pDLL->head->value;
}
struct DLNode * getTailDLL(const struct DLList * pDLL)
{
    return pDLL->tail;
}

value_t getTailValueDLL(const struct DLList * pDLL)
{
    return pDLL->tail->value;
}

bool isEmptyDLL(const struct DLList * pDLL)
{
    return pDLL->head == NULL;
}

size_t getSizeDLL(const struct DLList * pDLL)
{
    struct DLNode * current = getHeadDLL(pDLL);
    size_t cpt = 0;
    while (current != NULL)
    {
        cpt++;
        current = current->next;
    }
    return cpt;
}

struct DLNode * insertHeadDLL(struct DLList * pDLL, value_t value)
{
    //ajouter tail nouveau
    struct DLNode * node = newDLN(value);
    if (pDLL->head != NULL)
    {
        setNextDLN(node, pDLL->head);
        pDLL->head->previous = node;
        if (pDLL->tail == NULL)
        {
            pDLL->tail = node;
        }
    }
    pDLL->head = node;
    return node;
}

struct DLNode * removeHeadDLL(struct DLList * pDLL)
{
    //traiter liste vide
    if (isEmptyDLL(pDLL))
    {
        errno = EDLLEMPTY;
    }
    struct DLNode * node = getHeadDLL(pDLL)->next;
    struct DLNode * head = getHeadDLL(pDLL);
    deleteDLN(&head);
    if (node == NULL)
    {
        pDLL->tail = NULL;
        pDLL->head = NULL;
        return NULL;
    }
    pDLL->head = node;
    return node;
}

struct DLNode * insertTailDLL(struct DLList * pDLL, value_t value)
{
    struct DLNode * nodeFinal = newDLN(value);
    if (nodeFinal == NULL)
    {
        errno = EDLLMEMORYFAIL;
    }
    setPreviousDLN(nodeFinal, getTailDLL(pDLL));
    setNextDLN(getTailDLL(pDLL), nodeFinal);
    pDLL->tail = nodeFinal;
    return pDLL->tail;
}



struct DLNode * removeTailDLL(struct DLList * pDLL)
{
    if (isEmptyDLL(pDLL))
    {
        errno = EDLLEMPTY;
    }
    struct DLNode * nodeFinal = getPreviousDLN(pDLL->tail);
    setNextDLN(nodeFinal, NULL);
    deleteDLN(&(pDLL->tail));
    pDLL->tail = nodeFinal;
    return pDLL->tail;
}

struct DLNode * insertAfterDLL(struct DLList * pDLL,
                               struct DLNode * pDLN,
                               value_t newValue)
{
    if (getSizeDLL(pDLL) == 0)
    {
        return pDLN;
    }
    struct DLNode * aAjouter = newDLN(newValue);
    if (aAjouter == NULL)
    {
        errno = EDLNMEMORYFAIL;
    }
    if (pDLL->tail == pDLN)
    {
        setNextDLN(pDLN, aAjouter);
        setPreviousDLN(aAjouter, pDLN);
        pDLL->tail = pDLN;
    }
    else
    {
        setNextDLN(aAjouter, getNextDLN(pDLN));
        setPreviousDLN(getNextDLN(pDLN), aAjouter);
        setNextDLN(pDLN, aAjouter);
        setPreviousDLN(aAjouter, pDLN);
    }
    return aAjouter;
}

struct DLNode * insertBeforeDLL(struct DLList * pDLL,
                                struct DLNode * pDLN,
                                value_t newValue)
{
    if (getSizeDLL(pDLL) == 0)
    {
        return pDLN;
    }

    struct DLNode * aAjouter = newDLN(newValue);

    if (aAjouter == NULL)
    {
        errno = EDLNMEMORYFAIL;
    }
    if (pDLL->head == pDLN)
    {
        setNextDLN(aAjouter, pDLN);
        setPreviousDLN( pDLN, aAjouter);
        pDLL->head = pDLN;
    }
    else
    {
        setPreviousDLN(aAjouter, getPreviousDLN(pDLN));
        setNextDLN(getPreviousDLN(pDLN), aAjouter);
        setNextDLN(aAjouter, pDLN);
        setPreviousDLN( pDLN, aAjouter);
    }
    return aAjouter;
}

struct DLNode * removeDLL(struct DLList * pDLL,
                          struct DLNode * pDLN)
{
    if (isEmptyDLL(pDLL))
    {
        return NULL;
    }
    struct DLNode * toRet = pDLN;
    if (pDLL->head == pDLN)
    {
        pDLL->head = pDLN->next;
        setPreviousDLN(pDLL->head, NULL);
    }
    else
    {
        setPreviousDLN(pDLN->previous->next, pDLN->next);
    }

    if (pDLL->tail == pDLN)
    {
        pDLL->tail = pDLN->previous;
        setNextDLN(pDLL->tail, NULL);
    }
    else
    {
        setNextDLN(pDLN->next->previous, pDLN->previous);
    }

    return toRet;
}



















