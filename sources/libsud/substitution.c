//substitution.c - меняет массивы местами

#include "../../include/sudlib.h"
#include <string.h>

void subs (unsigned int array1 [][SIZE + 1], unsigned int array2 [][SIZE + 1])
{
    unsigned int zamena [SIZE][SIZE + 1] = {};

    memcpy (zamena, array1, SIZE * (SIZE + 1) * sizeof (**array1));
    memcpy (array1, array2, SIZE * (SIZE + 1) * sizeof (**array1));
    memcpy (array2, zamena, SIZE * (SIZE + 1) * sizeof (**array2));

    return;
}
