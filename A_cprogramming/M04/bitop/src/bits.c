#include "bits.h"
#include <stdio.h>
#include <stdlib.h>

#define BITMASK (0x00000001)
#define BITMASK0 (0x01)

/* DESCRIPTION:
 * ------------
 * The function clears a bit with index i (makes the bit active (1)) in the argument
 * data.
 *
 * You do not need to handle any invalid parameters.
 *
 * PARAMETERS:
 * ------------
 * uint32_t data: an array of binary data.
 * int i: the index of the bit.
 *
 * RETURNS:
 * ------------
 * modified data.
 *
 */
uint32_t op_bit_set(uint32_t data, int i)
{
    data = data | (BITMASK << i); 
    return data;
}

/* DESCRIPTION:
 * ------------
 * The function clears a bit with index i (makes the bit inactive (0)) in the argument
 * data.
 *
 * You do not need to handle any invalid parameters.
 *
 * PARAMETERS:
 * ------------
 * uint32_t data: a 32-bit data.
 * int i: the index of the bit.
 *
 * RETURNS:
 * ------------
 * modified.
 *
 */

uint32_t op_bit_clear(uint32_t data, int i)
{
    int bitmask = BITMASK << i;
    data = data & ~bitmask; 
    return data;
}

/* DESCRIPTION:
 * ------------
 * The function toggles a bit with index i in the argument
 * data.
 *
 * You do not need to handle any invalid parameters.
 *
 * PARAMETERS:
 * ------------
 * uint32_t data: a 32-bit data.
 * int i: the index of the bit which to set as inactive (0).
 *
 * RETURNS:
 * ------------
 * modified data.
 *
 */

uint32_t op_bit_toggle(uint32_t data, int i)
{
    data = data ^ (BITMASK << i);
    return data;
}

/* DESCRIPTION:
 * ------------
 * The functions returns 1 or 0 depending on whether the bit with index i in
 * the binary data is set or not.
 *
 * You do not need to handle any invalid parameters.
 *
 * PARAMETERS:
 * ------------
 * uint32_t data: a 32-bit data.
 * int i: the index of the bit which value to return.
 *
 * RETURNS:
 * ------------
 * 0: if the bit was not set.
 * 1: if the bit was set.
 */

int op_bit_get(uint32_t data, int i)
{
    uint32_t data0 = data & (BITMASK << i);
    uint32_t data1 = BITMASK << i;
    if (data0 == data1)
    {
        return 1;
    }
    else
        return 0;    
}


void op_print_byte(unsigned char b)
{
    for(int i=7; i>=0; i--) 
    {   
        int bit = op_bit_get(b, i);
        printf("%d",bit);
    }
}
