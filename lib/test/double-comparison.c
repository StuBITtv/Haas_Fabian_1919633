//
// Created by fhs on 13.12.2022.
//

#include "check.h"
#include "double-comparison.h"

void isSimilar(double actual, double expected) {
    if ((fabs(actual - expected) > 0.00005)) {
        ck_assert_double_eq(actual, expected);
    }
}
