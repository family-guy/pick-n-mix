TARGET = bin/runner
CC = gcc
OBJS = build/all_util_tests.o build/cu_test.o build/str_util_test.o build/str_util.o
INC = -I vendor/cutest-1.5 -I include
CFLAGS = -Wall -c
LFLAGS = -Wall

$(TARGET): $(OBJS) 
	$(CC) $(LFLAGS) $(INC) $(OBJS) -o $(TARGET)
	
build/all_util_tests.o: test/unit/util/all_util_tests.c 
	$(CC) $(CFLAGS) $(INC) test/unit/util/all_util_tests.c -o build/all_util_tests.o
	
build/cu_test.o: vendor/cutest-1.5/CuTest.c vendor/cutest-1.5/CuTest.h 
	$(CC) $(CFLAGS) $(INC) vendor/cutest-1.5/CuTest.c -o build/cu_test.o
	
build/str_util_test.o: test/unit/util/str_util_test.c include/str_util_test.h
	$(CC) $(CFLAGS) $(INC) test/unit/util/str_util_test.c -o build/str_util_test.o
	
build/str_util.o: src/util/str_util.c include/str_util.h
	$(CC) $(CFLAGS) $(INC) src/util/str_util.c -o build/str_util.o
	
clean:
	\rm build/*.o $(TARGET)
	

