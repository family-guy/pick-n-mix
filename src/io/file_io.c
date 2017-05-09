/** @file file_io.c
 *  @brief Function definitions for file I/O routines.
 *
 *  @author Guy R. King (grking8@geemail.com)
 *  @date 8 May 2017
 *  @bug No known bugs.
 */

#include <stdio.h>
#include <stdlib.h>

/** @brief Reads the contents of a text file into a string.
 *  
 *  If there is not enough memory to read in the contents of the file, an error
 *  message is displayed before exiting the function.
 *
 *  @param path The text file's path.
 *  @return The string containing the file's contents.
 */
char *read_file(const char *path) {
	FILE *fp = fopen(path, "r"); // file pointer
	int block_size = 1024; // in bytes
	int blocks = 1;
	
	char *buf;
	buf = malloc(block_size * blocks); 

	if (buf == NULL) {
		fprintf(stderr, "Error - unable to allocate required memory.\n");
		exit(1);
	}
	
	int c;
	int i = 0;

	while ((c = fgetc(fp)) != EOF) {
		if (i == blocks * block_size) { // one char is size one byte
			blocks++;
			buf = realloc(buf, block_size * blocks);
			if (buf == NULL) {
				fprintf(stderr, "Error - unable to allocate required 				memory.\n");
				exit(1);
			}
		}
		buf[i] = c;
		i++;
	}
	fclose(fp);
	buf[i] = '\0';
	free(buf);
	return buf;
}
