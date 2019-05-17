
#include <stdio.h>

#define PRINTERR(fmt, ...) fprintf(stderr, "ERROR (%s): " fmt "\n", __FUNCTION__, ##__VA_ARGS__)
