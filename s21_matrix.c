#include "s21_matrix.h"

/**
 * @brief Функция для инициализации матрицы
 *
 * @param rows количество строк
 * @param columns количество столбцов
 * @param result структура, которая хранит в себе массив, количество строк и
 * столбцов
 *
 * @return result_code - статус ошибки
 *
 * @note OK (0) - OK
 * @note INCORRECT_MATRIX (1) - incorrect matrix
 */
int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int result_code = INCORRECT_MATRIX;
  if (result && rows > 0 && columns > 0) {
    result_code = OK;
    result->rows = rows;
    result->columns = columns;
    result->matrix = calloc(rows, sizeof(double *));
    for (int i = 0; i < rows; i++)
      result->matrix[i] = calloc(columns, sizeof(double));
  }
  return result_code;
}

/**
 * @brief Функция для очистки матрицы
 *
 * @param А структура, которая хранит в себе массив, количество строк и
 * столбцов
 */
void s21_remove_matrix(matrix_t *A) {
  if (A && A->matrix) {
    for (int i = 0; i < A->rows; i++) free(A->matrix[i]);
    free(A->matrix);
    A->matrix = NULL;
    A->columns = 0;
    A->rows = 0;
  }
}

/**
 * @brief Функция для сравнения матриц
 *
 * @param А структура, которая хранит в себе массив, количество строк и
 * столбцов первой матрицы
 * @param B структура, которая хранит в себе массив, количество строк и
 * столбцов второй матрицы
 *
 * @return result_code - результат сравнения
 *
 * @note SUCCESS (1) - матрицы равны
 * @note FAILURE (0) - матрицы не равны
 */
int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int result_code = SUCCESS;
  if (!incorrect_matrix(A) && !incorrect_matrix(B) &&
      A->columns == B->columns && A->rows == B->rows) {
    for (int i = 0; i < A->rows && result_code; i++) {
      for (int j = 0; j < A->columns && result_code; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) >= 1e-07)
          result_code = FAILURE;
      }
    }
  } else
    result_code = FAILURE;
  return result_code;
}

/**
 * @brief Функция для сложения матриц
 *
 * @param А структура, которая хранит в себе массив, количество строк и
 * столбцов первой матрицы
 * @param B структура, которая хранит в себе массив, количество строк и
 * столбцов второй матрицы
 * @param result структура, которая хранит в себе массив, количество строк и
 * столбцов получившейся матрицы
 *
 * @return result_code - результат сложения
 *
 * @note OK (0) - ОК
 * @note INCORRECT_MATRIX (1) - некорректная матрица
 * @note OPERATION_ERROR (2) - ошибка вычисления (несовпадающие размеры матриц;
 * матрица, для которой нельзя провести вычисления и т.д.)
 */
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int result_code = OK;
  if (!incorrect_matrix(A) && !incorrect_matrix(B) && result) {
    if (A->columns == B->columns && A->rows == B->rows) {
      s21_create_matrix(A->rows, A->columns, result);
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++)
          result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
      }
    } else
      result_code = OPERATION_ERROR;
  } else
    result_code = INCORRECT_MATRIX;
  return result_code;
}

/**
 * @brief Функция для вычитания матриц
 *
 * @param А структура, которая хранит в себе массив, количество строк и
 * столбцов первой матрицы
 * @param B структура, которая хранит в себе массив, количество строк и
 * столбцов вычитаемой матрицы
 * @param result структура, которая хранит в себе массив, количество строк и
 * столбцов получившейся матрицы
 *
 * @return result_code - результат вычитания
 *
 * @note OK (0) - ОК
 * @note INCORRECT_MATRIX (1) - некорректная матрица
 * @note OPERATION_ERROR (2) - ошибка вычисления (несовпадающие размеры матриц;
 * матрица, для которой нельзя провести вычисления и т.д.)
 */
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int result_code = OK;
  if (!incorrect_matrix(A) && !incorrect_matrix(B) && result) {
    if (A->columns == B->columns && A->rows == B->rows) {
      s21_create_matrix(A->rows, A->columns, result);
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++)
          result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
      }
    } else
      result_code = OPERATION_ERROR;
  } else
    result_code = INCORRECT_MATRIX;
  return result_code;
}

/**
 * @brief Функция для умножение матрицы на число
 *
 * @param А структура, которая хранит в себе массив, количество строк и
 * столбцов матрицы
 * @param number число, на которое умножают матрицу
 * @param result структура, которая хранит в себе массив, количество строк и
 * столбцов получившейся матрицы
 *
 * @return result_code - результат умножения
 *
 * @note OK (0) - ОК
 * @note INCORRECT_MATRIX (1) - некорректная матрица
 */
int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int result_code = OK;
  if (!incorrect_matrix(A) && result) {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++)
        result->matrix[i][j] = A->matrix[i][j] * number;
    }
  } else
    result_code = INCORRECT_MATRIX;
  return result_code;
}

