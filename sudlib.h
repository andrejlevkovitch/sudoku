//sudlib.h
//запись необходимых ф-ций и констант

#define SIZE 9
#define ERROR_STRING "Do NOT do that!"
#define MAXCROSSDIGIT 58
#define UNKN_ELEMENT ' '

void initialization (unsigned char *array);

void printMas (unsigned char *array);

void randArr (unsigned char *outputArr, unsigned char *inputArr);

void zeros (unsigned char *array);

unsigned char numCros (void);

unsigned char inputType (void);

void sortArr (unsigned char *array, unsigned char endArr);

void vozvrat (unsigned char *outputArr, unsigned char *inputArr, int size_s, int size_c);

unsigned char randDig (unsigned char maxValue);

void sudMaker (unsigned char *array);
