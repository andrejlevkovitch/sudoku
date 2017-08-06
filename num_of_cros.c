//num_of_cros.c - вводит количество вычеркиваемых элементов

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include "sudlib.h"

unsigned char numCros (void)
{
    unsigned int crosDigit = 0;

    printw ("%s 0<=n<=%i\n", "How many digits do you want to cross out?", MAXCROSSDIGIT);

    refresh();

    scanw ("%u", &crosDigit);

    if (crosDigit > MAXCROSSDIGIT) {
        endwin();
        printf ("\033[01;31m%s\n\033[0m", ERROR_STRING);
        exit (EXIT_FAILURE);
    }

    return crosDigit;
}
