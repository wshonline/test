# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall

# the build target executable:
TARGET1 = nyush

all:
	$(CC) $(CFLAGS) -o $(TARGET1) $(TARGET1).c

clean:
	$(RM) $(TARGET1)