//input_psbl_sc.c - вводит возможные значения в массивы возможных чисел

#include "sudlib.h"

void inputPsblS (unsigned int psblArr [][SIZE + 1], const unsigned int matrix [][SIZE])
{
    for (unsigned int i = 0; i < SIZE; ++i) {
        for (unsigned int j = 0; j < SIZE; ++j) {
            if (matrix [i][j] != UNKN_ELEMENT) {
                for (unsigned int l = 0; l < psblArr [i][SIZE]; ++l) {
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
