CC = g++
FLAGS = -Iinclude -std=gnu++17 -Wall -Wextra -pedantic-errors

INC = include
OBJ = obj/Debug
SRC = src
BIN = bin/Debug

# Removed: Scalar.o, Node_T.o, Ordered_Set.o

# Overall output
$(BIN)/Physics: $(OBJ)/src/Matrix.o $(OBJ)/src/PhysVector.o $(OBJ)/src/Numerical.o $(OBJ)/src/PhysExcept.o $(OBJ)/main.o
	$(CC) -o $(BIN)/Physics $(OBJ)/src/Matrix.o $(OBJ)/src/PhysVector.o $(OBJ)/src/Numerical.o $(OBJ)/src/PhysExcept.o $(OBJ)/main.o $(FLAGS)

# Each obj file
$(OBJ)/main.o: main.cpp
	$(CC) -o $(OBJ)/main.o main.cpp $(FLAGS) -c
$(OBJ)/src/Matrix.o: $(SRC)/Matrix.cpp
	$(CC) -o $(OBJ)/src/Matrix.o $(SRC)/Matrix.cpp $(FLAGS) -c
$(OBJ)/src/PhysVector.o: $(SRC)/PhysVector.cpp
	$(CC) -o $(OBJ)/src/PhysVector.o $(SRC)/PhysVector.cpp $(FLAGS) -c
$(OBJ)/src/Numerical.o: $(SRC)/Numerical.cpp
	$(CC) -o $(OBJ)/src/Numerical.o $(SRC)/Numerical.cpp $(FLAGS) -c
$(OBJ)/src/PhysExcept.o: $(SRC)/PhysExcept.cpp
	$(CC) -o $(OBJ)/src/PhysExcept.o $(SRC)/PhysExcept.cpp $(FLAGS) -c
