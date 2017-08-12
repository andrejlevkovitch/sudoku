//num_of_cros.c - вводит количество вычеркиваемых элементов

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include "sudlib.h"

unsigned char numCros (void)
{
    unsigned char crosDigit = 0;

    printw ("%s 0<=n<=%hhu\n", "How many digits do you want to cross out?", MAXCROSSDIGIT);

    scanw ("%hhu", &crosDigit);

    if (crosDigit > MAXCROSSDIGIT) {
        endwin();
        printf ("\033[01;31m%s\n\033[0m", ERROR_STRING);
        exit (EXIT_FAILURE);
    }

    return crosDigit;
}
