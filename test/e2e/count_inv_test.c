#include <stdio.h>

#include "CuTest.h"
#include "file_io.h"
#include "str_util.h"
#include "count_inv_algo.h"

void count_inv_test(CuTest *tc) {
	const char *path = "./test/e2e/data/IntegerArray.txt";
	
	char *fs = read_file(path);
	struct int_array *A_prime = parser(fs);
	
	unsigned long long actual = count_inv(A_prime->A, 0, A_prime->len - 1);
	unsigned long long expected = 2407905288;
	
	int cond = (actual == expected);
	CuAssertTrue(tc, cond);
}

CuSuite* count_inv_get_suite() {
	CuSuite* suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, count_inv_test);
	return suite;
}

