
#include "source.h"
#include <stdio.h>
#include <stdlib.h>


/**
 * \brief Creates a dynamically allocated array and reads the specified number of
 *        integers from the standard input stream.
 *
 * \param n The number of integers to be read
 * \return A pointer to the allocated and filled array
 */

int *create_dyn_array(unsigned int n)
{
    int *array;
    array = (int*)calloc( n, n * sizeof(int));
    if (array == NULL)
    {
        return 0;
    }
    for (unsigned int i = 0; i < n; i++)
    {
        array[i] = n - i;
    }
    for (unsigned int k = 0; k < n; k++)
    {
        scanf("%d", &array[k]);
    }
    
    return array;
}

/**
 * \brief Appends a new element to the existing and dynamically allocated array
 *
 * \param arr The dynamically allocated array of num elements
 * \param num The number of elements in arr
 * \param newval The value of the new element that will be appended
 * \return A pointer to the resized array
 */
int *add_dyn_array(int *arr, unsigned int num, int newval)
{
    arr = realloc(arr, num * sizeof(int) + 1 * sizeof(int));
    arr[num] = newval; 
    return arr;
}
