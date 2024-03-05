#include "s21_matrix.h"

/**
 * @brief Функция для проверки корректности матрицы
 *
 * @param matrix структура, которая хранит в себе массив, количество строк и
 * столбцов
 *
 * @return result - результат проверки
 *
 * @note OK (0) - ОК
 * @note INCORRECT_MATRIX (1) - некорректная матрица
 */
int incorrect_matrix(matrix_t *matrix) {
  int result = INCORRECT_MATRIX;
  if (matrix && matrix->matrix && matrix->columns > 0 && matrix->rows > 0)
    result = OK;
  return result;
}

/**
 * @brief Вспомогательная функция для нахождения определителя матрицы
 *
 * @param А структура, которая хранит в себе массив, количество строк и
 * столбцов матрицы
 * @param result число double - опеределитель
 */
void get_determinant(matrix_t A, double *result) {
  int sign = 0;
  for (int i = 0; i < A.columns; i++) {
    for (int j = i + 1; j < A.rows; j++) {
      if (A.matrix[j][i] != 0) {
        if (A.matrix[i][i] == 0) {
          sign++;
          change_rows(&A, i, j);
        }
        double div = A.matrix[j][i] / A.matrix[i][i];
        for (int k = 0; k < A.columns; k++)
          A.matrix[j][k] = A.matrix[j][k] - div * A.matrix[i][k];
      }
    }
  }
  *result = pow(-1, sign);
  for (int i = 0; i < A.columns; i++) *result *= A.matrix[i][i];
}

/**
 * @brief Функция для замены строк местами (вспомогательная функция для
 * нахождения определителя)
 *
 * @param А структура, которая хранит в себе массив, количество строк и
 * столбцов матрицы
 * @param row_1 строка, которую необходимо заменить
 * @param row_2 строка, на которую необходимо заменить
 */
void change_rows(matrix_t *A, int row_1, int row_2) {
  for (int i = 0; i < A->columns; i++) {
    double num = A->matrix[row_1][i];
    A->matrix[row_1][i] = A->matrix[row_2][i];
    A->matrix[row_2][i] = num;
  }
}

/**
 * @brief Функция для копирования матрицы
 *
 * @param result структура, которая хранит в себе массив, количество строк и
 * столбцов получившейся матрицы
 * @param А структура, которая хранит в себе массив, количество строк и
 * столбцов матрицы
 */
void copy_matrix(matrix_t *result, matrix_t A) {
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      result->matrix[i][j] = A.matrix[i][j];
    }
  }
}

/**
 * @brief Функция для копирования матрицы без row-строки и column-столбца
 *
 * @param rows строку, которую необходимо вычеркнуть
 * @param columns столбец, который необходимо вычеркнуть
 * @param result структура, которая хранит в себе массив, количество строк и
 * столбцов получившейся матрицы
 * @param А структура, которая хранит в себе массив, количество строк и
 * столбцов матрицы
 */
void copy_matrix_Wrc(int row, int columns, matrix_t *result, matrix_t A) {
  int result_row = 0;
  int result_col = 0;
  for (int i = 0; i < A.rows; i++) {
    if (i != row) {
      result_col = 0;
      for (int j = 0; j < A.columns; j++) {
        if (j != columns) {
          result->matrix[result_row][result_col] = A.matrix[i][j];
          result_col++;
        }
      }
      result_row++;
    }
  }
}
