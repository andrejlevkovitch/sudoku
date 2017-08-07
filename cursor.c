//cursor.c - передвигает курсор в поле судоку

#include <ncurses.h>
#include <stdbool.h>
#include <unistd.h>
#include "sudlib.h"

bool cursor (chtype * outputMatrix, const unsigned char * basisMatrix, const unsigned char type, const unsigned char quantityCrosDigits)
{
    unsigned char inputChar = 0;
    unsigned char koordY = Y0;
    unsigned char koordX = X0 + 1;

    unsigned char string = 0;
    unsigned char colum = 0;

    unsigned char tempStore = 0;

    unsigned short turnCounter = 0;
    unsigned char emptyValueCounter = quantityCrosDigits;

    unsigned char errorStore [MAXCROSSDIGIT + 1] = {};

    bool newGame = false;

    noecho();

    do {
        move (Y0, X0 + 22);
        printw ("%s %d", "Turn is:", turnCounter);
        move (Y0 + 1, X0 + 22);
        printw ("%s %2d", "Empty values:", emptyValueCounter);

        move (koordY, koordX);

        if ((inputChar = getch()) == ESC && getch() == 91) {
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
        else {
            if (inputChar != ESC) {
                if (emptyValueCounter != 0 || *(errorStore + MAXCROSSDIGIT) != 0) {
                    string = koordY - Y0;
                    colum = (koordX - (X0 + 1))/2;

                    if (*(basisMatrix + string * SIZE + colum) == UNKN_ELEMENT) {
                        if (inputChar == DELETE) {
                            tempStore = *(outputMatrix + string * SIZE + colum);
                            *(outputMatrix + string * SIZE + colum) -= tempStore;
                            *(outputMatrix + string * SIZE + colum) += UNKN_ELEMENT;

                            addch (*(outputMatrix + string * SIZE + colum) | A_BOLD);

                            message (string, colum, REMOVE, tempStore + type);

                            if (*(errorStore + MAXCROSSDIGIT) != 0) {
                                for (unsigned char i = 0; i < *(errorStore + MAXCROSSDIGIT); ++i) {
                                    if ((string * 10 + colum) == *(errorStore + i)) {
                                        *(errorStore + MAXCROSSDIGIT) -= 1;
                                        break;
                                    }
                                }
                            }

                            ++turnCounter;
                            ++emptyValueCounter;
                        }
                        else if ((inputChar -= type) < SIZE) {
                            tempStore = *(outputMatrix + string * SIZE + colum);

                            if (tempStore == UNKN_ELEMENT) --emptyValueCounter;

                            *(outputMatrix + string * SIZE + colum) -= tempStore;
                            *(outputMatrix + string * SIZE + colum) += inputChar;

                            if (*(errorStore + MAXCROSSDIGIT) != 0) {
                                for (unsigned char i = 0; i < *(errorStore + MAXCROSSDIGIT); ++i) {
                                    if ((string * 10 + colum) == *(errorStore + i)) {
                                        *(errorStore + MAXCROSSDIGIT) -= 1;
                                        break;
                                    }
                                }
                            }

                            if (!coincidence(outputMatrix, string, colum)) {
                                addch ((*(outputMatrix + string * SIZE + colum) + type) | A_BOLD);

                                message (string, colum, INPUT, inputChar + type);

                                ++turnCounter;
                            }
                            else {
                                attron (A_BOLD);
                                attron (COLOR_PAIR(6));
                                printw ("%c", *(outputMatrix + string * SIZE + colum) + type);

                                attroff (A_BOLD);
                                attroff (COLOR_PAIR(6));

                                message (string, colum, COINCIDENCE, inputChar + type);

                                *(errorStore + *(errorStore + MAXCROSSDIGIT)) = string * 10 + colum;
                                *(errorStore + MAXCROSSDIGIT) += 1;

                                ++turnCounter;
                            }
                        }
                    }
                    else if (inputChar == DELETE || (inputChar -= type) < SIZE) {
                        message (string, colum, ERROR, UNKN_ELEMENT);

                        ++turnCounter;
                    }

                    if (emptyValueCounter == 0 && (*(errorStore + MAXCROSSDIGIT)) == 0 && quantityCrosDigits != 0) {
                        message (string, colum, WIN, UNKN_ELEMENT);
                    }
                }

                if (inputChar == '\n' || inputChar == RESTART) {
                    message (string, colum, GAME, UNKN_ELEMENT);

                    if (getch() == '\n') {
                        inputChar = ESC;
                        newGame = true;
                    }
                }
            }
        }
    } while (inputChar != ESC);

    echo();

    return newGame;
}
