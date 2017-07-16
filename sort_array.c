//sort_array.c
//сортировка массива методом пузырька - нули смещаются вправо

#include "sudlib.h"

void sortArr (unsigned char *array, unsigned char endArr)
{
    for (unsigned char i = 0; i < SIZE; ++i) {
        for (unsigned char l = 1; l <= 3; ++l) {
            for (unsigned char j = 0; j <= endArr - l; ++j) {
                if (*(array + i * SIZE + j) == UNKN_ELEMENT) {
                    *(array + i * SIZE + j) = *(array + i * SIZE + j + 1);
                    *(array + i * SIZE + j + 1) = UNKN_ELEMENT;
                }
            }
        }
    }
    return;
}
