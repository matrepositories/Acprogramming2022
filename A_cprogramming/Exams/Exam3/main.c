#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
 * \brief Counts the number of set bits in a byte array of n elements.
 * 
 * \details This function counts the number set bits in a byte array. 
 *          For example, if array = {0xA3, 0x58} and n = 2, the array 
 *          bytes has binary values 1010 0011 0101 1000, and the function
 *          returns 7. Since 
 *          1010 0011 0101 1000
 *          ^ ^    ^^  ^ ^ ^   
 *          has 7 set bits.
 * 
 * \param array A byte array of n elements.
 * \param n The number of bytes in array.
 * \return The number of set bits in the bytes of array.
 * 
 * \note In your implementation, do not write to stdout to check the functionality.
 *       You should use my_tests function to print and check the functionality 
 *       of your implementation.
 */
unsigned int count_set_bits_in_array(unsigned char* array, unsigned int n) {
	unsigned int count = 0;

	for (unsigned int i = 0; i < n; i++)
	{
		for (unsigned int j = 0; j < 8; j++)
		{
			unsigned int bitmask = 1 << j;
			if(bitmask == (array[i] & bitmask))
			{
				count++;
			}
		}
	}

	return count;
}

/**
 * \brief conducts the tests for your implementation.
 * 
 * \details You are strongly encouraged to test your implementation
 * using this function. Try to create at least three test cases to check
 * whether your function implementation is correct.
 * 
 */
void my_tests(void) {
	// You can write your own test code here.
}

unsigned int main(void) {
	/* You may implement your own tests in my_tests function */
	unsigned int array[] = {0xd4, 0x80, 0xae, 0xc8, 0x9e};
	unsigned int n = (sizeof(array) / sizeof(array[0]));
	unsigned int finalcount = count_set_bits_in_array(array, n);
	//my_tests();
	return finalcount;
}
