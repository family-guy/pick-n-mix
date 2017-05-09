/** @file count_inv_algo_test.h
 *  @brief Function prototypes for unit testing of count inversion algorithms.
 *
 *  Uses the CuTest library.
 *
 *  @author Guy R. King (grking8@geemail.com)
 *  @date 8 May 2017
 *  @see http://cutest.sourceforge.net/
 *  @bug No known bugs.
 */

#ifndef COUNT_INV_ALGO_TEST_H
#define COUNT_INV_ALGO_TEST_H

#include "CuTest.h"

/** @brief Returns a test suite containing the unit tests of count inversion
 *         algorithms.
 *  
 *  @return The test suite.
 */
CuSuite* count_inv_algo_get_suite();

#endif