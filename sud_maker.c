//sud_maker.c - создает из начальной матрицы судоку - матрицу судоку, имеющую только одно решение

#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include "sudlib.h"

void sudMaker (unsigned char * matrix, const unsigned char rmDigits)
{
    unsigned char counter = 0;

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

    memcpy (copyArr, matrix, SIZE * SIZE);

    for (unsigned char i = 0; i < SIZE; ++i) {
        for (unsigned char j = 0; j < SIZE; ++j) {
            *(koordNotZero + i * SIZE + j) = i * 10 + j;
        }
    }

    *(koordNotZero + SIZE * SIZE) = SIZE * SIZE;
    counter = 0;
    indexNull = 0;

    do {
        if (counter == *(koordNotZero + SIZE * SIZE)) {
            *(koordNotZero + SIZE * SIZE) += 1;
            counter = 1;
            --indexNull;

            string = *(koordNotZero + *(koordNotZero + SIZE + SIZE)) / 10;
            colum = *(koordNotZero + *(koordNotZero + SIZE + SIZE)) - string * 10;
            copyArr [string][colum] = *(matrix + string * SIZE + colum);
        }

        do {
            memcpy (trueArr, copyArr, SIZE * SIZE);

            num = 0 + rand() % (*(koordNotZero + SIZE * SIZE) - counter);
            string = *(koordNotZero + num) / 10;
            colum = *(koordNotZero + num) - string * 10;
            tempStore = *(koordNotZero + num);
            *(koordNotZero + num) = *(koordNotZero + *(koordNotZero + SIZE * SIZE) - 1 - counter);
            *(koordNotZero + *(koordNotZero + SIZE * SIZE) - 1 - counter) = tempStore;

            copyDig = trueArr [string][colum];
            trueArr [string][colum] = UNKN_ELEMENT;
            ++indexNull;

            memcpy (copyArr, trueArr, SIZE * SIZE);

            solution = true;

            if (indexNull > 12) {
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
                ++counter;
                --indexNull;
            }
            else {
                *(koordNotZero + SIZE * SIZE) -= 1;

                if (counter > 0) {
                    tempStore = *(koordNotZero + *(koordNotZero + SIZE * SIZE) - counter);
                    *(koordNotZero + *(koordNotZero + SIZE * SIZE) - counter) = *(koordNotZero + *(koordNotZero + SIZE * SIZE));
                    *(koordNotZero + *(koordNotZero + SIZE * SIZE)) = tempStore;
                }

                counter = 0;
            }

            if (counter == *(koordNotZero + SIZE * SIZE)) {
                break;
            }

        } while (indexNull < rmDigits);

    } while (counter == *(koordNotZero + SIZE * SIZE));

    memcpy (matrix, copyArr, SIZE * SIZE);

    return;
}
