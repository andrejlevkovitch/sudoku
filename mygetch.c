//mygetch.c - требуется для windows, так как pdcurses не распознает стрелки и конфликтует с conio.h

#include <conio.h>

unsigned char mygetch (void)
{
    return getch();
}
