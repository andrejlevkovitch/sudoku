//sud_maker.c

#include "sudlib.h"

void sudMaker (unsigned char *matrix)
{
    unsigned char counter = 0;

    unsigned char trueArr[SIZE][SIZE] = {};
    unsigned char copyArr[SIZE][SIZE] = {};
    unsigned char koordNotZero[SIZE * SIZE + 1] = {};

    unsigned char rmDigits = numCros();

    srand (time(NULL));

    if (rmDigits != 0) {
        do {
            memcpy (copyArr, matrix, SIZE * SIZE);

            for (unsigned char i = 0; i < SIZE; ++i) {
                for (unsigned char j = 0; j < SIZE; ++j) {
                    *(koordNotZero + i * SIZE + j) = i * 10 + j;
                }
            }

            *(koordNotZero + SIZE * SIZE) = SIZE * SIZE;
            counter = 0;
            unsigned char indexNull = 0;

            unsigned char psblS[SIZE][SIZE + 1] = {};
            unsigned char psblC[SIZE][SIZE + 1] = {};

            do {
                memcpy (trueArr, copyArr, SIZE * SIZE);

                unsigned char num = 0 + rand() % (*(koordNotZero + SIZE * SIZE) - counter);
                unsigned char y = *(koordNotZero + num) / 10;
                unsigned char x = *(koordNotZero + num) - y * 10;
                unsigned char z = *(koordNotZero + num);
                *(koordNotZero + num) = *(koordNotZero + *(koordNotZero + SIZE * SIZE) - 1 - counter);
                *(koordNotZero + *(koordNotZero + SIZE * SIZE) - 1 - counter) = z;

                unsigned char copyDig = trueArr[y][x];
                trueArr[y][x] = UNKN_ELEMENT;
                ++indexNull;

                memcpy (copyArr, trueArr, SIZE * SIZE);

                if (indexNull > 12) {

                psblSC (*psblS, *psblC, *trueArr);

                decision (*psblS, *psblC, *trueArr);
                }

                unsigned char solution = true;

                for (unsigned char i = 0; i < SIZE; ++i) {
                    if (psblS[i][SIZE] != 0) {
                        solution = false;
                        break;
                    }
                }

                if (!solution) {
                    copyArr[y][x] = copyDig;
                    ++counter;
                    --indexNull;
                }
                else {
                    *(koordNotZero + SIZE * SIZE) -= 1;

                    if (counter > 0) {
                        z = *(koordNotZero + *(koordNotZero + SIZE * SIZE) - counter);
                        *(koordNotZero + *(koordNotZero + SIZE * SIZE) - counter) = *(koordNotZero + *(koordNotZero + SIZE * SIZE));
                        *(koordNotZero + *(koordNotZero + SIZE * SIZE)) = z;
                    }
                    counter = 0;
                }

                if (counter == *(koordNotZero + SIZE * SIZE)) {
                    break;
                }

            } while (indexNull < rmDigits);
        } while (counter == *(koordNotZero + SIZE * SIZE));

        memcpy (matrix, copyArr, SIZE * SIZE);
    }

    return;
}
