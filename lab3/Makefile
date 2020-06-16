SRC = $(wildcard *.cpp)
HEADERS = $(wildcard *.h)
OBJ := $(patsubst %.cpp,%.o,$(SRC))
CC = g++
CXXFLAGS = -Wall -pedantic

main: $(OBJ) $(HEADERS)
	$(CC) $(CXXFLAGS) $(OBJ) -o main

clean:
	rm *.o main

run: main
	./main

all: main run

check: main 
	valgrind ./main

.PHONY: clean run all check

