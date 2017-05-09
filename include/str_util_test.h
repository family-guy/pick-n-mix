/** @file str_util_test.h
 *  @brief Function prototypes for unit testing of functions that manipulate 
 *         strings.
 *
 *  Uses the CuTest library.
 *
 *  @author Guy R. King (grking8@geemail.com)
 *  @date 8 May 2017
 *  @see http://cutest.sourceforge.net/
 *  @bug No known bugs.
 */

#ifndef STRING_UTIL_TEST_H
#define STRING_UTIL_TEST_H

#include "CuTest.h"

/** @brief Returns a test suite containing the unit tests of functions that
 *		   manipulate strings.
 *
 *  @return The test suite.
 */
CuSuite* str_util_get_suite();

#endif