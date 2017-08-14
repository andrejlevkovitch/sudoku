//main.c - основное тело

#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include "sudlib.h"

int main (int argc, char *argv[])
{
    unsigned char bgnMtrx [SIZE][SIZE] = {};
    unsigned char sudoku [SIZE][SIZE] = {};

    unsigned char type = 0;
    unsigned char crosDig = 0;

    unsigned char variety = DEFAULT;

    char *validFlags [FLAGQ] = {"-help", "-solution", "-girandola"};
    char *descriptionFlags [FLAGQ] = {"for help", "if you want to solve any Sudoku", "Sudoku-girandola"};

    if (argc > 2){
        printf ("\033[01;31mYou can not enter more than one flag!\033[0m\n");
        exit (EXIT_FAILURE);
    }
    else if (argc == 2) {
        unsigned char numOfFlag;
        for (numOfFlag = 0; numOfFlag < FLAGQ; ++numOfFlag) {
           if (strcmp (argv [1], validFlags [numOfFlag]) == 0) break; 
        }
        
        switch (numOfFlag) {
            case 0:
                    printf ("This program generates unique Sudoku, which have only one solution.\n");
                    printf ("You can choose the type of Sudoku: with letters or numbers; and complexity: up to %hhu crossed out numbers.\n\n", MAXCROSSDIGIT);

                    printf ("Control if carried out by arrows.\n");
                    printf ("The values can be entered using the keyboard (latin only).\n");
                    printf ("If you want to remove the value press BackSpace\n\n");
                    printf ("If you want to exit press ESC and any key else.\n");
                    printf ("If you want a new game, press ENTER.\n\n");

                    printf ("Valid flags:\n");
                    for (unsigned char i = 0; i < FLAGQ; ++i) {
                        printf ("%-15s%s\n", validFlags [i], descriptionFlags [i]);
                    }
                    printf ("\n");

                    printf ("Have a good game!!!\n");

                    exit (EXIT_SUCCESS);
                    break;
            case 1:
                    initscr();
                    colors();

                    for (unsigned char i = 0; i < SIZE; ++i) {
                        for (unsigned char j = 0; j < SIZE; ++j) {
                            sudoku [i][j] = UNKN_ELEMENT;
                        }
                    }
                    
                    type = '1';
                    crosDig = 81;
                    printw ("Input Sudoku.\n");
                    printw ("When you are done, press Enter.\n");
                    if (ioSystem (*sudoku, type, crosDig, SOLUTION)){
                        unsigned char psblS [SIZE][SIZE + 1] = {};
                        unsigned char psblC [SIZE][SIZE + 1] = {};

                        psblSC (*psblS, *psblC, *sudoku);
                        decision (*psblS, *psblC, *sudoku);

                        crosDig = 0;
                        for (unsigned char i = 0; i < SIZE; ++i) {
                            for (unsigned char j = 0; j < SIZE; ++j) {
                                if (sudoku [i][j] == UNKN_ELEMENT) {
                                    crosDig += 1;
                                }
                            }
                        }

                        if (crosDig == 0) {
                            printw ("Solution of the Sudoku\n");
                        }
                        else {
                            attron (A_BOLD);
                            attron (COLOR_PAIR (6));
 
                            printw ("This Sudoku has more than one solution\n");

                            attroff (A_BOLD);
                            attroff (COLOR_PAIR (6));
                        }

                        ioSystem (*sudoku, type, crosDig, DECISION);
                    }

                    endwin();
                    
                    exit (EXIT_SUCCESS);
                    break;
            case 2:
                    variety = GIRANDOLA;
                    break;
            default:
                    printf ("\033[01;31mThis flag does not exist!\033[0m\n");
                    printf ("Use -help to inform.\n");

                    exit (EXIT_FAILURE);
                    break;
        }
        
                }

    initscr();

    colors();

    do {
        type = inputType();
        crosDig = numCros();

        randArr (*bgnMtrx, variety);

        memcpy (sudoku, bgnMtrx, SIZE * SIZE);
        if (crosDig != 0) sudMaker (*sudoku, crosDig);

    } while (ioSystem (*sudoku, type, crosDig, variety));

    endwin();

    return EXIT_SUCCESS;
}
