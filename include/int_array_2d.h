/** @file int_array_2d.h
 *  @brief @c struct definition.
 *
 *  @author Guy R. King (grking8@geemail.com)
 *  @date 15 May 2017
 *  @bug No known bugs.
 */

#ifndef INT_ARRAY_2D_H
#define INT_ARRAY_2D_H

/**
 *  @brief A @c struct to keep track of the dimensions of a two dimensional 
 *         array of integers.
 *
 *  The usual implementation of a two dimensional array is augmented with the
 *  number of rows and columns.
 */
struct int_array_2d {
	int rows;
	int cols; 
	int **A; 
};

#endif
