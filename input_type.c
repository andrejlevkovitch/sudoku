//input_type.c - ф-ция ввода типа судоку

#include <stdio.h>
#include <stdlib.h>
#include "sudlib.h"

#ifdef _WIN32
    #include <conio.h>
#elif _WIN64
    #include <conio.h>
#endif

unsigned char inputType (void)
{
    printf ("%s\n", "If you want sudoku with numbers put key 1, if with letters - a");
    const unsigned char typeOfSud = getch();
    if (typeOfSud != '1' && typeOfSud != 'a') {
        printf ("%s\n", ERROR_STRING);
        exit (EXIT_FAILURE);
    }

    return typeOfSud;
}
