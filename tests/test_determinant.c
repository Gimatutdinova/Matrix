#include "test.h"

START_TEST(test_determinant) {
  // correct values
  {
    const int size = 1;
    matrix_t A = {0};
    double result = 0;
    s21_create_matrix(size, size, &A);
    A.matrix[0][0] = 5;
    ck_assert_int_eq(s21_determinant(&A, &result), OK);
    ck_assert_double_eq_tol(result, 5, TOL);
    s21_remove_matrix(&A);
  }
  {
    const int size = 1;
    matrix_t A = {0};
    double result = 0;
    s21_create_matrix(size, size, &A);
    A.matrix[0][0] = -5;
    ck_assert_int_eq(s21_determinant(&A, &result), OK);
    ck_assert_double_eq_tol(result, -5, TOL);
    s21_remove_matrix(&A);
  }
  {
    const int size = 1;
    matrix_t A = {0};
    double result = 0;
    s21_create_matrix(size, size, &A);
    A.matrix[0][0] = 0;
    ck_assert_int_eq(s21_determinant(&A, &result), OK);
    ck_assert_double_eq_tol(result, 0, TOL);
    s21_remove_matrix(&A);
  }
  {
    const int size = 2;
    matrix_t A = {0};
    s21_create_matrix(size, size, &A);

    A.matrix[0][0] = -5;
    A.matrix[0][1] = -4;
    A.matrix[1][0] = -2;
    A.matrix[1][1] = -3;

    double result = 0;
    ck_assert_int_eq(s21_determinant(&A, &result), OK);
    ck_assert_double_eq_tol(result, 7, TOL);
    s21_remove_matrix(&A);
  }
  {
    const int size = 2;
    matrix_t A = {0};
    s21_create_matrix(size, size, &A);

    A.matrix[0][0] = 1.0;
    A.matrix[0][1] = -1.0;
    A.matrix[1][0] = 0.0;
    A.matrix[1][1] = 0.0;

    double result = 0;
    ck_assert_int_eq(s21_determinant(&A, &result), OK);
    ck_assert_double_eq_tol(result, 0, TOL);
    s21_remove_matrix(&A);
  }
  {
    const int size = 2;
    matrix_t A = {0};
    s21_create_matrix(size, size, &A);

    A.matrix[0][0] = 1.0;
    A.matrix[0][1] = -1.0;
    A.matrix[1][0] = -1.0;
    A.matrix[1][1] = 0.0;

    double result = 0;
    ck_assert_int_eq(s21_determinant(&A, &result), OK);
    ck_assert_double_eq_tol(result, -1, TOL);
    s21_remove_matrix(&A);
  }
  {
    const int size = 3;
    matrix_t A = {0};
    s21_create_matrix(size, size, &A);

    A.matrix[0][0] = 2;
    A.matrix[0][1] = 3;
    A.matrix[0][2] = 1;
    A.matrix[1][0] = 7;
    A.matrix[1][1] = 4;
    A.matrix[1][2] = 1;
    A.matrix[2][0] = 9;
    A.matrix[2][1] = -2;
    A.matrix[2][2] = 1;

    double result = 0;
    ck_assert_int_eq(s21_determinant(&A, &result), OK);
    ck_assert_double_eq_tol(result, -32, TOL);
    s21_remove_matrix(&A);
  }
  {
    const int size = 4;
    matrix_t A = {0};
    s21_create_matrix(size, size, &A);

    for (int i = 0; i < size; i++)
      for (int j = 0; j < size; j++) A.matrix[i][j] = j + i;

    double result = 0;
    ck_assert_int_eq(s21_determinant(&A, &result), OK);
    ck_assert_double_eq_tol(result, 0, TOL);
    s21_remove_matrix(&A);
  }
  {
    const int size = 5;
    matrix_t A = {0};
    s21_create_matrix(size, size, &A);

    for (int i = 0; i < size; i++)
      for (int j = 0; j < size; j++) A.matrix[i][j] = j;

    double result = 0;
    ck_assert_int_eq(s21_determinant(&A, &result), OK);
    ck_assert_double_eq_tol(result, 0, TOL);
    s21_remove_matrix(&A);
  }
  {
    const int size = 5;
    matrix_t A = {0};
    s21_create_matrix(size, size, &A);

    for (int i = 0; i < size; i++)
      for (int j = 0; j < size; j++) A.matrix[i][j] = i;

    double result = 0;
    ck_assert_int_eq(s21_determinant(&A, &result), OK);
    ck_assert_double_eq_tol(result, 0, TOL);
    s21_remove_matrix(&A);
  }
  {
    const int size = 5;
    matrix_t A = {0};
    s21_create_matrix(size, size, &A);

    A.matrix[0][1] = 6;
    A.matrix[0][2] = -2;
    A.matrix[0][3] = -1;
    A.matrix[0][4] = 5;
    A.matrix[1][3] = -9;
    A.matrix[1][4] = -7;
    A.matrix[2][1] = 15;
    A.matrix[2][2] = 35;
    A.matrix[3][1] = -1;
    A.matrix[3][2] = -11;
    A.matrix[3][3] = -2;
    A.matrix[3][4] = 1;
    A.matrix[4][0] = -2;
    A.matrix[4][1] = -2;
    A.matrix[4][2] = 3;
    A.matrix[4][4] = -2;

    double result = 0;
    ck_assert_int_eq(s21_determinant(&A, &result), OK);
    ck_assert_double_eq_tol(result, 2480, TOL);
    s21_remove_matrix(&A);
  }
  {
    const int size = 5;
    matrix_t A = {0};
    s21_create_matrix(size, size, &A);

    A.matrix[0][0] = 7.389428;
    A.matrix[0][1] = 2.958676;
    A.matrix[0][2] = 9.588797;
    A.matrix[0][3] = -3.047775;
    A.matrix[0][4] = 6.871365;

    A.matrix[1][0] = 7.647412;
    A.matrix[1][1] = 6.283314;
    A.matrix[1][2] = 1.088828;
    A.matrix[1][3] = -1.504749;
    A.matrix[1][4] = 4.928701;

    A.matrix[2][0] = 3.512002;
    A.matrix[2][1] = 3.837188;
    A.matrix[2][2] = -2.289623;
    A.matrix[2][3] = -6.025250;
    A.matrix[2][4] = 1.820978;

    A.matrix[3][0] = -8.616517;
    A.matrix[3][1] = -3.838246;
    A.matrix[3][2] = 0.406613;
    A.matrix[3][3] = -2.473955;
    A.matrix[3][4] = 9.841163;

    A.matrix[4][0] = -3.091114;
    A.matrix[4][1] = 3.274901;
    A.matrix[4][2] = 4.103472;
    A.matrix[4][3] = -2.941481;
    A.matrix[4][4] = 8.295972;

    double result = 0;
    ck_assert_int_eq(s21_determinant(&A, &result), OK);
    ck_assert_double_eq_tol(result, -29092.6559853, TOL);
    s21_remove_matrix(&A);
  }
  {
    const int size = 5;
    matrix_t A = {0};
    s21_create_matrix(size, size, &A);

    A.matrix[0][0] = 0.0;
    A.matrix[0][1] = -1.0;
    A.matrix[0][2] = -1.0;
    A.matrix[0][3] = 0.0;
    A.matrix[0][4] = 1.0;

    A.matrix[1][0] = -1.0;
    A.matrix[1][1] = 0.0;
    A.matrix[1][2] = -1.0;
    A.matrix[1][3] = -1.0;
    A.matrix[1][4] = -1.0;

    A.matrix[2][0] = 1.0;
    A.matrix[2][1] = 0.0;
    A.matrix[2][2] = -1.0;
    A.matrix[2][3] = 1.0;
    A.matrix[2][4] = -1.0;

    A.matrix[3][0] = 1.0;
    A.matrix[3][1] = 0.0;
    A.matrix[3][2] = 1.0;
    A.matrix[3][3] = 0.0;
    A.matrix[3][4] = 1.0;

    A.matrix[4][0] = -1.0;
    A.matrix[4][1] = 0.0;
    A.matrix[4][2] = 0.0;
    A.matrix[4][3] = 1.0;
    A.matrix[4][4] = -1.0;

    double result = 0;
    ck_assert_int_eq(s21_determinant(&A, &result), OK);
    ck_assert_double_eq_tol(result, 2, TOL);
    s21_remove_matrix(&A);
  }
  {
    const int size = 6;
    matrix_t A = {0};
    s21_create_matrix(size, size, &A);

    A.matrix[0][0] = 0;
    A.matrix[0][1] = 0;
    A.matrix[0][2] = 2;
    A.matrix[0][3] = 4;
    A.matrix[0][4] = 5;
    A.matrix[0][5] = 1;

    A.matrix[1][0] = 3;
    A.matrix[1][1] = 5;
    A.matrix[1][2] = 1;
    A.matrix[1][3] = 3;
    A.matrix[1][4] = 0;
    A.matrix[1][5] = 1;

    A.matrix[2][0] = 1;
    A.matrix[2][1] = 4;
    A.matrix[2][2] = 2;
    A.matrix[2][3] = 1;
    A.matrix[2][4] = 5;
    A.matrix[2][5] = 6;

    A.matrix[3][0] = 3;
    A.matrix[3][1] = 0;
    A.matrix[3][2] = 1;
    A.matrix[3][3] = 4;
    A.matrix[3][4] = 2;
    A.matrix[3][5] = 1;

    A.matrix[4][0] = 4;
    A.matrix[4][1] = 2;
    A.matrix[4][2] = 0;
    A.matrix[4][3] = 1;
    A.matrix[4][4] = 9;
    A.matrix[4][5] = 2;

    A.matrix[5][0] = 3;
    A.matrix[5][1] = 1;
    A.matrix[5][2] = 9;
    A.matrix[5][3] = 5;
    A.matrix[5][4] = 7;
    A.matrix[5][5] = 0;

    double result = 0;
    ck_assert_int_eq(s21_determinant(&A, &result), OK);
    ck_assert_double_eq_tol(result, 26588, TOL);
    s21_remove_matrix(&A);
  }
  {
    const int size = 2;
    matrix_t A = {0};
    s21_create_matrix(size, size, &A);
    double mas_a[2][2] = {{101, -1}, {2, 3}};

    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) A.matrix[i][j] = mas_a[i][j];
    }

    double result = 0;
    ck_assert_int_eq(s21_determinant(&A, &result), OK);
    ck_assert_double_eq_tol(result, 305, TOL);
    s21_remove_matrix(&A);
  }
  {
    const int size = 2;
    matrix_t A = {0};
    s21_create_matrix(size, size, &A);
    double mas_a[2][2] = {{-19.4, -0.24}, {3.33, 18}};

    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) A.matrix[i][j] = mas_a[i][j];
    }

    double result = 0;
    ck_assert_int_eq(s21_determinant(&A, &result), OK);
    ck_assert_double_eq_tol(result, -348.4008, TOL);
    s21_remove_matrix(&A);
  }
  {
    const int size = 2;
    matrix_t A = {0};
    s21_create_matrix(size, size, &A);
    double mas_a[2][2] = {{-0.3, 0.8}, {12, 1.25}};

    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) A.matrix[i][j] = mas_a[i][j];
    }

    double result = 0;
    ck_assert_int_eq(s21_determinant(&A, &result), OK);
    ck_assert_double_eq_tol(result, -9.975, TOL);
    s21_remove_matrix(&A);
  }
  {
    const int size = 3;
    matrix_t A = {0};
    s21_create_matrix(size, size, &A);
    double mas_a[3][3] = {{4, 0, 2}, {1, 2, 3}, {5, 2, 1}};

    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) A.matrix[i][j] = mas_a[i][j];
    }

    double result = 0;
    ck_assert_int_eq(s21_determinant(&A, &result), OK);
    ck_assert_double_eq_tol(result, -32, TOL);
    s21_remove_matrix(&A);
  }
  {
    const int size = 3;
    matrix_t A = {0};
    s21_create_matrix(size, size, &A);
    double mas_a[3][3] = {{0, 4, 2}, {1, 2, 3}, {5, 2, 1}};

    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) A.matrix[i][j] = mas_a[i][j];
    }

    double result = 0;
    ck_assert_int_eq(s21_determinant(&A, &result), OK);
    ck_assert_double_eq_tol(result, 40, TOL);
    s21_remove_matrix(&A);
  }
  {
    const int size = 3;
    matrix_t A = {0};
    s21_create_matrix(size, size, &A);
    double mas_a[3][3] = {{0, 1, 2}, {1, 2, 3}, {3, 4, 2}};

    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) A.matrix[i][j] = mas_a[i][j];
    }

    double result = 0;
    ck_assert_int_eq(s21_determinant(&A, &result), OK);
    ck_assert_double_eq_tol(result, 3, TOL);
    s21_remove_matrix(&A);
  }
  {
    const int size = 4;
    matrix_t A = {0};
    s21_create_matrix(size, size, &A);
    double mas_a[4][4] = {{-4.1, -2, 0, 0.2},
                          {0.4, 13, 21, -0.3},
                          {5, -2, 3.3, -9.1},
                          {1, 2, 3, 4}};

    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) A.matrix[i][j] = mas_a[i][j];
    }

    double result = 0;
    ck_assert_int_eq(s21_determinant(&A, &result), OK);
    ck_assert_double_eq_tol(result, -2511.72, TOL);
    s21_remove_matrix(&A);
  }

  // rows = 0
  {
    const int rows = 0;
    const int columns = rand() % 100 + 1;
    matrix_t A = {0};
    double result = 0;
    s21_create_matrix(rows, columns, &A);
    ck_assert_int_eq(s21_determinant(&A, &result), INCORRECT_MATRIX);
    s21_remove_matrix(&A);
  }
  // columns = 0
  {
    const int rows = rand() % 100 + 1;
    const int columns = 0;
    matrix_t A = {0};
    double result = 0;
    s21_create_matrix(rows, columns, &A);
    ck_assert_int_eq(s21_determinant(&A, &result), INCORRECT_MATRIX);
    s21_remove_matrix(&A);
  }
  // Отрицательное значение rows
  {
    const int rows = -(rand() % 100);
    const int columns = rand() % 100 + 1;
    matrix_t A = {0};
    double result = 0;
    s21_create_matrix(rows, columns, &A);
    ck_assert_int_eq(s21_determinant(&A, &result), INCORRECT_MATRIX);
    s21_remove_matrix(&A);
  }
  // Отрицательное значение columns
  {
    const int rows = rand() % 100 + 1;
    const int columns = -(rand() % 100);
    matrix_t A = {0};
    double result = 0;
    s21_create_matrix(rows, columns, &A);
    ck_assert_int_eq(s21_determinant(&A, &result), INCORRECT_MATRIX);
    s21_remove_matrix(&A);
  }
  // result - NULL
  {
    const int rows = rand() % 100 + 1;
    const int columns = rand() % 100 + 1;
    matrix_t A = {0};
    s21_create_matrix(rows, columns, &A);
    ck_assert_int_eq(s21_determinant(&A, NULL), INCORRECT_MATRIX);
    s21_remove_matrix(&A);
  }
  // A - NULL
  {
    double result = 0;
    ck_assert_int_eq(s21_determinant(NULL, &result), INCORRECT_MATRIX);
  }
  // row != col
  {
    const int rows = 1;
    const int columns = 2;
    matrix_t A = {0};
    double result = 0;
    s21_create_matrix(rows, columns, &A);
    ck_assert_int_eq(s21_determinant(&A, &result), OPERATION_ERROR);
    s21_remove_matrix(&A);
  }
}
END_TEST

Suite *suite_s21_determinant() {
  Suite *s = suite_create("s21_determinant");
  TCase *tc = tcase_create("s21_determinant");

  tcase_add_test(tc, test_determinant);
  suite_add_tcase(s, tc);
  return s;
}