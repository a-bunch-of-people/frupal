CC=g++
FLAGS=-g3 -Wall -std=c++11

HEAD=driver.h pch.h
SRC=driver.cpp pch.cpp utilities/*.cpp
TESTS=tests/*.cpp terrain/*.cpp utilities/*.cpp

TEST_EXE=tests/ALL_TESTS
EXE=frupal

VAL=valgrind
VFLAGS=--leak-check=full

all: $(HEAD)
	$(CC) $(FLAGS) $(SRC) -o $(EXE)

execute:	all
	./$(EXE)

e:	execute

terrain: driver.h terrain/terrain.h
	$(CC) $(FLAGS) driver.cpp utilities/utilities.cpp terrain/terrain.cpp -o $(EXE)

test:
	$(CC) $(FLAGS) $(TESTS) -o $(TEST_EXE)

flagless:
	$(CC) $(SRC) -o $(EXE)

f: flagless

valgrind:	$(EXE)
	$(VAL) $(VFLAGS) ./$(EXE)

v:	valgrind

clean:
	rm -rf $(EXE) $(TEST_EXE) *.o

c:	clean
