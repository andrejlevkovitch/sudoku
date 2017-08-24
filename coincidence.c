//coincidence.c - проверяет нет ли вводимого значения в уже имеющемся массиве

#include <curses.h>
#include <stdbool.h>
#include "sudlib.h"

bool coincidence (chtype array [][SIZE], const unsigned char numS, const unsigned char numC, const char modify)
{
    bool indicator = false;//индикатор совпадений

    unsigned char digit = 0;

    unsigned char beginstring = 0;//показатели верхнего левого угла малых квадратов
    unsigned char begincolum = 0;

    unsigned char girandolaKoords [SIZE] = {0, 8, 14, 41, 44, 47, 74, 80, 88};
    unsigned char string = 0;
    unsigned char colum = 0;

    chtype tempStore = array [numS][numC];
    const unsigned char value = tempStore;

    array [numS][numC] = UNKN_ELEMENT;//чтобы проверяемый элемент не мешал

    for (unsigned char i = 0; i < SIZE; ++i) {
        if ((digit = array [i][numC]) == value) {//проверка в строке
            indicator = true;
            break;
        }
    }

    for (unsigned char i = 0; i < SIZE; ++i) {
        if ((digit = array [numS][i]) == value) {//проверка в столбце
            indicator = true;
            break;
        }
    }

    switch (numS) {
        case 0: case 1: case 2:
            beginstring = 0;
            break;
        case 3: case 4: case 5:
            beginstring = 3;
            break;
        case 6: case 7: case 8:
            beginstring = 6;
            break;
    }

    switch (numC) {
        case 0: case 1: case 2:
            begincolum = 0;
            break;
        case 3: case 4: case 5:
            begincolum = 3;
            break;
        case 6: case 7: case 8:
            begincolum = 6;
            break;
    }


    if (!indicator) {//проверка в малом квадрате
        for (unsigned char i = beginstring; i < beginstring + 3; ++i) {
            for (unsigned char j = begincolum; j < begincolum + 3; ++j) {
                if ((digit = array [i][j]) == value) {
                    indicator = true;
                    break;
                }
            }
        }
    }

    if (!indicator && modify == GIRANDOLA) {//проверка жирандоля
        for (unsigned char i = 0; i < SIZE; ++i) {
            if (numS * 10 + numC == girandolaKoords [i]) {
                for (unsigned char j = 0; j < SIZE; ++j) {
                    string = girandolaKoords [j] / 10;
                    colum = girandolaKoords [j] % 10;
                    if ((digit = array [string][colum]) == value) {
                        indicator = true;
                        break;
                    }
                }

                break;
            }
        }
    }

    array [numS][numC] = tempStore;//возврат проверяемого значения в матрицу

    return indicator;
}
