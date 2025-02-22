//
// Created by fhs on 20.12.2022.
//

#include <stdlib.h>
#include <stdio.h>
#include "runner.h"

extern Suite **init(size_t *n);

Suite **setSuites(const Suite **suites, size_t count) {
    size_t size = sizeof(Suite *) * count;

    Suite **copy = malloc(size);
    memcpy(copy, suites, size);

    return copy;
}

int runSuite(Suite *suite) {
    SRunner *runner = srunner_create(suite);

    srunner_run_all(runner, CK_NORMAL);

    int failedTestCount = srunner_ntests_failed(runner);

    srunner_free(runner);

    return failedTestCount;
}

int main() {
    size_t suiteCount;
    Suite **suites = init(&suiteCount);

    size_t fails = 0;

    for (int i = 0; i < suiteCount; ++i) {
        fails += runSuite(suites[i]);
        printf("\n");
    }

    free(suites);

    return fails ? EXIT_FAILURE : EXIT_SUCCESS;
}