//frame.c - выводит на экран рамку для судоку

#include <ncurses.h>
#include "sudlib.h"

void frame (void)
{
    initscr();

    chtype frameElement;

    start_color();
    init_pair (1, COLOR_BLACK, COLOR_YELLOW);


    printw ("  ");

    for (unsigned char i = 0; i < SIZE; ++i) {
        frameElement = ' ' | COLOR_PAIR (1);
        addch (frameElement);
        frameElement = (i + 'A') | COLOR_PAIR (1);
        addch (frameElement);
    }

    for (unsigned char i = 0; i < SIZE; ++i) {
        printw ("\n");
        frameElement = ' ' | COLOR_PAIR (1);
        addch (frameElement);
        frameElement = (i + '1') | COLOR_PAIR (1);
        addch (frameElement);
    }

    endwin();

    return;
}
