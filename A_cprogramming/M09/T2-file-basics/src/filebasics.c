#include "filebasics.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * \brief Print the given text file to the standard output stream.
 * 
 * \param filename The name of the file
 * \return The number of characters printed or -1 if file opening or reading 
 *         fails.
 */
int print_file_and_count(const char* filename) {
    FILE *f = fopen(filename, "r");
    if (!f)
    {
        return -1;
    }
    int length = 0;
    while(1) 
    {
        char string[1000] = "";
        if(fgets(string, 1000, f) == NULL)
        {  
            break;
        }
        length += strlen(string);
        printf("%s", string);
    }
    fclose(f);
    return length;	
}

/**
 * \brief Compares two files and returns the first line that differ
 *        in the two files, concatenated together, separated by four dashes, on
 *        different lines.      
 * 
 * \param file1 The name of the first file
 * \param file2 The name of the second file
 * 
 * \note You can assume that lines are not longer than 1000 characters.
 * 
 * \return A dynamically allocated string that contains the first different 
 *         lines in the files. An example string is 
 * 
 *            printf("Hello world!\n");
 *       ----
 *            printf("Hello world\n");
 * \returns NULL if the files are equal or if either one of the 
            files ends.
 */
char* difference(const char* file1, const char* file2) {
    FILE *f1 = fopen(file1, "r");
    FILE *f2 = fopen(file2, "r");
    if (!f1 || !f2) 
    {
        fprintf(stderr, "Error in file opening\n");
        return 0;
    }
    char *s1, *s2, *s1orig, *s2orig;
    int store = 10000;
    s1 = s1orig = malloc(store);
    s2 = s2orig = malloc(store);
    while(1) 
    {
        s1 = fgets(s1, store, f1);
        s2 = fgets(s2, store, f2);
        if(s1 == 0 || s2 == 0)
        {
            break;
        }
        char *s1copy, *s2copy;
        s1copy = s1;
        s2copy = s2;
        int diff = 0;
        while(*s1copy) 
        {
            if(!(*s1copy == *s2copy)) 
            {
                diff = 1;
                break;
            }
            if(*s2copy == 0) 
            {
                diff = 1;
                break;
            }
            s1copy++, s2copy++;
        }
        if(*s2copy)
        {
            diff = 1;
        }
        if(diff) 
        {
            char* dashes = "----\n";
            s1 = strcat(s1, dashes);
            s1 = strcat(s1, s2);
            strcpy(s2, s1);
            strcpy(s1orig, s2);
            free(s2orig);
            fclose(f1);
            fclose(f2);
            return s1orig;
        }
        s1++, s2++;
    }
    fclose(f1);
    fclose(f2);
    free(s1orig);
    free(s2orig);
    return 0;
	
}
