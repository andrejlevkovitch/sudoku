//revers.c

#include "sudlib.h"

void revers (unsigned char *array) 
{
    unsigned char zamena[SIZE][SIZE] = {};

    vozvrat (*zamena, array, SIZE, SIZE);

    for (unsigned char i = 0; i < SIZE; ++i) {
        for (unsigned char j = 0; j < SIZE; ++j) {
            *(array + j * SIZE + i) = zamena[i][j];
        }
    }
   
    return;
}