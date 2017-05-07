#include <stdio.h>

#include "CuTest.h"
#include "str_util_test.h"
#include "file_io_test.h"
#include "count_inv_algo_test.h"

void run_all_tests(void) {
	CuString *output = CuStringNew();
	CuSuite *suite = CuSuiteNew();
	
	CuSuiteAddSuite(suite, str_util_get_suite());
	CuSuiteAddSuite(suite, file_io_get_suite());
	CuSuiteAddSuite(suite, count_inv_algo_get_suite());
	
	CuSuiteRun(suite);
	CuSuiteSummary(suite, output);
	CuSuiteDetails(suite, output);
	printf("%s\n", output->buffer);
}

int main() {
	run_all_tests();
	return 0;
}