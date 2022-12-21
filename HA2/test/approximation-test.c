//
// Created by fhs on 21.12.2022.
//

#include <check.h>
#include <double-comparison.h>
#include "approximation-test.h"

void earlyExitTest(double start, Rational function, Rational derivative) {
    Approximation result = newtonRaphson(start, function, derivative);

    ck_assert_int_eq(result.iterations, 0);
}

void approximationTest(double start, double expected, Rational function, Rational derivative) {
    Approximation result = newtonRaphson(start, function, derivative);

    isSimilar(result.x, expected);
    ck_assert_int_ne(result.iterations, 0);
}


