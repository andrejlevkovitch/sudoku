//init.c

#include "sudlib.h"

void initialization (unsigned char *array, unsigned char size_c)
{
    for (unsigned char i = 0; i < SIZE; ++i) {
        for (unsigned char j = 0; j < SIZE; ++j) {
            *(array + i * size_c + j) = j;
        }
    }

    return;
}
