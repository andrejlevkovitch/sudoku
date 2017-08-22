//forecasting.c - редактрирование матрицы прогноза

#include "sudlib.h"

void forecasting (unsigned char basisArr [][SIZE], signed char prognoz [][SIZE][SIZE + 1], unsigned char string, unsigned char colum)
{
    unsigned char beginstring = 0;
    unsigned char begincolum = 0;

    for (unsigned char i = 0; i < SIZE; ++i) {//вычеркивание встречающихся значений в строке
        if (basisArr [i][colum] == UNKN_ELEMENT) {
            for (unsigned char n = 0; n < prognoz [i][colum][SIZE]; ++n) {
                if (prognoz [i][colum][n] == basisArr [string][colum]) {
                    prognoz [i][colum][SIZE] -= 1;
                    prognoz [i][colum][n] = prognoz [i][colum][prognoz [i][colum][SIZE]];
                }
            }
        }
    }

    for (unsigned char i = 0; i < SIZE; ++i) {//вычеркивание встречающихся значений в столбце
        if (basisArr [string][i] == UNKN_ELEMENT) {
            for (unsigned char n = 0; n < prognoz [string][i][SIZE]; ++n) {
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

    for (unsigned char i = beginstring; i < 3 + beginstring; ++i) {//вычеркивание значений встречающихся в малых квадратах
        for (unsigned char j = begincolum; j < 3 + begincolum; ++j) {
            if (basisArr [i][j] == UNKN_ELEMENT) {
                for (unsigned char n = 0; n < prognoz [i][j][SIZE]; ++n) {
                    if (prognoz [i][j][n] == basisArr [string][colum]) {
                        prognoz [i][j][SIZE] -= 1;
                        prognoz [i][j][n] = prognoz [i][j][prognoz [i][j][SIZE]];
                    }
                }
            }
        }
    }

    return;
}
