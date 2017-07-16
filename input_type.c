//input_type.c

#include <stdlib.h>
#include "sudlib.h"
#include <stdio.h>

unsigned char inputType (void)
{
    unsigned char typeOfSud;
    printf ("%s\n", "If you want sudoku with numbers put key 1, if with letters - a");
    scanf ("%c", &typeOfSud);
    if (typeOfSud != '1' && typeOfSud != 'a') {
        printf ("%s\n", ERROR_STRING);
        exit (EXIT_FAILURE);
    }

    return typeOfSud;
}
