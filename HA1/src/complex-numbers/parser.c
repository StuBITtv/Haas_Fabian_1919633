//
// Created by fhs on 13.12.2022.
//

#include <string.h>
#include <malloc.h>
#include "parser.h"

unsigned charIsOperation(char c) {
    return c == '+' || c == '-';
}

int validComplexNumber(const char *input) {
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

        unsigned isOperation = charIsOperation(input[i]);
        operationCount += isOperation;

        if(isOperation && digitCount != 0 && !hasSecondPart) {
            hasSecondPart = 1;
            digitCount = 0;
        }

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

#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err34-c"
void setNumberPart(const char *input, Complex *number) {
    size_t last = strlen(input) - 1;

    if(input[last] == 'i') {
        char *trimmed = malloc(strlen(input) + 1);
        strcpy(trimmed, input);

        trimmed[last] = '\0';
        number->imaginary = atof(trimmed);

        free(trimmed);
    } else {
        number->real = atof(input);
    }
}
#pragma clang diagnostic pop

Complex parseComplexNumber(const char *input) {
    char *trimmed = malloc(strlen(input));

    size_t pos = 0;
    for(size_t i = 0; i < strlen(input); ++i) {
        if (input[i] == ' ') {
            continue;
        }

        trimmed[pos] = input[i];
        ++pos;
    }

    trimmed[pos] = '\0';

    Complex result = {0, 0};
    for(size_t i = strlen(trimmed) - 1; i != 0; --i) {
        if (!charIsOperation(trimmed[i])) {
            continue;
        }

        setNumberPart(&trimmed[i], &result);

        if(charIsOperation(trimmed[i - 1])) {
            if(trimmed[i - 1] == '-') {
                result.real *= -1;
                result.imaginary *= -1;
            }

            --i;
        }

        trimmed[i] = '\0';
    }

    setNumberPart(trimmed, &result);

    free(trimmed);
    return result;
}
