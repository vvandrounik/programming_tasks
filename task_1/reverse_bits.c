#include <stdlib.h>

#include "reverse_bits.h"

unsigned int reverse_bits(unsigned int num)
{
    unsigned int count = sizeof(int) * CHAR_BIT - 1;
    unsigned int reverse_num = num;

    num >>= 1;
    while (num)
    {
        reverse_num <<= 1;
        reverse_num |= num & 1;
        num >>= 1;
        count--;
    }
    reverse_num <<= count;
    return reverse_num;
}