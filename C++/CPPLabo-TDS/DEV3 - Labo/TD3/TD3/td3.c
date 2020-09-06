 #include <td3.h>
#include <errno.h>

struct DLNode * newDLN(value_t value){

    struct DLNode *dlnode = malloc(sizeof(value_t));
    if (dlnode == NULL) {
        errno = EDLNMEMORYFAIL;
        return NULL;
    }
    dlnode->value = value;
    dlnode->next = NULL;
    dlnode->previous = NULL;
    return dlnode;
}
void deleteDLN(struct DLNode **adpDLN){

    free(adpDLN);
}

struct DLNode * getPreviousDLN(const struct DLNode * pDLN){
    return pDLN->previous;
}

struct DLNode * getNextDLN(const struct DLNode * pDLN){
    return pDLN->next;
}

value_t getValueDLN(const struct DLNode * pDLN){
    return pDLN->value;
}

void setPreviousDLN(struct DLNode * pDLN, struct DLNode * pNewPrevious){
    pDLN->previous = pNewPrevious;
}

void setNextDLN(struct DLNode * pDLN, struct DLNode * pNewNext){
    pDLN->next = pNewNext;
}

void setValueDLN(struct DLNode * pDLN, value_t newValue){
    pDLN->value = newValue;
}

struct DLNode * forwardDLN(struct DLNode * pDLN, int value){
    struct DLNode * myDLN;
    int i = 0;
    if (value > 0){
        while(i<value) {
            myDLN = pDLN->next;
            i++;
        }
    }
    if (value < 0){
        while(i>value) {
            myDLN = pDLN->previous;
            i--;
        }
    }
    return myDLN;
}
struct DLNode * previousDLN(struct DLNode * pDLN, int value){
    struct DLNode * myDLN;
    int i = 0;
    if (value > 0){
        while(i<value) {
            myDLN = pDLN->previous;
            i++;
        }
    }
    if (value < 0){
        while(i>value) {
            myDLN = pDLN->next;
            i--;
        }
    }
    return myDLN;
}

struct DLList * newDLL(){
    struct DLList * myDLList = malloc(0);
    myDLList->head = NULL;
    myDLList->tail = NULL;
    if (myDLList == NULL){
        errno = EDLLMEMORYFAIL;
        return NULL;
    }
    return myDLList;

}

void deleteDLL(struct DLList * * adpDLL){
    if((*adpDLL)->head != NULL) {
        free((*adpDLL)->head);
    }
    if((*adpDLL)->tail != NULL) {
        free((*adpDLL)->tail);
    }
    free(adpDLL);
    *(adpDLL) = NULL;
}

void clearDLL(struct DLList * pDLL){
    //if(*(pDLL)->head != NULL) {
    if ((pDLL)->head != NULL){
        free((pDLL)->head);
    }
    if((pDLL)->tail != NULL) {
        free((pDLL)->tail);
    }
    (pDLL) = NULL;
}

struct DLNode * getHeadDLL(const struct DLList * pDLL){
    if((pDLL) == NULL){
        return NULL;
    }
    return (pDLL)->head;
}

value_t getHeadValueDLL(const struct DLList * pDLL){
    if (pDLL == NULL){
        errno = EDLLEMPTY;
    }
    value_t value = pDLL->head->value;
    return value;
}

struct DLNode * getTailDLL(const struct DLList * pDLL){
    if((pDLL) == NULL){
        return NULL;
    }
    return (pDLL)->tail;
}

value_t getTailValueDLL(const struct DLList * pDLL){
    if (pDLL == NULL){
        errno = EDLLEMPTY;
    }
    value_t value = pDLL->tail->value;
    return value;
}

bool isEmptyDLL(const struct DLList * pDLL){
    return ((pDLL)->head == NULL && (pDLL)->tail == NULL);
}

size_t getSizeDLL(const struct DLList * pDLL){
    int cpt = 0;
    const struct DLNode *myDLNode = (pDLL->head);
    while(myDLNode != NULL){
        cpt++;
        myDLNode = myDLNode->next;
    }
    return cpt;
}

struct DLNode * insertHeadDLL(struct DLList * pDLL, value_t value){
    struct DLNode * myDLNode = newDLN(value);
    if(myDLNode == NULL){
        return pDLL->head;
    }else {
        myDLNode->next = (pDLL)->head;
        pDLL->head->previous = myDLNode;
        pDLL->head = myDLNode;
        return myDLNode;
    }
}

struct DLNode * removeHeadDLL(struct DLList * pDLL){
    if (pDLL->head == NULL)
            return NULL;

        struct DLNode * adpDLN = pDLL->head;
        pDLL->head = adpDLN->next;
        deleteDLN(&adpDLN);
        return adpDLN;
}

