/** @file gcd_algo_test.c
 *  @brief Function definitions for unit testing of GCD algorithms.
 *
 *  Uses the CuTest library. Contains unit tests for each function that 
 *  implements an algorithm to find the greatest common divisor (GCD) of an 
 *  array of pairs of positive integers. A unit test verifies one aspect of a 
 *  function's behaviour. A function can have more than one unit test.
 *
 *  @author Guy R. King (grking8@geemail.com)
 *  @date 16 May 2017
 *  @see http://cutest.sourceforge.net/
 *  @see src/algo/gcd_algo.c
 *  @bug No known bugs.
 */

#include <stdlib.h>

#include "CuTest.h"
#include "gcd_algo.h"
#include "int_array_2d.h"

/** @brief Checks gcd_euclid returns the correct GCDs.
 *  
 *  The example array is
 *  [[3455, 1], [888,888], [34, 170], [57, 45], [99989510, 5451486]].
 *
 *  @param tc Pointer to CuTest @c struct.
 *  @return Void.
 *  @see gcd_euclid
 */
void gcd_euclid_test(CuTest *tc) {	
	int x[5][2] = {
		{3455, 1},
		{888,888},
		{68, 170},
		{57, 45},
		{99989510, 5451486}
	};
	
	struct int_array_2d *input = malloc(sizeof *input);
	input->rows = 5;
	input->cols = 2;
	input->A = calloc(input->rows, sizeof(int *));
	for (int i = 0; i < input->rows; i++) {
		input->A[i] = calloc(input->cols, sizeof(int));
		memcpy(input->A[i], x[i], sizeof(int) * input->cols);
	}
	
	int *actual = gcd_euclid(input);
	int expected[] = {1, 888, 34, 3, 2};
	
	int cond = 1;
	for (int i = 0; i < input->rows; i++) {
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
CuSuite* gcd_algo_get_suite() {
	CuSuite* suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, gcd_euclid_test);
	return suite;
}