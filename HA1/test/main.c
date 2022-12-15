//
// Created by fhs on 13.12.2022.
//

#include <stdlib.h>
#include <stdio.h>
#include "check.h"
#include "arithmetic/check-addition.h"
#include "arithmetic/check-subtraction.h"
#include "arithmetic/check-multiplication.h"
#include "arithmetic/check-division.h"
#include "cli/check-validation.h"
#include "cli/check-parser.h"
#include "cli/check-complex-string.h"

int runSuite(Suite *suite) {
    SRunner *runner = srunner_create(suite);

    srunner_run_all(runner, CK_NORMAL);

    int failedTestCount = srunner_ntests_failed(runner);

    srunner_free(runner);

    return failedTestCount;
}

int main() {
    Suite *suites[] = {
            additionSuite(),
            subtractionSuite(),
            multiplicationSuite(),
            divisionSuite(),
            numberValidationSuite(),
            parserSuite(),
            complexNumberStringSuite()
    };

    int result = EXIT_SUCCESS;

    for (int i = 0; i < sizeof(suites) / sizeof(Suite *); ++i) {
        if (runSuite(suites[i]) != 0) {
            result = EXIT_FAILURE;
        }

        printf("\n");
    }

    return result;
}