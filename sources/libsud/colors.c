//colors.c - цвета

#include "sudlib.h"
#include <curses.h>
#include <stdlib.h>

void colors (void)
{
    if (!has_colors()) {//проверка на поддержку цветов
        endwin();
        printf ("%s", "Colors are not supported!");
        exit (EXIT_FAILURE);
    }

    start_color();

    init_pair (1, COLOR_BLACK, COLOR_CYAN);
    init_pair (2, COLOR_WHITE, COLOR_GREEN);
    init_pair (3, COLOR_WHITE, COLOR_BLUE);
    init_pair (4, COLOR_YELLOW, COLOR_GREEN);
    init_pair (5, COLOR_YELLOW, COLOR_BLUE);
    init_pair (6, COLOR_RED, COLOR_MAGENTA);
    init_pair (7, COLOR_RED, COLOR_BLACK);
    init_pair (8, COLOR_YELLOW, COLOR_BLACK);
    init_pair (9, COLOR_WHITE, COLOR_YELLOW);
    init_pair (10, COLOR_YELLOW, COLOR_YELLOW);

    return;
}
