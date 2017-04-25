TARGET = bin/runner
CC = gcc
OBJS = build/count_inversions.o build/grkio.o 
INC = -I include
CFLAGS = -Wall -c
LFLAGS = -Wall

$(TARGET): $(OBJS) 
	$(CC) $(LFLAGS) $(INC) $(OBJS) -o $(TARGET)
	
build/count_inversions.o: src/count_inversions.c
	$(CC) $(CFLAGS) $(INC) src/count_inversions.c -o build/count_inversions.o
	
build/grkio.o: src/grkio.c include/grkio.h
	$(CC) $(CFLAGS) $(INC) src/grkio.c -o build/grkio.o

clean:
	\rm build/*.o $(TARGET)