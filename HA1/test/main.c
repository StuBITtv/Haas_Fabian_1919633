//
// Created by fhs on 13.12.2022.
//

#include <runner.h>
#include "arithmetic/check-addition.h"
#include "arithmetic/check-subtraction.h"
#include "arithmetic/check-multiplication.h"
#include "arithmetic/check-division.h"
#include "cli/check-validation.h"
#include "cli/check-parser.h"
#include "cli/check-complex-string.h"

Suite **init(size_t *n) {
    const Suite *suites[] = {
            additionSuite(),
            subtractionSuite(),
            multiplicationSuite(),
            divisionSuite(),
            numberValidationSuite(),
            parserSuite(),
            complexNumberStringSuite()
    };

    *n = sizeof(suites) / sizeof(Suite *);

    return setSuites(suites, *n);
}