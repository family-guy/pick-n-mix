#include <stdlib.h>

#include "CuTest.h"
#include "str_util.h"
#include "int_array.h"

void parser_test_len(CuTest *tc) {
	char input[12] = "123\n100\n24\n\0";
	
	struct int_array *A_prime = parser(input);
	
	int actual = A_prime->len;
	int expected = 3;
	
	CuAssertIntEquals(tc, expected, actual);
	free(A_prime);
}

void parser_test_vals(CuTest *tc) {
	char input[12] = "123\n100\n24\n\0";
	
	struct int_array *A_prime = parser(input);
	
	int *actual = A_prime->A;
	int expected[] = {123, 100, 24};
	
	int cond = 1;
	for (int i = 0; i < 3; i++) {
		if (!actual[i] == expected[i]) {
			cond = 0;
		}
	}
	CuAssertTrue(tc, cond);
	free(A_prime);
}

CuSuite* str_util_get_suite() {
	CuSuite* suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, parser_test_len);
	SUITE_ADD_TEST(suite, parser_test_vals);
	return suite;
}













