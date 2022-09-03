
#include "string.h"
#include "stdio.h"

unsigned int qstr_length()
{
    const char s[] = "Foobar123nelja?viisibaz";
    const char *p;
    int laskuri = 0;
    for(p = &s[0]; *p != '?'; p++)
    {
        laskuri++;  
    }
return laskuri;
}