CC=g++
FLAGS=-g3 -Wall
HEAD=driver.h pch.h
SRC=driver.cpp pch.cpp
TESTS=tests/*.cpp
EXE=frupal

VAL=valgrind
VFLAGS=--leak-check=full

all: $(HEAD)
	$(CC) $(FLAGS) $(SRC) -o $(EXE)

execute:	all
	./$(EXE)

e:	execute

# Custom Compile

menu: driver.h menu.h
	$(CC) $(FLAGS) driver.cpp menu.cpp -o $(EXE)

terrain: driver.h terrain.h
	$(CC) $(FLAGS) driver.cpp terrain.cpp -o $(EXE)

pch: driver.h pch.h
	$(CC) $(FLAGS) driver.cpp pch.cpp -o $(EXE)

tests: 
	$(CC) $(FLAGS) $(TESTS) -o tests/ALL_TESTS

flagless:
	$(CC) $(SRC) -o $(EXE)

f: flagless

valgrind:	$(EXE)
	$(VAL) $(VFLAGS) ./$(EXE)

v:	valgrind

clean:
	rm -rf $(EXE) *.o

c:	clean
