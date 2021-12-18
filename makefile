# *-* Makefile *-*
OBJS = main.cpp game.cpp
CC = g++
COMPAILER_FLAGS = -std=c++17 -pedantic-errors -Wall -Werror -Weffc++ -Wextra -Wsign-conversion
LINKER_FLAGS = -lSDL2 -lSDL2_image
OBJ_NAME = spaceShip
all: $(OBJS)
	$(CC) $(OBJS) $(COMPAILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)