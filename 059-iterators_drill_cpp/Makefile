# Makefile for compiling drill.cpp

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++17

# Target executable
TARGET = drill

# Source file
SRC = drill.cpp

# Default target
all: $(TARGET)

# Compile target
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

# Clean up generated files
clean:
	rm -f $(TARGET)
