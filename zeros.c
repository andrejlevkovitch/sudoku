//zeros.c - прсваивает всем элементам массива 0

#include "sudlib.h"

void zeros (unsigned char * const array)
{
    for (unsigned char i = 0; i < SIZE; ++i) {
        *(array + i) = 0;
    }
    return;
}
