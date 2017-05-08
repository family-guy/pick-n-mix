#include "aux_algo.h"

unsigned long long count_inv(int *A, int low, int high) {
	if (low == high) {
		return 0;
	}
	int mid = (low + high) / 2;
	unsigned long long left_invs = count_inv(A, low, mid);
	unsigned long long right_invs = count_inv(A, mid + 1, high);
	
	unsigned long long split_invs = count_inv_aux(A, low, high, mid);
	
	return left_invs + right_invs + split_invs;
}

