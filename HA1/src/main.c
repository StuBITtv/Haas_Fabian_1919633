//
// Created by fhs on 13.12.2022.
//

#include <stdio.h>
#include "complex-numbers/complex.h"

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

char askForOperation() {
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

int main() {
    Complex first = askForNumber("first");
    printf("\n");
    char operation = askForOperation();
    printf("\n");
    Complex second = askForNumber("second");
}
