CXX = g++
EXEC = main
CXXFLAGS = -MMD -MP -Wall -pedantic $(flag) -std=c++14
LIBS = -lm

SRC=$(wildcard *.cpp)
OBJS=$(SRC:.cpp=.o)
DEPS=$(SRC:.cpp=.d)

$(EXEC): $(OBJS) 
	$(CXX) $+ $(LIBS) -o $@

.PHONY: clean

clean:
	rm -f *.o
	rm -f *.txt
	rm -f *.d
	rm -f $(EXEC)

-include $(DEPS)