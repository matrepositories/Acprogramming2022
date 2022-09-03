#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
 * \brief Converts all non-printable characters in a null-terminated 
 *        string to space character, ' '.
 * 
 * \details This function finds all non-printable characters in a string and 
 *          converts these characters into a space character, ' '. It changes 
 *          the found non-printable characters inplace so that no dynamic 
 *          allocation is needed.
 * 
 * \param str The null-terminated string with some non-printable characters.
 * 
 * \note stdlib provides useful character handling functions in ctype.h. 
 *       ctype.h documentation also states different character classes,  
 *       including printable characters.
 * 
 * \note In your implementation, do not write to stdout to check the functionality.
 *       You should use my_tests function to print and check the functionality 
 *       of your implementation.
 */
void convert_non_printable(char* str) {
	char rep = ' ';
	for(; *str; str++)
	{
		if(isprint(*str) == 0)
			*str = rep;
	}
	//TODO: implement your function here!
}

void my_tests(void) {
	// You can write your own test code here.
}

int main(void) {
	/* You may implement your own tests in my_tests function */
	my_tests();
	return 0;
}
