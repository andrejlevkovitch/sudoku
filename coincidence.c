//coincidence.c - проверяет нет ли вводимого значения в уже имеющемся массиве

#include <curses.h>
#include <stdbool.h>
#include "sudlib.h"

bool coincidence (chtype array [][SIZE], const unsigned int numS, const unsigned int numC, const char modify)
{
    bool indicator = false;//индикатор совпадений
    bool stopIter = false;

    unsigned int beginstring = 0;//показатели верхнего левого угла малых квадратов
    unsigned int begincolum = 0;

    unsigned int girandolaKoords [SIZE] = {0, 8, 14, 41, 44, 47, 74, 80, 88};

    unsigned int diagonalKoordsL [SIZE] = {0, 11, 22, 33, 44, 55, 66, 77, 88};
    unsigned int diagonalKoordsR [SIZE] = {8, 17, 26, 35, 44, 53, 62, 71, 80};

    unsigned int string = 0;
    unsigned int colum = 0;

    chtype tempStore = array [numS][numC];
    const unsigned char value = tempStore;

    array [numS][numC] = UNKN_ELEMENT;//чтобы проверяемый элемент не мешал

    for (unsigned int i = 0; i < SIZE; ++i) {
        if (((char) array [i][numC]) == value) {//проверка в строке
            indicator = true;
            break;
        }
    }

    for (unsigned int i = 0; i < SIZE; ++i) {
        if (((char) array [numS][i]) == value) {//проверка в столбце
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
        for (unsigned int i = beginstring; i < beginstring + 3; ++i) {
            for (unsigned int j = begincolum; j < begincolum + 3; ++j) {
                if (((char) array [i][j]) == value) {
                    indicator = true;
                    break;
                }
            }
        }
    }

    if (!indicator && modify == GIRANDOLA) {//проверка жирандоля
        for (unsigned int i = 0; i < SIZE; ++i) {
            if (numS * 10 + numC == girandolaKoords [i]) {
                for (unsigned int j = 0; j < SIZE; ++j) {
                    string = girandolaKoords [j] / 10;
                    colum = girandolaKoords [j] % 10;
                    if (((char) array [string][colum]) == value) {
                        indicator = true;
                        break;
                    }
                }

                break;
            }
        }
    }

    if (!indicator && modify == WINDOKU) {
        stopIter = false;

        switch (numS) {
            case 1: case 2: case 3:
                beginstring = 1;
                break;

            case 5: case 6: case 7:
                beginstring = 5;
                break;

            default:
                stopIter = true;
                break;
        }

        if (!stopIter) {
            switch (numC) {
                case 1: case 2: case 3:
                    begincolum = 1;
                    break;

                case 5: case 6: case 7:
                    begincolum = 5;
                    break;

                default:
                    stopIter = true;
                    break;
            }
        }

        if (!stopIter) {
            for (unsigned int i = beginstring; i < 3 + beginstring; ++i) {
                for (unsigned int j = begincolum; j < 3 + begincolum; ++j) {
                    if (((char) array [i][j]) == value) {
                        indicator = true;
                        break;
                    }
                }

                if (indicator) break;
            }
        }
    }

    if (!indicator && modify == DIAGONAL) {
        for (unsigned int i = 0; i < SIZE; ++i) {
            if (numS * 10 + numC == diagonalKoordsL [i]) {
                for (unsigned int l = 0; l < SIZE; ++l) {
                    string = diagonalKoordsL [l] / 10;
                    colum = diagonalKoordsL [l] % 10;

                    if (((char) array [string][colum]) == value) {
                        indicator = true;
                        break;
                    }
                }

                if (indicator) break;
            }
        }

        if (!indicator) {
            for (unsigned int i = 0; i < SIZE; ++i) {
                if (numS * 10 + numC == diagonalKoordsR [i]) {
                    for (unsigned int l = 0; l < SIZE; ++l) {
                        string = diagonalKoordsR [l] / 10;
                        colum = diagonalKoordsR [l] % 10;

                        if (((char) array [string][colum]) == value) {
                            indicator = true;
                            break;
                        }
                    }

                    if (indicator) break;
                }
            }
        }
    }

    array [numS][numC] = tempStore;//возврат проверяемого значения в матрицу

    return indicator;
}
