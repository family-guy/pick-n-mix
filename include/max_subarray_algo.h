/** @file max_subarray_algo.h
 *  @brief Function prototypes for maximum subarray algorithms.
 *
 *  Let A be an array. The maximum subarray is the (continguous) subarray S of A
 *  such that for each subarray S' of A, the sum of the elements of S' is less
 *  than or equal to the sum of the elements of S.
 *
 *  @author Guy R. King (grking8@geemail.com)
 *  @date 10 May 2017
 *  @bug No known bugs.
 */

#ifndef MAX_SUBARRAY_ALGO_H
#define MAX_SUBARRAY_ALGO_H

#include "int_array.h"

/** @brief Finds the maximum subarray of an array of integers incrementally.
 *
 *  @param A The array to find the maximum subarray of.
 *  @return An array containing the maximum subarray's lower demarcation, upper
 *  demarcation, and sum.
 */
int *max_subarray_incr(struct int_array *A);

#endif
