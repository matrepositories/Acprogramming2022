#include "stringsplit.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


/**
 * \brief Splits a string into its parts, and returns a dynamically allocated  
 *        array of strings that are dynamically allocated.
 * 
 * \details For example called with "Test string split" and " ",
 *          the function returns ["Test", "string", "split", NULL].
 *          
 *          Or called with "Another - test" and " - ",
 *          returns ["Another", "test", NULL].
 * 
 * \param str The null-terminated string to split.
 * \param split The token string to split str with.
 * \return An array of strings that contains parts of str in each of 
 *         strings excluding the split.      
 */
char** split_string(const char* str, const char* split) {
	char** strarray = malloc(sizeof(char*)); //** -> datatyyppi listaan pointereita 
	int nth = 0;
	
//jos char* del ois loopin ulkopuolella voisi olla esim while(del != NULL) ja NULL case whilen ulkopuolelle
	while(1)
	{
		char* del = strstr(str, split);
		if(del != NULL)
		{
			int len = del - str;			
			strarray = realloc(strarray, (nth + 1) * (sizeof(char*))); 
			strarray[nth] = calloc(len + 1, sizeof(char));
			strncpy(strarray[nth], str, len);
			nth++;
			str = str + (len + strlen(split));
		} 
		else
		{
			int len = strlen(str);			
			strarray = realloc(strarray, (nth + 2) * (sizeof(char*))); 
			strarray[nth] = calloc(len + 1, sizeof(char));
			strarray[nth + 1] = NULL;
			strncpy(strarray[nth], str, len);
			break;
		}
		
	}
return strarray;

}
//sizeof operaattori tyypin koko
/**
 * \brief Prints string parts that are split with split_string function.
 * 
 * \param split_string An array of strings returned by split_string function.
 */
void print_split_string(char** split_string) {
	int i = 0;
	while(split_string[i] != NULL)
	{
		printf("%s\n", split_string[i]);
		i++;
	}

}
/**
 * \brief Releases dynamically allocated string parts by split_string function.
 * 
 * \param split_string An array of strings returned by split_string function.
 */
void free_split_string(char** split_string) {
	int i = 0;
	while(split_string[i] != NULL)
	{
		free(split_string[i]);
		i++;
	}
	free(split_string);
}
