/** @file aux_algo.c
 *  @brief Function definitions for auxiliary routines used in algorithm
 *         implementations.
 *
 *  @author Guy R. King (grking8@geemail.com)
 *  @date 8 May 2017
 *  @see src/algo/count_inv_algo.c
 *  @see src/algo/max_subarray_algo.c
 *  @bug No known bugs.
 */

#include <limits.h>
#include <stdlib.h>

/** @brief Counts the number of split inversions by taking two adjacent sorted
 *         continguous subarrays and combining them into a single sorted array.
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
 *  @see count_inv_ms
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

/** @brief Finds the maximum subarray with at least one element in the left 
 *         array and at least one element in the right array.
 *  
 *  Considers the solution subarray as the union of two subarrays, one 
 *  contained in the left array, the other contained in the right array. Uses 
 *  the contiguity of the solution subarray.
 *
 *  @param A The array of integers.
 *  @param low The left subarray's lower demarcation.
 *  @param mid The left subarray's upper demarcation.
 *  @param high The right subarray's upper demarcation.
 *  @return The maximum crossing subarray.
 *  @see max_subarray_dc
 */
int *max_subarray_cross(int *A, int low, int mid, int high) {
	int *result = calloc(3, sizeof(int));
	int left_sum = INT_MAX * (-1);
	int sum = 0;
	int max_left = -1;
	for (int i = mid; i >= low; i--) {
		sum += A[i];
		if (sum > left_sum) {
			left_sum = sum;
			max_left = i;
		}
	}
	int right_sum = INT_MAX * (-1);
	sum = 0;
	int max_right = -1;
	for (int i = mid + 1; i <= high; i++) {
		sum += A[i];
		if (sum > right_sum) {
			right_sum = sum;
			max_right = i;
		}
	}
	result[0] = max_left;
	result[1] = max_right;
	result[2] = left_sum + right_sum;
	return result;
}





