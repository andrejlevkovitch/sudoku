//input_psbl_sc.c - вводит возможные значения в массивы возможных чисел

#include "sudlib.h"

void inputPsblS (unsigned char psblArr [][SIZE + 1], const unsigned char matrix [][SIZE])
{
    for (unsigned char i = 0; i < SIZE; ++i) {
        psblArr [i][SIZE] = 9;//последний столбец хранит в себе количество элементов в строке

        for (unsigned char j = 0; j < SIZE; ++j) {
            if (matrix [i][j] != UNKN_ELEMENT) {
                for (unsigned char l = 0; l < psblArr [i][SIZE]; ++l) {
                    if (matrix [i][j] == psblArr [i][l]) {
                        psblArr [i][SIZE] -= 1;
                        psblArr [i][l] = psblArr [i][psblArr [i][SIZE]];
                        break;
                    }
                }
            }
        }
    }

    return;
}
