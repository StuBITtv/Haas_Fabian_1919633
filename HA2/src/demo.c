//
// Created by fhs on 21.12.2022.
//

#include <math.h>
#include <function-descriptor.h>

static double function(double x) {
    return pow(x - 3, 2);
}

static double derivative(double x) {
    return 2 * (x - 3);
}

FunctionDescriptor setFunction() {
    return (FunctionDescriptor) {
            "(x - 3)^2",
            (Rational) function,
            (Rational) derivative,
    };
}
