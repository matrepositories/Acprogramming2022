#include "source.h"
#include <stdio.h>

/**
 * \brief Calculates the sum of integer elements in an array
 *
 * \param array An array of integers
 * \param count The number elements in the array
 * \return The sum of the elements
 */
int array_sum(int *array, int count)
{
    int i;
    int summ = 0;
    for(i = 0; i < count; i++)
    {
        summ = summ + array[i];
    }   
return summ;     
}


