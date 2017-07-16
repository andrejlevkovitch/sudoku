//zeros.c

#include "sudlib.h"

void zeros (unsigned char *array)
{
    for (unsigned char i = 0; i < SIZE; ++i) {
        *(array + i) = 0;
    }
    return;
}
