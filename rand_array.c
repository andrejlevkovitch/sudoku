//rand_array.c - рандомизирует массив, создает начальную матрицу судоку

#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "sudlib.h"

void randArr (unsigned char * outputArr, const char variety)
{
    srand (time (NULL));

    unsigned char psblDgts [SIZE][SIZE] = {};

    unsigned char randElem = 0;

    unsigned char krajline = 0;

    unsigned char availElem = 1;
    unsigned char tempStore = 0;

    unsigned char endPsblDgt = 0;

    unsigned char copyInArr [SIZE][SIZE] = {};
    unsigned char copyMasEmpty [SIZE] = {}, masEmpty[SIZE] = {};
    unsigned char copyRezerv [SIZE] = {}, rezerv[SIZE] = {};
    unsigned char operMasEmpty [SIZE] = {};

    unsigned char girandola [SIZE] = {0, 8, 14, 41, 44, 47, 74, 80, 88};

    initialization (*psblDgts, SIZE);

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
            if (availElem > 0) {
                memcpy (copyInArr, psblDgts, SIZE * SIZE);
                memcpy (copyMasEmpty, masEmpty, SIZE);
                memcpy (copyRezerv, rezerv, SIZE);
            }
            else {
                memcpy (psblDgts, copyInArr, SIZE * SIZE);
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
                availElem = endPsblDgt - *(masEmpty + j) + 1;
                if (availElem == 0) {
                    break;
                }
                randElem = 0 + rand() % availElem;

                *(outputArr + i * SIZE + j) = psblDgts [j][randElem];

                switch (j) {
                    case 0: case 1: case 2:
                        krajline = 0;
                        break;
                    case 3: case 4: case 5:
                        krajline = 3;
                        break;
                    case 6: case 7: case 8:
                        krajline = 6;
                        break;
                }

                for (unsigned char l = krajline; l < SIZE; ++l) {
                    for (unsigned char k = 0; k <= endPsblDgt - *(masEmpty + l); ++k) {
                        if (j == 3 || j == 6) {
                            *(rezerv + l) = *(masEmpty + l) - *(operMasEmpty + l);
                        }

                        if (*(outputArr + i * SIZE + j) == psblDgts [l][k]) {
                            tempStore = psblDgts [l][k];
                            psblDgts [l][k] = psblDgts [l][endPsblDgt - *(masEmpty + l)];

                            if (l != j) {
                                psblDgts [l][endPsblDgt - *(masEmpty + l)] = tempStore;
                            }
                            else {
                                psblDgts [l][endPsblDgt - *(masEmpty + l)] = UNKN_ELEMENT;
                            }

                            *(masEmpty + l) += 1;
                            break;
                        }
                    }
                }

                if (i != 2 && i != 5 && i != 8) {
                    for (unsigned char l = 0; l < SIZE; ++l) {
                        if (endPsblDgt - (*(masEmpty + l) - *(rezerv + l)) < 0) {
                            availElem = 0;
                            break;
                        }
                    }
                }

                if (availElem == 0) {
                    break;
                }

                if (j == 8 && i != 2 && i != 5 && i != 8) {
                    for (unsigned char l = 3; l < SIZE; ++l) {
                        for (signed char k = endPsblDgt - *(operMasEmpty + l); k > endPsblDgt - 3 - *(operMasEmpty + l); --k) {
                            if (k - *(rezerv + l) >= 0) {
                                tempStore = psblDgts [l][k - *(rezerv +l)];
                                psblDgts [l][k - *(rezerv + l)] = psblDgts [l][k];
                                psblDgts [l][k] = tempStore;
                            }
                        }
                    }
                }
            }
        } while (availElem == 0);

        if (i == 2 || i == 5) {
            sortArr (*psblDgts, endPsblDgt);
            zeros (masEmpty);
            zeros (rezerv);
            zeros (operMasEmpty);
        }
    }
    return;
}
