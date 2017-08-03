//main.c - основное тело

#include <stdlib.h>
#include <string.h>
#include "sudlib.h"

int main (void)
{
    unsigned char psblDgts [SIZE][SIZE] = {};
    unsigned char bgnMtrx [SIZE][SIZE] = {};
    unsigned char sudoku [SIZE][SIZE] = {};

    const unsigned char type = inputType();
    const unsigned char crosDig = numCros();

    randArr (*bgnMtrx, *psblDgts);

    memcpy (sudoku, bgnMtrx, SIZE * SIZE);
    sudMaker (*sudoku, crosDig);

    io (*sudoku, type, crosDig);

    return EXIT_SUCCESS;
}
