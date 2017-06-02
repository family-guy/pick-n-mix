/** @file sort_algo.h
 *  @brief Function prototypes for sorting algorithms.
 *
 *  @author Guy R. King (grking8@geemail.com)
 *  @date 21 May 2017
 *  @bug No known bugs.
 */

#ifndef SORT_ALGO_H
#define SORT_ALGO_H

#include "int_array.h"

/** @brief Sorts an array of integers into ascending order in-place using bubble
 *         sort.
 *
 *  @param A_prime The array to sort.
 *  @return Void.
 */
void sort_bubble(struct int_array *);

/** @brief Sorts an array of integers into ascending order in-place using
 *         insertion sort.
 *
 *  @param A_prime The array to sort.
 *  @return Void.
 */
void sort_ins(struct int_array *);

/** @brief Sorts an array of integers into ascending order in-place using
 *         selection sort.
 *
 *  @param A_prime The array to sort.
 *  @return Void.
 */
void sort_select(struct int_array *);

#endif
