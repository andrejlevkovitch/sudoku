//frame.c - выводит на экран рамку для судоку

#include <ncurses.h>
#include "sudlib.h"

void frame (const char modify)
{
    chtype frameElement;

    move (Y0 - 1, 0);
    printw ("  ");

    for (unsigned char i = 0; i < SIZE; ++i) {
        frameElement = ' ' | COLOR_PAIR (1);
        addch (frameElement);
        frameElement = (i + 'A') | COLOR_PAIR (1);
        addch (frameElement | A_BOLD);
    }

    for (unsigned char i = 0; i < SIZE; ++i) {
        printw ("\n");
        frameElement = ' ' | COLOR_PAIR (1);
        addch (frameElement);
        frameElement = (i + '1') | COLOR_PAIR (1);
        addch (frameElement | A_BOLD);
    }

    move (Y0 + 7, X0 + 22);
    printw ("%s", "If you want to leave the game, press ESC (twice).");
    move (Y0 + 8, X0 + 22);
    switch (modify) {
        case DECISION:
            break;

        case SOLUTION:
            printw ("%s", "If you want to see the solution, press Enter.");
            break;

        default: 
            printw ("%s", "If you want to play a new game, press Enter.");
            break;
    }

    return;
}
