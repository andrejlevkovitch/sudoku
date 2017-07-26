//input_type.c

#include "sudlib.h"

unsigned char inputType (void)
{
    printf ("%s\n", "If you want sudoku with numbers put key 1, if with letters - a");
    unsigned char typeOfSud = getch();
    if (typeOfSud != '1' && typeOfSud != 'a') {
        printf ("%s\n", ERROR_STRING);
        exit (EXIT_FAILURE);
    }

    return typeOfSud;
}
