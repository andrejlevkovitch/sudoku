//print_mas.c

#include <stdio.h>
#include "sudlib.h"

void printMas (const unsigned char const *array, unsigned char type, unsigned char size_s, unsigned char size_c)
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
