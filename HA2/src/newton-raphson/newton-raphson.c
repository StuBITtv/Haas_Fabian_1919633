//
// Created by fhs on 20.12.2022.
//

#include <math.h>
#include "newton-raphson.h"

typedef double (*Divider)(double x, Rational function, Rational derivative);

static double divideByLimit(double x, Rational function, __attribute__((unused)) Rational _) {
    double magnitude = pow(10, 8);

    return ((*function)(x) - (*function)(x - 1 / magnitude)) * magnitude;
}

static double divideByDerivative(double x, __attribute__((unused)) Rational _, Rational derivative) {
    return derivative(x);
}

Approximation newtonRaphson(double x, Rational function, Rational derivative) {
    Divider divider = derivative ? divideByDerivative : divideByLimit;

    for (unsigned long i = 0; i < 10000000 - 1; ++i) {
        double new = x - (*function)(x) / (*divider)(x, function, derivative);

        if (fabs(new - x) < 0.0000001 || fabs(new) < 0.0000001) {
            return (Approximation) {new, i + 1};
        }

        x = new;
    }

    return (Approximation) {x, 0};
}
