/** @file sort_algo.c
 *  @brief Function definitions for sorting algorithms.
 *
 *  Each function implements an algorithm to sort an array of integers.
 *
 *  @author Guy R. King (grking8@geemail.com)
 *  @date 21 May 2017
 *  @see include/int_array.h
 *  @bug No known bugs.
 */

#include "int_array.h"

/** @brief Sorts an array of integers into ascending order in-place using bubble
 *         sort.
 *
 *  Pairs of elements are compared and swapped until the correct order is
 *  reached.
 *
 *  @param A_prime The array to sort.
 *  @return Void.
 *  @see int_array
 */
void sort_bubble(struct int_array *A_prime) {
	int swap = 1;
	while (swap) {
		swap = 0;
		for (int i = 0; i < A_prime->len - 1; i++) {
			if (A_prime->A[i] > A_prime->A[i + 1]) {
				swap = 1;
				int tmp = A_prime->A[i];
				A_prime->A[i] = A_prime->A[i + 1];
				A_prime->A[i + 1] = tmp;
			}
		}
	}
}

/** @brief Sorts an array of integers into ascending order in-place using
 *         insertion sort.
 *
 *  Sorts incrementally by each time adding an element to a sorted subarray of n
 *  elements to create a sorted subarray of n+1 elements.
 *
 *  @param A_prime The array to sort.
 *  @return Void.
 *  @see int_array
 */
void sort_ins(struct int_array *A_prime) {
	for (int i = 1; i < A_prime->len; i++) {
		int j = i - 1;
		int val_to_ins = A_prime->A[i];
		while (j >= 0 && A_prime->A[j] > val_to_ins) {
			A_prime->A[j + 1] = A_prime->A[j];
			j--;
		}
		A_prime->A[j + 1] = val_to_ins;
	}
}