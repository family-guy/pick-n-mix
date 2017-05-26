/** @file all_tests.c
 *  @brief Main program for running unit tests.
 *
 *  Uses the CuTest library. Individual unit tests are grouped into suites   
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
#include "str_util_test.h"
#include "file_io_test.h"
#include "count_inv_algo_test.h"
#include "max_subarray_algo_test.h"
#include "gcd_algo_test.h"
#include "sort_algo_test.h"

void run_all_tests(void) {
	CuString *output = CuStringNew();
	CuSuite *suite = CuSuiteNew(); // container suite
	
	CuSuiteAddSuite(suite, str_util_get_suite());
	CuSuiteAddSuite(suite, file_io_get_suite());
	CuSuiteAddSuite(suite, count_inv_algo_get_suite());
	CuSuiteAddSuite(suite, max_subarray_algo_get_suite());
	CuSuiteAddSuite(suite, gcd_algo_get_suite());
	CuSuiteAddSuite(suite, sort_algo_get_suite());
	
	CuSuiteRun(suite);
	CuSuiteSummary(suite, output);
	CuSuiteDetails(suite, output);
	printf("%s\n", output->buffer);
}

int main() {
	run_all_tests();
	return 0;
}
