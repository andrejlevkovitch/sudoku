//psbl_sc.c - формирует два массива возможных строк и столбцов

#include "sudlib.h"

void psblSC (unsigned char arrayS [][SIZE + 1], unsigned char arrayC [][SIZE + 1], unsigned char matrix [][SIZE])
{
    initialization (*arrayS, SIZE + 1);
    initialization (*arrayC, SIZE + 1);

    inputPsblS (arrayS, matrix);//ввод возможных значений в строках

    revers (matrix);//отображение матрицы
    inputPsblS (arrayC, matrix);//ввод возможных значений в столбцах (столбцы теперь являются строками)

    revers (matrix);//возврат матрицы к начальному значению

    return;
}
