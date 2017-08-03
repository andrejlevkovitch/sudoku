//print_mas.c - выводит массив

#include <stdio.h>
#include "sudlib.h"

void printMas (const unsigned char * array, const unsigned char type, const unsigned char size_s, const unsigned char size_c)
{
    printf ("\n");
    for (unsigned char i = 0; i < size_s; ++i) {
        for (unsigned char j = 0; j < size_c; ++j) {
            if (*(array + i * size_c + j) != UNKN_ELEMENT) {
                printf ("%-2c", *(array + i * size_c + j) + type);
            }
            else {
                printf ("%-2c", *(array + i * size_c + j));
            }
        }
        printf ("\n");
    }
    printf ("\n");

    return;
}
