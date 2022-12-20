//
// Created by fhs on 13.12.2022.
//

#include <check.h>
#include "check-subtraction.h"
#include "double-comparison.h"
#include "../complex-getter.h"
#include "../../src/complex-numbers/complex.h"

START_TEST(with_all_positiv_parts) {
    Complex result = subtraction(getComplex(1.2, 3.4), getComplex(5.6, 7.8));

    isSimilar(result.real, -4.4);
    isSimilar(result.imaginary, -4.4);
} END_TEST

START_TEST(with_one_positiv_and_one_negative_part) {
    Complex result = subtraction(getComplex(-1.2, 3.4), getComplex(-5.6, 7.8));

    isSimilar(result.real, 4.4);
    isSimilar(result.imaginary, -4.4);
} END_TEST

START_TEST(with_all_negative_parts) {
    Complex result = subtraction(getComplex(-1.2, -3.4), getComplex(-5.6, -7.8));

    isSimilar(result.real, 4.4);
    isSimilar(result.imaginary, 4.4);
} END_TEST

START_TEST(with_opposite_parts_in_numbers) {
    Complex result = subtraction(getComplex(-1.2, 3.4), getComplex(5.6, -7.8));

    isSimilar(result.real, -6.8);
    isSimilar(result.imaginary, 11.2);
} END_TEST

Suite *subtractionSuite() {
    Suite *suite = suite_create("Subtraction of complex numbers");
    TCase *testCase = tcase_create("Subtraction");

    tcase_add_test(testCase, with_all_positiv_parts);
    tcase_add_test(testCase, with_one_positiv_and_one_negative_part);
    tcase_add_test(testCase, with_all_negative_parts);
    tcase_add_test(testCase, with_opposite_parts_in_numbers);
    suite_add_tcase(suite, testCase);

    return suite;
}