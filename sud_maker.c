//sud_maker.c

#include "sudlib.h"

void sudMaker (unsigned char *trueArr)
{
    unsigned char z;
    unsigned char y, x;
    unsigned char counter;
    unsigned char num;
    unsigned char copyDig;

    unsigned char copyArr[SIZE][SIZE] = {};
    unsigned char koordNotZero[SIZE * SIZE + 1] = {};

    unsigned char rmDigits;
    rmDigits = numCros();

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
            do {
                if (*(koordNotZero + SIZE * SIZE) != SIZE * SIZE) {
                    vozvrat (trueArr, *copyArr, SIZE, SIZE);
                }

                num = 0 + rand() % *(koordNotZero + SIZE * SIZE) - counter;
                y = *(koordNotZero + num) / 10;
                x = *(koordNotZero + num) - y * 10;
                z = *(koordNotZero + num);
                *(koordNotZero + num) = *(koordNotZero + *(koordNotZero + SIZE * SIZE) - counter);
                *(koordNotZero + *(koordNotZero + SIZE * SIZE) - counter) = z;

                copyDig = *(trueArr + y * SIZE + x);
                *(trueArr + y * SIZE + x) = UNKN_ELEMENT;

                vozvrat (*copyArr, trueArr, SIZE, SIZE);

            } while (SIZE * SIZE - *(koordNotZero + SIZE * SIZE) < rmDigits);
        } while (counter == *(koordNotZero + SIZE * SIZE));
    }
    return;
}
