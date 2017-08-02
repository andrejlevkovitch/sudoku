//sudlib.h - заголовочный файл, включающий объявление всех используемых ф-ций в программе

#define SIZE 9
#define ERROR_STRING "Do NOT do that!"
#define MAXCROSSDIGIT 58
#define UNKN_ELEMENT 32
#define Y0 5
#define X0 2

void initialization (unsigned char * const array, const unsigned char size_c);

void printMas (const unsigned char * const array, const unsigned char type, const unsigned char size_s, const unsigned char size_c);

void randArr (unsigned char * const outputArr, unsigned char * const inputArr);

void zeros (unsigned char * const array);

unsigned char numCros (void);

unsigned char inputType (void);

void sortArr (unsigned char * const array, const unsigned char endArr);

void sudMaker (unsigned char * const array);

void inputPsblS (unsigned char * const psblArr, const unsigned char * const matrix);

void psblSC (unsigned char * const arrayS, unsigned char * const arrayC, unsigned char * const matrix);

void revers (unsigned char * const array);

void subs (unsigned char * const array1, unsigned char * const array2);

void decision (unsigned char * const arrayS, unsigned char * const arrayC, unsigned char * const matrix);

void io (const unsigned char * const array, const unsigned char type);

void frame (void);

void cursor (void);
