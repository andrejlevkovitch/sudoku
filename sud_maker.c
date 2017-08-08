//sud_maker.c - создает из начальной матрицы судоку - матрицу судоку, имеющую только одно решение

#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include "sudlib.h"

void sudMaker (unsigned char * matrix, const unsigned char rmDigits)
{
    unsigned char trueArr[SIZE][SIZE] = {};
    unsigned char copyArr[SIZE][SIZE] = {};
    unsigned char koordNotZero[SIZE * SIZE + 1] = {};

    unsigned char psblS[SIZE][SIZE + 1] = {};
    unsigned char psblC[SIZE][SIZE + 1] = {};

    unsigned char indexNull = 0;

    unsigned char num = 0;
    unsigned char string = 0;
    unsigned char colum = 0;

    unsigned char tempStore = 0;
    unsigned char copyDig = 0;

    bool solution = true;

    srand (time(NULL));

    do {
        memcpy (copyArr, matrix, SIZE * SIZE);

        for (unsigned char i = 0; i < SIZE; ++i) {
            for (unsigned char j = 0; j < SIZE; ++j) {
                *(koordNotZero + i * SIZE + j) = i * 10 + j;
            }
        }

        *(koordNotZero + SIZE * SIZE) = SIZE * SIZE;
        indexNull = 0;

        do {
            memcpy (trueArr, copyArr, SIZE * SIZE);

            num = 0 + rand() % *(koordNotZero + SIZE * SIZE);

            string = *(koordNotZero + num) / 10;
            colum = *(koordNotZero + num) - string * 10;

            tempStore = *(koordNotZero + num);
            *(koordNotZero + SIZE * SIZE) -= 1;
            *(koordNotZero + num) = *(koordNotZero + *(koordNotZero + SIZE * SIZE));
            *(koordNotZero + *(koordNotZero + SIZE * SIZE)) = tempStore;

            copyDig = trueArr [string][colum];
            trueArr [string][colum] = UNKN_ELEMENT;
            ++indexNull;

            memcpy (copyArr, trueArr, SIZE * SIZE);

            solution = true;

            if (indexNull > 15) {
                psblSC (*psblS, *psblC, *trueArr);
                decision (*psblS, *psblC, *trueArr);

                for (unsigned char i = 0; i < SIZE; ++i) {
                    if (psblS [i][SIZE] != 0) {
                        solution = false;
                        break;
                    }
                }
            }

            if (!solution) {
                copyArr [string][colum] = copyDig;
                --indexNull;
            }

            if (*(koordNotZero + SIZE * SIZE) == 0) {
                break;
            }
        } while (indexNull < rmDigits);

    } while (*(koordNotZero + SIZE * SIZE) == 0);

    memcpy (matrix, copyArr, SIZE * SIZE);

    return;
}
