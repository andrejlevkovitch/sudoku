//rand_array_special.c - рандомизация для особых случаев

#include "../../include/sudlib.h"
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

void randArrSpecial (unsigned int outputArr [][SIZE], const char variety)
{
    srand (time(NULL));

    signed int prognoz [SIZE][SIZE][SIZE + 1] = {};//1 и 2 измерения - это строки и столбцы судоку, а 3-е - возможные значения в данной клетке; SIZE + 1 - хранит количество возможных элементов

    unsigned int randElement = 0;

    unsigned int girandolaKoords [SIZE] = {0, 8, 14, 41, 44, 47, 74, 80, 88};
    unsigned int girandolaValues [SIZE + 1] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    unsigned int diagonalKoordsL [SIZE] = {0, 11, 22, 33, 44, 55, 66, 77, 88};
    unsigned int diagonalKoordsR [SIZE] = {8, 17, 26, 35, 44, 53, 62, 71, 80};

    unsigned int string = 0;
    unsigned int colum = 0;

    unsigned int numS = 0;
    unsigned int numC = 0;

    unsigned int psblS [SIZE][SIZE + 1] = {};
    unsigned int psblC [SIZE][SIZE + 1] = {};

    unsigned int copyBasisArr [SIZE][SIZE] = {};

    unsigned int minValue = 0;

    unsigned int tempStore = 0;

    unsigned int beginstring = 0;
    unsigned int begincolum = 0;

    bool solOne = false;
    bool solTwo = false;
    bool minPrognoz = false;
    bool bigIter = false;
    bool fromBegin = false;

    if (variety == GIRANDOLA) {//рандомизация константных значений жирандоля
        for (unsigned int i = 0; i < SIZE; ++i) {
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

        for (unsigned int i = 0; i < SIZE; ++i) {//инициализация прогноза
            for (unsigned int j = 0; j < SIZE; ++j) {
                for (unsigned int n = 0; n < SIZE + 1; ++n) {
                    prognoz [i][j][n] = n;
                }
            }
        }

        for (unsigned int i = 0; i < SIZE; ++i) {//обнуление начальной матрицы
            for (unsigned int j = 0; j < SIZE; ++j) {
                outputArr [i][j] = UNKN_ELEMENT;
            }
        }

        if (variety == GIRANDOLA) {//вычеркивание значений жиндораля
            for (unsigned int i = 0; i < SIZE; ++i) {
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

                    for (unsigned int i = 0; i < SIZE; ++i) {//нахождение единственно-возможного значения
                        for (unsigned int j = 0; j < SIZE; ++j) {
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

                memcpy (copyBasisArr, outputArr, SIZE * SIZE * sizeof (**outputArr));//решение
                psblSC (psblS, psblC, outputArr);
                decision (psblS, psblC, outputArr);

                for (unsigned int i = 0; i < SIZE; ++i) {//редактирование прогноза после решения
                    for (unsigned int j = 0; j < SIZE; ++j) {
                        if (copyBasisArr [i][j] != outputArr[i][j]) {
                            forecasting (outputArr, prognoz, i, j, variety);
                            solTwo = true;
                        }
                    }
                }
            } while (solTwo);

            bigIter = false;

            for (unsigned int i = 0; i < SIZE; ++i) {//проверка на наличие пустых ячеек
                for (unsigned int j = 0; j < SIZE; ++j) {
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

            for (unsigned int i = 0; i < SIZE; ++i) {//нахождение минимальных прогнозов для последующего рандомного выбора
                for (unsigned int j = 0; j < SIZE; ++j) {
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
            for (unsigned int i = 0; i < 4; ++i) {
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

                for (unsigned int l = beginstring; l < 3 + beginstring; ++l) {
                    for (unsigned int k = begincolum; k < 3 + begincolum; ++k) {
                        for (unsigned int m = beginstring; m < 3 + beginstring; ++m) {
                            for (unsigned int n = begincolum; n < 3 + begincolum; ++n) {
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
            for (unsigned int i = 0; i < SIZE; ++i) {//проверка в первой диагонали
                string = diagonalKoordsL [i] / 10;
                colum = diagonalKoordsL [i] % 10;

                for (unsigned int j = 0; j < SIZE; ++j) {
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
                for (unsigned int i = 0; i < SIZE; ++i) {//проверка во второй диагонали
                    string = diagonalKoordsR [i] / 10;
                    colum = diagonalKoordsR [i] % 10;

                    for (unsigned int j = 0; j < SIZE; ++j) {
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
