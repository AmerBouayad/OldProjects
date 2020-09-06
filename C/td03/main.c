#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dllist.h"
#include "dllist_utility.h"

void printDLL(struct DLList * list)
{
    struct DLNode * n;
    n = list -> head;
    printf("Head: %d\n", n -> value);
    printf("Tail: %d\n Complete List: \n", list -> tail -> value);

    while (n != NULL)
    {
        printf(" %d ", n ->value);
        n = n -> next;
    }
    printf("\n");
}

int int_comparator (value_t a, value_t b)
{
    a = (int) a;
    b = (int) b;
    if (a < b)
    {
        return -1;
    }
    else if (a > b)
    {
        return 1;
    }
    return 0;
}

void newTestList(struct DLList ** list)
{
    if (*list)
    {
        deleteDLL(list);
    }
    *list = newDLL();
    insertHeadDLL(*list, 1);
    insertHeadDLL(*list, -5);
    insertHeadDLL(*list, 42);
    insertHeadDLL(*list, 0);
    insertHeadDLL(*list, 14);
    insertHeadDLL(*list, -1);
    insertHeadDLL(*list, 20);
}

// creates a new list of 10 random elements with values between 0-99.
// Be carefull to give a random seed if you want random values.
// If the list exists, it's deleted first.
void newRandomList10(struct DLList ** list, int seed)
{
    if (*list)
    {
        deleteDLL(list);
    }
    srand(seed);
    *list = newDLL();
    for (int i = 0; i < 10; ++i)
    {
        insertHeadDLL(*list, rand() % 100);
    }
}

void testToArrayDLL(struct DLList * list)
{
    size_t size;
    value_t * array = to_arrayDLL(&size, list);
    printf("Linked list:\n");
    printDLL(list);
    printf("Array:\n");
    for (size_t i = 0; i < size; ++i)
    {
        printf(" %d ", array[i]);
    }
    printf("\n");
    free(array);
}

void testToArrayReverseDLL(struct DLList * list)
{
    size_t size;
    value_t * array = to_array_reverseDLL(&size, list);
    printf("Linked list:\n");
    printDLL(list);
    printf("Reversed array:\n");
    for (size_t i = 0; i < size; ++i)
    {
        printf(" %d ", array[i]);
    }
    printf("\n\n");
    free(array);
}

void testgetHeadTailValueDLL_NULL(){
    printf("testgetHeadTailValueDLL_NULL\n");
    struct DLList *l = newDLL();
    printf("La liste est vide. Valeur de la tête: %d\n", getHeadValueDLL(l));
    printf("La liste est vide. Valeur de la queue: %d\n", getTailValueDLL(l));
    printf("\n");
    deleteDLL(&l);
}

int main()
{
    struct DLList * list = NULL;
    newTestList(&list);
    printf("liste de départ:\n");
    printDLL(list);

    printf("list after sorting by changing values:\n");
    sortDLL(list, int_comparator,
            SORT_BY_CHANGING_VALUE);
    printDLL(list);

    newTestList(&list);
    printf("list after sorting by changing links:\n");
    sortDLL(list, int_comparator,
            SORT_BY_CHANGING_LINK);
    printDLL(list);
    printf("\n\n");


    struct DLList * list2 = NULL;
    newRandomList10(&list2, 42);
    printf("Unsorted list2: \n");
    printDLL(list2);
    sortDLL(list2, int_comparator, SORT_BY_CHANGING_LINK);
    printf("Merging list1: \n");
    printDLL(list);
    printf("and list2:\n");
    printDLL(list2);
    struct DLList * merged = mergeDLL(list, list2, int_comparator);
    printf("Merged list: \n");
    printDLL(merged);
    printf("\n\n");

    testToArrayDLL(list);
    testToArrayReverseDLL(list);
    testgetHeadTailValueDLL_NULL();

    deleteDLL(&list);
    deleteDLL(&list2);
    deleteDLL(&merged);
}


// TODO: check and fix "still reachable allocations"
