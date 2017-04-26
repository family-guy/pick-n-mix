#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "grkio.h"

struct int_array {
	int len;
	int *A;
};

unsigned long long count_inv(int *A, int low, int high) {
	if (low == high) {
		return 0;
	}
	int mid = (low + high) / 2;
	unsigned long long left_invs = count_inv(A, low, mid);
	unsigned long long right_invs = count_inv(A, mid + 1, high);
	
	int L[mid - low + 2];
	int R[high - mid + 1];
	int i = low;
	while (i <= mid) {
		L[i - low] = A[i];
		i++;
	}
	L[i - low] = INT_MAX;
	
	i = mid + 1;
	while (i <= high) {
		R[i - (mid + 1)] = A[i];
		i++;
	}
	R[i - (mid + 1)] = INT_MAX;
	
	unsigned long long split_invs = 0;
	i = 0; // left counter
	int j = 0; // right counter
	for (int k = low; k <= high; k++) {
		if (L[i] <= R[j]) {
			A[k] = L[i];
			i++;
		}
		else {
			A[k] = R[j];
			j++;
			split_invs += (mid - low + 1) - i;
		}
	}
	return left_invs + right_invs + split_invs;
}

struct int_array *parser(char *fs) {
	struct int_array *result;
	
	int *A;
	int block_size = 1024;
	int blocks = 1;
	A = calloc(block_size * blocks, sizeof(int));
	if (A == NULL) {
		fprintf(stderr, "Error - unable to allocate required memory.\n");
		exit(1);
	}
	int i = 0;
	char *pos = strtok(fs, "\n");
	while (pos != NULL) {
		if (i == blocks * block_size) {
			blocks++;
			A = realloc(A, block_size * blocks * sizeof(int));
			if (A == NULL) {
				fprintf(stderr, "Error - unable to allocate required 				memory.\n");
				exit(1);
			}
		}
		A[i] = atoi(pos);
		pos = strtok(NULL, "\n");
		i++;
	}
	result->len = i;
	result->A = A;
	free(A);
	return result;
}

int main() {
	const char *path = "IntegerArray.txt"; // relative to working directory when making files (not directory of this file)

	char *fs = read_file(path);
	struct int_array *A_prime = parser(fs);
	
	unsigned long long invs = count_inv(A_prime->A, 0, A_prime->len - 1);
	printf("%llu\n", invs);
	return 0;
}

