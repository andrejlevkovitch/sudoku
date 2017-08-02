//main.c - основное тело

#include <stdlib.h>
#include <string.h>
#include "sudlib.h"

int main (void)
{
    unsigned char psblDgts [SIZE][SIZE] = {};
    unsigned char bgnMtrx [SIZE][SIZE] = {};
    unsigned char sudoku [SIZE][SIZE] = {};

    unsigned char type = inputType();

    randArr (*bgnMtrx, *psblDgts);

    memcpy (sudoku, bgnMtrx, SIZE * SIZE);
    sudMaker (*sudoku);

    io (*sudoku, type);

    return EXIT_SUCCESS;
}
