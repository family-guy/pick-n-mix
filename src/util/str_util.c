#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "int_array.h"

struct int_array *parser(char *fs) {
	struct int_array *result = malloc(sizeof *result);
	
	int block_size = 1024;
	int blocks = 1;
	
	result->A = calloc(block_size * blocks, sizeof(int));
	
	if (result->A == NULL) {
		fprintf(stderr, "Error - unable to allocate required memory.\n");
		exit(1);
	}
	int i = 0;
	char *pos = strtok(fs, "\n");
	while (pos != NULL) {
		if (i == blocks * block_size) {
			blocks++;
			result->A = realloc(result->A, block_size * blocks * sizeof(int));
			if (result->A == NULL) {
				fprintf(stderr, "Error - unable to allocate required 				memory.\n");
				exit(1);
			}
		}
		result->A[i] = atoi(pos);
		pos = strtok(NULL, "\n");
		i++;
	}
	result->len = i;
	return result;
}