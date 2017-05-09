/** @file file_io_test.h
 *  @brief Function prototypes for unit testing of file I/O functions.
 *
 *  Uses the CuTest library.
 *
 *  @author Guy R. King (grking8@geemail.com)
 *  @date 8 May 2017
 *  @see http://cutest.sourceforge.net/
 *  @bug No known bugs.
 */

#ifndef FILE_IO_TEST_H
#define FILE_IO_TEST_H

#include "CuTest.h"

/** @brief Returns a test suite containing the unit tests of file I/O functions.
 *  
 *  @return The test suite.
 */
CuSuite* file_io_get_suite();

#endif