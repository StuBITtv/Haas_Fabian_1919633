//
// Created by fhs on 15.12.2022.
//

#include "check-complex-string.h"
#include "check-rectangular-form-string.h"
#include "check-polar-form-string.h"
#include "check-exponential-form-string.h"

Suite *complexNumberStringSuite() {
    Suite *suite = suite_create("Complex numbers to String");

    suite_add_tcase(suite, rectangularFormStringCase());
    suite_add_tcase(suite, polarFormStringCase());
    suite_add_tcase(suite, exponentialFormStringCase());

    return suite;
}
