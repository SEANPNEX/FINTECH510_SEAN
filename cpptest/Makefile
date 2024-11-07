# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -pedantic -std=c++17 -Wall -Wextra -Werror -ggdb3

# Target executable
TARGET = myprogram

# Source files
SOURCES = print.cpp

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Default target
all: $(TARGET)

# Rule to create the target executable
$(TARGET): $(OBJECTS)
    $(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)

# Rule to create object files
%.o: %.cpp
    $(CXX) $(CXXFLAGS) -c $< -o $@

# Clean target
clean:
    rm -f $(TARGET) $(OBJECTS)