//decision.c

#include <stdbool.h>
#include "sudlib.h"

void decision (unsigned char *arrayS, unsigned char *arrayC, unsigned char *matrix)
{
    bool reversOn = false;
    bool solution = false;
    bool rezInIter = false;

    do {
        rezInIter = false;

        do {
            solution = false;

            for (unsigned char i = 0; i < SIZE; ++i) {
                if (*(arrayS + i * (SIZE + 1) + SIZE) != 0) {
                    unsigned char masFreeColum[SIZE + 1] = {};

                    for (unsigned char j = 0; j < SIZE; ++j) {
                        if (*(matrix + i * SIZE + j) == UNKN_ELEMENT) {
                            *(masFreeColum + *(masFreeColum + SIZE)) = j;
                            *(masFreeColum + SIZE) += 1;
                        }
                    }

                    for (char j = *(arrayS + i * (SIZE + 1) + SIZE) - 1; j >= 0; --j) {
                        unsigned char rezult = 0;
                        unsigned char numColum = 0, numString = 0;

                        for (unsigned char l = 0; l < *(masFreeColum + SIZE); ++l) {
                            unsigned char masBuzyQuadr[SIZE + 1] = {};
                            unsigned char krajline = 0, krajcolum = 0;

                            switch (i) {
                                case 0: case 1: case 2:
                                    krajline = 0;
                                    break;
                                case 3: case 4: case 5:
                                    krajline = 3;
                                    break;
                                case 6: case 7: case 8:
                                    krajline = 6;
                                    break;
                            }

                            switch (*(masFreeColum + l)) {
                                case 0: case 1: case 2:
                                    krajcolum = 0;
                                    break;
                                case 3: case 4: case 5:
                                    krajcolum = 3;
                                    break;
                                case 6: case 7: case 8:
                                    krajcolum = 6;
                                    break;
                            }

                            for (unsigned char k = krajline; k < krajline + 3; ++k) {
                                for (unsigned char n = krajcolum; n < krajcolum + 3; ++n) {
                                    if (*(matrix + k * SIZE + n) != UNKN_ELEMENT) {
                                        *(masBuzyQuadr + *(masBuzyQuadr + SIZE)) = *(matrix + k * SIZE + n);
                                        *(masBuzyQuadr + SIZE) += 1;
                                    }
                                }
                            }

                            unsigned char indexCoincidence = 0;

                            for (char m = *(arrayC + *(masFreeColum + l) * (SIZE + 1) + SIZE) - 1; m >= 0; --m) {
                                for (unsigned char n = 0; n < *(masBuzyQuadr + SIZE); ++n) {
                                    if (*(arrayC + *(masFreeColum + l) * (SIZE + 1) + m) == *(masBuzyQuadr + n)) {
                                        unsigned char z = 0;

                                        z = *(arrayC + *(masFreeColum + l) * (SIZE + 1) + m);
                                        *(arrayC + *(masFreeColum + l) * (SIZE + 1) + SIZE) -= 1;
                                        *(arrayC + *(masFreeColum + l) * (SIZE + 1) + m) = *(arrayC + *(masFreeColum + l) * (SIZE + 1) + *(arrayC + *(masFreeColum + l) * (SIZE + 1) + SIZE));
                                        *(arrayC + *(masFreeColum + l) * (SIZE + 1) + *(arrayC + *(masFreeColum + l) * (SIZE + 1) + SIZE)) = z;

                                        *(masBuzyQuadr + SIZE) -= 1;
                                        *(masBuzyQuadr + n) = *(masBuzyQuadr + *(masBuzyQuadr + SIZE));
                                        ++indexCoincidence;
                                        break;
                                    }
                                }
                            }

                            for (unsigned char m = 0; m < *(arrayC + *(masFreeColum + l) * (SIZE + 1) + SIZE); ++m) {
                                if (*(arrayS + i * (SIZE + 1) + j) == *(arrayC + *(masFreeColum + l) * (SIZE + 1) + m)) {
                                    ++rezult;
                                    numString = m;
                                    numColum = *(masFreeColum + l);
                                    break;
                                }
                            }

                            *(arrayC + *(masFreeColum + l) * (SIZE + 1) + SIZE) += indexCoincidence;
                            if (rezult > 1) break;
                        }

                        if (rezult == 1) {
                            *(matrix + i * SIZE + numColum) = *(arrayS + i * (SIZE + 1) + j);
                            *(arrayS + i * (SIZE + 1) + SIZE) -= 1;
                            *(arrayS + i * (SIZE + 1) + j) = *(arrayS + i * (SIZE + 1) + *(arrayS + i *(SIZE + 1) + SIZE));

                            *(arrayC + numColum * (SIZE + 1) + SIZE) -= 1;
                            *(arrayC + numColum * (SIZE + 1) + numString) = *(arrayC + numColum * (SIZE + 1) + *(arrayC + numColum * (SIZE + 1) + SIZE));

                            solution = true;
                            rezInIter = true;
                        }
                    }
                }
            }

        } while (solution);

        if (rezInIter) {
            for (unsigned char i = 0; i < SIZE; ++i) {
                if (*(arrayS + i * (SIZE + 1) + SIZE) != 0) {
                    subs (arrayS, arrayC);
                    revers (matrix);
                    reversOn = !reversOn;
                    break;
                }
            }
        }
        else if (reversOn) {
            subs (arrayS, arrayC);
            revers (matrix);
        }

    } while (rezInIter);

    return;
}
