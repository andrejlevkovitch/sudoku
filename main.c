//main.c - основное тело

#include <curses.h>
#include <stdlib.h>
#include <string.h>
#include "sudlib.h"

int main (int argc, char *argv [])
{
    unsigned int bgnMtrx [SIZE][SIZE] = {};//начальная матрица
    unsigned int sudoku [SIZE][SIZE] = {};//сюда запишем судоку

    unsigned char type = 0;//тип судоку
    unsigned int crosDig = 0;//количество вычеркнутых цифр

    char variety = DEFAULT;//модификатор, нужен для реализации решения судоку и разных вариантов судоку

    if (argc > 1) {
        variety = flags (argc, argv);
    }

    if (variety == SOLUTION) {
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
    }
    else {
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
    }

    return EXIT_SUCCESS;
}
