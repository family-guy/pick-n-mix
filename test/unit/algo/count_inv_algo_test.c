#include <stdlib.h>

#include "CuTest.h"
#include "count_inv_algo.h"

void count_inv_test_inv(CuTest *tc) {
	int input[] = {2, 4, 1, 3, 5};
	int input_len = 5;
	
	int actual = count_inv(input, 0, input_len - 1);
	int expected = 3;
	
	CuAssertIntEquals(tc, expected, actual);
}

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

CuSuite* count_inv_algo_get_suite() {
	CuSuite* suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, count_inv_test_inv);
	SUITE_ADD_TEST(suite, count_inv_test_sort);
	return suite;
}