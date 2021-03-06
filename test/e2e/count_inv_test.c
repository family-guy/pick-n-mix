/** @file count_inv_test.c
 *  @brief Function definitions for e2e testing of count inversion algorithms.
 *
 *  Uses the CuTest library. Contains e2e tests for each function that 
 *  implements an algorithm to count the number of inversions in an array of
 *  integers. Let A be an array. An inversion is a pair of indices i,j such that
 *  i<j, A[i]>A[j].
 *
 *  @author Guy R. King (grking8@geemail.com)
 *  @date 8 May 2017
 *  @see http://cutest.sourceforge.net/
 *  @see src/algo/count_inv_algo.c
 *  @see src/util/str_util.c
 *  @see src/io/file_io.c
 *  @see include/macros.h
 *  @bug No known bugs.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "CuTest.h"
#include "file_io.h"
#include "str_util.h"
#include "count_inv_algo.h"
#include "macros.h"

/** @brief e2e test of the count inversion algorithm that uses merge sort.
 *  
 *  The test data consists of 100,000 integers in a text file. The data is read,
 *  parsed into an array, and the number of inversions counted. Checks there are
 *  no errors, the user's patience exceeds the runtime, and the number of
 *  inversions.
 *
 *  @param tc Pointer to CuTest @c struct.
 *  @return Void.
 *  @see read_file
 *  @see parser
 *  @see count_inv_ms
 */
void count_inv_ms_test(CuTest *tc) {
	clock_t start = clock();
	const char *path = "./test/e2e/data/IntegerArray.txt";
	
	char *fs = read_file(path);
	struct int_array *A_prime = parser(fs);
	
	unsigned long long actual = count_inv_ms(A_prime->A, 0, A_prime->len - 1);
	unsigned long long expected = 2407905288;
	
	int cond = (actual == expected);
	PRINT_EXEC_TIME(start, __func__);
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
CuSuite* count_inv_get_suite() {
	CuSuite* suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, count_inv_ms_test);
	return suite;
}
