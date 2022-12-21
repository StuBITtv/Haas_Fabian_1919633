//
// Created by fhs on 21.12.2022.
//

#ifndef C_COURSE_INPUT_VALIDATORS_H
#define C_COURSE_INPUT_VALIDATORS_H

#include <string.h>

int validNumber(const char *input) {
    size_t dotCount = 0;

    for (size_t i = 0; i < strlen(input); ++i) {
        if (input[i] >= '0' && input[i] <= '9') continue;

        dotCount += input[i] == '.';
        if (input[i] == '.' && dotCount < 2) continue;

        if (i == 0 && (input[0] == '-' || input[0] == '+')) continue;

        return 0;
    }

    return 1;
}

int validateChoice(const char *input) {
    return (input[0] == 'y' || input[0] == 'n') && strlen(input) == 1;
}

#endif //C_COURSE_INPUT_VALIDATORS_H
