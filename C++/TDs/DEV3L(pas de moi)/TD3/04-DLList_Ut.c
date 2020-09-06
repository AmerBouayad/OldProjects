#include "dllist_utlity.h"
#include "dllist.h"
#include "dlnode.h"


value_t * to_arrayDLL(size_t * size, const struct DLList * pDLL)
{
    if (pDLL == NULL)
    {
        *size = 0;
        return NULL;
    }
    else
    {
        struct DLNode node = getHeadDLL(pDLL);
        value_t * tableau = getValueDLN(node);
        *size = getSizeDLL(pDLL);
        for (unsigned i = 1 ; i < *size; ++i )
        {

        }


    }
    retunr tableau;
}

value_t * to_array_reverseDLL(size_t * size,
                              const struct DLList * pDLL);
struct DLList * reverseDLL(const struct DLList * pDLL);

void sortDLL(struct DLList * pDLL, int (* comp)(value_t, value_t),
             enum SortingMethod sm);

struct DLList * mergeDLL(const struct DLList * pDLL_l,
                         const struct DLList * pDLL_r,
                         int (* comp)(value_t, value_t));
