
#ifndef MATRIX_H
#define MATRIX_H

struct matrix {
	int rows;
	int cols;
	int ** ptr;
};

void matrix_new(struct matrix * mat, int rows, int cols);
void matrix_free(struct matrix * mat);
void matrix_print(struct matrix mat);
int  matrix_determinant(struct matrix mat, int * determinant);
int  matrix_determinant(struct matrix mat, int * determinant);

#endif
