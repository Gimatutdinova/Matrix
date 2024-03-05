#ifndef S21_MATRIX
#define S21_MATRIX

#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

// Resulting code

#define OK 0
#define INCORRECT_MATRIX 1
#define OPERATION_ERROR 2

// Resulting code for comparison

#define SUCCESS 1
#define FAILURE 0

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

int incorrect_matrix(matrix_t *matrix);
void get_determinant(matrix_t A, double *result);
void change_rows(matrix_t *A, int row_1, int row_2);
void copy_matrix(matrix_t *result, matrix_t A);
void copy_matrix_Wrc(int row, int columns, matrix_t *minor, matrix_t A);

#endif