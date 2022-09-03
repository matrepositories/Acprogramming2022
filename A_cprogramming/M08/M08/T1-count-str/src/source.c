#include "source.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>


/**
 * \brief Returns the number of occurrences of string sub in the string str.
 * 
 * \param str A null-terminated string that might contain sub in it. 
 * \param sub A null terminated string to search for.
 * \return The number of occurrences of sub in str.
 * 
 * \note strstr function declared in string.h might be useful. 
 */
int num_substr(const char* str, const char* sub) {
	int length = strlen(sub);
    int count = 0; 
    char *occurence;
    occurence = malloc(sizeof(char) * (strlen(str) + 1));
    strcpy(occurence, str);
    if (length)
    {
        while((occurence = strstr(occurence, sub)))
        {
            occurence += length;
            count++;
        }
    }
    free(occurence);
    return count;


}   
