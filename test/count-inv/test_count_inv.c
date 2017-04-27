#include <stdio.h>
#include "grkio.h"
#include "util.h"
#include "count_inv.h"

int main() {
	const char *path = "./test/count-inv/IntegerArray.txt"; // relative to working directory when making files (not directory of this file)

	char *fs = read_file(path);
	struct int_array *A_prime = parser(fs);
	
	unsigned long long invs = count_inv(A_prime->A, 0, A_prime->len - 1);
	printf("%llu\n", invs);
	return 0;
}
