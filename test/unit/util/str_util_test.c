/** @file str_util_test.c
 *  @brief Function definitions for unit testing of functions that manipulate
 *         strings.
 *
 *  Uses the CuTest library. A unit test verifies one aspect of a function's
 *  behaviour. A function can have more than one unit test.
 *
 *  @author Guy R. King (grking8@geemail.com)
 *  @date 8 May 2017
 *  @see http://cutest.sourceforge.net/
 *  @see src/util/str_util.c
 *  @bug No known bugs.
 */

#include <stdlib.h>

#include "CuTest.h"
#include "str_util.h"
#include "int_array.h"

/** @brief Checks parser returns the correct integers.
 *
 *  The example string is  "123\n100\n24\n\0". As the parser allocates memory
 *  manually, this memory needs to be freed once the test is done.
 *
 *  @param tc Pointer to CuTest @c struct.
 *  @return Void.
 *  @see parser
 */
void parser_test(CuTest *tc) {
	char input[12] = "123\n100\n24\n\0";
	
	struct int_array *A_prime = parser(input);
	
	int *actual = A_prime->A;
	int actual_len = A_prime->len;
	int expected[] = {123, 100, 24};
	int expected_len = 3;
	
	int cond = 1;
	if (actual_len != expected_len) {
		cond = 0;
	}
	else {
		for (int i = 0; i < actual_len; i++) {
			if (!actual[i] == expected[i]) {
				cond = 0;
			}
		}
	}
	CuAssertTrue(tc, cond);
	free(A_prime);
}

/** @brief Returns a test suite containing the unit tests in this file.
 *  
 *  Adds each unit test via SUITE_ADD_TEST.
 *
 *  @return The test suite.
 */
CuSuite* str_util_get_suite() {
	CuSuite* suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, parser_test);
	return suite;
}













