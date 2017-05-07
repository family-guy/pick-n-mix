#include <stdlib.h>

#include "CuTest.h"
#include "file_io.h"

void read_file_test(CuTest *tc) {
	const char *input = "./test/unit/io/aa";
	
	char *actual = read_file(input);
	char *expected = "This is a test file.\nThis is the second line of the test file.\n";
	CuAssertStrEquals(tc, expected, actual);
}

CuSuite* file_io_get_suite() {
	CuSuite* suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, read_file_test);
	return suite;
}