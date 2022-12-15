//
// Created by fhs on 13.12.2022.
//
#include "operations.h"

Complex addition(Complex a, Complex b) {
    return (Complex) {
            a.real + b.real,
            a.imaginary + b.imaginary
    };
}

Complex subtraction(Complex a, Complex b) {
    return (Complex) {
            a.real - b.real,
            a.imaginary - b.imaginary
    };
}

Complex multiplication(Complex a, Complex b) {
    return (Complex) {
            a.real * b.real - a.imaginary * b.imaginary,
            a.real * b.imaginary + a.imaginary * b.real
    };
}

Complex division(Complex a, Complex b) {
    Complex result;
    return result;
}

