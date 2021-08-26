CC = g++
FLAGS = -Iinclude -std=gnu++17 -Wall -Wextra -pedantic-errors

INC = include
OBJ = obj/Debug
SRC = src
BIN = bin/Debug

# Overall output
$(BIN)/Physics: $(OBJ)/src/Matrix.o $(OBJ)/src/PhysVector.o $(OBJ)/src/Scalar.o $(OBJ)/src/Node_T.o $(OBJ)/src/Ordered_Set.o $(OBJ)/main.o
	$(CC) -o $(BIN)/Physics $(OBJ)/src/Matrix.o $(OBJ)/src/PhysVector.o $(OBJ)/src/Scalar.o $(OBJ)/src/Node_T.o $(OBJ)/src/Ordered_Set.o $(OBJ)/main.o $(FLAGS)

# Each obj file
$(OBJ)/main.o: main.cpp
	$(CC) -o $(OBJ)/main.o main.cpp $(FLAGS) -c
$(OBJ)/src/Matrix.o: $(SRC)/Matrix.cpp
	$(CC) -o $(OBJ)/src/Matrix.o $(SRC)/Matrix.cpp $(FLAGS) -c
$(OBJ)/src/PhysVector.o: $(SRC)/PhysVector.cpp
	$(CC) -o $(OBJ)/src/PhysVector.o $(SRC)/PhysVector.cpp $(FLAGS) -c
$(OBJ)/src/Scalar.o: $(SRC)/Scalar.cpp
	$(CC) -o $(OBJ)/src/Scalar.o $(SRC)/Scalar.cpp $(FLAGS) -c
$(OBJ)/src/Node_T.o: $(SRC)/Node_T.cpp
	$(CC) -o $(OBJ)/src/Node_T.o $(SRC)/Node_T.cpp $(FLAGS) -c
$(OBJ)/src/Ordered_Set.o: $(SRC)/Ordered_Set.cpp
	$(CC) -o $(OBJ)/src/Ordered_Set.o $(SRC)/Ordered_Set.cpp $(FLAGS) -c
