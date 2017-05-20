/** @file gcd_test.h
 *  @brief Function prototypes for e2e testing of GCD algorithms.
 *
 *  Uses the CuTest library.
 *
 *  @author Guy R. King (grking8@geemail.com)
 *  @date 20 May 2017
 *  @see http://cutest.sourceforge.net/
 *  @bug No known bugs.
 */

#ifndef GCD_TEST_H
#define GCD_TEST_H

#include "CuTest.h"

/** @brief Returns a test suite containing the e2e tests of GCD algorithms.
 *
 *  @return The test suite.
 */
CuSuite* gcd_get_suite();

#endif