//main.c

#include "sudlib.h"

int main (void)
{
    unsigned char psblDgts[SIZE][SIZE] = {};
    unsigned char bgnMtrx[SIZE][SIZE] = {};
    unsigned char sudoku[SIZE][SIZE] = {};

    unsigned char type = 0;
    type = inputType();

    initialization (*psblDgts, SIZE);

    randArr (*bgnMtrx, *psblDgts);

    memcpy (sudoku, bgnMtrx, SIZE * SIZE);
    sudMaker (*sudoku);
    printMas (*sudoku, type, SIZE, SIZE);

    return EXIT_SUCCESS;
}
