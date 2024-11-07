CPPFLAGS=-Wall -Werror -std=c++17 -pedantic -ggdb3
SRCS=$(wildcard *.cpp)
OBJS=$(patsubst %.cpp, %.o, $(SRCS))
PROGRAM=test

$(PROGRAM): $(OBJS)
	g++ $(CPPFLAGS) -o $@ $(OBJS)

%.o: %.cpp circle.hpp
	g++ -c $(CPPFLAGS) $<

.PHONY: clean
clean:
	rm -f $(OBJS) $(PROGRAM) *~
