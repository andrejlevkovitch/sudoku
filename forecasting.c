//forecasting.c - редактрирование матрицы прогноза

#include <stdbool.h>
#include "sudlib.h"

void forecasting (unsigned int basisArr [][SIZE], signed int prognoz [][SIZE][SIZE + 1], unsigned int string, unsigned int colum, char variety)
{
    unsigned int beginstring = 0;
    unsigned int begincolum = 0;

    unsigned int numS = 0;
    unsigned int numC = 0;

    bool stopIter = false;

    unsigned int diagonalKoordsL [SIZE] = {0, 11, 22, 33, 44, 55, 66, 77, 88};
    unsigned int diagonalKoordsR [SIZE] = {8, 17, 26, 35, 44, 53, 62, 71, 80};

    for (unsigned int i = 0; i < SIZE; ++i) {//вычеркивание встречающихся значений в строке
        if (basisArr [i][colum] == UNKN_ELEMENT) {
            for (unsigned int n = 0; n < prognoz [i][colum][SIZE]; ++n) {
                if (prognoz [i][colum][n] == basisArr [string][colum]) {
                    prognoz [i][colum][SIZE] -= 1;
                    prognoz [i][colum][n] = prognoz [i][colum][prognoz [i][colum][SIZE]];
                }
            }
        }
    }

    for (unsigned int i = 0; i < SIZE; ++i) {//вычеркивание встречающихся значений в столбце
        if (basisArr [string][i] == UNKN_ELEMENT) {
            for (unsigned int n = 0; n < prognoz [string][i][SIZE]; ++n) {
                if (prognoz [string][i][n] == basisArr [string][colum]) {
                    prognoz [string][i][SIZE] -= 1;
                    prognoz [string][i][n] = prognoz [string][i][prognoz [string][i][SIZE]];
                }
            }
        }
    }

    switch (string) {
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

    switch (colum) {
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

    for (unsigned int i = beginstring; i < 3 + beginstring; ++i) {//вычеркивание значений встречающихся в малых квадратах
        for (unsigned int j = begincolum; j < 3 + begincolum; ++j) {
            if (basisArr [i][j] == UNKN_ELEMENT) {
                for (unsigned int n = 0; n < prognoz [i][j][SIZE]; ++n) {
                    if (prognoz [i][j][n] == basisArr [string][colum]) {
                        prognoz [i][j][SIZE] -= 1;
                        prognoz [i][j][n] = prognoz [i][j][prognoz [i][j][SIZE]];
                    }
                }
            }
        }
    }

    if (variety == WINDOKU) {
        stopIter = false;

        switch (string) {
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
            switch (colum) {
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
                    if (basisArr [i][j] == UNKN_ELEMENT) {
                        for (unsigned int n = 0; n < prognoz [i][j][SIZE]; ++n) {
                            if (prognoz [i][j][n] == basisArr [string][colum]) {
                                prognoz [i][j][SIZE] -= 1;
                                prognoz [i][j][n] = prognoz [i][j][prognoz [i][j][SIZE]];
                            }
                        }
                    }
                }
            }
        }
    }

    if (variety == DIAGONAL) {
        for (unsigned int i = 0; i < SIZE; ++i) {
            if (string * 10 + colum == diagonalKoordsL [i]) {//вычеркивание значений прогноза из левой диагонали
                for (unsigned int j = 0; j < SIZE; ++j) {
                    numS = diagonalKoordsL [j] / 10;
                    numC = diagonalKoordsL [j] % 10;

                    if (basisArr [numS][numC] == UNKN_ELEMENT) {
                        for (unsigned int n = 0; n < prognoz [numS][numC][SIZE]; ++n) {
                            if (prognoz [numS][numC][n] == basisArr [string][colum]) {
                                prognoz [numS][numC][SIZE] -= 1;
                                prognoz [numS][numC][n] = prognoz [numS][numC][prognoz [numS][numC][SIZE]];
                            }
                        }
                    }
                }

                break;
            }
        }

        for (unsigned int i = 0; i < SIZE; ++i) {
            if (string * 10 + colum == diagonalKoordsR [i]) {//вычеркивание значений из правой диагонали
                for (unsigned int j = 0; j < SIZE; ++j) {
                    numS = diagonalKoordsR [j] / 10;
                    numC = diagonalKoordsR [j] % 10;

                    if (basisArr [numS][numC] == UNKN_ELEMENT) {
                        for (unsigned int n = 0; n < prognoz [numS][numC][SIZE]; ++n) {
                            if (prognoz [numS][numC][n] == basisArr [string][colum]) {
                                prognoz [numS][numC][SIZE] -= 1;
                                prognoz [numS][numC][n] = prognoz [numS][numC][prognoz [numS][numC][SIZE]];
                            }
                        }
                    }
                }

                break;
            }
        }
    }

    return;
}
