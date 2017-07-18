//sudlib.h
//запись необходимых ф-ций и констант

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define SIZE 9
#define ERROR_STRING "Do NOT do that!"
#define MAXCROSSDIGIT 58
#define UNKN_ELEMENT ' '

void initialization (unsigned char *array);

void printMas (unsigned char *array, unsigned char type);

void randArr (unsigned char *outputArr, unsigned char *inputArr);

void zeros (unsigned char *array);

unsigned char numCros (void);

unsigned char inputType (void);

void sortArr (unsigned char *array, unsigned char endArr);

void vozvrat (unsigned char *outputArr, unsigned char *inputArr, unsigned char size_s, unsigned char size_c);

unsigned char randDig (unsigned char maxValue);

void sudMaker (unsigned char *array);

void inputPsblLC (unsigned char *array1, unsigned char *array2, unsigned char *matrix);

void revers (unsigned char *array);

void subs (unsigned char *array1, unsigned char *array2);

int mygetch ();
