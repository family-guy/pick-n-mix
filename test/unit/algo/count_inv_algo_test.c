/** @file count_inv_algo_test.c
 *  @brief Function definitions for unit testing of count inversion algorithms.
 *
 *  Uses the CuTest library. Contains unit tests for each function that 
 *  implements an algorithm to count the number of inversions in an array of
 *  integers. Let A be an array. An inversion is a pair of indices i,j such that
 *  i<j, A[i]>A[j]. A unit test verifies one aspect of a function's behaviour. A
 *  function can have more than one unit test.
 *
 *  @author Guy R. King (grking8@geemail.com)
 *  @date 8 May 2017
 *  @see http://cutest.sourceforge.net/
 *  @see src/algo/count_inv_algo.c
 *  @bug No known bugs.
 */

#include <stdlib.h>

#include "CuTest.h"
#include "count_inv_algo.h"

/** @brief Checks count_inv_ms returns the correct number of inversions.
 *  
 *  The example array is [2,4,1,3,5].
 *
 *  @param tc Pointer to CuTest @c struct.
 *  @return Void.
 *  @see count_inv_ms
 */
void count_inv_ms_test_inv(CuTest *tc) {
	int input[] = {2, 4, 1, 3, 5};
	int input_len = 5;
	
	int actual = count_inv_ms(input, 0, input_len - 1);
	int expected = 3;
	
	CuAssertIntEquals(tc, expected, actual);
}

/** @brief Checks count_inv_ms sorts correctly.
 *  
 *  The example array is 
 *  [-5, 45, 111, -54945, 14, 77, 309504, -134, 1, 4, -4, 0].
 *
 *  @param tc Pointer to CuTest @c struct.
 *  @return Void.
 *  @see count_inv_ms
 */
void count_inv_ms_test_sort(CuTest *tc) {
	int input[] = {-5, 45, 111, -54945, 14, 77, 309504, -134, 1, 4, -4, 0};
	int input_len = 12;
	
	count_inv_ms(input, 0, input_len - 1);
	int *actual = input;
	int expected[] = {-54945, -134, -5, -4, 0, 1, 4, 14, 45, 77, 111, 309504};
	int cond = 1;
	for (int i = 0; i < input_len; i++) {
		if (actual[i] != expected[i]) {
			cond = 0;
		}
	}
	CuAssertTrue(tc, cond);
}

/** @brief Returns a test suite containing the unit tests in this file.
 *  
 *  Adds each unit test via SUITE_ADD_TEST.
 *
 *  @return The test suite.
 */
CuSuite* count_inv_algo_get_suite() {
	CuSuite* suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, count_inv_ms_test_inv);
	SUITE_ADD_TEST(suite, count_inv_ms_test_sort);
	return suite;
}
