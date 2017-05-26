/** @file sort_test.h
 *  @brief Function prototypes for e2e testing of sorting algorithms.
 *
 *  Uses the CuTest library.
 *
 *  @author Guy R. King (grking8@geemail.com)
 *  @date 24 May 2017
 *  @see http://cutest.sourceforge.net/
 *  @bug No known bugs.
 */

#ifndef SORT_TEST_H
#define SORT_TEST_H

#include "CuTest.h"

/** @brief Returns a test suite containing the e2e tests of sorting algorithms.
 *
 *  @return The test suite.
 */
CuSuite* sort_get_suite();

#endif
