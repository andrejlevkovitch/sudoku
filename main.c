//main.c

#include <stdlib.h>
#include <string.h>
#include "sudlib.h"

int main (void)
{
    system ("clear");
    unsigned char psblDgts[SIZE][SIZE] = {};

    unsigned char type = inputType();

    initialization (*psblDgts, SIZE);

    unsigned char bgnMtrx[SIZE][SIZE] = {};
    randArr (*bgnMtrx, *psblDgts);

    unsigned char sudoku[SIZE][SIZE] = {};
    memcpy (sudoku, bgnMtrx, SIZE * SIZE);
    sudMaker (*sudoku);
    printMas (*sudoku, type, SIZE, SIZE);

    return EXIT_SUCCESS;
}
