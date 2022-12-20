//
// Created by fhs on 20.12.2022.
//

#include <runner.h>

Suite **init(size_t *n) {
    const Suite *suites[] = {};

    *n = sizeof(suites) / sizeof(Suite *);

    return setSuites(suites, *n);
}
