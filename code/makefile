SRC         = ./src
INCLUDE     = ./include
OBJ         = ./obj
COMPILE     = gcc
OTHER_FLAGS = -std=c11 -Wall
EXE         = ./main

all: queue stack list tree getch functions_aux main

main:
	$(COMPILE) $(SRC)/main.c $(OBJ)/*.o -o $(EXE) $(OTHER_FLAGS)

queue:
	$(COMPILE) -c $(SRC)/queue.c -o $(OBJ)/queue.o $(OTHER_FLAGS)

stack:
	$(COMPILE) -c $(SRC)/stack.c -o $(OBJ)/stack.o $(OTHER_FLAGS)

list:
	$(COMPILE) -c $(SRC)/doublyLinkedList.c -o $(OBJ)/doublyLinkedList.o $(OTHER_FLAGS)

tree:
	$(COMPILE) -c $(SRC)/binaryTree.c -o $(OBJ)/binaryTree.o $(OTHER_FLAGS)

getch:
	$(COMPILE) -c $(SRC)/getch.c -o $(OBJ)/getch.o $(OTHER_FLAGS)

functions_aux:
	$(COMPILE) -c $(SRC)/functionsAux.c -o $(OBJ)/functionsAux.o $(OTHER_FLAGS)

compile_windows: queue stack list tree functions_aux
	$(COMPILE) $(SRC)/main.c $(OBJ)/queue.o $(OBJ)/stack.o $(OBJ)/doublyLinkedList.o $(OBJ)/binaryTree.o $(OBJ)/functionsAux.o -o $(EXE) $(OTHER_FLAGS)

run:
	$(EXE)

comp_run: all run

re_comp_run: clean comp_run

comp_run_win: compile_windows run
	
runS:
	$(EXE) -suits=on

runGM:
	$(EXE) -gm=on

runGMS:
	$(EXE) -gm=on -suits=on

clean:
	rm $(OBJ)/*
	rm $(EXE)
