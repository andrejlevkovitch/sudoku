//num_of_cros.c

#include "sudlib.h"

unsigned char numCros (void)
{
    unsigned int crosDigit;
    printf ("%s 0<=n<=%i\n", "How many digits do you want to cross out?", MAXCROSSDIGIT);
    scanf ("%d", &crosDigit);
    if (crosDigit > MAXCROSSDIGIT) {
        printf ("%s\n", ERROR_STRING);
        exit (EXIT_FAILURE);
    }

    return crosDigit;
}
