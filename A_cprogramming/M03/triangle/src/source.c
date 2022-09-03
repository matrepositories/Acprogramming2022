/* In this task, you are required to print a box composed of two triangles using
 * nested loops. An example output of the program is shown below.
 *   ....#
 *   ...##
 *   ..###
 *   .####
 *   #####
 *
 *  1. Implement function void draw_triangle(unsigned int size) that draws a box
 *     that contains a triangle of . and another triangle of #. The function should
 *     print the example output above when it is called draw_triangle(5);.
 *  2. The box should be size characters wide, and size characters tall.
 *  3. The box is split diagonally into two such that the right-bottom characters
 *     are '#', and the left-top characters are '.'.
 *  4. The first line contains one '#' character at the right edge, the second line
 *     contains two '##' characters, and so on. On the last line all characters are '#'.
 *  5. All lines (also the last line) should end with a newline character ('\n').
 *  6. (optional) To test draw_triangle(unsigned int size) function, you can write a main
 *     function that asks user for an input number of unsigned int type, and calls
 *     draw_triangle function using the given input. The main function in the provided
 *     template just has draw_triangle(5); statement.
 */

#include "source.h"
#include <math.h>
#include <stdio.h>

void draw_triangle(unsigned int size)
{
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
  
}
