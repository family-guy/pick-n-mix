/** @file max_subarray_algo.c
 *  @brief Function definitions for maximum subarray algorithms.
 *
 *  Each function implements an algorithm to find the maximum subarray of an
 *  array of integers. Let A be an array. The maximum subarray is the
 *  (continguous) subarray S of A such that for each subarray S' of A, the sum 
 *  of the elements of S' is less than or equal to the sum of the elements of S.
 *
 *  @author Guy R. King (grking8@geemail.com)
 *  @date 10 May 2017
 *  @see include/int_array.h
 *  @bug No known bugs.
 */

#include <stdlib.h>

#include "int_array.h"

/** @brief Finds the maximum subarray of an array of integers incrementally.
 *
 *  @param A The array to find the maximum subarray of.
 *  @return An array containing the maximum subarray's lower demarcation, upper
 *  demarcation, and sum.
 *  @see int_array
 */
int *max_subarray_incr(struct int_array *A) {
	int *result = calloc(3, sizeof(int));
	result[0] = 0;
	result[1] = 0;
	result[2] = 0;
	return result;
}

