#include "test.h"

START_TEST(test_mult_number) {
  // random
  {
    const int rows = rand() % 25 + 1;
    const int columns = rand() % 25 + 1;
    const double number = (double)((double)rand() / RAND_MAX) + rand() % 50;
    matrix_t A = {0};
    matrix_t check = {0};
    matrix_t result = {0};
    s21_create_matrix(rows, columns, &A);
    s21_create_matrix(rows, columns, &check);
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
        A.matrix[i][j] = (double)((double)rand() / RAND_MAX) + rand() % 50;
        check.matrix[i][j] = A.matrix[i][j] * number;
      }
    }
    ck_assert_int_eq(s21_mult_number(&A, number, &result), OK);
    ck_assert_int_eq(s21_eq_matrix(&result, &check), SUCCESS);
    s21_remove_matrix(&A);
    s21_remove_matrix(&check);
    s21_remove_matrix(&result);
  }
  // rows = 0
  {
    const int rows = 0;
    const int columns = rand() % 100 + 1;
    const double number = (double)((double)rand() / RAND_MAX) + rand() % 50;
    matrix_t A = {0};
    matrix_t result = {0};
    s21_create_matrix(rows, columns, &A);
    ck_assert_int_eq(s21_mult_number(&A, number, &result), INCORRECT_MATRIX);
    s21_remove_matrix(&A);
  }
  // columns = 0
  {
    const int rows = rand() % 100 + 1;
    const int columns = 0;
    const double number = (double)((double)rand() / RAND_MAX) + rand() % 50;
    matrix_t A = {0};
    matrix_t result = {0};
    s21_create_matrix(rows, columns, &A);
    ck_assert_int_eq(s21_mult_number(&A, number, &result), INCORRECT_MATRIX);
    s21_remove_matrix(&A);
  }
  // Отрицательное значение rows
  {
    const int rows = -(rand() % 100);
    const int columns = rand() % 100 + 1;
    const double number = (double)((double)rand() / RAND_MAX) + rand() % 50;
    matrix_t A = {0};
    matrix_t result = {0};
    s21_create_matrix(rows, columns, &A);
    ck_assert_int_eq(s21_mult_number(&A, number, &result), INCORRECT_MATRIX);
    s21_remove_matrix(&A);
  }
  // Отрицательное значение columns
  {
    const int rows = rand() % 100 + 1;
    const int columns = -(rand() % 100);
    const double number = (double)((double)rand() / RAND_MAX) + rand() % 50;
    matrix_t A = {0};
    matrix_t result = {0};
    s21_create_matrix(rows, columns, &A);
    ck_assert_int_eq(s21_mult_number(&A, number, &result), INCORRECT_MATRIX);
    s21_remove_matrix(&A);
  }
  // result - NULL
  {
    const int rows = rand() % 100 + 1;
    const int columns = rand() % 100 + 1;
    const double number = (double)((double)rand() / RAND_MAX) + rand() % 50;
    matrix_t A = {0};
    s21_create_matrix(rows, columns, &A);
    ck_assert_int_eq(s21_mult_number(&A, number, NULL), INCORRECT_MATRIX);
    s21_remove_matrix(&A);
  }
  // A - NULL
  {
    const double number = (double)((double)rand() / RAND_MAX) + rand() % 50;
    matrix_t result = {0};
    ck_assert_int_eq(s21_mult_number(NULL, number, &result), INCORRECT_MATRIX);
  }
}
END_TEST

