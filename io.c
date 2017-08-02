//io.c - система ввода-вывода

#include <ncurses.h>
#include <stdbool.h>
#include "sudlib.h"

void io (const unsigned char * const array, const unsigned char type)
{
    initscr();

    bool biColorType = true;

    chtype outputElement = 0;

    frame();

    start_color();
    init_pair (2, COLOR_WHITE, COLOR_GREEN);
    init_pair (3, COLOR_WHITE, COLOR_BLUE);

    for (unsigned char i = 0; i < 3; ++i) {
        for (unsigned char j = 0; j < 3; ++j) {
            biColorType = !biColorType;
            for (unsigned char l = 0 + 3 * i; l < 3 + 3 * i; ++l) {
                for (unsigned char n = 0 + 3 * j; n < 3 + 3 * j; ++n) {
                    move (Y0 + l, X0 + n * 2);

                    outputElement = ' ' | COLOR_PAIR (biColorType + 2);
                    addch (outputElement);

                    outputElement = *(array + l * SIZE + n) | COLOR_PAIR (biColorType + 2);
                    if (*(array + l * SIZE + n) != UNKN_ELEMENT) outputElement += type;

                    addch (outputElement);
                }
            }
        }
    }

    cursor();

    endwin();

    return;
}
