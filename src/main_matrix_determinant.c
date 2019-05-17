
// System libraries
#include <stdio.h>
#include <stdlib.h>
// Source libraries
#include <config.h>
#include <matrix.h>

#define VERSION "0.1"

void help_and_exit(char * progname) {
	printf("\n");
	printf(" Version: " VERSION "\n\n");
	printf(" Usage: %s <path/matrix.txt>\n\n", progname);
	exit(1);
}

int main(int argc, char ** argv) {
	struct matrix mat;
	const char * filename_matrix;
	int determinant;
	
	if(argc < 2) {
		help_and_exit(argv[0]);
	}
	
	filename_matrix = argv[1];
	// For ANSI C, use "config_read_matrix_std"
	if(config_read_matrix_sys(filename_matrix, &mat) != 0) {
		return -1;
	}
	
	printf("Rows: %d  Cols: %d\n", mat.cols, mat.rows);
	printf("Matrix:\n");
	matrix_print(mat);
	
	if(matrix_determinant(mat, &determinant) == 0) {
		printf("Determinant: %d \n", determinant);
	}
	
	matrix_free(&mat);
	return 0;
}
