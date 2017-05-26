/** @file all_tests.c
 *  @brief Main program for running e2e tests.
 *
 *  Uses the CuTest library. Individual e2e tests are grouped into suites   
 *  which are placed into a container suite. The container suite is run and the 
 *  test results displayed.
 *
 *  @author Guy R. King (grking8@geemail.com)
 *  @date 8 May 2017
 *  @see http://cutest.sourceforge.net/
 *  @bug No known bugs.
 */

#include <stdio.h>

#include "CuTest.h"
#include "count_inv_test.h"
#include "max_subarray_test.h"
#include "gcd_test.h"
#include "sort_test.h"

void run_all_tests(void) {
	CuString *output = CuStringNew();
	CuSuite *suite = CuSuiteNew(); // container suite
	
	CuSuiteAddSuite(suite, count_inv_get_suite());
	CuSuiteAddSuite(suite, max_subarray_get_suite());
	CuSuiteAddSuite(suite, gcd_get_suite());
	CuSuiteAddSuite(suite, sort_get_suite());
	
	CuSuiteRun(suite);
	CuSuiteSummary(suite, output);
	CuSuiteDetails(suite, output);
	printf("%s\n", output->buffer);
}

int main() {
	run_all_tests();
	return 0;
}
