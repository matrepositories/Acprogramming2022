#include "source.h"

int main()
{
    void draw_triangle(unsigned int size);
        unsigned int size = 8;
        unsigned int a;
        unsigned int b;
        for (a = 1; a <= size; a++) 
        {
            for (b = a; b < size; b++) 
            {
                printf(".");
            }
            for (b = 1; b <= a; b++) 
            {
                printf("#");
            }
        printf("\n");
        }

        
    return 0;
}
