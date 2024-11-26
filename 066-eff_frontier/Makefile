CXX := g++
CXXFLAGS := -std=c++17 

TARGET := efficient_frontier

SRCS := parse.cpp parse_vec.cpp main.cpp valid.cpp

OBJS := $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

parse.o: parse.cpp parse.hpp
	$(CXX) $(CXXFLAGS) -c parse.cpp

parse_vec.o: parse_vec.cpp parse_vec.hpp
	$(CXX) $(CXXFLAGS) -c parse_vec.cpp

efficient_frontier.o: efficient_frontier.cpp parse.hpp parse_vec.hpp
	$(CXX) $(CXXFLAGS) -c efficient_frontier.cpp

clean:
	rm -f $(OBJS) $(TARGET)
