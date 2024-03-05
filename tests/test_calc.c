#include "test.h"

START_TEST(test_calc) {
  // correct values
  {
    const int size = 2;
    matrix_t check = {0};
    matrix_t A = {0};
    matrix_t result = {0};

    s21_create_matrix(size, size, &A);
    s21_create_matrix(size, size, &check);

    A.matrix[0][0] = 0.01;
    A.matrix[0][1] = 3;
    A.matrix[1][0] = 1;
    A.matrix[1][1] = 8;

    check.matrix[0][0] = 8;
    check.matrix[0][1] = -1;
    check.matrix[1][0] = -3;
    check.matrix[1][1] = 0.01;

    ck_assert_int_eq(s21_calc_complements(&A, &result), OK);
    ck_assert_int_eq(s21_eq_matrix(&result, &check), SUCCESS);
    s21_remove_matrix(&A);
    s21_remove_matrix(&result);
    s21_remove_matrix(&check);
  }
  {
    const int size = 2;
    matrix_t check = {0};
    matrix_t A = {0};
    matrix_t result = {0};

    s21_create_matrix(size, size, &A);
    s21_create_matrix(size, size, &check);

    A.matrix[0][0] = 57.0;
    A.matrix[0][1] = -55.0;
    A.matrix[1][0] = 2.0;
    A.matrix[1][1] = -79.0;

    check.matrix[0][0] = -79.0;
    check.matrix[0][1] = -2;
    check.matrix[1][0] = 55;
    check.matrix[1][1] = 57;

    ck_assert_int_eq(s21_calc_complements(&A, &result), OK);
    ck_assert_int_eq(s21_eq_matrix(&result, &check), SUCCESS);
    s21_remove_matrix(&A);
    s21_remove_matrix(&result);
    s21_remove_matrix(&check);
  }
  {
    const int size = 3;
    matrix_t check = {0};
    matrix_t A = {0};
    matrix_t result = {0};

    s21_create_matrix(size, size, &A);
    s21_create_matrix(size, size, &check);

    A.matrix[0][0] = 1;
    A.matrix[0][1] = 2;
    A.matrix[0][2] = 3;

    A.matrix[1][0] = 0;
    A.matrix[1][1] = 4;
    A.matrix[1][2] = 2;

    A.matrix[2][0] = 5;
    A.matrix[2][1] = 2;
    A.matrix[2][2] = 1;

    check.matrix[0][0] = 0;
    check.matrix[0][1] = 10;
    check.matrix[0][2] = -20;

    check.matrix[1][0] = 4;
    check.matrix[1][1] = -14;
    check.matrix[1][2] = 8;

    check.matrix[2][0] = -8;
    check.matrix[2][1] = -2;
    check.matrix[2][2] = 4;

    ck_assert_int_eq(s21_calc_complements(&A, &result), OK);
    ck_assert_int_eq(s21_eq_matrix(&result, &check), SUCCESS);
    s21_remove_matrix(&A);
    s21_remove_matrix(&result);
    s21_remove_matrix(&check);
  }
  {
    const int size = 3;
    matrix_t check = {0};
    matrix_t A = {0};
    matrix_t result = {0};

    s21_create_matrix(size, size, &A);
    s21_create_matrix(size, size, &check);

    A.matrix[0][0] = 0.01;
    A.matrix[0][1] = 3;
    A.matrix[0][2] = 0.24;
    A.matrix[1][0] = 1;
    A.matrix[1][1] = 8;
    A.matrix[1][2] = -5;
    A.matrix[2][0] = 41;
    A.matrix[2][1] = 0.36;
    A.matrix[2][2] = 1;

    check.matrix[0][0] = 9.8;
    check.matrix[0][1] = -206;
    check.matrix[0][2] = -327.64;
    check.matrix[1][0] = -2.9136;
    check.matrix[1][1] = -9.83;
    check.matrix[1][2] = 122.9964;
    check.matrix[2][0] = -16.92;
    check.matrix[2][1] = 0.29;
    check.matrix[2][2] = -2.92;

    ck_assert_int_eq(s21_calc_complements(&A, &result), OK);
    ck_assert_int_eq(s21_eq_matrix(&result, &check), SUCCESS);
    s21_remove_matrix(&A);
    s21_remove_matrix(&result);
    s21_remove_matrix(&check);
  }
  {
    const int size = 4;
    matrix_t check = {0};
    matrix_t A = {0};
    matrix_t result = {0};

    s21_create_matrix(size, size, &A);
    s21_create_matrix(size, size, &check);

    A.matrix[0][0] = 3;
    A.matrix[0][1] = 15;
    A.matrix[0][2] = 3;
    A.matrix[0][3] = 9;
    A.matrix[1][0] = 8;
    A.matrix[1][1] = 6;
    A.matrix[1][2] = 4;
    A.matrix[1][3] = 2;
    A.matrix[2][0] = 1;
    A.matrix[2][1] = 3;
    A.matrix[2][2] = 9;
    A.matrix[2][3] = 9;
    A.matrix[3][0] = -1;
    A.matrix[3][1] = 3;
    A.matrix[3][2] = 3;
    A.matrix[3][3] = 2;

    check.matrix[0][0] = -6;
    check.matrix[0][1] = 92;
    check.matrix[0][2] = -222;
    check.matrix[0][3] = 192;
    check.matrix[1][0] = 234;
    check.matrix[1][1] = 48;
    check.matrix[1][2] = 174;
    check.matrix[1][3] = -216;
    check.matrix[2][0] = 66;
    check.matrix[2][1] = -204;
    check.matrix[2][2] = 18;
    check.matrix[2][3] = 312;
    check.matrix[3][0] = -504;
    check.matrix[3][1] = 456;
    check.matrix[3][2] = 744;
    check.matrix[3][3] = -840;

    ck_assert_int_eq(s21_calc_complements(&A, &result), OK);
    ck_assert_int_eq(s21_eq_matrix(&result, &check), SUCCESS);
    s21_remove_matrix(&A);
    s21_remove_matrix(&result);
    s21_remove_matrix(&check);
  }
  {
    const int size = 4;
    matrix_t check = {0};
    matrix_t A = {0};
    matrix_t result = {0};

    s21_create_matrix(size, size, &A);
    s21_create_matrix(size, size, &check);

    A.matrix[0][0] = 1.0;
    A.matrix[0][1] = 0.0;
    A.matrix[0][2] = 0.0;
    A.matrix[0][3] = -1.0;
    A.matrix[1][0] = -1.0;
    A.matrix[1][1] = 1.0;
    A.matrix[1][2] = -1.0;
    A.matrix[1][3] = 0.0;
    A.matrix[2][0] = 1.0;
    A.matrix[2][1] = -1.0;
    A.matrix[2][2] = 1.0;
    A.matrix[2][3] = 1.0;
    A.matrix[3][0] = -1.0;
    A.matrix[3][1] = 1.0;
    A.matrix[3][2] = -1.0;
    A.matrix[3][3] = -1.0;

    check.matrix[0][0] = 0;
    check.matrix[0][1] = 0;
    check.matrix[0][2] = 0;
    check.matrix[0][3] = 0;
    check.matrix[1][0] = 0;
    check.matrix[1][1] = 0;
    check.matrix[1][2] = 0;
    check.matrix[1][3] = 0;
    check.matrix[2][0] = 0;
    check.matrix[2][1] = -1;
    check.matrix[2][2] = -1;
    check.matrix[2][3] = 0;
    check.matrix[3][0] = 0;
    check.matrix[3][1] = -1;
    check.matrix[3][2] = -1;
    check.matrix[3][3] = 0;

    ck_assert_int_eq(s21_calc_complements(&A, &result), OK);
    ck_assert_int_eq(s21_eq_matrix(&result, &check), SUCCESS);
    s21_remove_matrix(&A);
    s21_remove_matrix(&result);
    s21_remove_matrix(&check);
  }
  {
    const int size = 4;
    matrix_t check = {0};
    matrix_t A = {0};
    matrix_t result = {0};

    s21_create_matrix(size, size, &A);
    s21_create_matrix(size, size, &check);

    A.matrix[0][0] = 1.0;
    A.matrix[0][1] = 0.0;
    A.matrix[0][2] = -1.0;
    A.matrix[0][3] = 1.0;
    A.matrix[1][0] = 0.0;
    A.matrix[1][1] = 1.0;
    A.matrix[1][2] = 0.0;
    A.matrix[1][3] = 1.0;
    A.matrix[2][0] = 1.0;
    A.matrix[2][1] = 0.0;
    A.matrix[2][2] = 0.0;
    A.matrix[2][3] = 0.0;
    A.matrix[3][0] = 0.0;
    A.matrix[3][1] = 1.0;
    A.matrix[3][2] = -1.0;
    A.matrix[3][3] = -1.0;

    check.matrix[0][0] = 0;
    check.matrix[0][1] = 1;
    check.matrix[0][2] = 2;
    check.matrix[0][3] = -1;
    check.matrix[1][0] = 0;
    check.matrix[1][1] = -2;
    check.matrix[1][2] = -1;
    check.matrix[1][3] = -1;
    check.matrix[2][0] = -3;
    check.matrix[2][1] = -1;
    check.matrix[2][2] = -2;
    check.matrix[2][3] = 1;
    check.matrix[3][0] = 0;
    check.matrix[3][1] = -1;
    check.matrix[3][2] = 1;
    check.matrix[3][3] = 1;

    ck_assert_int_eq(s21_calc_complements(&A, &result), OK);
    ck_assert_int_eq(s21_eq_matrix(&result, &check), SUCCESS);
    s21_remove_matrix(&A);
    s21_remove_matrix(&result);
    s21_remove_matrix(&check);
  }
  {
    const int size = 3;
    matrix_t check = {0};
    matrix_t A = {0};
    matrix_t result = {0};

    s21_create_matrix(size, size, &A);
    s21_create_matrix(size, size, &check);

    double mas_a[3][3] = {{1, 2, 3}, {0, 4, 2}, {5, 2, 1}};
    double mas_ch[3][3] = {{0, 10, -20}, {4, -14, 8}, {-8, -2, 4}};

    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) A.matrix[i][j] = mas_a[i][j];
    }
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) check.matrix[i][j] = mas_ch[i][j];
    }

    ck_assert_int_eq(s21_calc_complements(&A, &result), OK);
    ck_assert_int_eq(s21_eq_matrix(&result, &check), SUCCESS);
    s21_remove_matrix(&A);
    s21_remove_matrix(&result);
    s21_remove_matrix(&check);
  }
  {
    const int size = 3;
    matrix_t check = {0};
    matrix_t A = {0};
    matrix_t result = {0};

    s21_create_matrix(size, size, &A);
    s21_create_matrix(size, size, &check);

    double mas_a[3][3] = {{0, 4, 2}, {1, 2, 3}, {5, 2, 1}};
    double mas_ch[3][3] = {{-4, 14, -8}, {0, -10, 20}, {8, 2, -4}};

    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) A.matrix[i][j] = mas_a[i][j];
    }
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) check.matrix[i][j] = mas_ch[i][j];
    }

    ck_assert_int_eq(s21_calc_complements(&A, &result), OK);
    ck_assert_int_eq(s21_eq_matrix(&result, &check), SUCCESS);
    s21_remove_matrix(&A);
    s21_remove_matrix(&result);
    s21_remove_matrix(&check);
  }
  {
    const int size = 3;
    matrix_t check = {0};
    matrix_t A = {0};
    matrix_t result = {0};

    s21_create_matrix(size, size, &A);
    s21_create_matrix(size, size, &check);

    double mas_a[3][3] = {{8, 15, 3}, {0, -4, 2}, {15, 20, 0}};
    double mas_ch[3][3] = {{-40, 30, 60}, {60, -45, 65}, {42, -16, -32}};

    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) A.matrix[i][j] = mas_a[i][j];
    }
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) check.matrix[i][j] = mas_ch[i][j];
    }

    ck_assert_int_eq(s21_calc_complements(&A, &result), OK);
    ck_assert_int_eq(s21_eq_matrix(&result, &check), SUCCESS);
    s21_remove_matrix(&A);
    s21_remove_matrix(&result);
    s21_remove_matrix(&check);
  }
  {
    const int size = 3;
    matrix_t check = {0};
    matrix_t A = {0};
    matrix_t result = {0};

    s21_create_matrix(size, size, &A);
    s21_create_matrix(size, size, &check);

    double mas_a[3][3] = {{8.2, 1.5, 3.0}, {0.5, -4.2, 2.1}, {15.2, 20.3, 0}};
    double mas_ch[3][3] = {{-42.63, 31.92, 73.99},
                           {60.9, -45.6, -143.66},
                           {15.75, -15.72, -35.19}};

    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) A.matrix[i][j] = mas_a[i][j];
    }
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) check.matrix[i][j] = mas_ch[i][j];
    }

    ck_assert_int_eq(s21_calc_complements(&A, &result), OK);
    ck_assert_int_eq(s21_eq_matrix(&result, &check), SUCCESS);
    s21_remove_matrix(&A);
    s21_remove_matrix(&result);
    s21_remove_matrix(&check);
  }
  // rows = 0
  {
    const int rows = 0;
    const int columns = rand() % 100 + 1;
    matrix_t A = {0};
    matrix_t result = {0};
    s21_create_matrix(rows, columns, &A);
    ck_assert_int_eq(s21_calc_complements(&A, &result), INCORRECT_MATRIX);
    s21_remove_matrix(&A);
  }
  // columns = 0
  {
    const int rows = rand() % 100 + 1;
    const int columns = 0;
    matrix_t A = {0};
    matrix_t result = {0};
    s21_create_matrix(rows, columns, &A);
    ck_assert_int_eq(s21_calc_complements(&A, &result), INCORRECT_MATRIX);
    s21_remove_matrix(&A);
  }
  // Отрицательное значение rows
  {
    const int rows = -(rand() % 100);
    const int columns = rand() % 100 + 1;
    matrix_t A = {0};
    matrix_t result = {0};
    s21_create_matrix(rows, columns, &A);
    ck_assert_int_eq(s21_calc_complements(&A, &result), INCORRECT_MATRIX);
    s21_remove_matrix(&A);
  }
  // Отрицательное значение columns
  {
    const int rows = rand() % 100 + 1;
    const int columns = -(rand() % 100);
    matrix_t A = {0};
    matrix_t result = {0};
    s21_create_matrix(rows, columns, &A);
    ck_assert_int_eq(s21_calc_complements(&A, &result), INCORRECT_MATRIX);
    s21_remove_matrix(&A);
  }
  // result - NULL
  {
    const int rows = rand() % 100 + 1;
    const int columns = rand() % 100 + 1;
    matrix_t A = {0};
    s21_create_matrix(rows, columns, &A);
    ck_assert_int_eq(s21_calc_complements(&A, NULL), INCORRECT_MATRIX);
    s21_remove_matrix(&A);
  }
  // A - NULL
  {
    matrix_t result = {0};
    ck_assert_int_eq(s21_calc_complements(NULL, &result), INCORRECT_MATRIX);
  }
  // row = 1, col = 1
  {
    const int size = 1;
    matrix_t A = {0};
    matrix_t result = {0};
    s21_create_matrix(size, size, &A);
    A.matrix[0][0] = 5;
    ck_assert_int_eq(s21_calc_complements(&A, &result), OPERATION_ERROR);
    s21_remove_matrix(&A);
  }
  // row != col
  {
    const int rows = 1;
    const int columns = 2;
    matrix_t A = {0};
    matrix_t result = {0};
    s21_create_matrix(rows, columns, &A);
    ck_assert_int_eq(s21_calc_complements(&A, &result), OPERATION_ERROR);
    s21_remove_matrix(&A);
  }
  {
    const int rows = 3;
    const int columns = 4;
    matrix_t A = {0};
    matrix_t result = {0};
    double mas_a[3][4] = {{1, 2, 3, 0}, {0, 4, 2, 0}, {5, 2, 1, 0}};

    s21_create_matrix(rows, columns, &A);
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) A.matrix[i][j] = mas_a[i][j];
    }
    ck_assert_int_eq(s21_calc_complements(&A, &result), OPERATION_ERROR);
    s21_remove_matrix(&A);
  }
}
END_TEST

Suite *suite_s21_calc_complements() {
  Suite *s = suite_create("s21_calc");
  TCase *tc = tcase_create("s21_calc");

  tcase_add_test(tc, test_calc);
  suite_add_tcase(s, tc);
  return s;
}