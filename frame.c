//frame.c - выводит на экран рамку для судоку

#include "sudlib.h"
#include <curses.h>

void frame (const char modify)
{
    chtype frameElement;

    move (Y0 - 1, X0);//перемещение к началу рамки относительно вывода судоку

    for (unsigned int i = 0; i < SIZE; ++i) {//верхняя часть
        frameElement = ' ' | COLOR_PAIR (1);
        addch (frameElement);
        frameElement = (i + 'A') | COLOR_PAIR (1);
        addch (frameElement | A_BOLD);
    }

    for (unsigned int i = 0; i < SIZE; ++i) {//нижняя часть
        move (Y0 + i, X0 - 2);
        frameElement = ' ' | COLOR_PAIR (1);
        addch (frameElement);
        frameElement = (i + '1') | COLOR_PAIR (1);
        addch (frameElement | A_BOLD);
    }

    mvprintw (Y0, X0 + 22, "%s", "Turn number: ");
    mvprintw (Y0 + 1, X0 + 22, "%s", "Empty values: ");

    mvprintw (Y0 + 7, X0 + 22, "%s", "If you want to leave the game, press ESC.");

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
