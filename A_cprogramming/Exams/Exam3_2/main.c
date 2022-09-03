#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
 * \brief Fetches left most four bits of a byte to create a number, and fetches 
 *        the rightmost four bits of the same byte to create another number. 
 *        Then, it ANDs these two parts to obtain a four bit number, and ORs 
 *        the parts to obtain another four bit number. The results of AND 
 *        operation and OR operation are combined in a way that result of AND
 *        is the left most four bits, and the result of OR operation is the four
 *        right most bits of a new byte.
 * 
 * \details This function feches the left most and the right most four bits 
 *          of the argument byte. Then, performs the operations exemplified 
 *          below. 
 * 
 *          Let byte = 10101101 (0xAD in hexadecimal), the 
 *          function would separate two binary numbers, 1010 and 1101, and 
 *          would then AND these numbers, resulting in 1000 (0x8 in hexadecimal),
 *          and OR them, which would result 1111 (0xf in hexadecimal).
 *          The function would return the value 10001111 (0x8f in hexadecimal),
 *          after combining them in a byte.
 * 
 * \param byte The byte value to be operated on
 * \return The resultant byte after the stated bit operations
 * 
 * \note In your implementation, do not write to stdout to check the functionality.
 *       You should use my_tests function to print and check the functionality 
 *       of your implementation.10101101
 */
unsigned char fetch_bits_and_combine(unsigned char byte) {
	
	unsigned int puuhastaja0 = 240;
	unsigned int puuhastaja1 = 15;
	unsigned int rightbyte = puuhastaja1 & byte;  
	unsigned int leftbyte = puuhastaja0 & byte;
	unsigned int fourbitnumberand = (leftbyte >> 4) & rightbyte;
	unsigned int fourbitnumberor = (leftbyte >> 4) | rightbyte;
	unsigned int valamis = (fourbitnumberand << 4) | fourbitnumberor;  
	return valamis;
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

int main(void) {
	/* You may implement your own tests in my_tests function */
	unsigned int wahuu = 0xAD;
	fetch_bits_and_combine(wahuu);
	return 0;
}
