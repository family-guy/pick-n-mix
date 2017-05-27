/** @file gcd_test.c
 *  @brief Function definitions for e2e testing of GCD algorithms.
 *
 *  Uses the CuTest library. Contains e2e tests for each function that
 *  implements an algorithm to find the greatest common divisor (GCD) of an 
 *  array of pairs of positive integers.
 *
 *  @author Guy R. King (grking8@geemail.com)
 *  @date 19 May 2017
 *  @see http://cutest.sourceforge.net/
 *  @see src/algo/gcd_algo.c
 *  @see src/util/str_util.c
 *  @see src/io/file_io.c
 *  @bug No known bugs.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "CuTest.h"
#include "file_io.h"
#include "str_util.h"
#include "gcd_algo.h"
#include "macros.h"

/** @brief e2e test of the implementation of Euclid's algorithm that calculates
 *         the GCDs of an array of pairs of positive integers.
 *  
 *  The test data consists of 100,000 positive integers in a text file. The data
 *  is read, parsed into an array, and the GCD of each pair calculated. Checks
 *  there are no errors, the user's patience exceeds the runtime, and the first
 *  few GCDs are correct.
 *
 *  @param tc Pointer to CuTest @c struct.
 *  @return Void.
 *  @see read_file
 *  @see parser
 *  @see gcd_euclid
 */
void gcd_euclid_test(CuTest  *tc) {
	clock_t start = clock();
	const char *path = "./test/e2e/data/IntegerArray.txt";
	
	char *fs = read_file(path);
	struct int_array *parsed = parser(fs);
	
	struct int_array_2d *A_prime = malloc(sizeof(*A_prime));
	A_prime->rows = parsed->len / 2;
	A_prime->cols = 2;
	A_prime->A = calloc(A_prime->rows, sizeof(int *));
	for (int i = 0; i < A_prime->rows; i++) {
		A_prime->A[i] = calloc(A_prime->cols, sizeof(int));
		A_prime->A[i][0] = parsed->A[i * 2];
		A_prime->A[i][1] = parsed->A[i * 2 + 1];
	}
	int *result = gcd_euclid(A_prime);
	// check first few results
	int cond = 1;
	if (result[0] != 4 || result[1] != 1 || result[2] != 60) {
		cond = 0;
	}
	
	for (int i = 0; i < A_prime->rows; i++) {
		int min = A_prime->A[i][0] > A_prime->A[i][1] ? A_prime->A[i][1] : 
		A_prime->A[i][0]; 
		if (result[i] > min || result[i] < 1) {
			cond = 0;
		}
	}
	PRINT_EXEC_TIME(start, __func__);
	CuAssertTrue(tc, cond);
	free(fs);
	free(parsed);
	free(A_prime);
	free(result);
}

/** @brief Returns a test suite containing the e2e tests in this file.
 *  
 *  Adds each e2e test via SUITE_ADD_TEST.
 *
 *  @return The test suite.
 */
CuSuite* gcd_get_suite() {
	CuSuite* suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, gcd_euclid_test);
	return suite;
}
