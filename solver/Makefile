CC=g++
EXECUTABLE=bin/solver

# Directories
HEADERS=./include
SRC_DIR=src
OBJ_DIR=obj

CFLAGS=-c -std=c++17 -Wall -pedantic-errors -I$(HEADERS)

# Find Sources and Objects
SOURCES=$(shell find $(SRC_DIR) -type f -name '*.cpp')
OBJECTS=$(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))

# Default Target
all: $(EXECUTABLE)

# Link object files into final executable
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXECUTABLE)

# Compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $< -o $@

# Clean build files
clean:
	rm -rf $(OBJ_DIR) $(EXECUTABLE)
