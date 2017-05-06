#include <stdlib.h>

#include "CuTest.h"
#include "count_inv_algo.h"

void count_inv_test(CuTest *tc) {
	int input[] = {2, 4, 1, 3, 5};
	
	int actual = count_inv(input, 0, 4);
	int expected = 3;
	
	CuAssertIntEquals(tc, expected, actual);
}

CuSuite* count_inv_algo_get_suite() {
	CuSuite* suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, count_inv_test);
	return suite;
}