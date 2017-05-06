#include <stdio.h>

#include "CuTest.h"
#include "str_util_test.h"

void run_all_tests(void) {
    CuString *output = CuStringNew();
    CuSuite* suite = CuSuiteNew();
	
	CuSuiteAddSuite(suite, str_util_get_suite());
	
    CuSuiteRun(suite);
    CuSuiteSummary(suite, output);
    CuSuiteDetails(suite, output);
    printf("%s\n", output->buffer);
}

int main() {
	run_all_tests();
	
	return 0;
}