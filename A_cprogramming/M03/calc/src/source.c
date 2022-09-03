/* In this task, you will learn how to use conditional statements and formatted
 * input and output using scanf and printf. You are required to implement
 * simple_math function that fulfills the following requirements.
 *  1. The function is declared in source.h as
 *      void simple_math(void);
 *  2. Implement the function definition in source.c.
 *  3. The function should expect the user input in the form
 *      <number><space><operator><space><number>
 *      where
 *      <number>
 *        is a float type floating point number.
 *      <operator>
 *        is one of '+', '-', '*' or '/' characters corresponding to the basic
 *        mathematical operators.
 *      <space>
 *        is the space character ' '.
 *  4. If the user entry is not in the expected format, the function should print
 *      ERR
 *  5. If the user enters any other operator than the above stated ones, the function
 *     should print
 *      ERR
 *  6. If the user enters the required input, the function performs the stated
 *     operation on the stated numbers and prints the result with a precision of
 *     a single decimal.
 * An example call of the function is shown below. The input from the user is marked with
 * an @ sign:
 *  @  8 - 2
 *     6.0
 *  @  5 * 5
 *     25.0
 *  @  8.3 / 5.1
 *     1.6
 *  @  2.2 / 0
 *     ERR
 *  @  -3.456 - 2.31
 *     -5.8
 *  @  2.45 : 1.0
 *     ERR
 *  @  * 2.0
 *     ERR
 * Hint
 * - Check the scanf function documentation (http://www.cplusplus.com/reference/cstdio/scanf/)
 * - how does it treat the white-space characters?
 * - how does it treat the non-white-space characters except format specifier?
 * - how does it read the input corresponding to a format specifier?
 * - what is the format specifier for a floating point number?
 * - what is the format specifier for a character constant?
 */

#include "source.h"

#include <math.h>
#include <stdio.h>

void simple_math(void)
{
float a, b, sum, subt, prod, div;
char op; 
if (scanf("%f %c %f", &a, &op, &b) != 3)
    printf("ERR\n");
switch (op) {
    case '+':
        sum = a + b;  
        printf("%2.1f\n", sum);  
        break;
    case '-':
        subt = a - b;
        printf("%2.1f\n", subt); 
        break;
    case '*':
        prod = a * b;
        printf("%2.1f\n", prod); 
        break;
    case '/':
        div = a / b; 
        printf("%2.1f\n", div); 
        break;
    default:
        printf("ERR\n");
        break;

}
    
}
