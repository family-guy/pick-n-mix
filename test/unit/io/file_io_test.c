/** @file file_io_test.c
 *  @brief Function definitions for unit testing of file I/O functions.
 *
 *  Uses the CuTest library. A unit test verifies one aspect of a function's
 *  behaviour. A function can have more than one unit test.
 *
 *  @author Guy R. King (grking8@geemail.com)
 *  @date 8 May 2017
 *  @see http://cutest.sourceforge.net/
 *  @bug No known bugs.
 */

#include <stdlib.h>

#include "CuTest.h"
#include "file_io.h"

/** @brief Checks read_file reads the contents of a text file into a string.
 *  
 *  test/unit/io/aa is the example file.
 *
 *  @param tc Pointer to CuTest @c struct.
 *  @return Void.
 *  @see read_file
 */
void read_file_test(CuTest *tc) {
	const char *input = "./test/unit/io/aa";
	
	char *actual = read_file(input);
	char *expected = "This is a test file.\nThis is the second line of the test file.\n";
	CuAssertStrEquals(tc, expected, actual);
}

/** @brief Creates a test suite for the unit tests in this file.
 *  
 *  @return The test suite containing the unit tests.
 */
CuSuite* file_io_get_suite() {
	CuSuite* suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, read_file_test);
	return suite;
}