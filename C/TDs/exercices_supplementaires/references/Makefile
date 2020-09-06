###
# Make changes in this section if you use this Makefile for another source file.
# The source file:
SRC = const.cpp
### 

# The compiler we use:
CC = g++

# Flags to give to the compiler:
CFLAGS = -Wall -pedantic-errors -std=c++14

# the binary will have the same name as the source file, without extension:
BIN = $(patsubst %.cpp,%,$(SRC))

default:
	$(CC) $(CFLAGS) -o $(BIN) $(SRC)

clean:
	-rm -f $(BIN)

# We have to tell make that "clean" isn't a filename:
.PHONY: clean