/**
 * @brief Функция для умножение матриц
 *
 * @param А структура, которая хранит в себе массив, количество строк и
 * столбцов первой матрицы
 * @param B структура, которая хранит в себе массив, количество строк и
 * столбцов второй матрицы
 * @param result структура, которая хранит в себе массив, количество строк и
 * столбцов получившейся матрицы
 *
 * @return result_code - результат умножения
 *
 * @note OK (0) - ОК
 * @note INCORRECT_MATRIX (1) - некорректная матрица
 * @note OPERATION_ERROR (2) - ошибка вычисления (несовпадающие размеры матриц;
 * матрица, для которой нельзя провести вычисления и т.д.)
 */
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int result_code = OK;
  if (!incorrect_matrix(A) && !incorrect_matrix(B) && result) {
    if (A->columns == B->rows) {
      s21_create_matrix(A->rows, B->columns, result);
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < B->columns; j++) {
          for (int k = 0; k < B->rows; k++)
            result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
        }
      }
    } else
      result_code = OPERATION_ERROR;
  } else
    result_code = INCORRECT_MATRIX;
  return result_code;
}

/**
 * @brief Функция для транспонирования матрицы
 *
 * @param А структура, которая хранит в себе массив, количество строк и
 * столбцов матрицы
 * @param result структура, которая хранит в себе массив, количество строк и
 * столбцов получившейся матрицы
 *
 * @return result_code - результат транспонирования
 *
 * @note OK (0) - ОК
 * @note INCORRECT_MATRIX (1) - некорректная матрица
 */
int s21_transpose(matrix_t *A, matrix_t *result) {
  int result_code = OK;
  if (!incorrect_matrix(A) && result) {
    s21_create_matrix(A->columns, A->rows, result);
    for (int i = 0; i < result->rows; i++) {
      for (int j = 0; j < result->columns; j++)
        result->matrix[i][j] = A->matrix[j][i];
    }
  } else
    result_code = INCORRECT_MATRIX;
  return result_code;
}

/**
 * @brief Функция для нахождения определителя матрицы
 *
 * @param А структура, которая хранит в себе массив, количество строк и
 * столбцов матрицы
 * @param result число double - опеределитель
 *
 * @return result_code - результат нахождения определителя матрицы
 *
 * @note OK (0) - ОК
 * @note INCORRECT_MATRIX (1) - некорректная матрица
 * @note OPERATION_ERROR (2) - ошибка вычисления (несовпадающие размеры матриц;
 * матрица, для которой нельзя провести вычисления и т.д.)
 */
int s21_determinant(matrix_t *A, double *result) {
  int result_code = OK;
  if (!incorrect_matrix(A) && result) {
    if (A->columns == A->rows) {
      matrix_t tmp = {0};
      s21_create_matrix(A->rows, A->rows, &tmp);
      copy_matrix(&tmp, *A);
      get_determinant(tmp, result);
      s21_remove_matrix(&tmp);
    } else
      result_code = OPERATION_ERROR;
  } else
    result_code = INCORRECT_MATRIX;
  return result_code;
}

/**
 * @brief Функция для получения матрицы алгебраических дополнений
 *
 * @param А структура, которая хранит в себе массив, количество строк и
 * столбцов матрицы
 * @param result структура, которая хранит в себе массив, количество строк и
 * столбцов получившейся матрицы
 *
 * @return result_code - результат получения
 *
 * @note OK (0) - ОК
 * @note INCORRECT_MATRIX (1) - некорректная матрица
 * @note OPERATION_ERROR (2) - ошибка вычисления (несовпадающие размеры матриц;
 * матрица, для которой нельзя провести вычисления и т.д.)
 */
int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int result_code = OK;
  if (!incorrect_matrix(A) && result) {
    if (A->columns == A->rows && A->rows > 1) {
      s21_create_matrix(A->rows, A->columns, result);
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          matrix_t minor = {0};
          double determinant = 0;
          s21_create_matrix(A->rows - 1, A->columns - 1, &minor);
          copy_matrix_Wrc(i, j, &minor, *A);
          s21_determinant(&minor, &determinant);
          result->matrix[i][j] = determinant * pow(-1, i + j);
          s21_remove_matrix(&minor);
        }
      }
    } else
      result_code = OPERATION_ERROR;
  } else
    result_code = INCORRECT_MATRIX;
  return result_code;
}

/**
 * @brief Функция для получения обратной матрицы
 *
 * @param А структура, которая хранит в себе массив, количество строк и
 * столбцов матрицы
 * @param result структура, которая хранит в себе массив, количество строк и
 * столбцов получившейся матрицы
 *
 * @return result_code - результат получения
 *
 * @note OK (0) - ОК
 * @note INCORRECT_MATRIX (1) - некорректная матрица
 * @note OPERATION_ERROR (2) - ошибка вычисления (несовпадающие размеры матриц;
 * матрица, для которой нельзя провести вычисления и т.д.)
 */
int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int result_code = OK;
  if (!incorrect_matrix(A) && result) {
    double determinant = 0;
    s21_determinant(A, &determinant);
    if (determinant != 0) {
      matrix_t minor = {0};
      result_code = s21_calc_complements(A, &minor);
      if (!result_code) {
        matrix_t transpose = {0};
        s21_transpose(&minor, &transpose);
        determinant = 1 / determinant;
        s21_mult_number(&transpose, determinant, result);
        s21_remove_matrix(&transpose);
        s21_remove_matrix(&minor);
      }
    } else
      result_code = OPERATION_ERROR;
  } else
    result_code = INCORRECT_MATRIX;
  return result_code;
}