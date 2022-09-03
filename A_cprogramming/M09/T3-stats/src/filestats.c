
#include "filestats.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * \brief Returns the number of lines in a file. 
 * 
 * \param filename The name of the file.
 * \return The number of lines in the file, or -1 if an error occurs. 
 */
int line_count(const char* filename) {
	FILE* f = fopen(filename, "r");
    if(!f)
    {
        return -1;
    }
    int firstchar = fgetc(f);
    if(firstchar == EOF)
    {
        return 0;
    }
    int count=0;
    if((char)firstchar == '\n')
    {
        count++;
    }
    char line[1000] = "";
    while(fgets(line, 1000, f) != NULL) 
    {
        count++;
    }
    return count;
}

/**
 * \brief Returns the number of words in a file.
 * 
 * \details The function assumes that a word is formed by alphabetical characters
 *          as defined in ctype.h so that isalpha() returns nonzero value.
 * 
 *          The words are separated by a white space character as defined in 
 *          ctype.h so that isspace() returns nonzero value.
 * 
 * \param filename The name of the file.
 * \return The number of words in the file, or -1 if an error occurs.
 */
int word_count(const char* filename) {
	FILE* f = fopen(filename, "r");
    if(!f)
    {
        return -1;
    }
    int words = 0;
    char line[1000] = "";
    while(fgets(line, 1000, f) != NULL) 
    {
        int i;
        int prevspace = 1;
        int prevalpha = 0;
        for(i = 0; i < 1000 && line[i] != 0; i++) 
        {
            if(prevspace == 1) 
            {
                if(isspace((int)line[i]))
                {
                    continue;
                }
            }
            if(isalpha((int)line[i])) 
            {
                if(prevalpha == 0)
                {
                    words++;
                }
                prevalpha = 1;
                prevspace = 0;
            }
            if(isspace((int)line[i])) 
            {
                prevspace = 1;
                prevalpha = 0;
            }
        }
    }
    return words;
}
