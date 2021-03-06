//mesage.c - выводит сообщения на экран

#include "../../include/sudlib.h"
#include <curses.h>
#include <string.h>

void message (const unsigned int numS, const unsigned int numC, const char operace, const unsigned char value)
{
    char string [50] = {};

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
            attron (A_BOLD);
            attron (COLOR_PAIR (7));
            strcat (string, "YOU WIN!!!");
            insertln();
            break;

        case GAME:
            attron (A_BOLD);
            attron (COLOR_PAIR (8));
            strcat (string, "You want to play a new game? If Yes - press Enter.");
            insertln();
            break;

        case SOLUTION:
            attron (A_BOLD);
            attron (COLOR_PAIR (8));
            strcat (string, "You want to see a solution? If Yes - press Enter.");
            insertln();
            break;
    }

    printw ("%c%c %s %c", numS + 49, numC + 65, string, value);

    attroff (A_BOLD);
    attroff (COLOR_PAIR (6));
    attroff (COLOR_PAIR (7));
    attroff (COLOR_PAIR (8));

    return;
}
