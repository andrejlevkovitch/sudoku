//flags.c - флаги

#include "sudlib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char flags (int argc, char *argv [])
{
    char modify = DEFAULT;

    char *validFlags [FLAGQ] = {"-help", "-solution", "-girandola", "-windoku", "-diagonal"};//флаги
    char *descriptionFlags [FLAGQ] = {"for help", "if you want to solve any Sudoku", "Sudoku-girandola", "Sudoku-windoku", "diagonal Sudoku"};//описание флагов

    unsigned int numOfFlag = 0;//номер флага

    if (argc > 2){//ввести можно не более одного флага

#ifdef linux

        printf ("\033[01;31mYou can not enter more than one flag!\033[0m\n");

#else

        printf ("You can not enter more than one flag!\n");

#endif

        printf ("Use -help to inform.\n");

        exit (EXIT_FAILURE);
    }
    else {
        for (numOfFlag = 0; numOfFlag < FLAGQ; ++numOfFlag) {//определение номера флага
           if (strcmp (argv [1], validFlags [numOfFlag]) == 0) break; 
        }
        
        switch (numOfFlag) {//сценарии для флагов
            case 0://help
                    printf ("This program generates unique Sudoku, which have only one solution.\n");
                    printf ("You can choose the type of Sudoku: with letters or numbers; and complexity: up to %i crossed out numbers.\n\n", MAXCROSSDIGIT);

                    printf ("Control if carried out by arrows.\n");
                    printf ("The values can be entered using the keyboard (latin only).\n");
                    printf ("If you want to remove the value press BackSpace\n\n");
                    printf ("If you want to exit press ESC and any key else.\n");
                    printf ("If you want a new game, press ENTER.\n\n");

                    printf ("Valid flags:\n");
                    for (unsigned int i = 0; i < FLAGQ; ++i) {
                        printf ("%-15s%s\n", validFlags [i], descriptionFlags [i]);
                    }
                    printf ("\n");

                    printf ("Have a good game!!!\n");

                    exit (EXIT_SUCCESS);
                    break;

            case 1://решение стороннего судоку
                    modify = SOLUTION;
                    break;

            case 2:
                    modify = GIRANDOLA;
                    break;

            case 3:
                    modify = WINDOKU;
                    break;

            case 4:
                    modify = DIAGONAL;
                    break;

            default://если флаг неизвестен

#ifdef linux

                    printf ("\033[01;31mThis flag does not exist!\033[0m\n");

#else

                    printf ("This flag does not exist!\n");

#endif

                    printf ("Use -help to inform.\n");

                    exit (EXIT_FAILURE);
                    break;
        }
    }

    return modify;
}
