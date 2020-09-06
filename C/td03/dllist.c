#include "dllist.h"
#include <errno.h>
#include <stdlib.h>

struct DLList * newDLL()
{
    struct DLList * s;
    s = malloc(sizeof(struct DLList));
    if (s == NULL)
    {
        errno = EDLLMEMORYFAIL;
        return NULL;
    }
    s -> tail = NULL;
    s -> head = NULL;
    return s;
}
// TODO: check if everything is correctly freed.
void deleteDLL(struct DLList ** adpDLL)
{
    clearDLL(*adpDLL);
    free(*adpDLL);
    *adpDLL = NULL;
}

void clearDLL(struct DLList * pDLL)
{
    while (pDLL -> head != NULL)
    {
        removeHeadDLL(pDLL);
    }
}

struct DLNode * getHeadDLL(const struct DLList * pDLL)
{
    return pDLL -> head;
}

value_t getHeadValueDLL(const struct DLList * pDLL)
{
    if (pDLL -> head == NULL)
    {
        errno = EDLLEMPTY;
        value_t v;
        return v;
    }
    return pDLL -> head -> value; // /!\ null pointer dereference
}

struct DLNode * getTailDLL(const struct DLList * pDLL)
{
    return pDLL -> tail;
}

value_t getTailValueDLL(const struct DLList * pDLL)
{
    if (pDLL -> head == NULL)
    {
        errno = EDLLEMPTY;
        value_t v;
        return v;
    }
    return pDLL -> tail ->value; // /!\ null pointer dereference
}

bool isEmptyDLL(const struct DLList * pDLL)
{
    return pDLL -> head == NULL;
}

size_t getSizeDLL(const struct DLList * pDLL)
{
    if (isEmptyDLL(pDLL))
    {
        return 0;
    }
    struct DLNode * n;
    n = pDLL -> head;
    int len = 1;
    while (n != pDLL -> tail)
    {
        n = n -> next;
        len++;
    }
    return len;
}

struct DLNode * insertHeadDLL(struct DLList * pDLL, value_t value)
{
    struct DLNode * n;
    n = malloc(sizeof(struct DLNode));
    if (n == NULL)
    {
        errno = EDLLMEMORYFAIL;
        n = pDLL -> head;
    }
    else
    {
        n -> value = value;
        n -> previous = NULL;
        n -> next = pDLL -> head;
        if (pDLL -> head == NULL)
        {
            pDLL -> tail = n;
        }
        else
        {
            pDLL -> head -> previous = n;
        }
        pDLL -> head = n;
    }
    return n;
}

struct DLNode * removeHeadDLL(struct DLList * pDLL)
{
    if (pDLL -> head == NULL)
    {
        errno = EDLLEMPTY;
        return NULL;
    }
    if (pDLL -> head == pDLL ->
            tail) // if there's only one element we have to set the tail to NULL before freeing the head
    {
        pDLL -> tail = NULL;
    }
    struct DLNode * n;
    n = pDLL -> head -> next;
    if (n != NULL)
    {
        n -> previous = NULL;
    }
    deleteDLN(&(pDLL -> head));
    pDLL -> head = n;
    return n;
}

struct DLNode * insertTailDLL(struct DLList * pDLL, value_t value)
{
    struct DLNode * n;
    n = malloc(sizeof(struct DLNode));
    if (n == NULL)
    {
        errno = EDLLMEMORYFAIL;
        return pDLL -> tail;
    }
    n -> value = value;
    n -> next = NULL;
    n -> previous = pDLL -> tail;
    if (pDLL -> tail == NULL)
    {
        pDLL -> head = n;
    }
    else
    {
        pDLL -> tail -> next = n;
    }

    pDLL -> tail = n;
    return n;
}

struct DLNode * removeTailDLL(struct DLList * pDLL)
{
    if (pDLL -> tail == NULL)
    {
        errno = EDLLEMPTY;
        return NULL;
    }
    if (pDLL -> head == pDLL ->
            tail) // if there's only one element we have to set the head to NULL before freeing the tail
    {
        pDLL -> head = NULL;
    }
    struct DLNode * n;
    n = pDLL -> tail -> previous;
    if (n != NULL)
    {
        n -> next = NULL;
    }
    deleteDLN(&(pDLL -> tail));
    pDLL -> tail = n;
    return n;
}

struct DLNode * insertAfterDLL(struct DLList * pDLL,
                               struct DLNode * pDLN,
                               value_t newValue)
{
    if (pDLN == pDLL -> tail)
    {
        return insertTailDLL(pDLL, newValue);
    }
    else
    {
        struct DLNode * n;
        n = malloc(sizeof(struct DLNode));
        if (n == NULL)
        {
            errno = EDLLMEMORYFAIL;
            return pDLN;
        }
        n -> value = newValue;
        n -> next = pDLN -> next;
        n -> previous = pDLN;
        pDLN -> next = n;
        n -> next -> previous = n;
        return n;
    }
}

struct DLNode * insertBeforeDLL(struct DLList * pDLL,
                                struct DLNode * pDLN,
                                value_t newValue)
{
    if (pDLN == pDLL -> head)
    {
        return insertHeadDLL(pDLL, newValue);
    }
    else
    {
        struct DLNode * n;
        n = malloc(sizeof(struct DLNode));
        if (n == NULL)
        {
            errno = EDLLMEMORYFAIL;
            return pDLN;
        }
        n -> value = newValue;
        n -> next = pDLN;
        n -> previous = pDLN -> previous;
        pDLN -> previous = n;
        n -> previous -> next = n;
        return n;
    }
}

struct DLNode * removeDLL(struct DLList * pDLL, struct DLNode * pDLN)
{
    if (pDLL -> head == NULL)
    {
        return NULL;
    }
    struct DLNode * n;
    if (pDLN == pDLL -> head)
    {
        pDLL -> head = pDLN -> next;
        deleteDLN(&pDLN);
        n = pDLL -> head;
    }
    else if (pDLN == pDLL -> head)
    {
        pDLL -> tail = pDLN -> previous;
        deleteDLN(&pDLN);
        n = pDLL -> tail;
    }
    else
    {
        n = pDLN -> next;
        pDLN -> previous -> next = pDLN -> next;
        pDLN -> next -> previous = pDLN -> previous;
        deleteDLN(&pDLN);
    }
    return n;
}

// TODO: test everything
