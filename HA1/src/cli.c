//
// Created by fhs on 15.12.2022.
//

#include <stdio.h>
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
