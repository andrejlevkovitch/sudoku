//mygetch.c - требуется для windows, так как pdcurses не распознает стрелки и конфликтует с conio.h

#include "sudlib.h"

#ifdef linux
    #include <curses.h>
#else
    #include <conio.h>
#endif

unsigned char mygetch (void)
{
    return getch();
}
