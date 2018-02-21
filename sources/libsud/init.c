//init.c - инициализирует массив цифрами 0-8 в каждой строке

#include "sudlib.h"

void initialization (unsigned int array [][SIZE + 1])
{
    for (unsigned int i = 0; i < SIZE; ++i) {//инициализирует строки значениями от 0 до 8, последний элемент - 9
        for (unsigned int j = 0; j < SIZE + 1; ++j) {
            array [i][j] = j;
        }
    }

    return;
}
