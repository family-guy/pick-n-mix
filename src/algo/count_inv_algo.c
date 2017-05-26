/** @file count_inv_algo.c
 *  @brief Function definitions for count inversion algorithms.
 *
 *  Each function implements an algorithm to count the number of inversions in 
 *  an array of integers. Let A be an array. An inversion is a pair of indices 
 *  i,j such that i<j, A[i]>A[j]. Functions may rely on auxiliary functions.
 *
 *  @author Guy R. King (grking8@geemail.com)
 *  @date 8 May 2017
 *  @see src/algo/aux_algo.c
 *  @bug No known bugs.
 */

#include "aux_algo.h"

/** @brief Counts the number of inversions in an array of integers using merge 
 *         sort.
 *  
 *  Inversions are grouped into left, right, and split inversions. Left (right)
 *  inversions are those contained in the left (right) array, split inversions
 *  are those with one element in the left array and one in the right array. 
 *  Demarcations are inclusive.
 *
 *  @param A The array of integers to count the number of inversions for.
 *  @param low The subarray's lower demarcation.
 *  @param high The subarray's upper demarcation.
 *  @return The number of inversions.
 *  @see count_split_inv
 */
unsigned long long count_inv_ms(int *A, int low, int high) {
	if (low == high) {
		return 0;
	}
	int mid = (low + high) / 2;
	unsigned long long left_invs = count_inv_ms(A, low, mid);
	unsigned long long right_invs = count_inv_ms(A, mid + 1, high);
	
	unsigned long long split_invs = count_split_inv(A, low, high, mid);
	
	return left_invs + right_invs + split_invs;
}
