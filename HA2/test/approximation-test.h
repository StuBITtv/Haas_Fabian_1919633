//
// Created by fhs on 21.12.2022.
//

#ifndef C_COURSE_APPROXIMATION_TEST_H
#define C_COURSE_APPROXIMATION_TEST_H

#include "../src/newton-raphson/newton-raphson.h"

void earlyExitTest(double start, Rational function, Rational derivative);

void approximationTest(double start, double expected, Rational function, Rational derivative);

#endif //C_COURSE_APPROXIMATION_TEST_H
