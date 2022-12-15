//
// Created by fhs on 13.12.2022.
//

#include <stdio.h>
#include <malloc.h>
#include "complex-numbers/complex.h"
#include "cli/cli.h"

int main() {
    Complex first = askForNumber("first");
    printf("\n");

    Operation operation = askForOperation();
    printf("\n");

    Complex second = askForNumber("second");
    printf("\n");

    Format format = askForFormat();

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

    char *output = complexToString(format, result);

    printf("\nThe result is\n%s\n", output);

    free(output);
    return 0;
}
