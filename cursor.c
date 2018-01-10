//cursor.c - передвигает курсор в поле судоку

#include "sudlib.h"
#include <curses.h>
#include <stdbool.h>
#include <unistd.h>

int cursor (long outputMatrix [][SIZE], const unsigned int basisMatrix [][SIZE], const unsigned char type, const unsigned int quantityCrosDigits, const char modify)
{
    int inputChar = 0;
    unsigned int koordY = Y0;//координаты первго элемента судоку
    unsigned int koordX = X0 + 1;

    unsigned int string = 0;
    unsigned int colum = 0;

    unsigned char tempStore = 0;

    unsigned short turnCounter = 0;//количество ходов
    unsigned int emptyValueCounter = quantityCrosDigits;//количество незаполненых клеток

    unsigned int errorStore [MAXCROSSDIGIT + 1] = {};//сдесь заисываются ошибочные значения для того, чтобы заполнение произвольными числами всех пустых клеток не приводило бы к победе; последний элемент массива хранит количество значений во всей матрице

    bool newGame = false;//проверка на желание начать новую игру

    noecho();
    keypad (stdscr, true);

    do {
        mvprintw (Y0, X0 + 36, "%hu", turnCounter);
        mvprintw (Y0 + 1, X0 + 36, "%2hu", emptyValueCounter);

        move (koordY, koordX);//перемещение в верхний левый угол вывода

        refresh ();

        switch (inputChar = getch()) {
            case KEY_UP:
                if (koordY != Y0) koordY -= 1;
                break;
            case KEY_DOWN:
                if (koordY != (Y0 + SIZE - 1)) koordY += 1;
                break;
            case KEY_LEFT:
                if (koordX != (X0 + 1)) koordX -= 2;
                break;
            case KEY_RIGHT:
                if (koordX != (X0 + 1 + (SIZE - 1) * 2)) koordX += 2;
                break;

            case ESC:
                break;
            case '':
                inputChar = ESC;
                break;

            case CONFIRM:
                if (modify != DECISION) {
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
                break;

            case KEY_BACKSPACE: case KEY_DC:
                if (modify != DECISION) {
                    if (emptyValueCounter != 0 || errorStore [MAXCROSSDIGIT] != 0) {//ввод возможен пока судоку не решено
                        string = koordY - Y0;//определение соответсвующих координат матрицы
                        colum = (koordX - (X0 + 1))/2;

                        if (basisMatrix [string][colum] == UNKN_ELEMENT) {//только если это не дефолтное значение судоку
                            if ((tempStore = outputMatrix [string][colum]) != UNKN_ELEMENT) {//удаление символа
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
                        }
                        else {//если это дефолтное значение, то об этом всплывает сообщение
                            message (string, colum, ERROR, UNKN_ELEMENT);

                            ++turnCounter;
                        }
                    }
                }
                break;

            default:
                if (modify != DECISION) {
                    if (emptyValueCounter != 0 || errorStore [MAXCROSSDIGIT] != 0) {//ввод возможен пока судоку не решено
                        string = koordY - Y0;//определение соответсвующих координат матрицы
                        colum = (koordX - (X0 + 1))/2;

                        if ((inputChar -= type) < SIZE && inputChar >= 0) {//ввод нужного значения
                            if (basisMatrix [string][colum] == UNKN_ELEMENT) {//только если это не дефолтное значение судоку
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
                            else {//если это дефолтное значение, то об этом всплывает сообщение
                                message (string, colum, ERROR, UNKN_ELEMENT);

                                ++turnCounter;
                            }
                        }

                        if (emptyValueCounter == 0 && (errorStore [MAXCROSSDIGIT]) == 0 && quantityCrosDigits != 0) {//сообщение о победе, находится сдесь для одного-единственного вывода
                            message (string, colum, WIN, UNKN_ELEMENT);
                        }
                    }

                }
                break;
        }

    } while (inputChar != ESC);

    echo();

    return newGame;
}
