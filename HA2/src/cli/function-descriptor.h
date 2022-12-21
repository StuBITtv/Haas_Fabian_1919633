//
// Created by fhs on 21.12.2022.
//

#ifndef C_COURSE_FUNCTION_DESCRIPTOR_H
#define C_COURSE_FUNCTION_DESCRIPTOR_H

#include "../newton-raphson/newton-raphson.h"

typedef struct {
    const char *functionString;
    Rational function;
    Rational derivative;
} FunctionDescriptor;

#endif //C_COURSE_FUNCTION_DESCRIPTOR_H
