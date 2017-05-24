/** @file sort_test.c
 *  @brief Function definitions for e2e testing of sorting algorithms.
 *
 *  Uses the CuTest library. Contains e2e tests for each function that
 *  implements an algorithm to sort an array of integers.
 *
 *  @author Guy R. King (grking8@geemail.com)
 *  @date 24 May 2017
 *  @see http://cutest.sourceforge.net/
 *  @see src/algo/sort_algo.c
 *  @see src/util/str_util.c
 *  @see src/io/file_io.c
 *  @bug No known bugs.
 */

#include <stdlib.h>

#include "CuTest.h"
#include "file_io.h"
#include "str_util.h"
#include "sort_algo.h"

/** @brief e2e test of bubble sort.
 *  
 *  The test data consists of 100,000 integers in a text file. The data is read,
 *  parsed into an array, and sorted in-place. Checks there are no errors, the 
 *  user's patience exceeds the runtime, and the array's order.
 *
 *  @param tc Pointer to CuTest @c struct.
 *  @return Void.
 *  @see read_file
 *  @see parser
 *  @see sort_bubble
 */
void sort_bubble_test(CuTest *tc) {
	const char *path = "./test/e2e/data/IntegerArray.txt";
	char *fs = read_file(path);
	struct int_array *A_prime = parser(fs);
	sort_bubble(A_prime);
	int cond = 1;
	for (int i = 0; i < A_prime->len - 1; i++) {
		if (A_prime->A[i] > A_prime->A[i + 1]) {
			cond = 0;
		}
	}
	CuAssertTrue(tc, cond);
	free(fs);
	free(A_prime);
}

/** @brief Returns a test suite containing the e2e tests in this file.
 *  
 *  Adds each e2e test via SUITE_ADD_TEST.
 *
 *  @return The test suite.
 */
CuSuite* sort_get_suite() {
	CuSuite* suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, sort_bubble_test);
	return suite;
}