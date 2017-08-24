//io.c - система ввода-вывода

#include <curses.h>
#include <stdbool.h>
#include "sudlib.h"

bool ioSystem (unsigned char matrix [][SIZE], const unsigned char type, const unsigned char quantityCrosDigits, const char modify)
{
    bool biColorType = true;//судоку выводится в двух чередующихся цветах, поэтому, для облегчения условия, использую булевский тип

    bool newGame = false;

    unsigned char specialValue = 0;//для других типов судоку

    unsigned char girandolaKoords [SIZE + 1] = {0, 14, 8, 41, 44, 47, 80, 74, 88, 0};//координаты Жирандолы
    unsigned char windokuKoords [SIZE * 4 + 1] = {11, 12, 21, 22, 13, 15, 23, 25, 16, 17, 26, 27, 31, 32, 51, 52, 33, 35, 53, 55, 36, 37, 56, 57, 61, 62, 71, 72, 63, 65, 73, 75, 66, 67, 76, 77, 0};//координаты Виндоку

    chtype outputElements [SIZE][SIZE] = {};//выводная матрица
    chtype space = 0;//просто пробел, заполнение пробелов между цифрами в судоку

    frame(modify);//рамка

    for (unsigned char i = 0; i < 3; ++i) {
        for (unsigned char j = 0; j < 3; ++j) {
            biColorType = !biColorType;//изменение цвета

            for (unsigned char l = 0 + 3 * i; l < 3 + 3 * i; ++l) {
                for (unsigned char n = 0 + 3 * j; n < 3 + 3 * j; ++n) {
                    move (Y0 + l, X0 + n * 2);

                    if (modify == GIRANDOLA || modify == WINDOKU) {
                        specialValue = l * 10 + n;
                    }

                    if (modify == WINDOKU && specialValue == windokuKoords [windokuKoords [SIZE * 4]] && n != 1 && n != 5) {
                        space = ' ' | COLOR_PAIR (9);
                    }
                    else {
                        space = ' ' | COLOR_PAIR (biColorType + 2);
                    }

                    addch (space);

                    if (matrix [l][n] != UNKN_ELEMENT) {
                        if ((modify == GIRANDOLA && specialValue == girandolaKoords [girandolaKoords [SIZE]]) || (modify == WINDOKU && specialValue == windokuKoords [windokuKoords [SIZE * 4]])) {
                            outputElements [l][n] = matrix [l][n] | COLOR_PAIR (9);
                        }
                        else {
                            outputElements [l][n] = matrix [l][n] | COLOR_PAIR (biColorType + 2);
                        }
                        addch ((outputElements [l][n] + type) | A_BOLD);
                    }
                    else {
                        if ((modify == GIRANDOLA && specialValue == girandolaKoords [girandolaKoords [SIZE]]) || (modify == WINDOKU && specialValue == windokuKoords [windokuKoords [SIZE * 4]])) {
                            outputElements [l][n] = matrix [l][n] | COLOR_PAIR (10);
                        }
                        else {
                            outputElements [l][n] = matrix [l][n] | COLOR_PAIR (biColorType + 4);
                        }
                        addch (outputElements [l][n] | A_BOLD);
                    }

                    if (modify == GIRANDOLA && specialValue == girandolaKoords [girandolaKoords [SIZE]]) {
                        girandolaKoords [SIZE] += 1;
                    }
                    else if (modify == WINDOKU && specialValue == windokuKoords [windokuKoords [SIZE * 4]]) {
                        windokuKoords [SIZE * 4] += 1;
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
