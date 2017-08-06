//input_type.c - ф-ция ввода типа судоку

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include "sudlib.h"

unsigned char inputType (void)
{
    initscr();

    if (!has_colors()) {
        endwin();
        printf ("%s", "Colors are not supported!");
        exit (EXIT_FAILURE);
    }

    start_color();

    printw ("%s\n", "If you want sudoku with numbers put key 1, if with letters - a/A");

    refresh();

    const unsigned char typeOfSud = getch();
    printw ("\n");

//    endwin();// закрытие в файле io_system.c

    if (typeOfSud != '1' && typeOfSud != 'a' && typeOfSud != 'A') {
        endwin();
        printf ("\033[01;31m%s\033[0m\n", ERROR_STRING);
        exit (EXIT_FAILURE);
    }

    return typeOfSud;
}
