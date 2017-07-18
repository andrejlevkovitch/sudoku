//substitution.c

#include "sudlib.h"

void subs (unsigned char *array1, unsigned char *array2)
{
    unsigned char zamena[SIZE + 1][SIZE + 1] = {};

    vozvrat (*zamena, array1, SIZE + 1, SIZE + 1);
    vozvrat (array1, array2, SIZE + 1, SIZE + 1);
    vozvrat (array2, *zamena, SIZE + 1, SIZE + 1);

    return;
}
