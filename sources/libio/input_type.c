//input_type.c - ф-ция ввода типа судоку

#include "../../include/sudlib.h"
#include <curses.h>
#include <stdio.h>
#include <stdlib.h>

unsigned char inputType (void)
{
    printw ("%s\n", "If you want sudoku with numbers put key 1, if with letters - a/A");

    const unsigned char typeOfSud = getch();

    printw ("\n");

    if (typeOfSud != '1' && typeOfSud != 'a' && typeOfSud != 'A') {
        endwin();

#ifdef linux

        printf ("\033[01;31m%s\033[0m\n", ERROR_STRING);

#else

        printf ("%s\n", ERROR_STRING);

#endif
        exit (EXIT_FAILURE);
    }

    return typeOfSud;
}
