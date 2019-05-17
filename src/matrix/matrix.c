
#include <matrix.h>
// System libraries
#include <stdio.h>
#include <stdlib.h>
// Source libraries
#include <common.h>

void matrix_new(struct matrix * mat, int rows, int cols) {
	mat->rows = rows;
	mat->cols = cols;
	
	mat->ptr = calloc(rows, sizeof(int *));
	for(int i=0; i < mat->rows; i++) {
		mat->ptr[i] = calloc(cols, sizeof(int));
	}
}

void matrix_free(struct matrix * mat) {
	for(int i=0; i < mat->rows; i++) {
		free(mat->ptr[i]);
	}
	free(mat->ptr);
	
	mat->rows = 0;
	mat->cols = 0;
}

void matrix_print(struct matrix mat) {
	for(int i=0; i < mat.rows; i++) {
		for(int j=0; j < mat.cols; j++) {
			if(mat.ptr[i][j] < 0) {
				printf(" %d ", mat.ptr[i][j]);
			} else {
				printf("  %d ", mat.ptr[i][j]);
			}
		}
		printf("\n");
	}
}

int matrix_determinant(struct matrix mat, int * determinant) {
	int i, j;
	int acc_sum, acc_sub, acc_mul;
	
	if(mat.rows != mat.cols) {
		PRINTERR("rows and columns are distincts");
		return -1;
	}
	
	// special case
	if(mat.rows == 2) {
		return mat.ptr[0][0] * mat.ptr[1][1] - mat.ptr[0][1] * mat.ptr[1][0];
	}
	
	// multiply and sum
	acc_sum = 0;
	for(int x=0; x<mat.rows; x++) {
		
		i = 0;
		j = x;
		
		acc_mul = 1;
		for(int y=0; y<mat.rows; y++) {
			acc_mul *= mat.ptr[i][j];
			i++;
			j++;
			if(j >= mat.rows) {
				j = 0;
			}
		}
		acc_sum += acc_mul;
	}
	
	// multiply and sub
	acc_sub = 0;
	for(int x=0; x<mat.rows; x++) {
		
		i = 0;
		j = mat.rows - 1 - x;
		
		acc_mul = 1;
		for(int y=0; y<mat.rows; y++) {
			acc_mul *= mat.ptr[i][j];
			i++;
			j--;
			if(j < 0) {
				j = mat.rows - 1;
			}
		}
		acc_sub -= acc_mul;
	}
	
	*determinant = acc_sum + acc_sub;
	return 0;
}
