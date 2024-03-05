#include "test.h"

START_TEST(test_transpose) {
  // random
  {
    const int rows = rand() % 25 + 1;
    const int columns = rand() % 25 + 1;
    matrix_t A = {0};
    matrix_t check = {0};
    matrix_t result = {0};
    s21_create_matrix(rows, columns, &A);
    s21_create_matrix(columns, rows, &check);
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
        A.matrix[i][j] = (double)((double)rand() / RAND_MAX) + rand() % 50;
        check.matrix[j][i] = A.matrix[i][j];
      }
    }
    ck_assert_int_eq(s21_transpose(&A, &result), OK);
    ck_assert_int_eq(s21_eq_matrix(&result, &check), SUCCESS);
    s21_remove_matrix(&A);
    s21_remove_matrix(&check);
    s21_remove_matrix(&result);
  }
  // rows = 0
  {
    const int rows = 0;
    const int columns = rand() % 100 + 1;
    matrix_t A = {0};
    matrix_t result = {0};
    s21_create_matrix(rows, columns, &A);
    ck_assert_int_eq(s21_transpose(&A, &result), INCORRECT_MATRIX);
    s21_remove_matrix(&A);
  }
  // columns = 0
  {
    const int rows = rand() % 100 + 1;
    const int columns = 0;
    matrix_t A = {0};
    matrix_t result = {0};
    s21_create_matrix(rows, columns, &A);
    ck_assert_int_eq(s21_transpose(&A, &result), INCORRECT_MATRIX);
    s21_remove_matrix(&A);
  }
  // Отрицательное значение rows
  {
    const int rows = -(rand() % 100);
    const int columns = rand() % 100 + 1;
    matrix_t A = {0};
    matrix_t result = {0};
    s21_create_matrix(rows, columns, &A);
    ck_assert_int_eq(s21_transpose(&A, &result), INCORRECT_MATRIX);
    s21_remove_matrix(&A);
  }
  // Отрицательное значение columns
  {
    const int rows = rand() % 100 + 1;
    const int columns = -(rand() % 100);
    matrix_t A = {0};
    matrix_t result = {0};
    s21_create_matrix(rows, columns, &A);
    ck_assert_int_eq(s21_transpose(&A, &result), INCORRECT_MATRIX);
    s21_remove_matrix(&A);
  }
  // result - NULL
  {
    const int rows = rand() % 100 + 1;
    const int columns = rand() % 100 + 1;
    matrix_t A = {0};
    s21_create_matrix(rows, columns, &A);
    ck_assert_int_eq(s21_transpose(&A, NULL), INCORRECT_MATRIX);
    s21_remove_matrix(&A);
  }
  // A - NULL
  {
    matrix_t result = {0};
    ck_assert_int_eq(s21_transpose(NULL, &result), INCORRECT_MATRIX);
  }
}
END_TEST

Suite *suite_s21_transpose() {
  Suite *s = suite_create("s21_transpose");
  TCase *tc = tcase_create("s21_transpose");

  tcase_add_test(tc, test_transpose);
  suite_add_tcase(s, tc);
  return s;
}