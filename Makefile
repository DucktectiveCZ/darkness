# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++20 -Wall -I./include

# Linker flags
LDFLAGS = -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf -lspdlog -lfmt

# Source files and directories
SRC_DIR = src
INCLUDE_DIR = include
BIN_DIR = bin

# Find all .cpp files in the src directory
SRC = $(wildcard $(SRC_DIR)/*.cpp)

# Object files generated from the source files
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(BIN_DIR)/%.o)

# Executable name
TARGET = $(BIN_DIR)/my_game

# Build the executable
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) -o $@ $^ $(LDFLAGS)

# Compile source files
$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(BIN_DIR)/*.o $(TARGET)

.PHONY: all clean
