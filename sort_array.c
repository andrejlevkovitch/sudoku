//sort_array.c - сортирует массив, смещает обнуленные элементы в право

#include "sudlib.h"

void sortArr (unsigned int array [][SIZE], const unsigned int endArr)
{
    for (unsigned int i = 0; i < SIZE; ++i) {
        for (unsigned int l = 1; l <= 3; ++l) {
            for (unsigned int j = 0; j <= endArr - l; ++j) {
                if (array [i][j] == UNKN_ELEMENT) {
                    array [i][j] = array [i][j + 1];
                    array [i][j + 1] = UNKN_ELEMENT;
                }
            }
        }
    }
    return;
}
