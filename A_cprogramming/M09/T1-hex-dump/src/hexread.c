#include "hexread.h"
#include <stdio.h>
#include <string.h>


/**
 * \brief Prints the given file as hexdump.
 * 
 * \details The function outputs each byte in the file as a two character hexadecimal 
 *          number. 
 *
 *    - If a byte is less than ``0x10``, then the output should have ``0`` in 
 *      front of the number. 
 *    
 *    - Each line must have maximum of 16 hexadecimal numbers with a space between 
 *      them.
 * 
 *    - Only 16 hexadecimal numbers must be printed in one line and there should 
 *      be a space after the last value.After printing 16 hex values, the next 
 *      byte should be printed on the next line. 
 *
 *    - If the end-of-file indicator is set before a line ends, the dump should 
 *      end.
 * 
 * \param filename The name of the file to dump.
 * \return Returns the number of characters read or -1 if an error occurs when 
 *         reading the file.
 */
int file_to_hex(const char* filename) {
	FILE* f;
    f = fopen(filename, "r");
    if(!f)
    {
        return -1;
    }
    int got, read = 0;
    while(!feof(f)) 
    {
        got = fgetc(f);
        if(got == EOF)
        {
            break;
        }
        read++;
        printf("%02x ", got);
        if(read != 0 && read % 16 == 0)
        {
        printf("\n");
        }
    }
    fclose(f);
    return read;
}    
