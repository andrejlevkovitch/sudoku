//sud_maker.c

#include "sudlib.h"

void sudMaker (unsigned char *trueArr)
{
    unsigned char z = 0;
    unsigned char y = 0, x = 0;
    unsigned char counter = 0;
    unsigned char indexNull = 0;
    unsigned char num = 0;
    unsigned char copyDig = 0;

    unsigned char copyArr[SIZE][SIZE] = {};
    unsigned char koordNotZero[SIZE * SIZE + 1] = {};

    bool solution;
    unsigned char psblS[SIZE][SIZE + 1] = {};
    unsigned char psblC[SIZE][SIZE + 1] = {};

    unsigned char rmDigits = 0;
    rmDigits = numCros();

    srand (time(NULL));

    if (rmDigits != 0) {
        do {
            vozvrat (*copyArr, trueArr, SIZE, SIZE);

            for (unsigned char i = 0; i < SIZE; ++i) {
                for (unsigned char j = 0; j < SIZE; ++j) {
                    *(koordNotZero + i * SIZE + j) = i * 10 + j;
                }
            }

            *(koordNotZero + SIZE * SIZE) = SIZE * SIZE;
            counter = 0;
            indexNull = 0;

            do {
                if (indexNull > 0) {
                    vozvrat (trueArr, *copyArr, SIZE, SIZE);
                }

                num = 0 + rand() % (*(koordNotZero + SIZE * SIZE) - counter);
                y = *(koordNotZero + num) / 10;
                x = *(koordNotZero + num) - y * 10;
                z = *(koordNotZero + num);
                *(koordNotZero + num) = *(koordNotZero + *(koordNotZero + SIZE * SIZE) - 1 - counter);
                *(koordNotZero + *(koordNotZero + SIZE * SIZE) - 1 - counter) = z;

                copyDig = *(trueArr + y * SIZE + x);
                *(trueArr + y * SIZE + x) = UNKN_ELEMENT;
                ++indexNull;

                vozvrat (*copyArr, trueArr, SIZE, SIZE);

                psblSC (*psblS, *psblC, trueArr);

                decision (*psblS, *psblC, trueArr);

                solution = true;

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
    }

    vozvrat (trueArr, *copyArr, SIZE, SIZE);

    return;
}
