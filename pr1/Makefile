CC = gcc
CFLAGS = -Wall
OBJ = main.o input.o output.o process1.o process2.o utility.o
program: $(OBJ)
	$(CC) -o $@ $^
main.o process1.o utility.o: process1.h
input.o process2.o: list.h
clean:
	rm -f *.o program
