//
// Created by fhs on 13.12.2022.
//

#include "double-comparison.h"

void isSimilar(double a, double b) {
    if((fabs(a - b) > 0.00005)) {
        ck_assert_double_eq(a, b);
    }
}
