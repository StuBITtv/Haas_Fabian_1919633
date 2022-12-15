//
// Created by fhs on 13.12.2022.
//

#include <string.h>
#include "parser.h"

int validComplexNumber(char *input) {
    unsigned hasImaginary = 0;
    unsigned hasDot = 0;
    unsigned operationCount = 0;
    unsigned digitCount = 0;
    unsigned hasSecondPart = 0;

    for (size_t i = 0; i < strlen(input); ++i) {
        if (input[i] == ' ') {
            if(digitCount != 0 && !hasSecondPart) {
                hasSecondPart = 1;
                operationCount = 0;
            }

            hasDot = 0;
            continue;
        }

        unsigned isDigit = input[i] >= '0' && input[i] <= '9';
        digitCount += isDigit;

        unsigned isOperation = input[i] == '+' || input[i] == '-';
        operationCount += isOperation;

        if((operationCount > 1 && digitCount == 0) || operationCount > 2) {
            return 0;
        }

        unsigned isDot = input[i] == '.';
        hasDot += isDot;

        unsigned isImaginary = input[i] == 'i';
        hasImaginary += isImaginary;

        if (!isDigit && !isOperation && !isImaginary && !isDot) {
            return 0;
        }

        if(hasImaginary > 1) {
            return 0;
        }

        if(hasDot > 1) {
            return 0;
        }
    }

    return !hasSecondPart || hasImaginary;
}

Complex parseComplexNumber(char *input) {
    Complex result;
    return result;
}
