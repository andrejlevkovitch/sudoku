//frame.c - выводит на экран рамку для судоку

#include <curses.h>
#include "sudlib.h"

void frame (const char modify)
{
    chtype frameElement;

    move (Y0 - 1, 2);//перемещение к началу рамки относительно вывода судоку
    for (unsigned char i = 0; i < SIZE; ++i) {//верхняя часть
        frameElement = ' ' | COLOR_PAIR (1);
        addch (frameElement);
        frameElement = (i + 'A') | COLOR_PAIR (1);
        addch (frameElement | A_BOLD);
    }

    for (unsigned char i = 0; i < SIZE; ++i) {//нижняя часть
        printw ("\n");
        frameElement = ' ' | COLOR_PAIR (1);
        addch (frameElement);
        frameElement = (i + '1') | COLOR_PAIR (1);
        addch (frameElement | A_BOLD);
    }

    mvprintw (Y0, X0 + 22, "%s", "Turn number: ");
    mvprintw (Y0 + 1, X0 + 22, "%s", "Empty values: ");

#ifdef linux

    mvprintw (Y0 + 7, X0 + 22, "%s", "If you want to leave the game, press ESC (twice).");

#else

    mvprintw (Y0 + 7, X0 + 22, "%s", "If you want to leave the game, press ESC.");

#endif

    move (Y0 + 8, X0 + 22);
    switch (modify) {//вывод в зависимости от модификатора
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
