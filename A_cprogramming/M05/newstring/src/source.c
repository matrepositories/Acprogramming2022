#include "source.h"
#include "string.h"
#include "stdio.h"


/* Print string */
/* Parameters:
 * s: string to be printed */

/**
 * \brief Prints ? terminated string
 *
 * \param s A ? terminated string
 */
void qstr_print(const char *s)
{
    printf("%.*s", (int) strcspn(s, "?"), s);
}

/**
 * \brief Returns the length of a ? terminated string
 *
 * \param s A ? terminated string
 * \return The number of characters before first occurrence of ?
 */
unsigned int qstr_length(const char *s)
{
    int i = 0;
    const char *p;
    int laskuri = 0;
    for(p = &s[i]; *p != '?'; p++)
    {
        laskuri++; 
        i++; 
    }
return laskuri;
}

/**
 * \brief Concatenates two ? terminated strings
 *
 * \param dst The ? terminated string that will contain the concatenated ? terminated string
 * \param src A ? terminated string that will be appended to dst.
 * \return The length of the dst after concatenation
 */
int qstr_cat(char *dst, const char *src)
{
    int i = 0;
    int j = 0;
    int k = 0;
    const char *p;
    int laskuri = 0;
    for(p = &dst[i]; *p != '?'; p++)
    { 
        i++; 
    }
    for(p = &src[j]; *p != '?'; p++)
    {
        dst[i] = src[j]; 
        i++; 
        j++;
    }
    dst[i] = '?';
    for(p = &dst[k]; *p != '?'; p++)
    {
        laskuri++; 
        k++; 
    }
return laskuri; 
}
