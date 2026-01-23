CC = gcc
CFLAGS = -Wall -g3
TARGET = test
ARGUMENTS = 1000

all:
	$(CC) $(CFLAGS) -o $(TARGET) test.c array.c

run:
	./$(TARGET) $(ARGUMENTS)

val-test:
	valgrind -q ./$(TARGET) $(ARGUMENTS)
