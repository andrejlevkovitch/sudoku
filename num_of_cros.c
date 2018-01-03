//num_of_cros.c - вводит количество вычеркиваемых элементов

#include "sudlib.h"
#include <curses.h>
#include <stdio.h>
#include <stdlib.h>

unsigned int numCros (void)
{
    unsigned int crosDigit = 0;

    printw ("%s 0<=n<=%u\n", "How many digits do you want to cross out?", MAXCROSSDIGIT);

    scanw ("%u", &crosDigit);

    if (crosDigit > MAXCROSSDIGIT) {
        endwin();

#ifdef linux

        printf ("\033[01;31m%s\n\033[0m", ERROR_STRING);

#else

        printf ("%s\n", ERROR_STRING);

#endif

        exit (EXIT_FAILURE);
    }

    return crosDigit;
}
