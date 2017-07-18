//vozvrat.c

#include "sudlib.h"

void vozvrat (unsigned char *outputArr, unsigned char *inputArr, unsigned char size_s, unsigned char size_c)
{
    for (unsigned char i = 0; i < size_s; ++i) {
        for (unsigned char j = 0; j < size_c; ++j) {
            *outputArr = *inputArr;
            ++outputArr;
            ++inputArr;
        }
    }

    return;
}
