
#include "source.h"
#include "stdlib.h"


int compare_ascending(const void *p1, const void *p2)
{
    int P1 = *(int *)p1;
    int P2 = *(int *)p2;
    return P1 - P2;
}


void sort(int *array, int size)
{
    qsort(array, size, sizeof(int), compare_ascending);
}
