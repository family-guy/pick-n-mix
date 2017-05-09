/** @file file_io.h
 *  @brief Function prototypes for file I/O routines.
 *
 *  @author Guy R. King (grking8@geemail.com)
 *  @date 8 May 2017
 *  @bug No known bugs.
 */

#ifndef FILE_IO_H
#define FILE_IO_H

/** @brief Reads the contents of a text file into a string.
 *
 *  @param The text file's path.
 *  @return The string containing the file's contents.
 */
char *read_file(const char *);

#endif
