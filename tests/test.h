#ifndef S21_TESTS
#define S21_TESTS

#include <check.h>
#include <time.h>

#include "../s21_matrix.h"

#define TOL 1e-7

Suite *suite_s21_create_remove();
Suite *suite_s21_equal();
Suite *suite_s21_sum();
Suite *suite_s21_sub();
Suite *suite_s21_mult();
Suite *suite_s21_transpose();
Suite *suite_s21_calc_complements();
Suite *suite_s21_determinant();
Suite *suite_s21_inverse_matrix();

#endif