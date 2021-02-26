#include <stdlib.h>

#include "reverse_bits.h"

int reverse_bits(int num)
{
    int count = sizeof(int) * CHAR_BIT - 1;
    int reverse_num = num;

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