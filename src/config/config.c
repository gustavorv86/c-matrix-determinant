
#include <config.h>
// System libraries
#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
// Source libraries
#include <common.h>

extern int errno;

int read_integer(int fd, int * value) {
	size_t buffer_count = 0;
	char buffer[24] = {0};
	char read_byte;
	ssize_t read_status;
	bool read_digits = false;
	int exit_status = 1;
	
	while(exit_status == 1) {
		read_status = read(fd, &read_byte, 1);
		
		if(read_status == 0) {
			// End of file
			exit_status = -1;
		}
		
		if(isdigit(read_byte) || read_byte == '-') {
			read_digits = true;
			buffer[buffer_count++] = read_byte;
		}
		
		if(buffer_count >= sizeof(buffer) - 1) {
			// Buffer overflow
			exit_status = -2;
		}
		
		if(read_digits && isspace(read_byte)) {
			// Read OK
			exit_status = 0;
		}
	}
	
	if(exit_status == 0) {
		*value = atoi(buffer);
	}
	
	return exit_status;
}

int config_read_matrix_sys(const char * filename, struct matrix * mat) {
	struct stat stat_file;
	int fd;
	int rows, cols;
	
	if(stat(filename, &stat_file) != 0) {
		PRINTERR("cannot open file \"%s\": %s", filename, strerror(errno));
		return -1;
	}
	
	if(! S_ISREG(stat_file.st_mode)) {
		PRINTERR("file \"%s\" is not a regular file", filename);
		return -1;
	}
	
	fd = open(filename, O_RDONLY);
	if(fd == -1) {
		PRINTERR("cannot open file \"%s\"", filename);
		return -1;
	}
	
	if(read_integer(fd, &rows) != 0 || rows < 0) {
		goto exit_failure;
	}
	
	if(read_integer(fd, &cols) != 0 || cols < 0) {
		goto exit_failure;
	}
	
	matrix_new(mat, rows, cols);
	for(int i=0; i<rows; i++) {
		for(int j=0; j<cols; j++) {
			if(read_integer(fd, &(mat->ptr[i][j])) != 0) {
				goto exit_failure;
			}
		}
	}
	
	close(fd);
	return 0;
	
	exit_failure:
		PRINTERR("invalid file format \"%s\"", filename);
		close(fd);
		return -1;
}

int config_read_matrix_std(const char * filename, struct matrix * mat) {
	FILE * file;
	int rows, cols;
	
	file = fopen(filename, "r");
	if(file == NULL) {
		PRINTERR("cannot open file \"%s\": %s", filename, strerror(errno));
		return -1;
	}
	
	if(fscanf(file, "%d", &rows) == 0 || rows < 0) {
		goto exit_failure;
	}
	
	if(fscanf(file, "%d", &cols) == 0 || cols < 0) {
		goto exit_failure;
	}
	
	matrix_new(mat, rows, cols);
	for(int i=0; i<rows; i++) {
		for(int j=0; j<cols; j++) {
			if(fscanf(file, "%d", &(mat->ptr[i][j])) == 0) {
				goto exit_failure;
			}
		}
	}
	
	fclose(file);
	return 0;
	
	exit_failure:
		PRINTERR("invalid file format \"%s\"", filename);
		fclose(file);
		return -1;
}
