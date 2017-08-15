//rand_array.c - рандомизирует массив, создает начальную матрицу судоку

#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "sudlib.h"

void randArr (unsigned char outputArr[][SIZE], const char variety)
{
    srand (time (NULL));

    unsigned char psblDgts [SIZE][SIZE] = {};//возможные значения

    unsigned char randElem = 0;//рандомный элемент

    unsigned char beginstring = 0;//начало большой строки

    unsigned char availElem = 1;//количество возможных для рандома значений
    unsigned char tempStore = 0;

    unsigned char endPsblDgt = 0;//количество ненулевых элементов в матрице

    unsigned char copyInArr [SIZE][SIZE] = {};//копия возможных значений
    unsigned char copyMasEmpty [SIZE] = {}, masEmpty[SIZE] = {};//количество незадействованных ненулевых элементов
    unsigned char copyRezerv [SIZE] = {}, rezerv[SIZE] = {};//переходящие элементы
    unsigned char operMasEmpty [SIZE] = {};//операционная копия возможных значений

    initialization (*psblDgts, SIZE);

    for (unsigned char i = 0; i < SIZE; ++i) {
        switch (i) {
            case 0: case 1: case 2:
                endPsblDgt = 8;
                break;

            case 3: case 4: case 5:
                endPsblDgt = 5;
                break;

            case 6: case 7: case 8:
                endPsblDgt = 2;
                break;
        }

        do {
            if (availElem > 0) {
                memcpy (copyInArr, psblDgts, SIZE * SIZE);
                memcpy (copyMasEmpty, masEmpty, SIZE);
                memcpy (copyRezerv, rezerv, SIZE);
            }
            else {//на случай, если генерация началась повторно
                memcpy (psblDgts, copyInArr, SIZE * SIZE);
                memcpy (masEmpty, copyMasEmpty, SIZE);
                memcpy (rezerv, copyRezerv, SIZE);
            }

            if (i > 0) {//редактирование возможных значений относительно этапа генерации
                for (unsigned char j = 3; j < SIZE; ++j) {
                    masEmpty [j] = masEmpty [j] - rezerv [j];
                    operMasEmpty [j] = masEmpty [j];
                }
            }

            for (unsigned char j = 0; j < SIZE; ++j) {
                availElem = endPsblDgt - masEmpty [j] + 1;//количество доступных для рандома значений

                if (availElem == 0) {
                    break;
                }

                randElem = 0 + rand() % availElem;

                outputArr [i][j] = psblDgts [j][randElem];//присваивание рандомного элемента выводной матрице

                switch (j) {
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

                for (unsigned char l = beginstring; l < SIZE; ++l) {//редактирование матрицы возможных значений осуществляется относительно больших строк
                    for (unsigned char k = 0; k <= endPsblDgt - masEmpty [l]; ++k) {
                        if (j == 3 || j == 6) {
                            rezerv [l] = masEmpty [l] - operMasEmpty [l];
                        }

                        if (outputArr [i][j] == psblDgts [l][k]) {//если сгенерированный элемент есть в строке - он переносится в конец, если он еще и совпадает со столбцом - то вычеркивается
                            tempStore = psblDgts [l][k];
                            psblDgts [l][k] = psblDgts [l][endPsblDgt - masEmpty [l]];

                            if (l != j) {
                                psblDgts [l][endPsblDgt - masEmpty [l]] = tempStore;
                            }
                            else {
                                psblDgts [l][endPsblDgt - masEmpty [l]] = UNKN_ELEMENT;
                            }

                            masEmpty [l] += 1;
                            break;
                        }
                    }
                }

                if (i != 2 && i != 5 && i != 8) {//проверка возможен ли следующий цикл
                    for (unsigned char l = 0; l < SIZE; ++l) {
                        if (endPsblDgt - (masEmpty [l] - rezerv [l]) < 0) {
                            availElem = 0;
                            break;
                        }
                    }
                }

                if (availElem == 0) {
                    break;
                }

                if (j == 8 && i != 2 && i != 5 && i != 8) {//приведение матрицы возможных значений в надлежащий вид для следующей итерации
                    for (unsigned char l = 3; l < SIZE; ++l) {
                        for (signed char k = endPsblDgt - operMasEmpty [l]; k > endPsblDgt - 3 - operMasEmpty [l]; --k) {
                            if (k - rezerv [l] >= 0) {
                                tempStore = psblDgts [l][k - rezerv [l]];
                                psblDgts [l][k - rezerv [l]] = psblDgts [l][k];
                                psblDgts [l][k] = tempStore;
                            }
                        }
                    }
                }
            }
        } while (availElem == 0);

        if (i == 2 || i == 5) {//обнуление и сортировка перед началом большой строки
            sortArr (psblDgts, endPsblDgt);
            zeros (masEmpty);
            zeros (rezerv);
            zeros (operMasEmpty);
        }
    }
    return;
}
