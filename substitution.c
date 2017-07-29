//substitution.c

#include <string.h>
#include "sudlib.h"

void subs (unsigned char * const array1, unsigned char * const array2)
{
    unsigned char zamena[SIZE][SIZE + 1] = {};

    memcpy (zamena, array1, SIZE * (SIZE + 1));
    memcpy (array1, array2, SIZE * (SIZE + 1));
    memcpy (array2, zamena, SIZE * (SIZE + 1));

    return;
}
