//revers.c - зеркально отображает матрицу судоку

#include "../../include/sudlib.h"
#include <string.h>

void revers (unsigned int array [][SIZE]) 
{
    unsigned int store [SIZE][SIZE] = {};

    memcpy (store, array, SIZE * SIZE * sizeof (**array));

    for (unsigned int i = 0; i < SIZE; ++i) {
        for (unsigned int j = 0; j < SIZE; ++j) {
            array [j][i] = store [i][j];
        }
    }
   
    return;
}
