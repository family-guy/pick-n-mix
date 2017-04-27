TARGET = bin/runner
CC = gcc
OBJS = build/count_inv.o build/grkio.o build/util.o
INC = -I include
CFLAGS = -Wall -c
LFLAGS = -Wall

$(TARGET): $(OBJS) 
	$(CC) $(LFLAGS) $(INC) $(OBJS) -o $(TARGET)
	
build/count_inv.o: src/count_inv.c
	$(CC) $(CFLAGS) $(INC) src/count_inv.c -o build/count_inv.o
	
build/grkio.o: src/grkio.c include/grkio.h
	$(CC) $(CFLAGS) $(INC) src/grkio.c -o build/grkio.o
	
build/util.o: src/util.c include/util.h
	$(CC) $(CFLAGS) $(INC) src/util.c -o build/util.o

clean:
	\rm build/*.o $(TARGET)