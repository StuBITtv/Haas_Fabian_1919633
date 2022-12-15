//
// Created by fhs on 14.12.2022.
//

#include "check-parser.h"
#include "../../src/complex-numbers/complex.h"
#include "../../src/cli/parser.h"

void parserTest(const char *input, double real, double imaginary) {
    Complex result = parseComplexNumber(input);

    ck_assert_double_eq(result.real, real);
    ck_assert_double_eq(result.imaginary, imaginary);
}

START_TEST(only_postiv_real_part) {
    parserTest("5.0", 5, 0);
}

END_TEST

START_TEST(only_negativ_real_part) {
    parserTest("-5.0", -5, 0);
}

END_TEST

START_TEST(only_postiv_imaginary_part) {
    parserTest("5.0i", 0, 5);
}

END_TEST

START_TEST(only_positiv_imaginary_part_single_i) {
    parserTest("i", 0, 1);
}

END_TEST

START_TEST(only_negativ_imaginary_part) {
    parserTest("-5.0i", 0, -5);
}

END_TEST

START_TEST(only_negativ_imaginary_part_single_i) {
    parserTest("-i", 0, -1);
}

END_TEST

START_TEST(all_positiv_parts) {
    parserTest("5.0 + 6i", 5, 6);
}

END_TEST

START_TEST(all_positiv_parts_single_i) {
    parserTest("5.0 + i", 5, 1);
}

END_TEST

START_TEST(negativ_real_part) {
    parserTest("-5.0 + 6i", -5, 6);
}

END_TEST

START_TEST(negativ_imaginary_part) {
    parserTest("5.0 + -6i", 5, -6);
}

END_TEST

START_TEST(negativ_imaginary_part_single_i) {
    parserTest("5.0 + -i", 5, -1);
}

END_TEST

START_TEST(subtrated_imaginary_part) {
    parserTest("5.0 - 6i", 5, -6);
}

END_TEST

START_TEST(subtrated_imaginary_part_single_i) {
    parserTest("5.0 - i", 5, -1);
}

END_TEST

START_TEST(all_negativ_parts) {
    parserTest("-5.0 + -6i", -5, -6);
}

END_TEST

START_TEST(negativ_real_part_subtrated_imaginary_part) {
    parserTest("-5.0 - 6i", -5, -6);
}

END_TEST

START_TEST(untrimmed_parts) {
    parserTest("   -   5.0    +   6   i   ", -5, 6);
}

END_TEST

START_TEST(flipped_parts) {
    parserTest("5.0i + 6", 6, 5);
}

END_TEST

START_TEST(flipped_parts_single_i) {
    parserTest("i + 6", 6, 1);
}

END_TEST

Suite *parserSuite() {
    Suite *suite = suite_create("Parses complex number");
    TCase *testCase = tcase_create("Parser");

    tcase_add_test(testCase, only_postiv_real_part);
    tcase_add_test(testCase, only_negativ_real_part);
    tcase_add_test(testCase, only_postiv_imaginary_part);
    tcase_add_test(testCase, only_positiv_imaginary_part_single_i);
    tcase_add_test(testCase, only_negativ_imaginary_part);
    tcase_add_test(testCase, only_negativ_imaginary_part_single_i);
    tcase_add_test(testCase, all_positiv_parts);
    tcase_add_test(testCase, all_positiv_parts_single_i);
    tcase_add_test(testCase, negativ_real_part);
    tcase_add_test(testCase, negativ_imaginary_part);
    tcase_add_test(testCase, negativ_imaginary_part_single_i);
    tcase_add_test(testCase, subtrated_imaginary_part);
    tcase_add_test(testCase, subtrated_imaginary_part_single_i);
    tcase_add_test(testCase, all_negativ_parts);
    tcase_add_test(testCase, negativ_real_part_subtrated_imaginary_part);
    tcase_add_test(testCase, untrimmed_parts);
    tcase_add_test(testCase, flipped_parts);
    tcase_add_test(testCase, flipped_parts_single_i);

    suite_add_tcase(suite, testCase);

    return suite;
}