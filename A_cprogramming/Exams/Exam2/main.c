#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
 * \brief Converts all non-numerical characters in a null-terminated 
 *        string to zero character, '0'.
 * 
 * \details This function finds all non-numerical characters in a string and 
 *          converts these characters into a zero character, '0'. It changes 
 *          the found non-numerical characters inplace so that no dynamic 
 *          allocation is needed.
 * 
 * \param str The null-terminated string with some non-numerical characters.
 * 
 * \note stdlib provides useful character handling functions in ctype.h. 
 *       ctype.h documentation also states different character classes,  
 *       including numerical (digit) characters.
 * 
 * \note In your implementation, do not write to stdout to check the functionality.
 *       You should use my_tests function to print and check the functionality 
 *       of your implementation.
 */
void convert_non_numbers(char* str) {
	for(long unsigned int i = 0; i < strlen(str); i++)
		{
			if((isdigit(str[i]) == 0))
			{
				str[i] = '0';
			}
		}
	//TODO: implement your function here!
}

/**
 * \brief conducts the tests for your implementation.
 * 
 * \details You are strongly encouraged to test your implementation
 * using this function. Try to create at least three test cases to check
 * whether your function implementation is correct.
 * 
 */
void my_tests(char* str) {
	printf("%s", str);



}

int main(void) {
	char string[] = "1234i3&o)12";
	convert_non_numbers(string);
	my_tests(string);
	return 0;
}