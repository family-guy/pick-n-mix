/** @file max_subarray_test.c
 *  @brief Function definitions for e2e testing of maximum subarray algorithms.
 *
 *  Uses the CuTest library. Contains e2e tests for each function that
 *  implements an algorithm to find the maximum subarray of an array of 
 *  integers. Let A be an array. The maximum subarray is the (continguous)
 *  subarray S of A such that for each subarray S' of A, the sum of the elements
 *  of S' is less than or equal to the sum of the elements of S.
 *
 *  @author Guy R. King (grking8@geemail.com)
 *  @date 11 May 2017
 *  @see http://cutest.sourceforge.net/
 *  @see src/algo/max_subarray_algo.c
 *  @see src/util/str_util.c
 *  @see src/io/file_io.c
 *  @bug No known bugs.
 */

#include <stdio.h>

#include "CuTest.h"
#include "file_io.h"
#include "str_util.h"
#include "max_subarray_algo.h"

/** @brief e2e test of the maximum subarray algorithm that solves incrementally.
 *  
 *  The test data consists of 100,000 integers in a text file. The data is read,
 *  parsed into an array, and the maximum subarray calculated. Checks there are 
 *  no errors and the user's patience exceeds the runtime, and sanity checks
 *  the result.
 *
 *  @param tc Pointer to CuTest @c struct.
 *  @return Void.
 *  @see read_file
 *  @see parser
 *  @see max_subarray_incr
 */
void max_subarray_incr_test(CuTest *tc) {
	const char *path = "./test/e2e/data/IntegerArray.txt";
	
	char *fs = read_file(path);
	struct int_array *A_prime = parser(fs);
	
	int *result = max_subarray_incr(A_prime);
	int cond;
	if (result[0] >= 0 && result[0] < A_prime->len) {
		if (result[1] >= 0 && result[1] < A_prime->len) {
			if (result[0] <= result[1]) {
				cond = 1;
			}
			else {
				cond = 0;
			}
		}
		else cond = 0;
	}
	else {
		cond = 0;
	}
	if (cond) {
		int sum = 0;
		for (int i = 0; i < A_prime->len; i++) {
			sum += A_prime->A[i];
		}
		if (result[2] < sum) {
			cond = 0;
		}
	}
	CuAssertTrue(tc, cond);
}

/** @brief Returns a test suite containing the e2e tests in this file.
 *  
 *  Adds each e2e test via SUITE_ADD_TEST.
 *
 *  @return The test suite.
 */
CuSuite* max_subarray_get_suite() {
	CuSuite* suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, max_subarray_incr_test);
	return suite;
}

