//
// Created by fhs on 15.12.2022.
//

#include <stdio.h>
#include <stdlib.h>
#include "cli.h"

Complex askForNumber(const char *position) {
    char input[512];

    while (1) {
        printf("What's the %s number?\n", position);
        scanf("%s", input);

        if(validComplexNumber(input)) break;

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

        if(choice >= FORM_RECTANGULAR && choice <= FORM_EXPONENTIAL) return choice;

        printf("\nExpected a whole number between 1 and 3, instead got \"%s\"\n\n", input);
    }
}
#pragma clang diagnostic pop
