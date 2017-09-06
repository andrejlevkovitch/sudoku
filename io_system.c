//io.c - система ввода-вывода

#include <curses.h>
#include <stdbool.h>
#include "sudlib.h"

bool ioSystem (unsigned int matrix [][SIZE], const unsigned char type, const unsigned int quantityCrosDigits, const char modify)
{
    bool biColorType = true;//судоку выводится в двух чередующихся цветах, поэтому, для облегчения условия, использую булевский тип

    bool newGame = false;

    unsigned char tempStore = 0;

    unsigned int specialValue = 0;//для других типов судоку

    unsigned int girandolaKoords [SIZE + 1] = {0, 14, 8, 41, 44, 47, 80, 74, 88, 0};//координаты Жирандолы
    unsigned int windokuKoords [SIZE * 4 + 1] = {11, 12, 21, 22, 13, 15, 23, 25, 16, 17, 26, 27, 31, 32, 51, 52, 33, 35, 53, 55, 36, 37, 56, 57, 61, 62, 71, 72, 63, 65, 73, 75, 66, 67, 76, 77, 0};//координаты Виндоку
    unsigned int diagonalKoords [SIZE + SIZE] = {0, 11, 22, 8, 17, 26, 33, 35, 44, 53, 55, 62, 71, 80, 66, 77, 88, 0};//диагональные координаты

    chtype outputElements [SIZE][SIZE] = {};//выводная матрица

    frame(modify);//рамка

    for (unsigned int i = 0; i < 3; ++i) {
        for (unsigned int j = 0; j < 3; ++j) {
            biColorType = !biColorType;//изменение цвета

            for (unsigned int l = 0 + 3 * i; l < 3 + 3 * i; ++l) {
                for (unsigned int n = 0 + 3 * j; n < 3 + 3 * j; ++n) {
                    move (Y0 + l, X0 + n * 2);

                    if (modify == GIRANDOLA || modify == WINDOKU || modify == DIAGONAL) {
                        specialValue = l * 10 + n;
                    }

                    if (modify == WINDOKU && specialValue == windokuKoords [windokuKoords [SIZE * 4]] && n != 1 && n != 5) {
                        addch (UNKN_ELEMENT | COLOR_PAIR (9));
                    }
                    else {
                        addch (UNKN_ELEMENT | COLOR_PAIR (biColorType + 2));
                    }

                    if (matrix [l][n] != UNKN_ELEMENT) {
                        if ((modify == GIRANDOLA && specialValue == girandolaKoords [girandolaKoords [SIZE]]) || (modify == WINDOKU && specialValue == windokuKoords [windokuKoords [SIZE * 4]]) || (modify == DIAGONAL && specialValue == diagonalKoords [diagonalKoords [SIZE + SIZE - 1]])) {
                            outputElements [l][n] = matrix [l][n] | COLOR_PAIR (9);
                        }
                        else {
                            outputElements [l][n] = matrix [l][n] | COLOR_PAIR (biColorType + 2);
                        }

                        addch ((outputElements [l][n] + type) | A_BOLD);
                    }
                    else {
                        if ((modify == GIRANDOLA && specialValue == girandolaKoords [girandolaKoords [SIZE]]) || (modify == WINDOKU && specialValue == windokuKoords [windokuKoords [SIZE * 4]]) || (modify == DIAGONAL && specialValue == diagonalKoords [diagonalKoords [SIZE + SIZE - 1]])) {
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
                    else if (modify == DIAGONAL && specialValue == diagonalKoords [diagonalKoords [SIZE + SIZE - 1]]) {
                        diagonalKoords [SIZE + SIZE - 1] += 1;
                    }
                }
            }
        }
    }

    newGame = cursor (outputElements, matrix, type, quantityCrosDigits, modify);

    if (modify == SOLUTION && newGame) {//если игрок требует решить стороннее судоку
        for (unsigned int i = 0; i < SIZE; ++i) {
            for (unsigned int j = 0; j < SIZE; ++j) {
                matrix [i][j] = tempStore = outputElements [i][j];
            }
        }
    }

    clear();//очистка экрана для нового использования

    return newGame;
}
