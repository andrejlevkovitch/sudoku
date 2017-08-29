//rand_array_special.c - рандомизация для особых случаев

#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include "sudlib.h"

void randArrSpecial (unsigned char outputArr [][SIZE], const char variety)
{
    srand (time(NULL));

    signed char prognoz [SIZE][SIZE][SIZE + 1] = {};//1 и 2 измерения - это строки и столбцы судоку, а 3-е - возможные значения в данной клетке; SIZE + 1 - хранит количество возможных элементов

    unsigned char randElement = 0;

    unsigned char girandolaKoords [SIZE] = {0, 8, 14, 41, 44, 47, 74, 80, 88};
    unsigned char girandolaValues [SIZE + 1] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    unsigned char diagonalKoordsL [SIZE] = {0, 11, 22, 33, 44, 55, 66, 77, 88};
    unsigned char diagonalKoordsR [SIZE] = {8, 17, 26, 35, 44, 53, 62, 71, 80};

    unsigned char string = 0;
    unsigned char colum = 0;

    unsigned char numS = 0;
    unsigned char numC = 0;

    unsigned char psblS [SIZE][SIZE + 1] = {};
    unsigned char psblC [SIZE][SIZE + 1] = {};

    unsigned char copyBasisArr [SIZE][SIZE] = {};

    unsigned char minValue = 0;

    unsigned char tempStore = 0;

    unsigned char beginstring = 0;
    unsigned char begincolum = 0;

    bool solOne = false;
    bool solTwo = false;
    bool minPrognoz = false;
    bool bigIter = false;
    bool fromBegin = false;

    if (variety == GIRANDOLA) {//рандомизация константных значений жирандоля
        for (unsigned char i = 0; i < SIZE; ++i) {
            randElement = 0 + rand() % girandolaValues [SIZE];

            girandolaValues [SIZE] -= 1;

            if (randElement != girandolaValues [SIZE]) {
                tempStore = girandolaValues [randElement];
                girandolaValues [randElement] = girandolaValues [girandolaValues [SIZE]];
                girandolaValues [girandolaValues [SIZE]] = tempStore;
            }
        }
    }

    do {
        fromBegin = false;

        outputArr [1][1] = 0;
        forecasting (outputArr, prognoz, 1, 1, variety);

        for (unsigned char i = 0; i < SIZE; ++i) {//инициализация прогноза
            for (unsigned char j = 0; j < SIZE; ++j) {
                for (unsigned char n = 0; n < SIZE + 1; ++n) {
                    prognoz [i][j][n] = n;
                }
            }
        }

        for (unsigned char i = 0; i < SIZE; ++i) {//обнуление начальной матрицы
            for (unsigned char j = 0; j < SIZE; ++j) {
                outputArr [i][j] = UNKN_ELEMENT;
            }
        }

        if (variety == GIRANDOLA) {//вычеркивание значений жиндораля
            for (unsigned char i = 0; i < SIZE; ++i) {
                string = girandolaKoords [i] / 10;
                colum = girandolaKoords [i] % 10;

                outputArr [string][colum] = girandolaValues [i];
                forecasting (outputArr, prognoz, string, colum, variety);
            }
        }

        do {
            do {
                do {
                    solOne = false;

                    for (unsigned char i = 0; i < SIZE; ++i) {//нахождение единственно-возможного значения
                        for (unsigned char j = 0; j < SIZE; ++j) {
                            if (outputArr [i][j] == UNKN_ELEMENT) {
                                if (prognoz [i][j][SIZE] == 1) {
                                    prognoz [i][j][SIZE] -= 1;
                                    outputArr [i][j] = prognoz [i][j][prognoz [i][j][SIZE]];

                                    string = i;
                                    colum = j;

                                    solOne = true;

                                    break;
                                }
                            }
                        }

                        if (solOne) break;
                    }

                    forecasting (outputArr, prognoz, string, colum, variety);

                } while (solOne);

                solTwo = false;

                memcpy (copyBasisArr, outputArr, SIZE * SIZE);//решение
                psblSC (psblS, psblC, outputArr);
                decision (psblS, psblC, outputArr);

                for (unsigned char i = 0; i < SIZE; ++i) {//редактирование прогноза после решения
                    for (unsigned char j = 0; j < SIZE; ++j) {
                        if (copyBasisArr [i][j] != outputArr[i][j]) {
                            forecasting (outputArr, prognoz, i, j, variety);
                            solTwo = true;
                        }
                    }
                }
            } while (solTwo);

            bigIter = false;

            for (unsigned char i = 0; i < SIZE; ++i) {//проверка на наличие пустых ячеек
                for (unsigned char j = 0; j < SIZE; ++j) {
                    if (outputArr [i][j] == UNKN_ELEMENT) {
                        bigIter = true;
                        break;
                    }
                }

                if (bigIter) break;
            }

            if (!bigIter) break;//когда получено окончательное решение

            minValue = 9;
            minPrognoz = false;

            for (unsigned char i = 0; i < SIZE; ++i) {//нахождение минимальных прогнозов для последующего рандомного выбора
                for (unsigned char j = 0; j < SIZE; ++j) {
                    if (outputArr [i][j] == UNKN_ELEMENT && prognoz [i][j][SIZE] < minValue) {
                        string = i;
                        colum = j;
                        minValue = prognoz [i][j][SIZE];

                        if (prognoz [i][j][SIZE] == 2) {
                            minPrognoz = true;
                            break;
                        }

                        if (prognoz [i][j][SIZE] < 2) {//если прога зашла в тупик, все начинается с начала
                            fromBegin = true;
                            break;
                        }
                    }
                }

                if (minPrognoz || fromBegin) break;
            }

            if (fromBegin) break;

            randElement = 0 + rand() % prognoz [string][colum][SIZE];//рандомный элемент
            outputArr [string][colum] = prognoz [string][colum][randElement];
            forecasting (outputArr, prognoz, string, colum, variety);

        } while (bigIter);

        if (variety == WINDOKU && !fromBegin) {//проверка для виндоку, обусловлена тем, что decision не учитывает прогноз
            for (unsigned char i = 0; i < 4; ++i) {
                switch (i) {
                    case 0:
                        beginstring = 1;
                        begincolum = 1;
                        break;

                    case 1:
                        beginstring = 1;
                        begincolum = 5;
                        break;

                    case 2:
                        beginstring = 5;
                        begincolum = 1;
                        break;

                    case 3:
                        beginstring = 5;
                        begincolum = 5;
                }

                for (unsigned char l = beginstring; l < 3 + beginstring; ++l) {
                    for (unsigned char k = begincolum; k < 3 + begincolum; ++k) {
                        for (unsigned char m = beginstring; m < 3 + beginstring; ++m) {
                            for (unsigned char n = begincolum; n < 3 + begincolum; ++n) {
                                if (outputArr [l][k] == outputArr [m][n] && m * 10 + n != l * 10 + k) {
                                    fromBegin = true;
                                    break;
                                }
                            }

                            if (fromBegin) break;
                        }

                        if (fromBegin) break;
                    }

                    if (fromBegin) break;
                }

                if (fromBegin) break;
            }
        }

        if (variety == DIAGONAL && !fromBegin) {
            for (unsigned char i = 0; i < SIZE; ++i) {//проверка в первой диагонали
                string = diagonalKoordsL [i] / 10;
                colum = diagonalKoordsL [i] % 10;

                for (unsigned char j = 0; j < SIZE; ++j) {
                    numS = diagonalKoordsL [j] / 10;
                    numC = diagonalKoordsL [j] % 10;

                    if (outputArr [string][colum] == outputArr [numS][numC] && diagonalKoordsL [i] != diagonalKoordsL [j]) {
                        fromBegin = true;
                        break;
                    }
                }

                if (fromBegin) break;
            }

            if (!fromBegin) {
                for (unsigned char i = 0; i < SIZE; ++i) {//проверка во второй диагонали
                    string = diagonalKoordsR [i] / 10;
                    colum = diagonalKoordsR [i] % 10;

                    for (unsigned char j = 0; j < SIZE; ++j) {
                        numS = diagonalKoordsR [j] / 10;
                        numC = diagonalKoordsR [j] % 10;

                        if (outputArr [string][colum] == outputArr [numS][numC] && diagonalKoordsR [i] != diagonalKoordsR [j]) {
                            fromBegin = true;
                            break;
                        }
                    }

                    if (fromBegin) break;
                }
            }
        }

    } while (fromBegin);

    return;
}
