//
// Created by fhs on 15.12.2022.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "cli.h"
#include "parser.h"

Complex askForNumber(const char *position) {
    char input[512];

    while (1) {
        printf("What's the %s number?\n", position);
        scanf("%s", input);

        if (validComplexNumber(input)) break;

        printf("\nExpected a number in the format a+bi, instead got \"%s\".\n\n", input);
    }

    return parseComplexNumber(input);
}

Operation askForOperation() {
    char input[128];

    while (1) {
        printf("What's the operation?\n");
        scanf("%s", input);

        switch (input[0]) {
            case '+':
            case '-':
            case '*':
            case '/':
                return input[0];
        }

        printf("\nSupported operations are '+', '-', '*', and '/', instead got \"%s\".\n\n", input);
    }
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err34-c"

Format askForFormat() {
    char input[128];

    while (1) {
        printf("In which format do you want to display the result?\n"
               "[1] Rectangular: a+bi\n"
               "[2] Exponential: r*e^(i*Theta)\n"
               "[3]       Polar: r*(cos(Theta)+i*sin(Theta))\n"
        );
        scanf("%s", input);

        int choice = atoi(input);

        if (choice >= FORM_RECTANGULAR && choice <= FORM_EXPONENTIAL) return choice;

        printf("\nExpected a whole number between 1 and 3, instead got \"%s\"\n\n", input);
    }
}

#pragma clang diagnostic pop

char *complexToRectangular(Complex number) {
    size_t outputSize = 1;

    char *output = malloc(sizeof(char));
    output[0] = '\0';

    if (number.real || !number.real && !number.imaginary) {
        outputSize += snprintf(output, outputSize, "%f", number.real);

        output = realloc(output, outputSize);

        sprintf(output, "%f", number.real);
    }

    if (number.real && number.imaginary) {
        output = realloc(output, outputSize + 3);

        sprintf(&output[outputSize - 1], number.imaginary > 0 ? " + " : " - ");

        outputSize += 3;
    }

    if (number.imaginary) {
        double imaginary = number.real ? fabs(number.imaginary) : number.imaginary;

        output = realloc(
                output,
                outputSize + snprintf(NULL, 0, "%fi", imaginary)
        );

        sprintf(&output[outputSize - 1], "%fi", imaginary);
    }

    return output;
}

char *complexToString(Format format, Complex number) {
    if (format == FORM_RECTANGULAR) {
        return complexToRectangular(number);
    }

    char *empty = malloc(1);
    empty[0] = '\0';

    return empty;
}
