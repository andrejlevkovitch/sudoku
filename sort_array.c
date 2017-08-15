//sort_array.c - сортирует массив, смещает обнуленные элементы в право

#include "sudlib.h"

void sortArr (unsigned char array [][SIZE], const unsigned char endArr)
{
    for (unsigned char i = 0; i < SIZE; ++i) {
        for (unsigned char l = 1; l <= 3; ++l) {
            for (unsigned char j = 0; j <= endArr - l; ++j) {
                if (array [i][j] == UNKN_ELEMENT) {
                    array [i][j] = array [i][j + 1];
                    array [i][j + 1] = UNKN_ELEMENT;
                }
            }
        }
    }
    return;
}
