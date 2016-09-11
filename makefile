#compiler to use
CC = clang
# compiler flags:
# #  -g    adds debugging information to the executable file
# #  -Wall turns on most, but not all, compiler warnings
#CFLAGS = -g -Wall -I/usr/local/include
CLAGS = -g -Wall
#   
#   #files to link:
#LFLAGS = -L/usr/local/lib -lm -lgsl -lgslcblas
LFLAGS = -lm
# the name to use for both the target source file, and the output file:
TARGET = findword#
all: $(TARGET)
       
$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o a.out $(TARGET).c $(LFLAGS)

run:
	./$(TARGET)
