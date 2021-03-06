/** @file gcd_algo_test.h
 *  @brief Function prototypes for unit testing of GCD algorithms.
 *
 *  Uses the CuTest library.
 *
 *  @author Guy R. King (grking8@geemail.com)
 *  @date 16 May 2017
 *  @see http://cutest.sourceforge.net/
 *  @bug No known bugs.
 */

#ifndef GCD_ALGO_TEST_H
#define GCD_ALGO_TEST_H

#include "CuTest.h"

/** @brief Returns a test suite containing the unit tests of GCD algorithms.
 *  
 *  @return The test suite.
 */
CuSuite* gcd_algo_get_suite();

#endif
