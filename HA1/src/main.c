//
// Created by fhs on 13.12.2022.
//

#include <stdio.h>
#include <math.h>
#include "complex-numbers/complex.h"
#include "cli.h"

int main() {
    Complex first = askForNumber("first");
    printf("\n");

    Operation operation = askForOperation();
    printf("\n");

    Complex second = askForNumber("second");
    printf("\n");

    Complex result;
    switch (operation) {
        case ADDITION:
            result = addition(first, second);
            break;
        case SUBTRACTION:
            result = subtraction(first, second);
            break;
        case MULTIPLICATION:
            result = multiplication(first, second);
            break;
        case DIVISION:
            result = division(first, second);
            break;
    }

    printf("The result is\n");
    if (result.real || !result.real && !result.imaginary) {
        printf("%f", result.real);
    }

    if (result.real && result.imaginary) {
        printf(result.imaginary > 0 ? " + " : " - ");
    }

    if(result.imaginary) {
        printf("%fi", fabs(result.imaginary));
    }

    return 0;
}
