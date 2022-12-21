//
// Created by fhs on 20.12.2022.
//

#include <runner.h>
#include "check-with-derivative.h"
#include "check-with-approximation.h"

Suite **init(size_t *n) {
    const Suite *suites[] = {
            derivativeSuite(),
            approximationSuite()
    };

    *n = sizeof(suites) / sizeof(Suite *);

    return setSuites(suites, *n);
}
