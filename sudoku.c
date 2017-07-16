//sudoku.c

#include "sudlib.h"

int main (void)
{
    unsigned char psblDgts[SIZE][SIZE] = {};
    unsigned char bgnMtrx[SIZE][SIZE] = {};
    unsigned char sudoku[SIZE][SIZE] = {};

    initialization (*psblDgts);

    randArr (*bgnMtrx, *psblDgts);

    vozvrat (*sudoku, *bgnMtrx, SIZE, SIZE);
    sudMaker (*sudoku);
    printMas (*sudoku);

    return EXIT_SUCCESS;
}
