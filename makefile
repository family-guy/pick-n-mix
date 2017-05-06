TARGET = bin/runner
CC = gcc
OBJS = build/cu_test.o \
build/all_unit_tests.o \
build/str_util_test.o \
build/str_util.o \
build/grk_io_test.o \
build/grk_io.o \


INC = -I vendor/cutest-1.5 -I include
CFLAGS = -Wall -c
LFLAGS = -Wall

$(TARGET): $(OBJS) 
	$(CC) $(LFLAGS) $(INC) $(OBJS) -o $(TARGET)
	
build/cu_test.o: vendor/cutest-1.5/CuTest.c vendor/cutest-1.5/CuTest.h 
	$(CC) $(CFLAGS) $(INC) vendor/cutest-1.5/CuTest.c -o build/cu_test.o
	
build/all_unit_tests.o: test/unit/all_unit_tests.c 
	$(CC) $(CFLAGS) $(INC) test/unit/all_unit_tests.c -o build/all_unit_tests.o
	
build/str_util_test.o: test/unit/util/str_util_test.c include/str_util_test.h
	$(CC) $(CFLAGS) $(INC) test/unit/util/str_util_test.c -o \
	build/str_util_test.o
	
build/str_util.o: src/util/str_util.c include/str_util.h
	$(CC) $(CFLAGS) $(INC) src/util/str_util.c -o build/str_util.o
	
build/grk_io_test.o: test/unit/io/grk_io_test.c include/grk_io_test.h
	$(CC) $(CFLAGS) $(INC) test/unit/io/grk_io_test.c -o build/grk_io_test.o
	
build/grk_io.o: src/io/grk_io.c include/grk_io.h
	$(CC) $(CFLAGS) $(INC) src/io/grk_io.c -o build/grk_io.o
	
clean:
	\rm build/*.o $(TARGET)
	

