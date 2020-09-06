#include <stdio.h>
#include <stdbool.h>

void arrayIntPrint(const int data[], unsigned nbElem)
{
    for (int i = 0; i < nbElem; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}

// sorts an array with a bubble sort
void arrayIntSort(int data[], unsigned nbElem, bool ascending)
{
    for (int i = 0; i < nbElem - 1; i++) {
        for (int j = nbElem - 1; j > 0 ; j--) {
            if (ascending == true) {
                if (data[j] < data[j-1]) {
                    int tmp = data[j];
                    data[j] = data[j-1];
                    data[j-1] = tmp;
                }
            } else {
                if (data[j] > data[j-1]) {
                    int tmp = data[j];
                    data[j] = data[j-1];
                    data[j-1] = tmp;
                }
            }

        }

    }
}

// TODO: est-on supposé déjà comprendre ça ? :
int compare_ints_ascending(const void *arg1, const void *arg2)
{
    int a = *(const int*)arg1;
    int b = *(const int*)arg2;
    if (a > b)
        return 1;
    if (a < b)
        return -1;
    return 0;
}

int compare_ints_descending(const void *arg1, const void *arg2)
{
    int a = *(const int*)arg1;
    int b = *(const int*)arg2;
    if (a > b)
        return -1;
    if (a < b)
        return 1;
    return 0;
}

int compare_ints_ascending_mod3(const void *arg1, const void *arg2)
{
    int a = *(const int*)arg1;
    int b = *(const int*)arg2;
    if ((a % 3) > (b % 3))
        return 1;
    if ((a % 3) < (b % 3))
        return -1;
    return 0;
}

// sorts an array with a bubble sort, using the comparator "comp"
void arraySortGeneric(int data[], unsigned nbElem, int (*comp)(const int *, const int *))
{
    for (int i = 0; i < nbElem - 1; i++) {
        for (int j = nbElem - 1; j > 0 ; j--) {
            if (comp(&data[j], &data[j-1]) < 0) {
                int tmp = data[j];
                data[j] = data[j-1];
                data[j-1] = tmp;
            }
        }

    }

}
