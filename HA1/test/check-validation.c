//
// Created by fhs on 13.12.2022.
//

#include "check-validation.h"
#include "../src/complex-numbers/complex.h"

#define isValid(X) ck_assert_int_ne(X, 0)
#define isInvalid(X) ck_assert_int_eq(X, 0)

START_TEST(invalid_unexpected_character) {
    isInvalid(validComplexNumber("5.0/"));
}

START_TEST(invalid_unexpected_letter) {
    isInvalid(validComplexNumber("5.0I"));
}

START_TEST(invalid_unexpected_leading_operation) {
    isInvalid(validComplexNumber("+ + 5"));
}

START_TEST(invalid_unexpected_ending_operation) {
    isInvalid(validComplexNumber("5 +"));
}

START_TEST(invalid_unexpected_operation_inbetween) {
    isInvalid(validComplexNumber("5 + + + 6i"));
}

START_TEST(invalid_unexpected_point_in_number) {
    isInvalid(validComplexNumber("5.0.0 + 6i"));
}

START_TEST(invalid_unexpected_real_part) {
    isInvalid(validComplexNumber("5 + 5"));
} END_TEST

START_TEST(invalid_unexpected_imaginary_part) {
    isInvalid(validComplexNumber("5i + 5i"));
} END_TEST

START_TEST(invalid_trimmed_unexpected_real_part) {
    isInvalid(validComplexNumber("5+5"));
} END_TEST

START_TEST(invalid_trimmed_unexpected_imaginary_part) {
    isInvalid(validComplexNumber("5i+5i"));
} END_TEST

START_TEST(invalid_unexpected_imaginary_endfix) {
    isInvalid(validComplexNumber("5 + 6.0ii"));
}

START_TEST(valid_only_postiv_real_part) {
    isValid(validComplexNumber("5.0"));
} END_TEST

START_TEST(valid_only_negativ_real_part) {
    isValid(validComplexNumber("-5.0"));
} END_TEST

START_TEST(valid_only_postiv_imaginary_part) {
    isValid(validComplexNumber("5.0i"));
} END_TEST

START_TEST(valid_only_negativ_imaginary_part) {
    isValid(validComplexNumber("-5.0i"));
} END_TEST

START_TEST(valid_all_positiv_parts) {
    isValid(validComplexNumber("5.0 + 6i"));
} END_TEST

START_TEST(valid_negativ_real_part) {
    isValid(validComplexNumber("-5.0 + 6i"));
} END_TEST

START_TEST(valid_negativ_imaginary_part) {
    isValid(validComplexNumber("5.0 + -6i"));
} END_TEST

START_TEST(valid_subtrated_imaginary_part) {
    isValid(validComplexNumber("5.0 - 6i"));
} END_TEST

START_TEST(valid_all_negativ_parts) {
    isValid(validComplexNumber("-5.0 + -6i"));
} END_TEST

START_TEST(valid_negativ_real_part_subtrated_imaginary_part) {
    isValid(validComplexNumber("-5.0 - 6i"));
} END_TEST

START_TEST(valid_untrimmed_parts) {
    isValid(validComplexNumber("      5.0    -   6   i   "));
} END_TEST

START_TEST(valid_flipped_parts) {
    isValid(validComplexNumber("5.0i + 6"));
} END_TEST

Suite *numberValidationSuite() {
    Suite *suite = suite_create("Validate complex number");
    TCase *testCase = tcase_create("Validate");

    tcase_add_test(testCase, invalid_unexpected_character);
    tcase_add_test(testCase, invalid_unexpected_letter);
    tcase_add_test(testCase, invalid_unexpected_leading_operation);
    tcase_add_test(testCase, invalid_unexpected_ending_operation);
    tcase_add_test(testCase, invalid_unexpected_operation_inbetween);
    tcase_add_test(testCase, invalid_unexpected_operation_inbetween);
    tcase_add_test(testCase, invalid_unexpected_real_part);
    tcase_add_test(testCase, invalid_unexpected_imaginary_part);
    tcase_add_test(testCase, invalid_trimmed_unexpected_real_part);
    tcase_add_test(testCase, invalid_trimmed_unexpected_imaginary_part);
    tcase_add_test(testCase, valid_only_postiv_real_part);
    tcase_add_test(testCase, valid_only_negativ_real_part);
    tcase_add_test(testCase, valid_only_postiv_imaginary_part);
    tcase_add_test(testCase, valid_only_negativ_imaginary_part);
    tcase_add_test(testCase, valid_all_positiv_parts);
    tcase_add_test(testCase, valid_negativ_real_part);
    tcase_add_test(testCase, valid_negativ_imaginary_part);
    tcase_add_test(testCase, valid_subtrated_imaginary_part);
    tcase_add_test(testCase, valid_all_negativ_parts);
    tcase_add_test(testCase, valid_negativ_real_part_subtrated_imaginary_part);
    tcase_add_test(testCase, valid_untrimmed_parts);
    tcase_add_test(testCase, valid_flipped_parts);

    suite_add_tcase(suite, testCase);

    return suite;
}
