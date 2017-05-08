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
 *  @bug No known bugs.
 */

#include <stdlib.h>

#include "CuTest.h"
#include "count_inv_algo.h"

/** @brief Checks count_inv returns the correct number of inversions.
 *  
 *  [2,4,1,3,5] is the example array.
 *
 *  @param tc Pointer to CuTest @c struct.
 *  @return Void.
 *  @see count_inv
 */
void count_inv_test_inv(CuTest *tc) {
	int input[] = {2, 4, 1, 3, 5};
	int input_len = 5;
	
	int actual = count_inv(input, 0, input_len - 1);
	int expected = 3;
	
	CuAssertIntEquals(tc, expected, actual);
}

/** @brief Checks count_inv sorts the example array in-place using the merge     *         sort algorithm.
 *  
 *  [-5, 45, 111, -54945, 14, 77, 309504, -134, 1, 4, -4, 0] is the example
 *  array.
 *
 *  @param tc Pointer to CuTest @c struct.
 *  @return Void.
 *  @see count_inv
 */
void count_inv_test_sort(CuTest *tc) {
	int input[] = {-5, 45, 111, -54945, 14, 77, 309504, -134, 1, 4, -4, 0};
	int input_len = 12;
	
	count_inv(input, 0, input_len - 1);
	int *actual = input;
	int expected[] = {-54945, -134, -5, -4, 0, 1, 4, 14, 45, 77, 111, 309504};
	int cond = 1;
	for (int i = 0; i < input_len; i++) {
		if (!actual[i] == expected[i]) {
			cond = 0;
		}
	}
	CuAssertTrue(tc, cond);
}

/** @brief Creates a test suite for the unit tests in this file.
 *  
 *  @return The test suite containing the unit tests.
 */
CuSuite* count_inv_algo_get_suite() {
	CuSuite* suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, count_inv_test_inv);
	SUITE_ADD_TEST(suite, count_inv_test_sort);
	return suite;
}