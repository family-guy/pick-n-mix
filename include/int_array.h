/** @file int_array.h
 *  @brief @c struct definition.
 *
 *  @author Guy R. King (grking8@geemail.com)
 *  @date 8 May 2017
 *  @bug No known bugs.
 */

#ifndef INT_ARRAY_H
#define INT_ARRAY_H

/**
 *  @brief A @c struct to keep track of the length of an array of integers.
 *
 *  The usual integer array type is augmented with an array length member.
 */
struct int_array {
	int len; 
	int *A; 
};

#endif
