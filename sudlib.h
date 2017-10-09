//sudlib.h - заголовочный файл, включающий объявление всех используемых ф-ций в программе

#ifdef linux
    #include <curses.h>
#else
    #include <stdbool.h>
#endif

#define FLAGQ 5//количество используемых флагов

#define SIZE 9
#define MAXCROSSDIGIT 58//максимальное количество вычеркиваемых значений
#define UNKN_ELEMENT ' '//"нулевой" элемент

#define ERROR_STRING "Do NOT do that!"

#define Y0 5//начальная позиция вывода судоку в системе ввода-вывода
#define X0 2

#ifdef linux
    #define UP 65//стрелки
    #define DOWN 66
    #define RIGHT 67
    #define LEFT 68

    #define DELETE 127
    #define CONFIRM '\n'
#else
    #define UP 72
    #define DOWN 80
    #define RIGHT 77
    #define LEFT 75

    #define DELETE 8
    #define CONFIRM 13

    #define ARROW 224
#endif

#define INPUT 'i'//для мессенджа
#define ERROR 'e'
#define REMOVE 'r'
#define COINCIDENCE 'c'
#define WIN 'w'
#define GAME 'g'

#define ESC 27

#define SOLUTION 's'//модификаторы
#define DEFAULT 'd'
#define DECISION 'q'
#define GIRANDOLA 'G'
#define CREATURE 'C'
#define WINDOKU 'W'
#define DIAGONAL 'D'

void initialization (unsigned int array [][SIZE + 1]);

void randArrSpecial (unsigned int outputArr [][SIZE], const char variety);

void forecasting (unsigned int inArr [][SIZE], signed int prognoz [][SIZE][SIZE + 1], unsigned int string, unsigned int colum, char variety);

unsigned int numCros (void);

unsigned char inputType (void);

void sudMaker (unsigned int array [][SIZE], const unsigned int quantityCrosDigits);

void inputPsblS (unsigned int psblArr [][SIZE + 1], const unsigned int matrix [][SIZE]);

void psblSC (unsigned int arrayS [][SIZE + 1], unsigned int arrayC [][SIZE + 1], unsigned int matrix [][SIZE]);

void revers (unsigned int array [][SIZE]);

void subs (unsigned int array1 [][SIZE + 1], unsigned int array2 [][SIZE + 1]);

void decision (unsigned int arrayS [][SIZE + 1], unsigned int arrayC [][SIZE + 1], unsigned int matrix [][SIZE]);

bool ioSystem (unsigned int array [][SIZE], const unsigned char type, const unsigned int quantityCrosDigits, const char modify);

void frame (const char modify);

#ifdef linux

    bool cursor (chtype array [][SIZE], const unsigned int basisMatrix [][SIZE], const unsigned char type, const unsigned int quantityCrosDigits, const char modify);

    bool coincidence (chtype array [][SIZE], const unsigned int numS, const unsigned int numC, const char modify);

#else

    unsigned char mygetch (void);

#endif

void message (const unsigned int numS, const unsigned int numC, const char operace, const unsigned char value);

void colors (void);

char flags (int argc, char *argv []);
