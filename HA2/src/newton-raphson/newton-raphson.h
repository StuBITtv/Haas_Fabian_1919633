//
// Created by fhs on 20.12.2022.
//

#ifndef C_COURSE_NEWTON_RAPHSON_H
#define C_COURSE_NEWTON_RAPHSON_H

typedef struct {
    double x;
    unsigned long iterations;
} Approximation;

typedef double (*Rational)(double);

Approximation newtonRaphson(double x, Rational function, Rational derivative);

#endif //C_COURSE_NEWTON_RAPHSON_H
