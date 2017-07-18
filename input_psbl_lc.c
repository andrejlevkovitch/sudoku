//input_psbl_lc.c

#include "sudlib.h"

void inputPsblLC (unsigned char *array1, unsigned char *array2, unsigned char *matrix)
{
    for (unsigned char i = 0; i < SIZE; ++i) {
        *(array1 + i * (SIZE + 1)) = 9;
        *(array2 + SIZE * SIZE + i) = 9;

        for (unsigned char j = 0; j < SIZE; ++j) {
            *(array1 + i * (SIZE + 1) + j) = j;
            *(array2 + j * (SIZE + 1) + i) = j;
        }

        for (unsigned char j = 0; j < SIZE; ++j) {
            if (*(matrix + i * SIZE + j) != UNKN_ELEMENT) {
                for (unsigned char l = 0; l < *(array1 + i * (SIZE + 1)); ++l) {
                    if (*(matrix + i * SIZE + j) == *(array1 + i * (SIZE + 1) + l)) {
                        *(array1 + i * (SIZE + 1) + l) = *(array1 + i * (SIZE + 1) + *(array1 + i * (SIZE + 1)));
                        *(array1 + i * (SIZE + 1)) -= 1;
                        break;
                    }
                }
            }
            if (*(matrix + j * SIZE + i) != UNKN_ELEMENT) {
                for (unsigned char l = 0; l < *(array2 + SIZE * SIZE + j); ++l) {
                    if (*(matrix + j * SIZE + i) == *(array2 + l * (SIZE + 1) + i)) {
                        *(array2 + l * (SIZE + 1) + i) = *(array2 + *(array2 + SIZE * SIZE + i) + i);
                        *(array2 + SIZE * SIZE + i) -= 1;
                        break;
                    }
                }
            }
        }
    }

    return;
}
