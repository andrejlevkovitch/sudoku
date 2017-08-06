//mesage.c - выводит сообщения на экран

#include <ncurses.h>
#include <string.h>
#include "sudlib.h"

void message (const unsigned char numS, const unsigned char numC, const unsigned char operace, const unsigned char value)
{
    char string[55] = {};

    move (Y0 + 10, 0);

    switch (operace) {
        case INPUT:
            strcat (string, "You input value");
            insertln();
            break;
        case ERROR:
            attron (A_BOLD);
            strcat (string, "You can not do this! It defolt value.");
            insertln();
            break;
        case REMOVE:
            strcat (string, "You remove value");
            insertln();
            break;
        case COINCIDENCE:
            attron (A_BOLD);
            attron (COLOR_PAIR (6));
            strcat (string, "There is already such a value");
            insertln();
            break;
        case WIN:
            strcat (string, "YOU WIN!!! If you want to play again, press Enter.");
            insertln();
            break;
        case GAME:
            strcat (string, "You want to play? If Yes - press Enter");
            insertln();
            break;
    }

    printw ("%c%c %s %c", numS + 49, numC + 65, string, value);

    attroff (A_BOLD);
    attroff (COLOR_PAIR (6));

    return;
}
