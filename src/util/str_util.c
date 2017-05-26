/** @file str_util.c
 *  @brief Function definitions for functions that manipulate strings.
 *
 *  @author Guy R. King (grking8@geemail.com)
 *  @date 8 May 2017
 *  @see include/int_array.h
 *  @bug No known bugs.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "int_array.h"

/** @brief Parses a string containing a list of integers into an array of 
 *         integers.
 *
 *  The integers in the string are separated by "\n". If there is not enough 
 *  memory to read all the integers into an array, an error message is displayed
 *  before exiting the function. It is the function caller's responsibility to 
 *  free the memory dynamically allocated.
 *
 *  @param fs The string containing the list of integers.
 *  @return The array of integers.
 *  @see int_array
 */
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
