//print_mas.c

#include "sudlib.h"

void printMas (unsigned char *array)
{
    printf ("\n");
    for (unsigned char i = 0; i < SIZE; ++i) {
        for (unsigned char j = 0; j < SIZE; ++j) {
            printf ("%-2c", *array);
            ++array;
        }
        printf ("\n");
    }
    printf ("\n");

    return;
}
