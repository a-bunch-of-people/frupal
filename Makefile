CC=g++
FLAGS=-g3 -Wall -std=c++11

HEAD=*.h terrain/*.h utilities/*.h
SRC=*.cpp character/player/*.cpp character/*.cpp terrain/*.cpp utilities/*.cpp
TESTS=tests/*.cpp $(SRC)

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

pch: driver.h terrain/terrain.h utilities/utilities.h pch.h
	$(CC) $(FLAGS) driver.cpp utilities/utilities.cpp terrain/terrain.cpp pch.cpp -o $(EXE)

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
