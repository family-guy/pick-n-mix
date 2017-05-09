/** @file count_inv_algo.h
 *  @brief Function prototypes for count inversion algorithms.
 *
 *  Let A be an array. An inversion is a pair of indices i,j such that i<j, A[i]
 *  >A[j]. Functions may rely on auxiliary functions.
 *
 *  @author Guy R. King (grking8@geemail.com)
 *  @date 8 May 2017
 *  @bug No known bugs.
 */

#ifndef COUNT_INV_ALGO_H
#define COUNT_INV_ALGO_H

/** @brief Counts the number of inversions in an array of integers.
 *
 *  @param The array of integers to count the number of inversions for.
 *  @param The subarray's lower demarcation.
 *  @param The subarray's upper demarcation.
 *  @return The number of inversions.
 */
unsigned long long count_inv(int *, int, int);

#endif
