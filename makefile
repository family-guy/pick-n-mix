TARGET = bin/runner
CC = gcc
OBJS = build/count_inv.o build/grkio.o build/str_util.o build/test_count_inv.o
INC = -I include
CFLAGS = -Wall -c
LFLAGS = -Wall

$(TARGET): $(OBJS) 
	$(CC) $(LFLAGS) $(INC) $(OBJS) -o $(TARGET)
	
build/count_inv.o: src/algo/count_inv.c include/count_inv.h
	$(CC) $(CFLAGS) $(INC) src/algo/count_inv.c -o build/count_inv.o
	
build/grkio.o: src/io/grkio.c include/grkio.h
	$(CC) $(CFLAGS) $(INC) src/io/grkio.c -o build/grkio.o
	
build/str_util.o: src/util/str_util.c include/str_util.h
	$(CC) $(CFLAGS) $(INC) src/util/str_util.c -o build/str_util.o
	
build/test_count_inv.o: test/count-inv/test_count_inv.c
	$(CC) $(CFLAGS) $(INC) test/count-inv/test_count_inv.c -o build/test_count_inv.o

clean:
	\rm build/*.o $(TARGET)