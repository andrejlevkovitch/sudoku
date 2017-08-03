//zeros.c - прсваивает всем элементам массива 0

#include "sudlib.h"

void zeros (unsigned char * array)
{
    for (unsigned char i = 0; i < SIZE; ++i) {
        *(array + i) = 0;
    }
    return;
}
