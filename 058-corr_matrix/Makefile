CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

SRCS = main.cpp parse.cpp Matrix.cpp
OBJS = $(SRCS:.cpp=.o)

TARGET = correl_matrix

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)
	chmod +x $(TARGET)


%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean


