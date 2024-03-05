#include "test.h"

START_TEST(test_sub) {
  {
    const int rows = rand() % 100 + 1;
    const int columns = rand() % 100 + 1;
    matrix_t A = {0};
    matrix_t B = {0};
    matrix_t check = {0};
    matrix_t result = {0};
    s21_create_matrix(rows, columns, &A);
    s21_create_matrix(rows, columns, &B);
    s21_create_matrix(rows, columns, &check);
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
        A.matrix[i][j] = (double)((double)rand() / RAND_MAX) + rand() % 50;
        B.matrix[i][j] = (double)((double)rand() / RAND_MAX) + rand() % 50 + 50;
        check.matrix[i][j] = A.matrix[i][j] - B.matrix[i][j];
      }
    }
    ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), OK);
    ck_assert_int_eq(s21_eq_matrix(&result, &check), SUCCESS);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&check);
    s21_remove_matrix(&result);
  }
  // rows = 0
  {
    const int rows = 0;
    const int columns = rand() % 100 + 1;
    matrix_t A = {0};
    matrix_t B = {0};
    matrix_t result = {0};
    s21_create_matrix(rows, columns, &A);
    s21_create_matrix(rows, columns, &B);
    ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), INCORRECT_MATRIX);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
  }
  // columns = 0
  {
    const int rows = rand() % 100 + 1;
    const int columns = 0;
    matrix_t A = {0};
    matrix_t B = {0};
    matrix_t result = {0};
    s21_create_matrix(rows, columns, &A);
    s21_create_matrix(rows, columns, &B);
    ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), INCORRECT_MATRIX);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
  }
  // Отрицательное значение rows
  {
    const int rows = -(rand() % 100);
    const int columns = rand() % 100 + 1;
    matrix_t A = {0};
    matrix_t B = {0};
    matrix_t result = {0};
    s21_create_matrix(rows, columns, &A);
    s21_create_matrix(rows, columns, &B);
    ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), INCORRECT_MATRIX);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
  }
  // Отрицательное значение columns
  {
    const int rows = rand() % 100 + 1;
    const int columns = -(rand() % 100);
    matrix_t A = {0};
    matrix_t B = {0};
    matrix_t result = {0};
    s21_create_matrix(rows, columns, &A);
    s21_create_matrix(rows, columns, &B);
    ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), INCORRECT_MATRIX);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
  }
  // result - NULL
  {
    const int rows = rand() % 100 + 1;
    const int columns = rand() % 100 + 1;
    matrix_t A = {0};
    matrix_t B = {0};
    s21_create_matrix(rows, columns, &A);
    s21_create_matrix(rows, columns, &B);
    ck_assert_int_eq(s21_sub_matrix(&A, &B, NULL), INCORRECT_MATRIX);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
  }
  // A - NULL
  {
    const int rows = rand() % 100 + 1;
    const int columns = rand() % 100 + 1;
    matrix_t A = {0};
    matrix_t result = {0};
    s21_create_matrix(rows, columns, &A);
    ck_assert_int_eq(s21_sub_matrix(&A, NULL, &result), INCORRECT_MATRIX);
    ck_assert_int_eq(s21_sub_matrix(NULL, &A, &result), INCORRECT_MATRIX);
    s21_remove_matrix(&A);
  }

  // Различное количество rows
  {
    const int rows_A = rand() % 50 + 1;
    const int rows_B = rand() % 50 + 50;
    const int columns = rand() % 100 + 1;
    matrix_t A = {0};
    matrix_t B = {0};
    matrix_t result = {0};
    s21_create_matrix(rows_A, columns, &A);
    s21_create_matrix(rows_B, columns, &B);
    ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), OPERATION_ERROR);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
  }
  // Различное количество columns
  {
    const int rows = rand() % 100 + 1;
    const int columns_A = rand() % 50 + 1;
    const int columns_B = rand() % 50 + 50;
    matrix_t A = {0};
    matrix_t B = {0};
    matrix_t result = {0};
    s21_create_matrix(rows, columns_A, &A);
    s21_create_matrix(rows, columns_B, &B);
    ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), OPERATION_ERROR);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
  }
}
END_TEST

Suite *suite_s21_sub() {
  Suite *s = suite_create("s21_sub");
  TCase *tc = tcase_create("s21_sub");

  tcase_add_test(tc, test_sub);
  suite_add_tcase(s, tc);
  return s;
}