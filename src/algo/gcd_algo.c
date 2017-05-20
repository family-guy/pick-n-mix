/** @file gcd_algo.c
 *  @brief Function definitions for GCD algorithms.
 *
 *  Each function implements an algorithm to find the greatest common divisor 
 *  (GCD) of two positive integers.
 *
 *  @author Guy R. King (grking8@geemail.com)
 *  @date 15 May 2017
 *  @see include/int_array_2d.h
 *  @see src/algo/aux_algo.c
 *  @bug No known bugs.
 */

#include <stdlib.h>

#include "int_array_2d.h"
#include "aux_algo.h"

/** @brief Finds the GCDs of an array of pairs of positive integers using
 *         Euclid's algorithm.
 *
 *  It is the caller's responsibility to free the memory dynamically allocated.
 *
 *  @param A_prime The array of pairs of positive integers.
 *  @return An array containing the GCD of each pair of positive integers.
 *  @see int_array_2d
 *  @see gcd_euclid_imp
 */
int *gcd_euclid(struct int_array_2d *A_prime) {
	int *result = calloc(A_prime->rows, sizeof(int));
	for (int i = 0; i < A_prime->rows; i++) {
		result[i] = gcd_euclid_imp(A_prime->A[i][0], A_prime->A[i][1]);
	}
	return result;
}