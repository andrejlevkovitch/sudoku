//sud_maker.c - создает из начальной матрицы судоку - матрицу судоку, имеющую только одно решение

#include "../../include/sudlib.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

void sudMaker (unsigned int matrix [][SIZE], const unsigned int rmDigits)
{
    unsigned int trueArr [SIZE][SIZE] = {};//операционный массив
    unsigned int copyArr [SIZE][SIZE] = {};
    unsigned int koordNotZero [SIZE * SIZE + 1] = {};//массив с координатами ненулевых значений в матрице, последний элемент хранит количество доступных координат

    unsigned int psblS [SIZE][SIZE + 1] = {};//возможные значения в строке, последний столбец хранит количество доступных элементов
    unsigned int psblC [SIZE][SIZE + 1] = {};

    unsigned int indexNull = 0;//количество вычеркнутых элементов, нужен для сверки с входным параметром

    unsigned int num = 0;//вычеркиваемое значение, элемент координатного массива
    unsigned int string = 0;
    unsigned int colum = 0;

    unsigned int tempStore = 0;
    unsigned int copyDig = 0;//копия вычеркиваемого значения

    bool solution = true;

    srand (time(NULL));

    for (unsigned int i = 0; i < SIZE; ++i) {//заполнение координатного массива
        for (unsigned int j = 0; j < SIZE; ++j) {
            koordNotZero [i * SIZE + j] = i * 10 + j;
        }
    }

    do {
        memcpy (copyArr, matrix, SIZE * SIZE * sizeof (**matrix));

        koordNotZero [SIZE * SIZE] = SIZE * SIZE;//количество доступных элементов в начале всегда равно 81
        indexNull = 0;

        do {
            memcpy (trueArr, copyArr, SIZE * SIZE* sizeof (**trueArr));

            num = 0 + rand() % koordNotZero [SIZE * SIZE];

            string = koordNotZero [num] / 10;//определение координат вычеркивоемого элемента
            colum = koordNotZero [num] % 10;

            tempStore = koordNotZero [num];
            koordNotZero [SIZE * SIZE] -= 1;
            koordNotZero [num] = koordNotZero [koordNotZero [SIZE * SIZE]];
            koordNotZero [koordNotZero [SIZE * SIZE]] = tempStore;

            copyDig = trueArr [string][colum];
            trueArr [string][colum] = UNKN_ELEMENT;
            ++indexNull;

            memcpy (copyArr, trueArr, SIZE * SIZE * sizeof (**trueArr));

            solution = true;

            if (indexNull > 15) {//первые 15 вычеркиваемых элементов не нуждаются в проверке
                psblSC (psblS, psblC, trueArr);
                decision (psblS, psblC, trueArr);

                for (unsigned int i = 0; i < SIZE; ++i) {//проверка было ли достигнуто решение
                    if (psblS [i][SIZE] != 0) {
                        solution = false;
                        break;
                    }
                }
            }

            if (!solution) {
                copyArr [string][colum] = copyDig;
                --indexNull;
            }

            if (koordNotZero [SIZE * SIZE] == 0) {
                break;
            }
        } while (indexNull < rmDigits);

    } while (koordNotZero [SIZE * SIZE] == 0);

    memcpy (matrix, copyArr, SIZE * SIZE * sizeof (**matrix));

    return;
}
