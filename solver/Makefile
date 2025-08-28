CC=g++
EXECUTABLE=bin/solver
SFML_INCLUDE_PATH=/home/bprevost/SFML-3.0.0/include
SFMLFLAGS=-lsfml-graphics -lsfml-window -lsfml-system
STATIC_INCLUDE_PATH=/usr/local/include
TOOLKIT_FLAG=-ltoolkit

# Directories
HEADERS=./include
SRC_DIR=src
OBJ_DIR=obj

CFLAGS=-c -std=c++17 -Wall -pedantic-errors -I$(SFML_INCLUDE_PATH) -I$(HEADERS) -I$(STATIC_INCLUDE_PATH)

# Find Sources and Objects
SOURCES=$(shell find $(SRC_DIR) -type f -name '*.cpp')
OBJECTS=$(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))

# Default Target
all: $(EXECUTABLE)

# Link object files into final executable
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXECUTABLE) -L/usr/local/lib $(TOOLKIT_FLAG) $(SFMLFLAGS)

# Compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $< -o $@

# Clean build files
clean:
	rm -rf $(OBJ_DIR) $(EXECUTABLE)
