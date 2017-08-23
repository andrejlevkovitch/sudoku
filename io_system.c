//io.c - система ввода-вывода

#include <curses.h>
#include <stdbool.h>
#include "sudlib.h"

bool ioSystem (unsigned char matrix [][SIZE], const unsigned char type, const unsigned char quantityCrosDigits, const char modify)
{
    bool biColorType = true;//судоку выводится в двух чередующихся цветах, поэтому, для облегчения условия, использую булевский тип

    bool newGame = false;

    unsigned char specialValue = 0;//для других типов судоку

    unsigned char girandola [SIZE + 1] = {0, 14, 8, 41, 44, 47, 80, 74, 88, 0};//координаты Жирандолы

    chtype outputElements [SIZE][SIZE] = {};//выводная матрица
    chtype space = 0;//просто пробел, заполнение пробелов между цифрами в судоку

    frame(modify);//рамка

    for (unsigned char i = 0; i < 3; ++i) {
        for (unsigned char j = 0; j < 3; ++j) {
            biColorType = !biColorType;//изменение цвета

            for (unsigned char l = 0 + 3 * i; l < 3 + 3 * i; ++l) {
                for (unsigned char n = 0 + 3 * j; n < 3 + 3 * j; ++n) {
                    move (Y0 + l, X0 + n * 2);

                    space = ' ' | COLOR_PAIR (biColorType + 2);
                    addch (space);

                    if (modify == GIRANDOLA) {
                        specialValue = l * 10 + n;
                    }

                    if (matrix [l][n] != UNKN_ELEMENT) {
                        if (modify == GIRANDOLA && specialValue == girandola [0]) {
                            outputElements [l][n] = matrix [l][n] | COLOR_PAIR (9);
                        }
                        else {
                            outputElements [l][n] = matrix [l][n] | COLOR_PAIR (biColorType + 2);
                        }
                        addch ((outputElements [l][n] + type) | A_BOLD);
                    }
                    else {
                        if (modify == GIRANDOLA && specialValue == girandola [0]) {
                            outputElements [l][n] = matrix [l][n] | COLOR_PAIR (10);
                        }
                        else {
                            outputElements [l][n] = matrix [l][n] | COLOR_PAIR (biColorType + 4);
                        }
                        addch (outputElements [l][n] | A_BOLD);
                    }

                    if (modify == GIRANDOLA && specialValue == girandola [0]) {
                        girandola [SIZE] += 1;
                        girandola [0] = girandola [girandola [SIZE]];
                    }
                }
            }
        }
    }

    newGame = cursor (outputElements, matrix, type, quantityCrosDigits, modify);

    if (modify == SOLUTION && newGame) {//если игрок требует решить стороннее судоку
        for (unsigned char i = 0; i < SIZE; ++i) {
            for (unsigned char j = 0; j < SIZE; ++j) {
                matrix [i][j] = outputElements [i][j];
            }
        }
    }

    clear();//очистка экрана для нового использования

    return newGame;
}
