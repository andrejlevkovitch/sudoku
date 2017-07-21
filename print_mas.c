//print_mas.c

#include "sudlib.h"

void printMas (unsigned char *array, unsigned char type, unsigned char size_s, unsigned char size_c)
{
    printf ("\n");
    for (unsigned char i = 0; i < size_s; ++i) {
        for (unsigned char j = 0; j < size_c; ++j) {
            printf ("%-2c", *array + type);
            ++array;
        }
        printf ("\n");
    }
    printf ("\n");

    return;
}
