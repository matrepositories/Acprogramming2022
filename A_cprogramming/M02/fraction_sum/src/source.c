# include <stdio.h>
# include "source.h"

double fracsum(int num0, int denom0, int num1, int denom1)
{
    double ffrac0 = (double)num0 / denom0; 
    double ffrac1 = (double)num1 / denom1;
    double fsum01 = ffrac0 + ffrac1;
    
    return fsum01;
}
