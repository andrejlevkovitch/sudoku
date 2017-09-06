//init.c - инициализирует массив цифрами 0-8 в каждой строке

#include "sudlib.h"

void initialization (unsigned int * array, const unsigned int size_c)
{
    for (unsigned int i = 0; i < SIZE; ++i) {//инициализирует строки значениями от 0 до 8
        for (unsigned int j = 0; j < SIZE; ++j) {
            *(array + i * size_c + j) = j;
        }
    }

    return;
}
