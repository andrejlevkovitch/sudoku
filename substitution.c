//substitution.c

#include "sudlib.h"

void subs (unsigned char *array1, unsigned char *array2)
{
    unsigned char zamena[SIZE][SIZE + 1] = {};

    vozvrat (*zamena, array1, SIZE, SIZE + 1);
    vozvrat (array1, array2, SIZE, SIZE + 1);
    vozvrat (array2, *zamena, SIZE, SIZE + 1);

    return;
}
