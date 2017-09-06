//cursor.c - передвигает курсор в поле судоку

#include <curses.h>
#include <stdbool.h>
#include <unistd.h>
#include "sudlib.h"

bool cursor (chtype outputMatrix [][SIZE], const unsigned int basisMatrix [][SIZE], const unsigned char type, const unsigned int quantityCrosDigits, const char modify)
{
    unsigned int inputChar = 0;
    unsigned int koordY = Y0;//координаты первго элемента судоку
    unsigned int koordX = X0 + 1;

    unsigned int string = 0;
    unsigned int colum = 0;

    unsigned int tempStore = 0;

    unsigned short turnCounter = 0;//количество ходов
    unsigned int emptyValueCounter = quantityCrosDigits;//количество незаполненых клеток

    unsigned int errorStore [MAXCROSSDIGIT + 1] = {};//сдесь заисываются ошибочные значения для того, чтобы заполнение произвольными числами всех пустых клеток не приводило бы к победе; последний элемент массива хранит количество значений во всей матрице

    bool newGame = false;//проверка на желание начать новую игру

    noecho();

    do {
//        move (Y0, X0 + 36);//вывод счетчиков
        mvprintw (Y0, X0 + 36, "%hu", turnCounter);
//        move (Y0 + 1, X0 + 36);
        mvprintw (Y0 + 1, X0 + 36, "%2hu", emptyValueCounter);

        move (koordY, koordX);//перемещение в верхний левый угол вывода

        refresh();

#ifdef linux
        if ((inputChar = getch()) == ESC && getch() == 91) {//стрелка = 3 байтам, 27 91 и далее значащий байт
            switch (getch()) {//перемещение
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
#else
        if ((inputChar = mygetch()) == ARROW) {
            switch (mygetch()) {
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
        }
#endif

        else {
            if (inputChar != ESC && modify != DECISION) {
                if ((emptyValueCounter != 0 || errorStore [MAXCROSSDIGIT] != 0) && inputChar != CONFIRM) {//ввод возможен пока судоку не решено
                    string = koordY - Y0;//определение соответсвующих координат матрицы
                    colum = (koordX - (X0 + 1))/2;

                    if (basisMatrix [string][colum] == UNKN_ELEMENT) {//только если это не дефолтное значение судоку
                        if (inputChar == DELETE && (tempStore = outputMatrix [string][colum]) != UNKN_ELEMENT) {//удаление символа
                            outputMatrix [string][colum] -= tempStore;//для сохранения значений цвета, которые хранятся в перезаписываемом элементе
                            outputMatrix [string][colum] += UNKN_ELEMENT;

                            addch (outputMatrix [string][colum] | A_BOLD);

                            message (string, colum, REMOVE, tempStore + type);

                            if (errorStore [MAXCROSSDIGIT] != 0) {
                                for (unsigned int i = 0; i < errorStore [MAXCROSSDIGIT]; ++i) {
                                    if ((string * 10 + colum) == errorStore [i]) {
                                        errorStore [MAXCROSSDIGIT] -= 1;//если был удален ошибочный элемент
                                        break;
                                    }
                                }
                            }

                            ++turnCounter;
                            ++emptyValueCounter;
                        }
                        else if ((inputChar -= type) < SIZE) {//ввод нужного значения
                            tempStore = outputMatrix [string][colum];

                            if (tempStore == UNKN_ELEMENT) --emptyValueCounter;//если элемент размещается в не занятую до этого клетку

                            outputMatrix [string][colum] -= tempStore;
                            outputMatrix [string][colum] += inputChar;

                            if (errorStore [MAXCROSSDIGIT] != 0) {
                                for (unsigned int i = 0; i < errorStore [MAXCROSSDIGIT]; ++i) {
                                    if ((string * 10 + colum) == errorStore [i]) {
                                        errorStore [MAXCROSSDIGIT] -= 1;
                                        break;
                                    }
                                }
                            }

                            if (!coincidence (outputMatrix, string, colum, modify)) {
                                addch ((outputMatrix [string][colum] + type) | A_BOLD);

                                message (string, colum, INPUT, inputChar + type);

                                ++turnCounter;
                            }
                            else {//в случае, если это значение уже встречалось
                                attron (A_BOLD);
                                attron (COLOR_PAIR(6));
                                printw ("%c", outputMatrix [string][colum] + type);

                                attroff (A_BOLD);
                                attroff (COLOR_PAIR(6));

                                message (string, colum, COINCIDENCE, inputChar + type);

                                errorStore [errorStore [MAXCROSSDIGIT]] = string * 10 + colum;
                                errorStore [MAXCROSSDIGIT] += 1;

                                ++turnCounter;
                            }
                        }
                    }
                    else if (inputChar == DELETE || (inputChar -= type) < SIZE) {//если это дефолтное значение, то об этом всплывает сообщение
                        message (string, colum, ERROR, UNKN_ELEMENT);

                        ++turnCounter;
                    }

                    if (emptyValueCounter == 0 && (errorStore [MAXCROSSDIGIT]) == 0 && quantityCrosDigits != 0) {//сообщение о победе
                        message (string, colum, WIN, UNKN_ELEMENT);
                    }
                }
                else if (inputChar == CONFIRM) {
                    if (modify == SOLUTION) {
                        message (string, colum, SOLUTION, UNKN_ELEMENT);
                    }
                    else {
                        message (string, colum, GAME, UNKN_ELEMENT);
                    }

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
