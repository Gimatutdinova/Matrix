#include "test.h"

START_TEST(test_equal) {
  // Равные матрицы, rows = 1
  {
    const int rows = 1;
    const int columns = 3;
    double matrix[] = {3, 5, 8};
    matrix_t A = {0};
    matrix_t B = {0};
    s21_create_matrix(rows, columns, &A);
    s21_create_matrix(rows, columns, &B);
    for (int j = 0; j < columns; j++) {
      A.matrix[0][j] = matrix[j];
      B.matrix[0][j] = matrix[j];
    }
    ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
  }
  // Неравные матрицы, rows = 1
  {
    const int rows = 1;
    const int columns = 3;
    double matrix_A[] = {3, 5, 7};
    double matrix_B[] = {1, 5, 9};
    matrix_t A = {0};
    matrix_t B = {0};
    s21_create_matrix(rows, columns, &A);
    s21_create_matrix(rows, columns, &B);
    for (int j = 0; j < columns; j++) {
      A.matrix[0][j] = matrix_A[j];
      B.matrix[0][j] = matrix_B[j];
    }
    ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
  }
  // Равные матрицы
  {
    const int rows = rand() % 100 + 1;
    const int columns = rand() % 100 + 1;
    matrix_t A = {0};
    matrix_t B = {0};
    s21_create_matrix(rows, columns, &A);
    s21_create_matrix(rows, columns, &B);
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
        A.matrix[i][j] = (double)((double)rand() / RAND_MAX) + rand() % 100;
        B.matrix[i][j] = A.matrix[i][j];
      }
    }
    ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
  }
  // Неравные матрицы
  {
    const int rows = rand() % 100 + 1;
    const int columns = rand() % 100 + 1;
    matrix_t A = {0};
    matrix_t B = {0};
    s21_create_matrix(rows, columns, &A);
    s21_create_matrix(rows, columns, &B);
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
        A.matrix[i][j] = (double)((double)rand() / RAND_MAX) + rand() % 50;
        B.matrix[i][j] = (double)((double)rand() / RAND_MAX) + rand() % 50 + 50;
      }
    }
    ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
  }
  // Отличается 8 знак после ,
  {
    const int rows = 1;
    const int columns = 3;
    double matrix_A[] = {0.00000035, 0.00000059, 0.00000081};
    double matrix_B[] = {0.00000037, 0.00000059, 0.00000089};
    matrix_t A = {0};
    matrix_t B = {0};
    s21_create_matrix(rows, columns, &A);
    s21_create_matrix(rows, columns, &B);
    for (int j = 0; j < columns; j++) {
      A.matrix[0][j] = matrix_A[j];
      B.matrix[0][j] = matrix_B[j];
    }
    ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
  }
  // Отличается 7 знак после ,
  {
    const int rows = 1;
    const int columns = 3;
    double matrix_A[] = {0.0000005, 0.0000005, 0.0000001};
    double matrix_B[] = {0.0000007, 0.0000005, 0.0000009};
    matrix_t A = {0};
    matrix_t B = {0};
    s21_create_matrix(rows, columns, &A);
    s21_create_matrix(rows, columns, &B);
    for (int j = 0; j < columns; j++) {
      A.matrix[0][j] = matrix_A[j];
      B.matrix[0][j] = matrix_B[j];
    }
    ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
  }
  // NULL
  {
    const int rows = 1;
    const int columns = 3;
    double matrix_A[] = {0.0000005, 0.0000005, 0.0000001};
    matrix_t A = {0};
    s21_create_matrix(rows, columns, &A);
    for (int j = 0; j < columns; j++) A.matrix[0][j] = matrix_A[j];
    ck_assert_int_eq(s21_eq_matrix(&A, NULL), FAILURE);
    ck_assert_int_eq(s21_eq_matrix(NULL, &A), FAILURE);
    s21_remove_matrix(&A);
  }
}
END_TEST

Suite *suite_s21_equal() {
  Suite *s = suite_create("s21_equal");
  TCase *tc = tcase_create("s21_equal");

  tcase_add_test(tc, test_equal);
  suite_add_tcase(s, tc);
  return s;
}