//
// Created by fhs on 15.12.2022.
//

#ifndef C_COURSE_CLI_H
#define C_COURSE_CLI_H

#include "../complex-numbers/complex.h"

typedef enum OPERATION {
    ADDITION = '+',
    SUBTRACTION = '-',
    MULTIPLICATION = '*',
    DIVISION = '/'
} Operation;

typedef enum FORMAT {
    FORM_RECTANGULAR = 1,
    FORM_EXPONENTIAL = 2,
    FORM_POLAR = 3,
} Format;

Complex askForNumber(const char *position);

Operation askForOperation();

Format askForFormat();

char *complexToString(Format format, Complex number);

#endif //C_COURSE_CLI_H
