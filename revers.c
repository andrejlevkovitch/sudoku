//revers.c - зеркально отображает матрицу судоку

#include <string.h>
#include "sudlib.h"

void revers (unsigned char * const array) 
{
    unsigned char store [SIZE][SIZE] = {};

    memcpy (store, array, SIZE * SIZE);

    for (unsigned char i = 0; i < SIZE; ++i) {
        for (unsigned char j = 0; j < SIZE; ++j) {
            *(array + j * SIZE + i) = *(*(store + i) + j);
        }
    }
   
    return;
}
