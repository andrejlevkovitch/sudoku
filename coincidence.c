//coincidence.c - проверяет нет ли вводимого значения в уже имеющемся массиве

#include <ncurses.h>
#include <stdbool.h>
#include "sudlib.h"

bool coincidence (chtype * array, const unsigned char numS, const unsigned char numC)
{
    bool indicator = false;

    unsigned char digit = 0;

    unsigned char krajline = 0;
    unsigned char krajcolum = 0;

    initscr();

    chtype tempStore = *(array + numS * SIZE + numC);
    const unsigned char value = tempStore;
    *(array + numS * SIZE + numC) = UNKN_ELEMENT;

    for (unsigned char i = 0; i < SIZE; ++i) {
        if ((digit = *(array + i * SIZE + numC)) == value) {
            indicator = true;
            break;
        }

        if ((digit = *(array + numS * SIZE + i)) == value) {
            indicator = true;
            break;
        }
    }

    switch (numS) {
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

    switch (numC) {
        case 0: case 1: case 2:
            krajcolum = 0;
            break;
        case 3: case 4: case 5:
            krajcolum = 3;
            break;
        case 6: case 7: case 8:
            krajcolum = 6;
            break;
    }


    if (!indicator) {
        for (unsigned char i = krajline; i < krajline + 3; ++i) {
            for (unsigned char j = krajcolum; j < krajcolum + 3; ++j) {
                if ((digit =*(array + i * SIZE + j)) == value) {
                    indicator = true;
                    break;
                }
            }
        }
    }

    *(array + numS * SIZE + numC) = tempStore;

    endwin();

    return indicator;
}
