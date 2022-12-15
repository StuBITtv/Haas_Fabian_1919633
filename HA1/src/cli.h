//
// Created by fhs on 15.12.2022.
//

#ifndef C_COURSE_CLI_H
#define C_COURSE_CLI_H

#include "complex-numbers/complex.h"

typedef enum OPERATION {
    ADDITION = '+',
    SUBTRACTION = '-',
    MULTIPLICATION = '*',
    DIVISION = '/'
} Operation;

Complex askForNumber(const char *position);

Operation askForOperation();

#endif //C_COURSE_CLI_H
