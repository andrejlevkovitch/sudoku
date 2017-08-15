//sud_maker.c - создает из начальной матрицы судоку - матрицу судоку, имеющую только одно решение

#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include "sudlib.h"

void sudMaker (unsigned char matrix [][SIZE], const unsigned char rmDigits)
{
    unsigned char trueArr [SIZE][SIZE] = {};//операционный массив
    unsigned char copyArr [SIZE][SIZE] = {};
    unsigned char koordNotZero [SIZE * SIZE + 1] = {};//массив с координатами ненулевых значений в матрице, последний элемент хранит количество доступных координат

    unsigned char psblS [SIZE][SIZE + 1] = {};//возможные значения в строке, последний столбец хранит количество доступных элементов
    unsigned char psblC [SIZE][SIZE + 1] = {};

    unsigned char indexNull = 0;//количество вычеркнутых элементов, нужен для сверки с входным параметром

    unsigned char num = 0;//вычеркиваемое значение, элемент координатного массива
    unsigned char string = 0;
    unsigned char colum = 0;

    unsigned char tempStore = 0;
    unsigned char copyDig = 0;//копия вычеркиваемого значения

    bool solution = true;

    srand (time(NULL));

    for (unsigned char i = 0; i < SIZE; ++i) {//заполнение координатного массива
        for (unsigned char j = 0; j < SIZE; ++j) {
            koordNotZero [i * SIZE + j] = i * 10 + j;
        }
    }

    do {
        memcpy (copyArr, matrix, SIZE * SIZE);

        koordNotZero [SIZE * SIZE] = SIZE * SIZE;//количество доступных элементов в начале всегда равно 81
        indexNull = 0;

        do {
            memcpy (trueArr, copyArr, SIZE * SIZE);

            num = 0 + rand() % koordNotZero [SIZE * SIZE];

            string = koordNotZero [num] / 10;//определение координат вычеркивоемого элемента
            colum = koordNotZero [num] - string * 10;

            tempStore = koordNotZero [num];
            koordNotZero [SIZE * SIZE] -= 1;
            koordNotZero [num] = koordNotZero [koordNotZero [SIZE * SIZE]];
            koordNotZero [koordNotZero [SIZE * SIZE]] = tempStore;

            copyDig = trueArr [string][colum];
            trueArr [string][colum] = UNKN_ELEMENT;
            ++indexNull;

            memcpy (copyArr, trueArr, SIZE * SIZE);

            solution = true;

            if (indexNull > 15) {//первые 15 вычеркиваемых элементов не нуждаются в проверке
                psblSC (psblS, psblC, trueArr);
                decision (psblS, psblC, trueArr);

                for (unsigned char i = 0; i < SIZE; ++i) {//проверка было ли достигнуто решение
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

    memcpy (matrix, copyArr, SIZE * SIZE);

    return;
}
