//
// Created by fhs on 15.12.2022.
//

#include <string.h>
#include <malloc.h>
#include <stdio.h>
#include <math.h>
#include "string-expectation.h"

const char *findPosition(char identifier, const char *string) {
    char id[3] = "";
    sprintf(id, "%%%c", identifier);

    return strstr(string, id);
}

char *getExpectedString(
        char firstIdentifier,
        char secondIdentifier,
        double firstNumber,
        double secondNumber,
        const char *format
) {
    size_t bufferSize = 0;
    char *expected = NULL;

    const char *first, *second;
    const char *last = format;

    while (1) {
        first = findPosition(firstIdentifier, last);
        second = findPosition(secondIdentifier, last);

        if (!first && !second) {
            expected = realloc(expected, bufferSize + &format[strlen(format)] - last + 1);
            strcpy(&expected[bufferSize], last);
            break;
        }

        int firstIsFirst = !second || first && first < second;

        const char *next = (firstIsFirst ? first : second) + 2;

        size_t formatSize = next - last;
        char *formatPart = malloc(formatSize + 1);
        memcpy(formatPart, last, formatSize);
        formatPart[formatSize] = '\0';
        formatPart[formatSize - 1] = 'f';

        double number = firstIsFirst ? firstNumber : secondNumber;
        size_t partSize = snprintf(NULL, 0, formatPart, number);
        expected = realloc(expected, bufferSize + partSize + 1);
        sprintf(&expected[bufferSize], formatPart, number);

        bufferSize += partSize;
        last = next;
    }

    return expected;
}
