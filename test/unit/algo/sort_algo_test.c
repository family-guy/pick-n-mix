/** @file sort_algo_test.c
 *  @brief Function definitions for unit testing of sorting algorithms.
 *
 *  Uses the CuTest library. Contains unit tests for each function that 
 *  implements an algorithm to sort an array of integers. A unit test verifies
 *  one aspect of a function's behaviour. A function can have more than one unit
 *  test.
 *
 *  @author Guy R. King (grking8@geemail.com)
 *  @date 21 May 2017
 *  @see http://cutest.sourceforge.net/
 *  @see src/algo/sort_algo.c
 *  @bug No known bugs.
 */

#include <stdlib.h>
#include <string.h>

#include "CuTest.h"
#include "sort_algo.h"
#include "int_array.h"

/** @brief Checks sort_bubble sorts correctly.
 *  
 *  The example array is
 *  [13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7].
 *
 *  @param tc Pointer to CuTest @c struct.
 *  @return Void.
 *  @see sort_bubble
 */
void sort_bubble_test(CuTest *tc) {
	int x[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
	struct int_array *input = malloc(sizeof *input);

	input->len = 16;
	input->A = calloc(input->len, sizeof(int));
	
	memcpy(input->A, x, sizeof(int) * input->len);
	
	sort_bubble(input);
	
	int expected[] = {-25, -23, -22, -16, -7, -5, -4, -3, -3, 7, 12, 13, 15, 18, 20, 20};
	
	int cond = 1;
	for (int i = 0; i < input->len; i++) {
		if (input->A[i] != expected[i]) {
			cond = 0;
			break;
		}
	}
	CuAssertTrue(tc, cond);
	free(input);
}

/** @brief Checks sort_ins sorts correctly.
 *  
 *  The example array is
 *  [13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7].
 *
 *  @param tc Pointer to CuTest @c struct.
 *  @return Void.
 *  @see sort_bubble
 */
void sort_ins_test(CuTest *tc) {
	int x[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
	struct int_array *input = malloc(sizeof *input);

	input->len = 16;
	input->A = calloc(input->len, sizeof(int));
	
	memcpy(input->A, x, sizeof(int) * input->len);
	
	sort_ins(input);
	
	int expected[] = {-25, -23, -22, -16, -7, -5, -4, -3, -3, 7, 12, 13, 15, 18, 20, 20};
	
	int cond = 1;
	for (int i = 0; i < input->len; i++) {
		if (input->A[i] != expected[i]) {
			cond = 0;
			break;
		}
	}
	CuAssertTrue(tc, cond);
	free(input);
}

/** @brief Returns a test suite containing the unit tests in this file.
 *  
 *  Adds each unit test via SUITE_ADD_TEST.
 *
 *  @return The test suite.
 */
CuSuite* sort_algo_get_suite() {
	CuSuite* suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, sort_bubble_test);
	SUITE_ADD_TEST(suite, sort_ins_test);
	return suite;
}