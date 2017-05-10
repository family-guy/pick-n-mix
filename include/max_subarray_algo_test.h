/** @file max_subarray_algo_test.h
 *  @brief Function prototypes for unit testing of maximum subarray algorithms.
 *
 *  Uses the CuTest library.
 *
 *  @author Guy R. King (grking8@geemail.com)
 *  @date 10 May 2017
 *  @see http://cutest.sourceforge.net/
 *  @bug No known bugs.
 */

#ifndef MAX_SUBARRAY_ALGO_TEST_H
#define MAX_SUBARRAY_ALGO_TEST_H

#include "CuTest.h"

/** @brief Returns a test suite containing the unit tests of maximum subarray
 *         algorithms.
 *  
 *  @return The test suite.
 */
CuSuite* max_subarray_algo_get_suite();

#endif