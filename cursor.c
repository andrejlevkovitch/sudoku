//cursor.c - передвигает курсор в поле судоку

#include <ncurses.h>
#include "sudlib.h"

void cursor (chtype * outputMatrix, const unsigned char * basisMatrix, const unsigned char type, const unsigned char quantityCrosDigits)
{
    unsigned char inputChar = 0;
    unsigned char koordY = Y0;
    unsigned char koordX = X0 + 1;

    unsigned char string = 0;
    unsigned char colum = 0;

    unsigned char tempStore = 0;

    unsigned short turnCounter = 0;
    unsigned char emptyValueCounter = quantityCrosDigits;

    initscr();

    noecho();

    do {
        move (koordY, koordX);

        if ((inputChar = getch()) == 27 && getch() == 91) {
            switch (getch()) {
                case UP:
                    if (koordY != Y0) koordY -= 1;
                    break;
                case DOWN:
                    if (koordY != (Y0 + SIZE - 1)) koordY += 1;
                    break;
                case LEFT:
                    if (koordX != (X0 + 1)) koordX -= 2;
                    break;
                case RIGHT:
                    if (koordX != (X0 + 1 + (SIZE - 1) * 2)) koordX += 2;
                    break;
            }

            inputChar = 0;
        }
        else
            if (inputChar != 27) {
                string = koordY - Y0;
                colum = (koordX - (X0 + 1))/2;

                if (*(basisMatrix + string * SIZE + colum) == UNKN_ELEMENT) {
                    if (inputChar == DELETE) {
                        tempStore = *(outputMatrix + string * SIZE + colum);
                        *(outputMatrix + string * SIZE + colum) -= tempStore;
                        *(outputMatrix + string * SIZE + colum) += UNKN_ELEMENT;

                        addch (*(outputMatrix + string * SIZE + colum));

                        mesage (string, colum, REMOVE, tempStore + type);

                        ++turnCounter;
                        ++emptyValueCounter;
                    }
                    else if ((inputChar -= type) < SIZE) {
                        tempStore = *(outputMatrix + string * SIZE + colum);

                        if (tempStore == UNKN_ELEMENT) --emptyValueCounter;

                        *(outputMatrix + string * SIZE + colum) -= tempStore;
                        *(outputMatrix + string * SIZE + colum) += inputChar;

                        if (!coincidence(outputMatrix, string, colum)) {
                            addch ((*(outputMatrix + string * SIZE + colum) + type) | A_BOLD);

                            mesage (string, colum, INPUT, inputChar + type);

                            ++turnCounter;
                        }
                        else {
                            attron (A_BOLD);
                            attron (COLOR_PAIR(6));
                            printw ("%c", *(outputMatrix + string * SIZE + colum) + type);

                            attroff (A_BOLD);
                            attroff (COLOR_PAIR(6));

                            mesage (string, colum, COINCIDENCE, inputChar + type);

                            ++turnCounter;
                        }
                    }
                }
                else if (inputChar == DELETE || (inputChar -= type) < SIZE) {
                    mesage (string, colum, ERROR, UNKN_ELEMENT);

                    ++turnCounter;
                }
            }
        move (Y0, X0 + 22);
        printw ("%s %d", "Turn is:", turnCounter);
        move (Y0 + 1, X0 + 22);
        printw ("%s %2d", "Empty values:", emptyValueCounter);

    } while (inputChar != 27);

    echo();

    endwin();

    return;
}
