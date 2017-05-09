/** @file aux_algo.h
 *  @brief Function prototypes for auxiliary routines used in algorithm
 * 		   implementations.
 *
 *  @author Guy R. King (grking8@geemail.com)
 *  @date 8 May 2017
 *  @bug No known bugs.
 */

#ifndef AUX_ALGO_H
#define AUX_ALGO_H

/** @brief Counts the number of split inversions by taking two adjacent sorted
 *		   continguous subarrays and combining them into a single sorted array.
 *
 *  @param The array of integers containing the elements to sort.
 *  @param The left subarray's lower demarcation.
 *  @param The right subarray's upper demarcation.
 *  @param The left subarray's upper demarcation.
 *  @return The number of split inversions.
 */
unsigned long long count_split_inv(int *, int, int, int);

#endif