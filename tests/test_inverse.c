#include "test.h"

START_TEST(test_inverse) {
  // correct values
  {
    const int size = 3;
    matrix_t check = {0};
    matrix_t A = {0};
    matrix_t result = {0};

    s21_create_matrix(size, size, &A);
    s21_create_matrix(size, size, &check);

    A.matrix[0][0] = 2.0;
    A.matrix[0][1] = 5.0;
    A.matrix[0][2] = 7.0;
    A.matrix[1][0] = 6.0;
    A.matrix[1][1] = 3.0;
    A.matrix[1][2] = 4.0;
    A.matrix[2][0] = 5.0;
    A.matrix[2][1] = -2.0;
    A.matrix[2][2] = -3.0;

    check.matrix[0][0] = 1.0;
    check.matrix[0][1] = -1.0;
    check.matrix[0][2] = 1.0;
    check.matrix[1][0] = -38.0;
    check.matrix[1][1] = 41.0;
    check.matrix[1][2] = -34.0;
    check.matrix[2][0] = 27.0;
    check.matrix[2][1] = -29.0;
    check.matrix[2][2] = 24.0;

    ck_assert_int_eq(s21_inverse_matrix(&A, &result), OK);
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

    double mas_a[3][3] = {{2, 5, 7}, {6, 3, 4}, {5, -2, -3}};
    double mas_ch[3][3] = {{1, -1, 1}, {-38, 41, -34}, {27, -29, 24}};

    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) A.matrix[i][j] = mas_a[i][j];
    }
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) check.matrix[i][j] = mas_ch[i][j];
    }

    ck_assert_int_eq(s21_inverse_matrix(&A, &result), OK);
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

    double mas_a[3][3] = {{20, -1.3, -10.1}, {1, 1, 1}, {5, -2, -3}};
    double mas_ch[3][3] = {{-0.02481389, 0.404466501, 0.218362282},
                           {0.198511166, -0.2357320099, -0.74689826},
                           {-0.17369727, 0.831265508, 0.52853598}};

    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) A.matrix[i][j] = mas_a[i][j];
    }
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) check.matrix[i][j] = mas_ch[i][j];
    }

    ck_assert_int_eq(s21_inverse_matrix(&A, &result), OK);
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

    double mas_a[3][3] = {{2, 5, 7}, {6, 3, 4}, {5, -2, -3}};
    double mas_ch[3][3] = {{1, -1, 1}, {-38, 41, -34}, {27, -29, 24}};

    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) A.matrix[i][j] = mas_a[i][j];
    }
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) check.matrix[i][j] = mas_ch[i][j];
    }

    ck_assert_int_eq(s21_inverse_matrix(&A, &result), OK);
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

    double mas_a[4][4] = {{-4.1, -2, 0, 0.2},
                          {0.4, 13, 21, -0.3},
                          {5, -2, 3.3, -9.1},
                          {1, 2, 3, 4}};
    double mas_ch[4][4] = {
        {-0.125842052, -0.033252114, 0.0678419569, 0.158138646},
        {-0.238247097, 0.0651784434, -0.14016291624, -0.3020698963},
        {0.1504228178, 0.007476948, 0.085320019, 0.187142675},
        {0.037766948, -0.029883904, -0.0108690459, 0.22114328}};

    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) A.matrix[i][j] = mas_a[i][j];
    }
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) check.matrix[i][j] = mas_ch[i][j];
    }

    ck_assert_int_eq(s21_inverse_matrix(&A, &result), OK);
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
    ck_assert_int_eq(s21_inverse_matrix(&A, &result), INCORRECT_MATRIX);
    s21_remove_matrix(&A);
  }
  // columns = 0
  {
    const int rows = rand() % 100 + 1;
    const int columns = 0;
    matrix_t A = {0};
    matrix_t result = {0};
    s21_create_matrix(rows, columns, &A);
    ck_assert_int_eq(s21_inverse_matrix(&A, &result), INCORRECT_MATRIX);
    s21_remove_matrix(&A);
  }
  // Отрицательное значение rows
  {
    const int rows = -(rand() % 100);
    const int columns = rand() % 100 + 1;
    matrix_t A = {0};
    matrix_t result = {0};
    s21_create_matrix(rows, columns, &A);
    ck_assert_int_eq(s21_inverse_matrix(&A, &result), INCORRECT_MATRIX);
    s21_remove_matrix(&A);
  }
  // Отрицательное значение columns
  {
    const int rows = rand() % 100 + 1;
    const int columns = -(rand() % 100);
    matrix_t A = {0};
    matrix_t result = {0};
    s21_create_matrix(rows, columns, &A);
    ck_assert_int_eq(s21_inverse_matrix(&A, &result), INCORRECT_MATRIX);
    s21_remove_matrix(&A);
  }
  // result - NULL
  {
    const int rows = rand() % 100 + 1;
    const int columns = rand() % 100 + 1;
    matrix_t A = {0};
    s21_create_matrix(rows, columns, &A);
    ck_assert_int_eq(s21_inverse_matrix(&A, NULL), INCORRECT_MATRIX);
    s21_remove_matrix(&A);
  }
  // A - NULL
  {
    matrix_t result = {0};
    ck_assert_int_eq(s21_inverse_matrix(NULL, &result), INCORRECT_MATRIX);
  }
  // row = 1, col = 1
  {
    const int size = 1;
    matrix_t A = {0};
    matrix_t result = {0};
    s21_create_matrix(size, size, &A);
    A.matrix[0][0] = 5;
    ck_assert_int_eq(s21_inverse_matrix(&A, &result), OPERATION_ERROR);
    s21_remove_matrix(&A);
  }
  // det = 0
  {
    const int size = 3;
    matrix_t A = {0};
    matrix_t result = {0};

    s21_create_matrix(size, size, &A);

    double mas_a[3][3] = {{10, 5, -1}, {0, 0, 0}, {5, -2, -3}};

    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) A.matrix[i][j] = mas_a[i][j];
    }

    ck_assert_int_eq(s21_inverse_matrix(&A, &result), OPERATION_ERROR);
    s21_remove_matrix(&A);
  }
  // row != col
  {
    const int rows = 1;
    const int columns = 2;
    matrix_t A = {0};
    matrix_t result = {0};
    s21_create_matrix(rows, columns, &A);
    ck_assert_int_eq(s21_inverse_matrix(&A, &result), OPERATION_ERROR);
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
    ck_assert_int_eq(s21_inverse_matrix(&A, &result), OPERATION_ERROR);
    s21_remove_matrix(&A);
  }
}
END_TEST

Suite *suite_s21_inverse_matrix() {
  Suite *s = suite_create("s21_inverse");
  TCase *tc = tcase_create("s21_inverse");

  tcase_add_test(tc, test_inverse);
  suite_add_tcase(s, tc);
  return s;
}