
#include "source.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * \brief Removes the C comments from the input C code.
 *
 * \details The function polishes the code by */
//          - removing the block comments delimited by /* and */.
/*            These comments may span multiple lines.You should remove only */
//            characters starting with /* and ending with */. The characters,
/*            including white space characters (' ', \n, \r, \t), */
//            after */ should not be removed.
/*
 *          - remove the line comments starting with // until and including the
 *            newline character \n.
 *
 * \param input A code segment that contains some comments.It is a dynamically
 *              allocated string(array of characters).
 * \return A pointer to the polished code
 */

char *delete_comments(char *input)
{
    int size = strlen(input);
    char *string = (char*)malloc(size * sizeof(char) + 1 * sizeof(char));
    for (int g = 0; g < size; g++)
    {
        string[g] = size - g;
    }
    int h = 0;
    for (int i = 0; i < size; i++)
    {
        if (input[i] == '/' && input[i + 1] == '*')
        {
            for (int j = i; j < size; j++)
            {
                if (input[j] == '*' && input[j + 1] == '/')
                {
                    i=j + 1;
                    break;
                }
                
            }
        }
        else if (input[i] == '/' && input[i + 1] == '/')
        {
            for (int j = i; j < size; j++)
            {
                if (input[j] == '\n')
                {
                    i=j;
                    break;
                }
            }
        }
        else 
        {
            string[h] = input[i];
            h++;
        }
    
    }
    free(input);
    string[h] = 0; 
    return string;
}
