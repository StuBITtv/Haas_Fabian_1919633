//
// Created by fhs on 15.12.2022.
//

#include <malloc.h>
#include "string-expectation.h"
#include "check-exponential-form-string.h"
#include "complex-getter.h"
#include "../../src/cli/cli.h"

#define FORMAT "%r*e^(%ti)"

static void stringTest(Complex number, double r, double t, const char *format) {
    char *expected = getExpectedString(
            'r', 't',
            r, t,
            format
    );

    ck_assert_str_eq(expected, complexToString(FORM_EXPONENTIAL, number));

    free(expected);
}

START_TEST(only_zero) {
    stringTest(getComplex(0, 0), 0, 0, "%r");
}

END_TEST

START_TEST(only_positiv_real_part) {
    stringTest(getComplex(1.2, 0), 1.2, M_PI, FORMAT);
}

END_TEST

START_TEST(only_negativ_real_part) {
    stringTest(getComplex(-1.2, 0), 1.2, -1 * M_PI, FORMAT);
}

END_TEST

START_TEST(only_positiv_imaginary_part) {
    stringTest(getComplex(0, 3.4), 3.4, M_PI / 2, FORMAT);
}

END_TEST

START_TEST(only_negativ_imaginary_part) {
    stringTest(getComplex(0, -3.4), 3.4, -1 * M_PI / 2, FORMAT);
}

END_TEST

START_TEST(all_positiv_parts) {
    stringTest(
            getComplex(1.2, 3.4),
            sqrt(13), atan((double) 17 / 6),
            FORMAT
    );
}

END_TEST

START_TEST(all_negativ_parts) {
    stringTest(
            getComplex(-1.2, -3.4),
            sqrt(13), atan((double) 17 / 6) - M_PI,
            FORMAT
    );
}

END_TEST

START_TEST(positiv_real_part_negativ_imaginary_part) {
    stringTest(
            getComplex(1.2, -3.4),
            sqrt(13), -1 * atan((double) 17 / 6),
            FORMAT
    );
}

END_TEST

START_TEST(negativ_real_part_positiv_imaginary_part) {
    stringTest(
            getComplex(-1.2, 3.4),
            sqrt(13), M_PI - atan((double) 17 / 6),
            FORMAT
    );
}

END_TEST

TCase *exponentialFormStringCase() {
    TCase *testCase = tcase_create("Exponential");

    tcase_add_test(testCase, only_zero);
    tcase_add_test(testCase, only_positiv_real_part);
    tcase_add_test(testCase, only_negativ_real_part);
    tcase_add_test(testCase, only_positiv_imaginary_part);
    tcase_add_test(testCase, only_negativ_imaginary_part);
    tcase_add_test(testCase, all_positiv_parts);
    tcase_add_test(testCase, all_negativ_parts);
    tcase_add_test(testCase, positiv_real_part_negativ_imaginary_part);
    tcase_add_test(testCase, negativ_real_part_positiv_imaginary_part);

    return testCase;
}
