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

        printf("\nExpected a number in the format a+bi but got \"%s\"\n\n", input);
    }

    return parseComplexNumber(input);
}

int main() {
    Complex first = askForNumber("first");
    Complex second = askForNumber("second");
}
