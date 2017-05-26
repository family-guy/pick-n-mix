/** @file count_inv_test.h
 *  @brief Function prototypes for e2e testing of count inversion algorithms.
 *
 *  Uses the CuTest library.
 *
 *  @author Guy R. King (grking8@geemail.com)
 *  @date 8 May 2017
 *  @see http://cutest.sourceforge.net/
 *  @bug No known bugs.
 */

#ifndef COUNT_INV_TEST_H
#define COUNT_INV_TEST_H

#include "CuTest.h"

/** @brief Returns a test suite containing the e2e tests of count inversion 
 *         algorithms.
 *
 *  @return The test suite.
 */
CuSuite* count_inv_get_suite();

#endif
