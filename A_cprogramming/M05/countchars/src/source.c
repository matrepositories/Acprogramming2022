#include <stdio.h>

/**
 * \brief Counts the number of occurrences of characters in an array
 *
 * \param array A zero (0) terminated string that is composed some number of characters
 * \param counts An int array of 256 elements that contains number of character occurrences.
 */

void countchars(const char *array, unsigned int *counts)
{
    const char *p; 
    for(p = &array[0]; *p != 0; p++)
    {
        counts[(int) *p]++;  
    }
}

/*int main(void)
{
unsigned int counts[256] = { 0 };
counts[(int) 'A'] += 5; //(int) on castaus int 'A' yrittää luoda uutta muuttujaa
printf("a occurred %d times\n", counts[(int)'A']); //counts kohdassa A
}*/
