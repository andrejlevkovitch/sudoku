//cursor.c - передвигает курсор в поле судоку

#include <ncurses.h>
#include "sudlib.h"

void cursor (void)
{
    unsigned char curs = 0;
    unsigned char koordY = Y0;
    unsigned char koordX = X0 + 1;

    noecho();

    do {
        move (koordY, koordX);

        switch (curs = getch()) {
            case 'w':
                if (koordY != Y0) koordY -= 1;
                break;
            case 's':
                if (koordY != (Y0 + SIZE - 1)) koordY += 1;
                break;
            case 'a':
                if (koordX != (X0 + 1)) koordX -= 2;
                break;
            case 'd':
                if (koordX != (X0 + 1 + (SIZE - 1) * 2)) koordX += 2;
                break;
            case 27:
                break;
        }

    } while (curs != 27);

    echo();

    return;
}
