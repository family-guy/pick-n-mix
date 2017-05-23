/** @file sort_algo_test.h
 *  @brief Function prototypes for unit testing of sorting algorithms.
 *
 *  Uses the CuTest library.
 *
 *  @author Guy R. King (grking8@geemail.com)
 *  @date 23 May 2017
 *  @see http://cutest.sourceforge.net/
 *  @bug No known bugs.
 */

#ifndef SORT_ALGO_TEST_H
#define SORT_ALGO_TEST_H

#include "CuTest.h"

/** @brief Returns a test suite containing the unit tests of sorting algorithms.
 *  
 *  @return The test suite.
 */
CuSuite* sort_algo_get_suite();

#endif