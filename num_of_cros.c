//num_of_cros.c - вводит количество вычеркиваемых элементов

#include <stdio.h>
#include <stdlib.h>
#include "sudlib.h"

unsigned char numCros (void)
{
    unsigned int crosDigit = 0;
    printf ("%s 0<=n<=%i\n", "How many digits do you want to cross out?", MAXCROSSDIGIT);
    scanf ("%u", &crosDigit);
    if (crosDigit > MAXCROSSDIGIT) {
        printf ("%s\n", ERROR_STRING);
        exit (EXIT_FAILURE);
    }

    return crosDigit;
}
