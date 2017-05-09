/** @file str_util.h
 *  @brief Function prototypes for functions that manipulate strings.
 *
 *  @author Guy R. King (grking8@geemail.com)
 *  @date 8 May 2017
 *  @bug No known bugs.
 */

#ifndef STR_UTIL_H
#define STR_UTIL_H

#include "int_array.h"

/** @brief Parses a string containing a list of integers into an array of 
 *         integers.
 *
 *  @param The string containing the list of integers.
 *  @return The array of integers.
 */
struct int_array *parser(char *);

#endif
