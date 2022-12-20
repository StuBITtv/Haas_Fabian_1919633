//
// Created by fhs on 13.12.2022.
//

#include <string.h>
#include <malloc.h>
#include <math.h>
#include "parser.h"

unsigned charIsOperation(char c) {
    return c == '+' || c == '-';
}

unsigned charIsDigit(char c) {
    return c >= '0' && c <= '9';
}

int validComplexNumber(const char *input) {
    unsigned hasImaginary = 0;
    unsigned hasDot = 0;
    unsigned operationCount = 0;
    unsigned digitCount = 0;
    unsigned hasSecondPart = 0;

    for (size_t i = 0; i < strlen(input); ++i) {
        if (input[i] == ' ') {
            if (digitCount != 0 && !hasSecondPart) {
                hasSecondPart = 1;
                operationCount = 0;
            }

            hasDot = 0;
            continue;
        }

        unsigned isDigit = charIsDigit(input[i]);
        digitCount += isDigit;

        unsigned isOperation = charIsOperation(input[i]);
        operationCount += isOperation;

        if (isOperation && digitCount != 0 && !hasSecondPart) {
            hasSecondPart = 1;
            digitCount = 0;
        }

        if ((operationCount > 1 && digitCount == 0) || operationCount > 2) {
            return 0;
        }

        unsigned isDot = input[i] == '.';
        hasDot += isDot;

        unsigned isImaginary = input[i] == 'i';
        hasImaginary += isImaginary;

        if (!isDigit && !isOperation && !isImaginary && !isDot) {
            return 0;
        }

        if (isImaginary && i != 0 && charIsDigit(input[i - 1]) && charIsDigit(input[i + 1])) {
            return 0;
        }

        if (hasImaginary > 1) {
            return 0;
        }

        if (hasDot > 1) {
            return 0;
        }
    }

    return !hasSecondPart || hasImaginary;
}

static char *trimOfLastCharacter(const char *input) {
    char *trimmed;

    size_t length = strlen(input);

    trimmed = malloc(length);

    memcpy(trimmed, input, length - 1);
    trimmed[length - 1] = '\0';

    return trimmed;
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err34-c"

void setNumberPart(const char *input, Complex *number) {
    const char *imaginary = strchr(input, 'i');

    if (imaginary) {
        char *trimmed = NULL;
        if (imaginary != input && (imaginary != input + sizeof(char) || charIsDigit(input[0]))) {
            trimmed = trimOfLastCharacter(input);
            imaginary = trimmed;
        } else {
            imaginary += sizeof(char);
        }

        if (strlen(imaginary) == 0) {
            number->imaginary = input[0] == '-' ? -1 : 1;
        } else {
            number->imaginary = fabs(atof(imaginary));

            if (input[0] == '-') {
                number->imaginary *= -1;
            }
        }

        if (trimmed) free(trimmed);
    } else {
        number->real = atof(input);
    }
}

#pragma clang diagnostic pop

Complex parseComplexNumber(const char *input) {
    char *trimmed = malloc(strlen(input) + 1);

    size_t pos = 0;
    for (size_t i = 0; i < strlen(input); ++i) {
        if (input[i] == ' ') {
            continue;
        }

        trimmed[pos] = input[i];
        ++pos;
    }

    trimmed[pos] = '\0';

    Complex result = {0, 0};
    for (size_t i = strlen(trimmed) - 1; i != 0; --i) {
        if (!charIsOperation(trimmed[i])) {
            continue;
        }

        setNumberPart(&trimmed[i], &result);

        if (charIsOperation(trimmed[i - 1])) {
            if (trimmed[i - 1] == '-') {
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
