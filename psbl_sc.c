//psbl_lc.c

#include "sudlib.h"

void psblSC (unsigned char *arrayS, unsigned char *arrayC, unsigned char *matrix)
{
    initialization (arrayS, SIZE + 1);
    initialization (arrayC, SIZE + 1);
    inputPsblL (arrayS, matrix);
    revers (matrix);
    inputPsblL (arrayC, matrix);
    revers (matrix);

    return;
}
