//sudoku.c

#include "sudlib.h"

int main (void)
{
    unsigned char psblDgts[SIZE][SIZE] = {};
    unsigned char bgnMtrx[SIZE][SIZE] = {};
    unsigned char sudoku[SIZE][SIZE] = {};

    unsigned char mas1[SIZE][SIZE + 1] = {};
    unsigned char mas2[SIZE][SIZE + 1] = {};

    unsigned char type;
    type = inputType();

    initialization (*psblDgts, SIZE);

    randArr (*bgnMtrx, *psblDgts);

    printMas (*bgnMtrx, type, SIZE, SIZE);

    bgnMtrx [5][6] = UNKN_ELEMENT;

    psblSC (*mas1, *mas2, *bgnMtrx);
    printMas (*bgnMtrx, type, SIZE, SIZE);
    printMas (*mas1, type, SIZE, SIZE + 1);
    printMas (*mas2, type, SIZE, SIZE + 1);

    return EXIT_SUCCESS;
}
