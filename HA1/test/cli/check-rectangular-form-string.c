//
// Created by fhs on 15.12.2022.
//

#include <malloc.h>
#include <stdio.h>
#include "check-rectangular-form-string.h"
#include "check-complex-string.h"
#include "../complex-getter.h"

void stringTest(Complex number, const char *outputFormat) {
    char *output = malloc(strlen(outputFormat) + 1);
    strcpy(output, outputFormat);

    char *real = strstr(output, "%r");
    char *imaginary = strstr(output, "%i");

    if (real != NULL) *(real + 1) = 'f';
    if (imaginary != NULL) *(imaginary + 1) = 'f';

    double first = number.real, second = number.imaginary;
    if (!real || imaginary && imaginary < real) {
        first = number.imaginary;
        second = number.real;
    }

    first = fabs(first);
    second = fabs(second);

    char *expected = malloc(snprintf(NULL, 0, output, first, second) + 1);

    sprintf(expected, output, first, second);

    ck_assert_str_eq(expected, complexToString(FORM_RECTANGULAR, number));

    free(expected);
    free(output);
}

START_TEST(only_zero) {
    stringTest(getComplex(0, 0), "%r");
}

END_TEST

START_TEST(only_positiv_real_part) {
    stringTest(getComplex(1.2, 0), "%r");
}

END_TEST

START_TEST(only_negativ_real_part) {
    stringTest(getComplex(-1.2, 0), "-%r");
}

END_TEST

START_TEST(only_positiv_imaginary_part) {
    stringTest(getComplex(0, 3.4), "%ii");
}

END_TEST

START_TEST(only_negativ_imaginary_part) {
    stringTest(getComplex(0, -3.4), "-%ii");
}

END_TEST

START_TEST(all_positiv_parts) {
    stringTest(getComplex(1.2, 3.4), "%r + %ii");
}

END_TEST

START_TEST(all_negativ_parts) {
    stringTest(getComplex(-1.2, -3.4), "-%r - %ii");
}

END_TEST

START_TEST(positiv_real_part_negativ_imaginary_part) {
    stringTest(getComplex(1.2, -3.4), "%r - %ii");
}

END_TEST

START_TEST(negativ_real_part_positiv_imaginary_part) {
    stringTest(getComplex(-1.2, 3.4), "-%r + %ii");
}

END_TEST

TCase *rectangularFormStringCase() {
    TCase *testCase = tcase_create("Rectangular");

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
