#include <td3.h>
#include <stdio.h>


int main()
{
    value_t value = 5;
    struct DLNode *dlnode =  newDLN(value);
    printf("%d, %p, %p ", dlnode->value, dlnode->next, dlnode->previous);
    printf("\n");
    deleteDLN(&dlnode);
    return 0;
}
