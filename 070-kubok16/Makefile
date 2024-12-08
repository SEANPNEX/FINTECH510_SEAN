# Compiler
CXX = g++

# Compiler Flags
CXXFLAGS = -Wall -Wextra -O2 -std=c++17

# Target executable name
TARGET = kubok

# Source files
SRCS = main.cpp parse.cpp solver.cpp

# Object files (same as SRCS but with .o extensions)
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Link the object files to create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile each .cpp file into an object file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets
.PHONY: all clean
