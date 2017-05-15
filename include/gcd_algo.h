/** @file gcd_algo.h
 *  @brief Function prototypes for GCD algorithms.
 *
 *  The greatest common divisor (GCD) of two positive integers.
 *
 *  @author Guy R. King (grking8@geemail.com)
 *  @date 15 May 2017
 *  @bug No known bugs.
 */

#ifndef GCD_ALGO_H
#define GCD_ALGO_H

#include "int_array_2d.h"

/** @brief Finds the GCDs of an array of pairs of positive integers using
 *         Euclid's algorithm.
 *
 *  @param The array of pairs of positive integers.
 *  @return An array containing the GCD of each pair of positive integers.
 */
int *gcd_euclid(struct int_array_2d *A_prime);

#endif
