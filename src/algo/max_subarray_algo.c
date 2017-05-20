/** @file max_subarray_algo.c
 *  @brief Function definitions for maximum subarray algorithms.
 *
 *  Each function implements an algorithm to find the maximum subarray of an
 *  array of integers. Let A be an array. The maximum subarray is the
 *  (continguous) subarray S of A such that for each subarray S' of A, the sum 
 *  of the elements of S' is less than or equal to the sum of the elements of S.
 *
 *  @author Guy R. King (grking8@geemail.com)
 *  @date 11 May 2017
 *  @see include/int_array.h
 *  @bug No known bugs.
 */

#include <stdlib.h>
#include <stdio.h>

#include "int_array.h"
#include "aux_algo.h"

/** @brief Finds the maximum subarray of an array of integers incrementally.
 *
 *  Keeps track of the maximum subarray and the maximum right subarray (the 
 *  maximum subarray such that A[A.len-1] is in the subarray). Solves for 
 *  successive subararys in the order A[0..0], A[0..1], ..., A. It is the
 *  caller's responsibility to free the memory dynamically allocated.
 *
 *  @param A_prime The array to find the maximum subarray of.
 *  @return An array containing the maximum subarray's lower demarcation, upper
 *  demarcation, sum.
 *  @see int_array
 */
int *max_subarray_incr(struct int_array *A_prime) {
	int *result = calloc(3, sizeof(int));
	int global_low = 0;
	int global_high = 0;
	int global_max = A_prime->A[0];
	int right_low = 0;
	int right_high = 0;
	int right_max = A_prime->A[0];
	for (int i = 1; i < A_prime->len; i++) {
		right_high = i;
		if (right_max > 0) { // <=> right_max + A[i] > A[i]
			right_max += A_prime->A[i];
		}
		else {
			right_max = A_prime->A[i];
			right_low = i;
		}
		if (right_max > global_max) {
			global_max = right_max;
			global_low = right_low;
			global_high = right_high;
		}
	}
	result[0] = global_low;
	result[1] = global_high;
	result[2] = global_max;
	return result;
}

/** @brief Finds the maximum subarray of an array of integers using divide and
 *  conquer.
 *
 *  As the maximum subarray of an array of one element is trivially the whole 
 *  array, it suffices to divide an array into two and find the maximum subarray
 *  using the maximum subarray of the left array and the maximum subarray of the
 *  right array, i.e. find the maximum subarray with at least one element in 
 *  each of the two (left and right) arrays. Demarcations are inclusive. It is
 *  the caller's responsibility to free the memory dynamically allocated.
 *  
 *  @param A The array to find the maximum subarray of.
 *  @param low The subarray's lower demarcation.
 *  @param high The subarray's upper demarcation.
 *  @return An array containing the maximum subarray's lower demarcation, upper
 *  demarcation, sum.
 *  @see max_subarray_cross
 */
int *max_subarray_dc(int *A, int low, int high) {
	int len_result = 3;
	int *result = calloc(len_result, sizeof(int));
	if (low == high) {
		result[0] = low;
		result[1] = high;
		result[2] = low;
		return result;
	}
	int mid = (low + high) / 2;
	int *left = max_subarray_dc(A, low, mid);
	int *right = max_subarray_dc(A, mid + 1, high);
	int *cross = max_subarray_cross(A, low, mid, high);
	if (left[2] >= right[2] && left[2] >= cross[2]) {
		for (int i = 0; i < len_result; i++) {
			result[i] = left[i];
		}
	}
	else if (right[2] >= left[2] && right[2] >= cross[2]) {
		for (int i = 0; i < len_result; i++) {
			result[i] = right[i];
		}
	}
	else {
		for (int i = 0; i < len_result; i++) {
			result[i] = cross[i];
		}
	}
	free(left);
	free(right);
	free(cross);
	return result;
}













