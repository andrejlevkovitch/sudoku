//colors.c - цвета

#include <ncurses.h>
#include "sudlib.h"

void colors (void)
{
    init_pair (1, COLOR_BLACK, COLOR_CYAN);
    init_pair (2, COLOR_WHITE, COLOR_GREEN);
    init_pair (3, COLOR_WHITE, COLOR_BLUE);
    init_pair (4, COLOR_YELLOW, COLOR_GREEN);
    init_pair (5, COLOR_YELLOW, COLOR_BLUE);
    init_pair (6, COLOR_RED, COLOR_MAGENTA);
    init_pair (7, COLOR_RED, COLOR_BLACK);
    init_pair (8, COLOR_YELLOW, COLOR_BLACK);

    return;
}