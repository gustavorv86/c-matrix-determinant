
#ifndef CONFIG_H
#define CONFIG_H

#include <matrix.h>

int config_read_matrix_sys(const char * filename, struct matrix * mat);
int config_read_matrix_std(const char * filename, struct matrix * mat);

#endif
