CC = g++
FLAGS = -lcurses -g3 -Wall -std=c++11

HEAD = $(filter-out tests/*.h, $(wildcard *.h)  $(wildcard */*.h))
SRC = $(filter-out tests/terrain_tests.cpp, $(wildcard *.cpp)  $(wildcard */*.cpp))

TEST_HEAD = $(wildcard *.h)  $(wildcard */*.h)
TEST_SRC := $(wildcard *.cpp)  $(wildcard */*.cpp)

EXE = frupal
TEST_EXE = tests/ALL_TESTS

VAL=valgrind
VFLAGS=--leak-check=full

a: all
all: $(HEAD)
	$(CC) $(FLAGS) $(SRC) -o $(EXE)

c: clean
clean:
	rm -rf $(EXE) $(TEST_EXE) *.o

e:	execute
execute: all
	./$(EXE)

f: flagless
flagless:
	$(CC) $(SRC) -o $(EXE)

t: test
test:	all
	$(CC) $(FLAGS) $(TESTS) -o $(TEST_EXE)

v:	valgrind
valgrind:	$(EXE)
	$(VAL) $(VFLAGS) ./$(EXE)
