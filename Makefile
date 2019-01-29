CC=g++
FLAGS=-g3 -Wall
HEAD=*.h
SRC=*.cpp
EXE=frupal

VAL=valgrind
VFLAGS=--leak-check=full

all: $(HEAD)
	$(CC) $(FLAGS) $(SRC) -o $(EXE)

e:	all
	./$(EXE)

f:
	$(CC) $(SRC) -o $(EXE)

v:	$(EXE)
	$(VAL) $(VFLAGS) ./$(EXE)

clean:
	rm -rf $(EXE) *.o
