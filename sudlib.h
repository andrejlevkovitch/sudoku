//sudlib.h - заголовочный файл, включающий объявление всех используемых ф-ций в программе

#include <ncurses.h>

#define FLAGQ 3//количество используемых флагов

#define SIZE 9
#define MAXCROSSDIGIT 58//максимальное количество вычеркиваемых значений
#define UNKN_ELEMENT ' '//"нулевой" элемент

#define ERROR_STRING "Do NOT do that!"

#define Y0 5//начальная позиция вывода судоку в системе ввода-вывода
#define X0 2

#define UP 65//стрелки
#define DOWN 66
#define RIGHT 67
#define LEFT 68

#define INPUT 'i'//для мессенджа
#define ERROR 'e'
#define REMOVE 'r'
#define COINCIDENCE 'c'
#define WIN 'w'
#define GAME 'g'

#define DELETE 127
#define ESC 27
#define RESTART 217

#define SOLUTION 's'//модификаторы
#define DEFAULT 'd'
#define DECISION 'q'
#define GIRANDOLA 'G'

void initialization (unsigned char * array, const unsigned char size_c);

void randArr (unsigned char outputArr [][SIZE], const char variety);

void zeros (unsigned char array []);

unsigned char numCros (void);

unsigned char inputType (void);

void sortArr (unsigned char array [][SIZE], const unsigned char endArr);

void sudMaker (unsigned char array [][SIZE], const unsigned char quantityCrosDigits);

void inputPsblS (unsigned char psblArr [][SIZE + 1], const unsigned char matrix [][SIZE]);

void psblSC (unsigned char arrayS [][SIZE + 1], unsigned char arrayC [][SIZE + 1], unsigned char matrix [][SIZE]);

void revers (unsigned char array [][SIZE]);

void subs (unsigned char array1 [][SIZE + 1], unsigned char array2 [][SIZE + 1]);

void decision (unsigned char arrayS [][SIZE + 1], unsigned char arrayC [][SIZE + 1], unsigned char matrix [][SIZE]);

bool ioSystem (unsigned char array [][SIZE], const unsigned char type, const unsigned char quantityCrosDigits, const char modify);

void frame (const char modify);

bool cursor (chtype array [][SIZE], const unsigned char basisMatrix [][SIZE], const unsigned char type, const unsigned char quantityCrosDigits, const char modify);

void message (const unsigned char numS, const unsigned char numC, const char operace, const unsigned char value);

bool coincidence (chtype array [][SIZE], const unsigned char numS, const unsigned char numC);

void colors (void);