START_TEST(test_mult_matrix) {
  // random (rows > columns)
  {
    const int rows = rand() % 25 + 25;
    int columns = rand() % 25 + 1;
    matrix_t A = {0};
    matrix_t B = {0};
    matrix_t check = {0};
    matrix_t result = {0};
    s21_create_matrix(rows, columns, &A);
    s21_create_matrix(columns, rows, &B);
    s21_create_matrix(A.rows, B.columns, &check);
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
        A.matrix[i][j] = (double)((double)rand() / RAND_MAX) + rand() % 25;
        B.matrix[j][i] = (double)((double)rand() / RAND_MAX) + rand() % 25 + 25;
      }
    }
    for (int i = 0; i < A.rows; i++) {
      for (int j = 0; j < B.columns; j++) {
        for (int k = 0; k < B.rows; k++)
          check.matrix[i][j] += A.matrix[i][k] * B.matrix[k][j];
      }
    }
    ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), OK);
    ck_assert_int_eq(s21_eq_matrix(&result, &check), SUCCESS);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&check);
    s21_remove_matrix(&result);
  }
  // Тест с readme
  {
    const int rows = 3;
    const int columns = 2;
    matrix_t A = {0};
    matrix_t B = {0};
    matrix_t check = {0};
    matrix_t result = {0};
    s21_create_matrix(rows, columns, &A);
    s21_create_matrix(columns, rows, &B);
    s21_create_matrix(A.rows, B.columns, &check);
    double matrix_A[] = {1, 4, 2, 5, 3, 6};
    double matrix_B[] = {1, 2, -1, 3, 1, 4};
    double matrix_check[] = {9, 11, 17, 12, 13, 22, 15, 15, 27};
    int count = 0;
    for (int i = 0; i < A.rows; i++) {
      for (int j = 0; j < A.columns; j++) {
        A.matrix[i][j] = matrix_A[count];
        B.matrix[j][i] = matrix_B[count];
        count++;
      }
    }
    count = 0;
    for (int i = 0; i < check.rows; i++) {
      for (int j = 0; j < check.columns; j++) {
        check.matrix[i][j] = matrix_check[count];
        count++;
      }
    }
    ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), OK);
    ck_assert_int_eq(s21_eq_matrix(&result, &check), SUCCESS);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&check);
    s21_remove_matrix(&result);
  }
  // r = 3, c = 2
  {
    const int rows = 3;
    const int columns = 2;
    matrix_t A = {0};
    matrix_t B = {0};
    matrix_t check = {0};
    matrix_t result = {0};
    s21_create_matrix(rows, columns, &A);
    s21_create_matrix(columns, columns, &B);
    s21_create_matrix(A.rows, B.columns, &check);
    double matrix_A[] = {1, -1, 2, 0, 3, 0};
    double matrix_B[] = {1, 1, 2, 0};
    double matrix_check[] = {-1, 1, 2, 2, 3, 3};
    int count = 0;
    for (int i = 0; i < A.rows; i++) {
      for (int j = 0; j < A.columns; j++) {
        A.matrix[i][j] = matrix_A[count];
        check.matrix[i][j] = matrix_check[count];
        count++;
      }
    }
    count = 0;
    for (int i = 0; i < B.rows; i++) {
      for (int j = 0; j < B.columns; j++) {
        B.matrix[i][j] = matrix_B[count];
        count++;
      }
    }
    ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), OK);
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
    ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), INCORRECT_MATRIX);
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
    ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), INCORRECT_MATRIX);
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
    ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), INCORRECT_MATRIX);
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
    ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), INCORRECT_MATRIX);
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
    ck_assert_int_eq(s21_mult_matrix(&A, &B, NULL), INCORRECT_MATRIX);
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
    ck_assert_int_eq(s21_mult_matrix(&A, NULL, &result), INCORRECT_MATRIX);
    ck_assert_int_eq(s21_mult_matrix(NULL, &A, &result), INCORRECT_MATRIX);
    s21_remove_matrix(&A);
  }
  // A->rows != B-> columns
  {
    const int rows = rand() % 25 + 1;
    const int columns = rand() % 25 + 25;
    matrix_t A = {0};
    matrix_t B = {0};
    matrix_t result = {0};
    s21_create_matrix(rows, columns, &A);
    s21_create_matrix(rows, columns, &B);
    ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), OPERATION_ERROR);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
  }
}
END_TEST

Suite *suite_s21_mult() {
  Suite *s = suite_create("s21_mult");
  TCase *tc = tcase_create("s21_mult");

  tcase_add_test(tc, test_mult_number);
  tcase_add_test(tc, test_mult_matrix);
  suite_add_tcase(s, tc);
  return s;
}