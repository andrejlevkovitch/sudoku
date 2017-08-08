//main.c - основное тело

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

    do {
        type = inputType();
        crosDig = numCros();

        randArr (*bgnMtrx, *psblDgts);

        memcpy (sudoku, bgnMtrx, SIZE * SIZE);
        if (crosDig != 0) sudMaker (*sudoku, crosDig);

    } while (ioSystem (*sudoku, type, crosDig));

    return EXIT_SUCCESS;
}
