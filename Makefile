CC=g++
FLAGS=-g3 -Wall
HEAD=driver.h menu.h
SRC=driver.cpp menu.cpp
EXE=frupal

VAL=valgrind
VFLAGS=--leak-check=full

all: $(HEAD)
	$(CC) $(FLAGS) $(SRC) -o $(EXE)

execute:	all
	./$(EXE)

e:	execute

flagless:
	$(CC) $(SRC) -o $(EXE)

f: flagless

valgrind:	$(EXE)
	$(VAL) $(VFLAGS) ./$(EXE)

v:	valgrind

clean:
	rm -rf $(EXE) *.o

c:	clean
