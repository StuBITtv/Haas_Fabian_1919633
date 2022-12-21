//
// Created by fhs on 21.12.2022.
//

#include <math.h>
#include "sample-functions.h"

double quadratic_without_zero(double x) {
    return (x - 1) * (x - 3) + 10;
}

double quadratic_without_zero_derivative(double x) {
    return 2 * x - 4;
}

double quadratic_zero_at_negative_5(double x) {
    return pow((x + 5), 2);
}

double quadratic_zero_at_negative_5_derivative(double x) {
    return 2 * x + 10;
}

double quadratic_zero_at_1_and_3(double x) {
    return (x - 1) * (x - 3);
}

double quadratic_zero_at_1_and_3_derivative(double x) {
    return 2 * x - 4;
}

double cubic_zero_at_10(double x) {
    return pow(x - 10, 3);
}

double cubic_zero_at_10_derivative(double x) {
    return 3 * pow(x, 2) - 60 * x + 300;
}

double cubic_zero_at_negative_8_and_7(double x) {
    return pow(x + 8, 2) * (x - 7);
}

double cubic_zero_at_negative_8_and_7_derivative(double x) {
    return 3 * pow(x, 2) + 18 * x - 48;
}

double cubic_zero_at_negative_4_and_0_and_11(double x) {
    return (x + 4) * x * (x - 11);
}

double cubic_zero_at_negative_4_and_0_and_11_derivative(double x) {
    return 3 * pow(x, 2) - 14 * x - 44;
}

