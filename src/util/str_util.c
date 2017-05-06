#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "int_array.h"

struct int_array *parser(char *fs) {
	struct int_array *result;
	
	int *A;
	int block_size = 1024;
	int blocks = 1;
	A = calloc(block_size * blocks, sizeof(int));
	if (A == NULL) {
		fprintf(stderr, "Error - unable to allocate required memory.\n");
		exit(1);
	}
	int i = 0;
	char *pos = strtok(fs, "\n");
	while (pos != NULL) {
		if (i == blocks * block_size) {
			blocks++;
			A = realloc(A, block_size * blocks * sizeof(int));
			if (A == NULL) {
				fprintf(stderr, "Error - unable to allocate required 				memory.\n");
				exit(1);
			}
		}
		A[i] = atoi(pos);
		pos = strtok(NULL, "\n");
		i++;
	}
	result->len = i;
	result->A = A;
	free(A);
	return result;
}