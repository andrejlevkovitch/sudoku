//rand_array.c

#include "sudlib.h"

void randArr (unsigned char *outputArr, unsigned char *inputArr)
{
    srand (time (NULL));

    unsigned char y = 1;
    unsigned char z = 0;

    unsigned char endPsblDgt = 0;

    unsigned char copyInArr[SIZE][SIZE] = {};
    unsigned char copyMasEmpty[SIZE] = {}, masEmpty[SIZE] = {};
    unsigned char copyRezerv[SIZE] = {}, rezerv[SIZE] = {};
    unsigned char operMasEmpty[SIZE] = {};

    for (unsigned char i = 0; i < SIZE; ++i) {
        switch (i) {
            case 0: case 1: case 2: endPsblDgt = 8;
                                    break;
            case 3: case 4: case 5: endPsblDgt = 5;
                                    break;
            case 6: case 7: case 8: endPsblDgt = 2;
                                    break;
        }
        do {
            if (y > 0) {
                memcpy (copyInArr, inputArr, SIZE * SIZE);
                memcpy (copyMasEmpty, masEmpty, SIZE);
                memcpy (copyRezerv, rezerv, SIZE);
            }
            else {
                memcpy (inputArr, copyInArr, SIZE * SIZE);
                memcpy (masEmpty, copyMasEmpty, SIZE);
                memcpy (rezerv, copyRezerv, SIZE);
            }

            if (i > 0) {
                for (unsigned char j = 3; j < SIZE; ++j) {
                    *(masEmpty + j) = *(masEmpty + j) - *(rezerv + j);
                    *(operMasEmpty + j) = *(masEmpty + j);
                }
            }

            for (unsigned char j = 0; j < SIZE; ++j) {
                y = endPsblDgt - *(masEmpty + j) + 1;
                if (y == 0) {
                    break;
                }
                unsigned char x = 0 + rand() % y;

                *(outputArr + i * SIZE + j) = *(inputArr + j * SIZE + x);

                unsigned char jump = 3 * (j / 3);
                for (unsigned char l = jump; l < SIZE; ++l) {
                    for (unsigned char k = 0; k <= endPsblDgt - *(masEmpty + l); ++k) {
                        if (j == 3 || j == 6) {
                            *(rezerv + l) = *(masEmpty + l) - *(operMasEmpty + l);
                        }

                        if (*(outputArr + i * SIZE + j) == *(inputArr + l * SIZE + k)) {
                            z = *(inputArr + l * SIZE + k);
                            *(inputArr + l * SIZE + k) = *(inputArr + l * SIZE + endPsblDgt - *(masEmpty + l));

                            if (l != j) {
                                *(inputArr + l * SIZE + endPsblDgt - *(masEmpty + l)) = z;
                            }
                            else {
                                *(inputArr + l * SIZE + endPsblDgt - *(masEmpty + l)) = UNKN_ELEMENT;
                            }
                            *(masEmpty + l) += 1;
                            break;
                        }
                    }
                }

                if (i != 2 && i != 5 && i != 8) {
                    for (unsigned char l = 0; l < SIZE; ++l) {
                        if (endPsblDgt - (*(masEmpty + l) - *(rezerv + l)) < 0) {
                            y = 0;
                            break;
                        }
                    }
                }

                if (y == 0) {
                    break;
                }

                if (j == 8 && i != 2 && i != 5 && i != 8) {
                    for (unsigned char l = 3; l < SIZE; ++l) {
                        for (signed char k = endPsblDgt - *(operMasEmpty + l); k > endPsblDgt - 3 - *(operMasEmpty + l); --k) {
                            if (k - *(rezerv + l) >= 0) {
                                z = *(inputArr + l * SIZE + k - *(rezerv +l));
                                *(inputArr + l * SIZE + k - *(rezerv + l)) = *(inputArr + l * SIZE + k);
                                *(inputArr + l * SIZE + k) = z;
                            }
                        }
                    }
                }
            }
        } while (y == 0);

        if (i == 2 || i == 5) {
            sortArr (inputArr, endPsblDgt);
            zeros (masEmpty);
            zeros (rezerv);
            zeros (operMasEmpty);
        }
    }
    return;
}
