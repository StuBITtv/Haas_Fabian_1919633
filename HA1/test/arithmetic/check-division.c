//
// Created by fhs on 13.12.2022.
//

#include "check-division.h"
#include "double-comparison.h"
#include "complex-getter.h"
#include "../../src/complex-numbers/complex.h"

START_TEST(all_parts_with_only_real_part) {
    Complex result = division(getComplex(1.2, 3.4), getComplex(5.6, 0));

    isSimilar(result.real, 0.2143);
    isSimilar(result.imaginary, 0.6071);
}

END_TEST

START_TEST(all_parts_with_only_imaginary_part) {
    Complex result = division(getComplex(1.2, 3.4), getComplex(0, 7.8));

    isSimilar(result.real, 0.4359);
    isSimilar(result.imaginary, -0.1538);
} END_TEST

START_TEST(only_real_part_with_all_parts) {
    Complex result = division(getComplex(1.2, 0), getComplex(5.6, 7.8));

    isSimilar(result.real, 0.0729);
    isSimilar(result.imaginary, -0.1015);
} END_TEST

START_TEST(only_imaginary_part_with_all_parts) {
    Complex result = division(getComplex(0, 3.4), getComplex(5.6, 7.8));

    isSimilar(result.real, 0.2876);
    isSimilar(result.imaginary, 0.2065);
} END_TEST

START_TEST(with_all_positiv_parts) {
    Complex result = division(getComplex(1.2, 3.4), getComplex(5.6, 7.8));

    isSimilar(result.real, 0.3605);
    isSimilar(result.imaginary, 0.105);
} END_TEST

START_TEST(with_flipped_positiv_parts) {
    Complex result = division(getComplex(1.2, 5.6), getComplex(3.4, 7.8));

    isSimilar(result.real, 0.6597);
    isSimilar(result.imaginary, 0.1337);
} END_TEST

START_TEST(with_one_positiv_and_one_negative_part) {
    Complex result = division(getComplex(-1.2, 3.4), getComplex(-5.6, 7.8));

    isSimilar(result.real, 0.3605);
    isSimilar(result.imaginary, -0.105);
} END_TEST

START_TEST(with_all_negative_parts) {
    Complex result = division(getComplex(-1.2, -3.4), getComplex(-5.6, -7.8));

    isSimilar(result.real, 0.3605);
    isSimilar(result.imaginary, 0.105);
} END_TEST

START_TEST(with_opposite_parts_in_numbers) {
    Complex result = division(getComplex(-1.2, 3.4), getComplex(5.6, -7.8));

    isSimilar(result.real, -0.3605);
    isSimilar(result.imaginary, 0.105);
} END_TEST

Suite *divisionSuite() {
    Suite *suite = suite_create("Division of complex numbers");
    TCase *testCase = tcase_create("Division");

    tcase_add_test(testCase, all_parts_with_only_real_part);
    tcase_add_test(testCase, all_parts_with_only_imaginary_part);
    tcase_add_test(testCase, only_real_part_with_all_parts);
    tcase_add_test(testCase, only_imaginary_part_with_all_parts);
    tcase_add_test(testCase, with_all_positiv_parts);
    tcase_add_test(testCase, with_flipped_positiv_parts);
    tcase_add_test(testCase, with_one_positiv_and_one_negative_part);
    tcase_add_test(testCase, with_all_negative_parts);
    tcase_add_test(testCase, with_opposite_parts_in_numbers);
    suite_add_tcase(suite, testCase);

    return suite;
}
