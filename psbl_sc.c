//psbl_sc.c - формирует два массива возможных строк и столбцов

#include "sudlib.h"

void psblSC (unsigned char * const arrayS, unsigned char * const arrayC, unsigned char * const matrix)
{
    initialization (arrayS, SIZE + 1);
    initialization (arrayC, SIZE + 1);
    inputPsblL (arrayS, matrix);
    revers (matrix);
    inputPsblL (arrayC, matrix);
    revers (matrix);

    return;
}
