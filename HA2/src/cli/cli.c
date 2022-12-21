//
// Created by fhs on 20.12.2022.
//

#include <stdio.h>
#include <stdlib.h>
#include "input-validators.h"
#include "function-descriptor.h"
#include "input-validation-loop.h"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err34-c"

extern FunctionDescriptor setFunction();

int main(void) {
    FunctionDescriptor function = setFunction();

    printf(
            "Newton-Raphson method demo on the function following function:\n"
            "%s.\n\n",
            function.functionString
    );

    char input[1000];
    validatedInput(
            "What's your starting estimation for x?",
            "Expected a real number",
            validNumber,
            input
    );

    double estimation = atof(input);

    if (function.derivative) {
        validatedInput(
                "Use the derivative for the approximation? [y/n]",
                "Expected either 'y' or 'n' as answer",
                validateChoice,
                input
        );

        if (input[0] == 'n') function.derivative = NULL;
    } else {
        printf("No derivative available, falling back to approximated derivative for approximation.\n");
    }

    Approximation approximation = newtonRaphson(estimation, function.function, function.derivative);

    if (approximation.iterations) {
        printf(
                "\nFound a solution after %ld iterations. The closest zero is located at x=%f. :D",
                approximation.iterations,
                approximation.x
        );
    } else {
        printf("\nNo zero found after reaching the maximum amount of iteration. :(");
    }
}

#pragma clang diagnostic pop
