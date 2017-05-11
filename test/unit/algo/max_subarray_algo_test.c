/** @file max_subarray_algo_test.c
 *  @brief Function definitions for unit testing of maximum subarray algorithms.
 *
 *  Uses the CuTest library. Contains unit tests for each function that 
 *  implements an algorithm to find the maximum subarray of an array of 
 *  integers. Let A be an array. The maximum subarray is the (continguous)
 *  subarray S of A such that for each subarray S' of A, the sum of the elements
 *  of S' is less than or equal to the sum of the elements of S. A unit test 
 *  verifies one aspect of a function's behaviour. A function can have more than
 *  one unit test.
 *
 *  @author Guy R. King (grking8@geemail.com)
 *  @date 10 May 2017
 *  @see http://cutest.sourceforge.net/
 *  @see src/algo/max_subarray_algo.c
 *  @bug No known bugs.
 */

#include <stdlib.h>
#include <string.h>

#include "CuTest.h"
#include "max_subarray_algo.h"
#include "int_array.h"

/** @brief Checks max_subarray_incr returns the correct subarray.
 *  
 *  The example array is
 *  [13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7].
 *
 *  @param tc Pointer to CuTest @c struct.
 *  @return Void.
 *  @see max_subarray_incr
 */
void max_subarray_incr_test(CuTest *tc) {
	int x[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
			
	struct int_array *input = malloc(sizeof *input);

	input->len = 16;
	input->A = calloc(input->len, sizeof(int));
	
	memcpy(input->A, x, sizeof(int) * input->len);
	
	int *actual = max_subarray_incr(input);
	int expected[] = {7, 10, 43};
	int expected_len = 3;
	
	int cond = 1;
	for (int i = 0; i < expected_len; i++) {
		if (actual[i] != expected[i]) {
			cond = 0;
		}
	}
	CuAssertTrue(tc, cond);
	free(input);
	free(actual);
}

/** @brief Returns a test suite containing the unit tests in this file.
 *  
 *  Adds each unit test via SUITE_ADD_TEST.
 *
 *  @return The test suite.
 */
CuSuite* max_subarray_algo_get_suite() {
	CuSuite* suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, max_subarray_incr_test);
	return suite;
}