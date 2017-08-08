//main.c - основное тело

#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include "sudlib.h"

int main (void)
{
    unsigned char psblDgts [SIZE][SIZE] = {};
    unsigned char bgnMtrx [SIZE][SIZE] = {};
    unsigned char sudoku [SIZE][SIZE] = {};

    unsigned char type = 0;
    unsigned char crosDig = 0;

    initscr();
//проверка на поддержку цветов
    if (!has_colors()) {
        endwin();
        printf ("%s", "Colors are not supported!");
        exit (EXIT_FAILURE);
    }

    start_color();

    do {
        type = inputType();
        crosDig = numCros();

        randArr (*bgnMtrx, *psblDgts);

        memcpy (sudoku, bgnMtrx, SIZE * SIZE);
        if (crosDig != 0) sudMaker (*sudoku, crosDig);

    } while (ioSystem (*sudoku, type, crosDig));

    endwin();

    return EXIT_SUCCESS;
}
