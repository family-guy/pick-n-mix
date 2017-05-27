#ifndef MACROS_H
#define MACROS_H

#define PRINT_EXEC_TIME(start, func) clock_t diff = clock() - start;\
int ms = diff * 1000 / CLOCKS_PER_SEC;\
printf("%-40s%d.%ds\n", func, ms / 1000, ms % 1000);

#endif