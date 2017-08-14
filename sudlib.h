//sudlib.h - заголовочный файл, включающий объявление всех используемых ф-ций в программе

#include <ncurses.h>

#define FLAGQ 3

#define SIZE 9
#define MAXCROSSDIGIT 58
#define UNKN_ELEMENT 32

#define ERROR_STRING "Do NOT do that!"

#define Y0 5
#define X0 2

#define UP 65
#define DOWN 66
#define RIGHT 67
#define LEFT 68

#define INPUT 'i'
#define ERROR 'e'
#define REMOVE 'r'
#define COINCIDENCE 'c'
#define WIN 'w'
#define GAME 'g'

#define DELETE 127
#define ESC 27
#define RESTART 217

#define SOLUTION 's'
#define DEFAULT 'd'
#define DECISION 'q'
#define GIRANDOLA 'G'

void initialization (unsigned char * array, const unsigned char size_c);

void randArr (unsigned char * outputArr, const char variety);

void zeros (unsigned char * array);

unsigned char numCros (void);

unsigned char inputType (void);

void sortArr (unsigned char * array, const unsigned char endArr);

void sudMaker (unsigned char * array, const unsigned char quantityCrosDigits);

void inputPsblS (unsigned char * psblArr, const unsigned char * matrix);

void psblSC (unsigned char * arrayS, unsigned char * arrayC, unsigned char * matrix);

void revers (unsigned char * array);

void subs (unsigned char * array1, unsigned char * array2);

void decision (unsigned char * arrayS, unsigned char * arrayC, unsigned char * matrix);

bool ioSystem (unsigned char * array, const unsigned char type, const unsigned char quantityCrosDigits, const char modify);

void frame (const char modify);

bool cursor (chtype * array, const unsigned char * basisMatrix, const unsigned char type, const unsigned char quantityCrosDigits, const char modify);

void message (const unsigned char numS, const unsigned char numC, const char operace, const unsigned char value);

bool coincidence (chtype * array, const unsigned char numS, const unsigned char numC);

void colors (void);
