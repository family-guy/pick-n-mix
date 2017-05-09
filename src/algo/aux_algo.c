/** @file aux_algo.c
 *  @brief Function definitions for auxiliary routines used in algorithm
 * 		   implementations.
 *
 *  @author Guy R. King (grking8@geemail.com)
 *  @date 8 May 2017
 *  @see src/algo/count_inv_algo.c
 *  @bug No known bugs.
 */

#include <limits.h>

/** @brief Counts the number of split inversions by taking two adjacent sorted
 *		   continguous subarrays and combining them into a single sorted array.
 *  
 *  Sorts in-place. The subarrays are copied into new arrays before being placed
 *  back into the original array in sorted order, during which the number of 
 *  inversions is counted.
 *
 *  @param A The array of integers containing the elements to sort.
 *  @param low The left subarray's lower demarcation.
 *  @param high The right subarray's upper demarcation.
 *  @param mid The left subarray's upper demarcation.
 *  @return The number of split inversions.
 *  @see count_inv
 */
unsigned long long count_split_inv(int *A, int low, int high, int mid) {
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