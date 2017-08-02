//input_psbl_sc.c - вводит возможные значения в массивы возможных чисел

#include "sudlib.h"

void inputPsblS (unsigned char * const psblArr, const unsigned char * const matrix)
{
    for (unsigned char i = 0; i < SIZE; ++i) {
        *(psblArr + i * (SIZE + 1) + SIZE) = 9;

        for (unsigned char j = 0; j < SIZE; ++j) {
            if (*(matrix + i * SIZE + j) != UNKN_ELEMENT) {
                for (unsigned char l = 0; l < *(psblArr + i * (SIZE + 1) + SIZE); ++l) {
                    if (*(matrix + i * SIZE + j) == *(psblArr + i * (SIZE + 1) + l)) {
                        *(psblArr + i * (SIZE + 1) + SIZE) -= 1;
                        *(psblArr + i * (SIZE + 1) + l) = *(psblArr + i * (SIZE + 1) + *(psblArr + i * (SIZE + 1) + SIZE));
                        break;
                    }
                }
            }
        }
    }

    return;
}
