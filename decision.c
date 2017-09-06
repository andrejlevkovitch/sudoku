//decision.c - решает судоку

#include <stdbool.h>
#include "sudlib.h"

void decision (unsigned int arrayS [][SIZE + 1], unsigned int arrayC [][SIZE + 1], unsigned int matrix [][SIZE])
{
    unsigned int numColum = 0;//координаты текущей строки и столбца
    unsigned int numString = 0;

    unsigned int beginstring = 0;//координаты малого квадрата (левый верхний угол)
    unsigned int begincolum = 0;

    unsigned int rezult = 0;//количество совпадений

    unsigned int indexCoincidence = 0;

    unsigned int tempStore = 0;

    unsigned int masFreeColum [SIZE + 1] = {};//незанятые значения в строке
    unsigned int masBuzyQuadr [SIZE + 1] = {};//занятые значения в малом квадрате

    bool reversOn = false;
    bool solution = false;
    bool rezInIter = false;

    do {
        rezInIter = false;

        do {
            solution = false;

            for (unsigned int i = 0; i < SIZE; ++i) {
                if (arrayS [i][SIZE] != 0) {

                    masFreeColum [SIZE] = 0;

                    for (unsigned int j = 0; j < SIZE; ++j) {//формирование матрицы свободных значений в строке
                        if (matrix [i][j] == UNKN_ELEMENT) {
                            masFreeColum [masFreeColum [SIZE]] = j;
                            masFreeColum [SIZE] += 1;
                        }
                    }

                    for (signed int j = arrayS [i][SIZE] - 1; j >= 0; --j) {
                        rezult = 0;

                        for (unsigned int l = 0; l < masFreeColum [SIZE]; ++l) {

                            switch (i) {
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

                            switch (masFreeColum [l]) {
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

                            masBuzyQuadr [SIZE] = 0;

                            for (unsigned int k = beginstring; k < beginstring + 3; ++k) {//формирование матрицы занятых значений в текущем малом квадрате
                                for (unsigned int n = begincolum; n < begincolum + 3; ++n) {
                                    if (matrix [k][n] != UNKN_ELEMENT) {
                                        masBuzyQuadr [masBuzyQuadr [SIZE]] = matrix [k][n];
                                        masBuzyQuadr [SIZE] += 1;
                                    }
                                }
                            }

                            indexCoincidence = 0;

                            for (signed int m = arrayC [masFreeColum [l]][SIZE] - 1; m >= 0; --m) {
                                for (unsigned int n = 0; n < masBuzyQuadr [SIZE]; ++n) {
                                    if (arrayC [masFreeColum [l]][m] == masBuzyQuadr [n]) {//вычеркивание из массива возможных значений встречающихся в квадрате значений

                                        arrayC [masFreeColum [l]][SIZE] -= 1;
                                        if (m != arrayC [masFreeColum [l]][SIZE]) {
                                            tempStore = arrayC [masFreeColum [l]][m];
                                            arrayC [masFreeColum [l]][m] = arrayC [masFreeColum [l]][arrayC [masFreeColum [l]][SIZE]];
                                            arrayC [masFreeColum [l]][arrayC [masFreeColum [l]][SIZE]] = tempStore;
                                        }

                                        masBuzyQuadr [SIZE] -= 1;
                                        masBuzyQuadr [n] = masBuzyQuadr [masBuzyQuadr [SIZE]];
                                        ++indexCoincidence;
                                        break;
                                    }
                                }
                            }

                            for (unsigned int m = 0; m < arrayC [masFreeColum [l]][SIZE]; ++m) {
                                if (arrayS [i][j] == arrayC [masFreeColum [l]][m]) {//есть ли возможность вставить значение
                                    ++rezult;
                                    numString = m;
                                    numColum = masFreeColum [l];
                                    break;
                                }
                            }

                            arrayC [masFreeColum [l]][SIZE] += indexCoincidence;
                            if (rezult > 1) break;//если можно подставить более одного значения, то эта не подходящая строка
                        }

                        if (rezult == 1) {//елси возможное значение только одно, то это значение единственное возможное и сразу подставляется в матрицу
                            matrix [i][numColum] = arrayS [i][j];
                            arrayS [i][SIZE] -= 1;
                            arrayS [i][j] = arrayS [i][arrayS [i][SIZE]];

                            arrayC [numColum][SIZE] -= 1;
                            arrayC [numColum][numString] = arrayC [numColum][arrayC [numColum][SIZE]];

                            solution = true;
                            rezInIter = true;
                        }
                    }
                }
            }

        } while (solution);

        if (rezInIter) {//если решение найдено не было, но в предыдудущих итерациях еще были найдены верные значения, то матрица переварачивается
            for (unsigned int i = 0; i < SIZE; ++i) {
                if (arrayS [i][SIZE] != 0) {
                    subs (arrayS, arrayC);
                    revers (matrix);
                    reversOn = !reversOn;
                    break;
                }
            }
        }
        else if (reversOn) {//если результата в предыдущей итерации не было и реверс включен, то матрица откатывается в дефолтный вид
            subs (arrayS, arrayC);
            revers (matrix);
        }

    } while (rezInIter);

    return;
}
