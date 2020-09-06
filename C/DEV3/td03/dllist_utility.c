#include "dllist_utility.h"
#include "dllist.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>

value_t * to_arrayDLL(size_t * size, const struct DLList * pDLL)
{
    *size = 0;
    if (isEmptyDLL(pDLL))
    {
        return NULL;
    }
    struct DLNode * n;
    n = pDLL -> head;
    while (n != NULL)
    {
        (*size)++;
        n = n-> next;
    }
    value_t * tmp, *array;
    array = malloc(*size * sizeof(value_t));
    tmp = array;
    if (tmp == NULL)
    {
        errno = EDLLMEMORYFAIL;
        return NULL;
    }
    n = pDLL -> head;
    while (n != NULL)
    {
        *tmp = n -> value;
        n = n-> next;
        tmp++;
    }
    return array;
}

value_t * to_array_reverseDLL(size_t * size,
                              const struct DLList * pDLL)
{
    *size = 0;
    if (isEmptyDLL(pDLL))
    {
        return NULL;
    }
    struct DLNode * n;
    n = pDLL -> tail;
    while (n != NULL)
    {
        (*size)++;
        n = n-> previous;
    }
    value_t  * tmp, *array;
    array = malloc(*size * sizeof(value_t));
    tmp = array;
    if (tmp == NULL)
    {
        errno = EDLLMEMORYFAIL;
        return NULL;
    }
    n = pDLL -> tail;
    while (n != NULL)
    {
        *tmp = n ->value
               ;
        n = n-> previous;
        tmp++;
    }
    return array;
}

struct DLList * reverseDLL(const struct DLList * pDLL)
{
    if (isEmptyDLL(pDLL))
    {
        return NULL;
    }

    struct DLList * l;
    l = newDLL();
    if (l == NULL)
    {
        errno = EDLLMEMORYFAIL;
        return NULL;
    }

    struct DLNode * n;
    n = pDLL -> head;
    while (n != NULL)
    {
        insertHeadDLL(l, n->value);
        n = n-> next;
    }
    return l;
}

// TODO: all the following "private" methods should be in the header as well:

// finds the minimum from node a
struct DLNode * find_min(struct DLNode * a, int (*comp)(value_t,
                         value_t))
{
    struct DLNode * min;
    min = a;
    while ( a != NULL)
    {
        if (comp (a -> value, min -> value) < 0 )
            min = a;
        a = a -> next;
    }
    return min;
}

// set the next node from a to be b, and the previous from b to be a. Handles NULLs
void setNext(struct DLList * l, struct DLNode * a, struct DLNode * b)
{
    if (a != NULL)
        a -> next = b;
    else
        l -> head = b; // a is null, b is the new head
    if (b != NULL)
        b -> previous = a;
    else
        l -> tail = a; // b is null, a is the new tail;
}

// set the previous node from a to be b, and the next from b to be a. Handles NULLs
void setPrevious(struct DLList * l, struct DLNode * a,
                 struct DLNode * b)
{
    if (a != NULL)
        a -> previous = b;
    else
        l -> tail = b; // a is null, b is the new tail
    if (b != NULL)
        b -> next = a;
    else
        l -> head = a; // b is null, a is the new head
}

void swap(struct DLList * l, struct DLNode * a, struct DLNode * b)
{
    struct DLNode * tmp;
    tmp = a -> next;
    setNext(l, a, b -> next);
    setNext(l, b, tmp); // maybe b itself if they're adjacents

    tmp = a -> previous;
    setPrevious(l, a, b -> previous); // maybe a itself if adjacents
    setPrevious(l, b, tmp);

    // b->next will be fixed here if they're adjacent:
    setNext(l, a -> previous, a);
    setNext(l, b -> previous, b);
    setPrevious(l, a -> next, a);
    // a->previous will be fixed here if they're adjacent:
    setPrevious(l, b -> next, b);
}

void swap_values(struct DLNode * a, struct DLNode * b)
{
    value_t tmp;
    tmp = a-> value;
    a -> value = b -> value;
    b -> value = tmp;
}

// sort a doubly linked list with a selection sort by modifying links
void sort_link(struct DLList * pDLL, int (*comp)(value_t, value_t))
{
    struct DLNode * n, *min;
    n = pDLL -> head;
    while (n != NULL)
    {
        min = find_min(n, comp); // finding the minimum from n
        if (min != n)
        {
            swap(pDLL, min, n);
            n = min -> next;
        }
        else
            n = n -> next;
    }
}

// sort a doubly linked list with a bubble sort by modifying values
void sort_value(struct DLList * pDLL, int (*comp)(value_t, value_t))
{
    bool swapped;
    struct DLNode * n, *o;
    n = pDLL ->head;

    do
    {
        swapped = false;
        if (n != NULL)
            o = n -> next;
        else
            o = NULL;
        while (o != NULL)
        {
            if (comp(n->value, o->value) > 0)
            {
                swap_values(n, o);
                swapped = true;
            }
            n = n -> next;
            o = n -> next;

        }
        n = pDLL -> head;

    }
    while (swapped);
}

void sortDLL(struct DLList * pDLL, int (*comp)(value_t, value_t),
             enum SortingMethod sm)
{
    if (sm == SORT_BY_CHANGING_LINK)
    {
        sort_link(pDLL, comp);
    }
    else
    {
        sort_value(pDLL, comp);
    }
}

struct DLList * mergeDLL(const struct DLList * pDLL_l,
                         const struct DLList * pDLL_r, int (*comp)(value_t, value_t))
{
    struct DLList * list = newDLL();
    if (! list)
        return NULL;
    struct DLNode * l, *r;
    l = pDLL_l -> head;
    r = pDLL_r -> head;
    while (l != NULL && r != NULL)
    {
        if (comp(l -> value, r -> value) < 0)
        {
            insertTailDLL(list, l -> value);
            l = l -> next;
        }
        else
        {
            insertTailDLL(list, r -> value);
            r = r -> next;
        }
    }
    while (l != NULL)
    {
        insertTailDLL(list, l -> value);
        l = l -> next;
    }
    while (r != NULL)
    {
        insertTailDLL(list, r -> value);
        r = r -> next;
    }
    return list;
}
