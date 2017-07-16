//init.c

#include "sudlib.h"

void initialization (unsigned char *array)
{
    unsigned char type;
    type = inputType ();
    for (unsigned char i = 0; i < SIZE; ++i) {
        for (unsigned char j = 0; j < SIZE; ++j) {
            *(array + i * SIZE + j) = j + type;
        }
    }

    return;
}
