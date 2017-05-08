#include <limits.h>

unsigned long long count_inv_aux(int *A, int low, int high, int mid) {
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
	
	return split_invs;
}