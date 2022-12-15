//
// Created by fhs on 13.12.2022.
//

#include "complex-getter.h"
#include "check-multiplication.h"
#include "double-comparison.h"
#include "../src/complex-numbers/complex.h"

START_TEST(with_only_real_part) {
    Complex result = multiplication(getComplex(1.2, 0), getComplex(5.6, 7.8));

    isSimilar(result.real, 6.72);
    isSimilar(result.imaginary, 9.36);
} END_TEST

START_TEST(with_only_imaginary_part) {
    Complex result = multiplication(getComplex(0, 3.4), getComplex(5.6, 7.8));

    isSimilar(result.real, -26.52);
    isSimilar(result.imaginary, 19.04);
} END_TEST

START_TEST(with_all_positiv_parts) {
    Complex result = multiplication(getComplex(1.2, 3.4), getComplex(5.6, 7.8));

    isSimilar(result.real, -19.8);
    isSimilar(result.imaginary, 28.4);
} END_TEST

START_TEST(with_flipped_positiv_parts) {
    Complex result = multiplication(getComplex(1.2, 5.6), getComplex(3.4, 7.8));

    isSimilar(result.real, -39.6);
    isSimilar(result.imaginary, 28.4);
} END_TEST

START_TEST(with_one_positiv_and_one_negative_part) {
    Complex result = multiplication(getComplex(-1.2, 3.4), getComplex(-5.6, 7.8));

    isSimilar(result.real, -19.8);
    isSimilar(result.imaginary, -28.4);
} END_TEST

START_TEST(with_all_negative_parts) {
    Complex result = multiplication(getComplex(-1.2, -3.4), getComplex(-5.6, -7.8));

    isSimilar(result.real, -19.8);
    isSimilar(result.imaginary, 28.4);
} END_TEST

START_TEST(with_opposite_parts_in_numbers) {
    Complex result = multiplication(getComplex(-1.2, 3.4), getComplex(5.6, -7.8));

    isSimilar(result.real, 19.8);
    isSimilar(result.imaginary, 28.4);
} END_TEST

Suite *multiplicationSuite() {
    Suite *suite = suite_create("Multiplication of complex numbers");
    TCase *testCase = tcase_create("Multiplication");

    tcase_add_test(testCase, with_only_real_part);
    tcase_add_test(testCase, with_only_imaginary_part);
    tcase_add_test(testCase, with_all_positiv_parts);
    tcase_add_test(testCase, with_flipped_positiv_parts);
    tcase_add_test(testCase, with_one_positiv_and_one_negative_part);
    tcase_add_test(testCase, with_all_negative_parts);
    tcase_add_test(testCase, with_opposite_parts_in_numbers);
    suite_add_tcase(suite, testCase);

    return suite;
}
