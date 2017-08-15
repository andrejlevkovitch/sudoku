//init.c - инициализирует массив цифрами 0-8 в каждой строке

#include "sudlib.h"

void initialization (unsigned char * array, const unsigned char size_c)
{
    for (unsigned char i = 0; i < SIZE; ++i) {//инициализирует строки значениями от 0 до 8
        for (unsigned char j = 0; j < SIZE; ++j) {
            *(array + i * size_c + j) = j;
        }
    }

    return;
}
