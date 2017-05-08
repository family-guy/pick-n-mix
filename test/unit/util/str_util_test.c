/** @file str_util_test.c
 *  @brief Function definitions for unit testing of functions that perform 
 *  operations on and transformations of strings.
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
#include "str_util.h"
#include "int_array.h"

/** @brief Checks parser returns the correct number of integers.
 *  
 *  "123\n100\n24\n\0" is the example string. As parser allocates memory
 *  manually, once the test is done this memory needs to be freed.
 *
 *  @param tc Pointer to CuTest @c struct.
 *  @return Void.
 *  @see parser
 */
void parser_test_len(CuTest *tc) {
	char input[12] = "123\n100\n24\n\0";
	
	struct int_array *A_prime = parser(input);
	
	int actual = A_prime->len;
	int expected = 3;
	
	CuAssertIntEquals(tc, expected, actual);
	free(A_prime);
}

/** @brief Checks parser returns the correct integers.
 *  
 *  "123\n100\n24\n\0" is the example string. As parser allocates memory
 *  manually, once the test is done this memory needs to be freed.
 *
 *  @param tc Pointer to CuTest @c struct.
 *  @return Void.
 *  @see parser
 */
void parser_test_vals(CuTest *tc) {
	char input[12] = "123\n100\n24\n\0";
	
	struct int_array *A_prime = parser(input);
	
	int *actual = A_prime->A;
	int expected[] = {123, 100, 24};
	
	int cond = 1;
	for (int i = 0; i < 3; i++) {
		if (!actual[i] == expected[i]) {
			cond = 0;
		}
	}
	CuAssertTrue(tc, cond);
	free(A_prime);
}

/** @brief Creates a test suite for the unit tests in this file.
 *  
 *  @return The test suite containing the unit tests.
 */
CuSuite* str_util_get_suite() {
	CuSuite* suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, parser_test_len);
	SUITE_ADD_TEST(suite, parser_test_vals);
	return suite;
}













