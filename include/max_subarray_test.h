/** @file max_subarray_test.h
 *  @brief Function prototypes for e2e testing of maximum subarray algorithms.
 *
 *  Uses the CuTest library.
 *
 *  @author Guy R. King (grking8@geemail.com)
 *  @date 11 May 2017
 *  @see http://cutest.sourceforge.net/
 *  @bug No known bugs.
 */

#ifndef MAX_SUBARRAY_TEST_H
#define MAX_SUBARRAY_TEST_H

#include "CuTest.h"

/** @brief Returns a test suite containing the e2e tests of maximum subarray 
 *         algorithms.
 *
 *  @return The test suite.
 */
CuSuite* max_subarray_get_suite();

#endif
