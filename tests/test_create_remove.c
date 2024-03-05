#include "test.h"

START_TEST(test_create) {
  {
    const int rows = rand() % 100 + 1;
    const int columns = rand() % 100 + 1;
    matrix_t result = {0};
    ck_assert_int_eq(s21_create_matrix(rows, columns, &result), OK);
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++)
        ck_assert_float_eq_tol(0, result.matrix[i][j], 1e-07);
    }
    ck_assert_int_eq(result.rows, rows);
    ck_assert_int_eq(result.columns, columns);
    s21_remove_matrix(&result);
  }
  {
    const int rows = 0;
    const int columns = rand() % 100 + 1;
    matrix_t result = {0};
    ck_assert_int_eq(s21_create_matrix(rows, columns, &result),
                     INCORRECT_MATRIX);
  }
  {
    const int rows = rand() % 100 + 1;
    const int columns = 0;
    matrix_t result = {0};
    ck_assert_int_eq(s21_create_matrix(rows, columns, &result),
                     INCORRECT_MATRIX);
  }
  {
    const int rows = -(rand() % 100);
    const int columns = rand() % 100 + 1;
    matrix_t result = {0};
    ck_assert_int_eq(s21_create_matrix(rows, columns, &result),
                     INCORRECT_MATRIX);
  }
  {
    const int rows = rand() % 100 + 1;
    const int columns = -(rand() % 100);
    matrix_t result = {0};
    ck_assert_int_eq(s21_create_matrix(rows, columns, &result),
                     INCORRECT_MATRIX);
  }
  {
    const int rows = rand() % 100 + 1;
    const int columns = rand() % 100 + 1;
    ck_assert_int_eq(s21_create_matrix(rows, columns, NULL), INCORRECT_MATRIX);
  }
}
END_TEST

START_TEST(test_remove) {
  {
    const int rows = 5;
    const int columns = 5;
    matrix_t result = {0};
    s21_create_matrix(rows, columns, &result);
    s21_remove_matrix(&result);
    ck_assert_int_eq(result.rows, 0);
    ck_assert_int_eq(result.columns, 0);
  }
  { s21_remove_matrix(NULL); }
  {
    matrix_t result = {NULL, 0, 0};
    s21_remove_matrix(&result);
  }
}
END_TEST

Suite *suite_s21_create_remove() {
  Suite *s = suite_create("s21_create_remove");
  TCase *tc = tcase_create("s21_create_remove");

  tcase_add_test(tc, test_create);
  tcase_add_test(tc, test_remove);
  suite_add_tcase(s, tc);
  return s;
}