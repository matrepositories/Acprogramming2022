#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
 * \brief Compares two integers and returns their comparison result.
 * \details This function defines the order of the elements by 
 *          returning (in a stable and transitive manner): 
 *          <0	The value pointed to by 'a' goes before the value pointed to by 'b'
 *           0	The value pointed to by 'a' is equivalent to the value pointed to by 'b'
 *          >0	The value pointed to by 'a' goes after the value pointed to by 'b'
 * 
 *          In other words, this function essentially calculates the difference
 *          of the values pointed by its arguments.
 * 
 * \param a A pointer to the integer that will be compared against the 
 *          value pointer by b.
 * \param b A pointer to the integer that will be compared against the 
 *          value pointer by a.
 * \return The comparison result
 */
int compare_ints_descending(const void* a, const void* b) {
	return *(int*) b - *(int*) a;
}

/**
 * \brief Creates a sorted copy of an integer array of n elements in descending order.
 * 
 * \details This function creates a sorted copy of the input array 
 *          by dynamically allocating the destination array 
 *          (i.e. you should allocate the memory for the destination array).
 *          The function should return a new array that contains the same 
 *          elements of the argument array, but its elements should be sorted in 
 *          descending order. 
 * 
 * \param array The array to be copied and sorted.
 * \param n The number of elements in the array.
 * \return The descending sorted copy of the array.
 * 
 * \note You don't need to free the memory for array.
 * 
 * \note  stdlib.h has some useful functions that might help you to sort the array.
 *        You might need the comparison function compare_ints_descending if you prefer to 
 *        use stdlib function for sorting the array.
 * 
 * \note In your implementation, do not write to stdout to check the functionality.
 *       You should use my_tests function to print and check the functionality 
 *       of your implementation.
 */
int* copy_sorted_descending(int* array, unsigned int n) {
	int* newarr = calloc(n, sizeof(int));
	for (unsigned int h = 0; h < n; h++) 
	{
    	newarr[h] = array[h];
    }
	qsort(newarr, n, sizeof(int), compare_ints_descending);
	
	/*for (unsigned int i = 0; i < n; ++i) 
        {
            for (unsigned int j = i + 1; j < n; ++j) 
            {
                if (array[i] < array[j]) 
                {
                    unsigned int a = array[i];
                    array[i] = array[j];
                    array[j] = a;
                }
            }
        }*/
	return newarr;
}

/**
 * \brief conducts the tests for your implementation.
 * 
 * \details You are strongly encouraged to test your implementation
 * using this function. Try to create at least three test cases to check
 * whether your function implementation is correct.
 * 
 */
void my_tests(int *ar, int size) {
	int i;
    for (i = 0; i < size-1; i++) printf("%d, ", ar[i]);
    printf("%d\n", ar[i]);
	// You can write your own test code here.
}

int main(void) {
	int array[] = {1, 4, 5, 2, 4, 9};
	unsigned int size = 6;
	int *sorted_array = copy_sorted_descending(array, size);
	/* You may implement your own tests in my_tests function */
	my_tests(sorted_array, size);
	return 0;
}