struct DLNode * insertTailDLL(struct DLList * pDLL, value_t value){
    struct DLNode * newNode = newDLN(value);
        if (newNode == NULL){
            return pDLL->tail;
        }else{
            newNode->previous = pDLL->tail;
            if (pDLL->tail != NULL){
                pDLL->tail->next = newNode;
                newNode->previous = pDLL->tail;
            }else{
                pDLL->head = newNode;
                pDLL->tail = newNode;
                return newNode;
            }
       }
       return NULL;
}

struct DLNode * removeTailDLL(struct DLList * pDLL){
    if (pDLL->head == NULL){
            return NULL;
    }
        struct DLNode * adpDLN = pDLL->tail;
        pDLL->tail = adpDLN->previous;
        deleteDLN(&adpDLN);
        return pDLL->tail;
}

struct DLNode * insertAfterDLL(struct DLList * pDLL, struct DLNode * pDLN, value_t newValue){
    struct DLNode * newNode = newDLN(newValue);
        if (newNode == NULL)
            return newNode;

        newNode->next = pDLN->next;
        newNode->previous = pDLN;
        pDLN->next = newNode;
        pDLL = pDLL;

        return newNode;
}

struct DLNode * insertBeforeDLL(struct DLList * pDLL, struct DLNode * pDLN, value_t newValue){
    struct DLNode * newNode = newDLN(newValue);
    if (newNode == NULL)
       return newNode;

       newNode->previous = pDLN->previous;
       newNode->next = pDLN;
       pDLN->previous = newNode;

       // unused parameter warning (design choice)
       pDLL = pDLL;

       return newNode;
}

struct DLNode * removeDLL(struct DLList * pDLL, struct DLNode * pDLN){
    if (pDLL->head == NULL) // one less call
            return NULL;

        struct DLNode * filler = pDLN->next;
        pDLN->previous->next = pDLN->next;
        pDLN->next->previous = pDLN->previous;

        deleteDLN(&pDLN);

        return filler;
}

value_t * to_arrayDLL(size_t * size, const struct DLList * pDLL){
    value_t * tab = malloc(*size * sizeof(value_t));
    if (pDLL == NULL){
        *size = 0;
        return NULL;
    }
    struct DLNode * newNode = newDLN(getHeadValueDLL(pDLL));
    for (unsigned int i = 0; i< *size; i++){
        if (newNode == NULL){
            errno = EDLLMEMORYFAIL;
            return NULL;
        }else {
            tab[i] = newNode->value;
            newNode = getNextDLN(newNode);
        }
    }
    return tab;
}

value_t * to_array_reverseDLL(size_t * size, const struct DLList * pDLL){
    value_t * tab = malloc(*size * sizeof(value_t));
    if (pDLL == NULL){
        *size = 0;
        return NULL;
    }
    struct DLNode * newNode = newDLN(getTailValueDLL(pDLL));
    for (unsigned int i = *size; i>0; i--){
        if (newNode == NULL){
            errno = EDLLMEMORYFAIL;
            return NULL;
        }else {
            tab[i] = newNode->value;
            newNode = getPreviousDLN(newNode);
        }
    }
    return tab;
}

struct DLList * reverseDLL(const struct DLList * pDLL){
    unsigned int size = getSizeDLL(pDLL);
    value_t *tab = to_array_reverseDLL(&size, pDLL);
    struct DLList *reverseList = malloc(size * sizeof(value_t));
    if (reverseList == NULL) {
        errno = EDLLMEMORYFAIL;
        return NULL;
    }
    for (unsigned int i = 1; i <=size+1; i++){
        struct DLNode *newDLNode = newDLN(tab[i]);
        if ((i =1)){
            reverseList->head = newDLNode;
        } else if (i<1 && i>= size){
            newDLNode->previous = newDLN(tab[i-1]);
            newDLNode->next = newDLN(tab[i+1]);
        } else {
            newDLNode->previous = newDLN(tab[i-1]);
        }
    }
    return reverseList;
}
/*
* \brief Tri d’une liste.
 *
 * Si ‘pDLL‘ ou ‘comp‘ sont ‘NULL‘, le comportement de la fonction
 * est indéterminé.
 *
 * La fonction ‘comp‘ définit l’ordre des éléménents de la liste
 * triée comme la fonction d’ordre utilisée par la fonction standard
 * [qsort](http://en.cppreference.com/w/c/algorithm/qsort).
 *
 * Il est possible de choisir le type de tri :
 * + avec ‘sm‘ valant ::SORT_BY_CHANGING_LINK, le maillage des
 * éléments de la liste est modifié, mais les valeurs contenues
 * par les éléments ne sont pas modifiées ;
 * + avec ‘sm‘ valant ::SORT_BY_CHANGING_VALUE, les valeurs
 * contenues dans les éléments sont modifiées, mais le maillage
 * des éléments de la liste n’est pas modifié.
 *
 * \param pDLL adresse de la liste à trier.
 * \param comp fonction d’ordre utilisée pour ordonner les éléments
 * de la liste.
 * \param sm choix du type de tri.
 */
 void sortDLL(struct DLList * pDLL, int (* comp)(value_t, value_t), enum SortingMethod sm){

 }
