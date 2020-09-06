#ifndef ARRAY_H
#define ARRAY_H

void arrayIntPrint(const int data [], unsigned nbElem);
void arrayIntSort(int data [], unsigned nbElem, bool ascending);
void arraySortGeneric(int data [], unsigned nbElem, int (*comp)(const int *, const int *));
int compare_ints_ascending(const void* arg1, const void* arg2);
int compare_ints_descending(const void* arg1, const void* arg2);
int compare_ints_ascending_mod3(const void* arg1, const void* arg2);

#endif // ARRAY_H
