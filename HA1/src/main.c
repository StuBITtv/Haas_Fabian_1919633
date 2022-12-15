//
// Created by fhs on 13.12.2022.
//

#include <stdio.h>
#include "complex-numbers/complex.h"
#include "cli.h"

int main() {
    Complex first = askForNumber("first");
    printf("\n");

    char operation = askForOperation();
    printf("\n");

    Complex second = askForNumber("second");
    printf("\n");
}
