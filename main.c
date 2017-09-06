//main.c - основное тело

#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
#include <string.h>
#include "sudlib.h"

int main (int argc, char *argv[])
{
    unsigned int bgnMtrx [SIZE][SIZE] = {};//начальная матрица
    unsigned int sudoku [SIZE][SIZE] = {};//сюда запишем судоку

    unsigned char type = 0;//тип судоку
    unsigned int crosDig = 0;//количество вычеркнутых цифр

    unsigned char variety = DEFAULT;//модификатор, нужен для реализации решения судоку и разных вариантов судоку

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
    else if (argc == 2) {
        for (numOfFlag = 0; numOfFlag < FLAGQ; ++numOfFlag) {//определение номера флага
           if (strcmp (argv [1], validFlags [numOfFlag]) == 0) break; 
        }
        
        switch (numOfFlag) {//сценарии для флагов
            case 0://help
                    printf ("This program generates unique Sudoku, which have only one solution.\n");
                    printf ("You can choose the type of Sudoku: with letters or numbers; and complexity: up to %hhu crossed out numbers.\n\n", MAXCROSSDIGIT);

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
                    initscr();
                    colors();

                    for (unsigned int i = 0; i < SIZE; ++i) {//обнуление всего судоку
                        for (unsigned int j = 0; j < SIZE; ++j) {
                            sudoku [i][j] = UNKN_ELEMENT;
                        }
                    }
                    
                    type = inputType();//фиксированный тип
                    crosDig = 81;//поле судоку полностью пустое
                    printw ("Input Sudoku.\n");
                    printw ("When you are done, press Enter.\n");
                    if (ioSystem (sudoku, type, crosDig, SOLUTION)){//если судоку введено и подтверждено желание получить решение, то введенное судоку решается
                        unsigned int psblS [SIZE][SIZE + 1] = {};
                        unsigned int psblC [SIZE][SIZE + 1] = {};

                        psblSC (psblS, psblC, sudoku);//формирование матриц возможных строк и столбцов
                        decision (psblS, psblC, sudoku);//решение судоку

                        crosDig = 0;
                        for (unsigned int i = 0; i < SIZE; ++i) {//если судоку не имеет решения получаем ненулевое значение
                            for (unsigned int j = 0; j < SIZE; ++j) {
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

                        ioSystem (sudoku, type, crosDig, DECISION);//вывод результата
                    }

                    endwin();
                   
                    exit (EXIT_SUCCESS);
                    break;

            case 2:
                    variety = GIRANDOLA;
                    break;

            case 3:
                    variety = WINDOKU;
                    break;

            case 4:
                    variety = DIAGONAL;
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

    initscr();

    colors();

    do {
        type = inputType();//ввод типа
        crosDig = numCros();//ввод количества вычеркиваемых значений

        randArrSpecial (bgnMtrx, variety);//рандомизация, получение уникальной начальной матрицы

        memcpy (sudoku, bgnMtrx, SIZE * SIZE * sizeof (**sudoku));
        if (crosDig != 0) sudMaker (sudoku, crosDig);//составление судоку

    } while (ioSystem (sudoku, type, crosDig, variety));//система ввода-вывода с возможностью начать новую игру

    endwin();

    return EXIT_SUCCESS;
}
