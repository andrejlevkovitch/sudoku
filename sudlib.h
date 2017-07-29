//sudlib.h

#define SIZE 9
#define ERROR_STRING "Do NOT do that!"
#define MAXCROSSDIGIT 59
#define UNKN_ELEMENT 32

#ifdef linux
    char getch ();
#endif

void initialization (unsigned char *array, unsigned char size_c);

void printMas (const unsigned char const *array, unsigned char type, unsigned char size_s, unsigned char size_c);

void randArr (unsigned char *outputArr, unsigned char *inputArr);

void zeros (unsigned char *array);

unsigned char numCros (void);

unsigned char inputType (void);

void sortArr (unsigned char *array, unsigned char endArr);

void sudMaker (unsigned char *array);

void inputPsblL (unsigned char *psblArr, unsigned char *matrix);

void psblSC (unsigned char *arrayS, unsigned char *arrayC, unsigned char *matrix);

void revers (unsigned char *array);

void subs (unsigned char *array1, unsigned char *array2);

void decision (unsigned char *arrayS, unsigned char *arrayC, unsigned char *matrix);
