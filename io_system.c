//io.c - система ввода-вывода

#include <ncurses.h>
#include <stdbool.h>
#include "sudlib.h"

bool ioSystem (const unsigned char * matrix, const unsigned char type, const unsigned char quantityCrosDigits)
{
//    initscr();// открытие в файле input_type.c

    bool biColorType = true;

    bool newGame = false;

    chtype outputElements [SIZE][SIZE] = {};
    chtype space = 0;

    frame();

    init_pair (2, COLOR_WHITE, COLOR_GREEN);
    init_pair (3, COLOR_WHITE, COLOR_BLUE);
    init_pair (4, COLOR_YELLOW, COLOR_GREEN);
    init_pair (5, COLOR_YELLOW, COLOR_BLUE);
    init_pair (6, COLOR_RED, COLOR_MAGENTA);

    for (unsigned char i = 0; i < 3; ++i) {
        for (unsigned char j = 0; j < 3; ++j) {
            biColorType = !biColorType;
            for (unsigned char l = 0 + 3 * i; l < 3 + 3 * i; ++l) {
                for (unsigned char n = 0 + 3 * j; n < 3 + 3 * j; ++n) {
                    move (Y0 + l, X0 + n * 2);

                    space = ' ' | COLOR_PAIR (biColorType + 2);
                    addch (space);

                    if (*(matrix + l * SIZE + n) != UNKN_ELEMENT) {
                        outputElements [l][n] = *(matrix + l * SIZE + n) | COLOR_PAIR (biColorType + 2);
                        addch ((outputElements [l][n] + type) | A_BOLD);
                    }
                    else {
                        outputElements [l][n] = *(matrix + l * SIZE + n) | COLOR_PAIR (biColorType + 4);
                        addch (outputElements [l][n] | A_BOLD);
                    }
                }
            }
        }
    }

    refresh();

    newGame = cursor(*outputElements, matrix, type, quantityCrosDigits);

    clear();

    endwin();

    return newGame;
}
