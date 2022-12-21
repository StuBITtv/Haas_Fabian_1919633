//
// Created by fhs on 21.12.2022.
//

#include "check-with-derivative.h"
#include "approximation-test.h"
#include "sample-functions.h"

START_TEST(quadratic_never_zero) {
    earlyExitTest(
            5,
            quadratic_without_zero,
            quadratic_without_zero_derivative
    );
}

END_TEST

START_TEST(quadratic_one_solution_from_left) {
    approximationTest(
            -20,
            -5,
            quadratic_zero_at_negative_5,
            quadratic_zero_at_negative_5_derivative
    );
}

END_TEST

START_TEST(quadratic_one_solution_from_right) {
    approximationTest(
            30,
            -5,
            quadratic_zero_at_negative_5,
            quadratic_zero_at_negative_5_derivative
    );
}

END_TEST

START_TEST(quadratic_two_solutions_first_from_left) {
    approximationTest(
            0,
            1,
            quadratic_zero_at_1_and_3,
            quadratic_zero_at_1_and_3_derivative
    );
}

END_TEST

START_TEST(quadratic_two_solutions_first_from_right) {
    approximationTest(
            1.5,
            1,
            quadratic_zero_at_1_and_3,
            quadratic_zero_at_1_and_3_derivative
    );
}

END_TEST


START_TEST(quadratic_two_solutions_second_from_left) {
    approximationTest(
            2.5,
            3,
            quadratic_zero_at_1_and_3,
            quadratic_zero_at_1_and_3_derivative
    );
}

END_TEST


START_TEST(quadratic_two_solutions_second_from_right) {
    approximationTest(
            12,
            3,
            quadratic_zero_at_1_and_3,
            quadratic_zero_at_1_and_3_derivative
    );
}

END_TEST

START_TEST(cubic_one_solution_from_left) {
    approximationTest(
            0,
            10,
            cubic_zero_at_10,
            cubic_zero_at_10_derivative
    );
}

END_TEST

START_TEST(cubic_one_solution_from_right) {
    approximationTest(
            13,
            10,
            cubic_zero_at_10,
            cubic_zero_at_10_derivative
    );
}

START_TEST(cubic_two_solutions_first_from_left) {
    approximationTest(
            -14,
            -8,
            cubic_zero_at_negative_8_and_7,
            cubic_zero_at_negative_8_and_7_derivative
    );
}

END_TEST

START_TEST(cubic_two_solutions_first_from_right) {
    approximationTest(
            -3,
            -8,
            cubic_zero_at_negative_8_and_7,
            cubic_zero_at_negative_8_and_7_derivative
    );
}

END_TEST


START_TEST(cubic_two_solutions_second_from_left) {
    approximationTest(
            3,
            7,
            cubic_zero_at_negative_8_and_7,
            cubic_zero_at_negative_8_and_7_derivative
    );
}

END_TEST


START_TEST(cubic_two_solutions_second_from_right) {
    approximationTest(
            21,
            7,
            cubic_zero_at_negative_8_and_7,
            cubic_zero_at_negative_8_and_7_derivative
    );
}

START_TEST(cubic_three_solutions_first_from_left) {
    approximationTest(
            -10,
            -4,
            cubic_zero_at_negative_4_and_0_and_11,
            cubic_zero_at_negative_4_and_0_and_11_derivative
    );
}

END_TEST

START_TEST(cubic_three_solutions_first_from_right) {
    approximationTest(
            -3,
            -4,
            cubic_zero_at_negative_4_and_0_and_11,
            cubic_zero_at_negative_4_and_0_and_11_derivative
    );
}

END_TEST

START_TEST(cubic_three_solutions_second_from_left) {
    approximationTest(
            -1,
            0,
            cubic_zero_at_negative_4_and_0_and_11,
            cubic_zero_at_negative_4_and_0_and_11_derivative
    );
}

END_TEST

START_TEST(cubic_three_solutions_second_from_right) {
    approximationTest(
            3,
            0,
            cubic_zero_at_negative_4_and_0_and_11,
            cubic_zero_at_negative_4_and_0_and_11_derivative
    );
}

END_TEST

START_TEST(cubic_three_solutions_third_from_left) {
    approximationTest(
            9,
            11,
            cubic_zero_at_negative_4_and_0_and_11,
            cubic_zero_at_negative_4_and_0_and_11_derivative
    );
}

END_TEST

START_TEST(cubic_three_solutions_third_from_right) {
    approximationTest(
            31,
            11,
            cubic_zero_at_negative_4_and_0_and_11,
            cubic_zero_at_negative_4_and_0_and_11_derivative
    );
}

END_TEST


Suite *derivativeSuite() {
    Suite *suite = suite_create("Zero of functions with their actual derivative");

    TCase *noSolution = tcase_create("No solution");
    tcase_add_test(noSolution, quadratic_never_zero);

    TCase *oneSolution = tcase_create("One solution");
    tcase_add_test(oneSolution, quadratic_one_solution_from_left);
    tcase_add_test(oneSolution, quadratic_one_solution_from_right);
    tcase_add_test(oneSolution, cubic_one_solution_from_left);
    tcase_add_test(oneSolution, cubic_one_solution_from_right);

    TCase *twoSolutions = tcase_create("Two solutions");
    tcase_add_test(twoSolutions, quadratic_two_solutions_first_from_left);
    tcase_add_test(twoSolutions, quadratic_two_solutions_first_from_right);
    tcase_add_test(twoSolutions, quadratic_two_solutions_second_from_right);
    tcase_add_test(twoSolutions, quadratic_two_solutions_second_from_left);
    tcase_add_test(twoSolutions, cubic_two_solutions_first_from_right);
    tcase_add_test(twoSolutions, cubic_two_solutions_first_from_left);
    tcase_add_test(twoSolutions, cubic_two_solutions_second_from_right);
    tcase_add_test(twoSolutions, cubic_two_solutions_second_from_left);

    TCase *threeSolutions = tcase_create("Three solutions");
    tcase_add_test(threeSolutions, cubic_three_solutions_first_from_left);
    tcase_add_test(threeSolutions, cubic_three_solutions_first_from_right);
    tcase_add_test(threeSolutions, cubic_three_solutions_second_from_left);
    tcase_add_test(threeSolutions, cubic_three_solutions_second_from_right);
    tcase_add_test(threeSolutions, cubic_three_solutions_third_from_left);
    tcase_add_test(threeSolutions, cubic_three_solutions_third_from_right);

    suite_add_tcase(suite, noSolution);
    suite_add_tcase(suite, oneSolution);
    suite_add_tcase(suite, twoSolutions);
    suite_add_tcase(suite, threeSolutions);

    return suite;
}
