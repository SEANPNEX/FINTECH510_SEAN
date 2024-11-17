CPPFLAGS=-std=c++17 -Werror -Wall -pedantic -ggdb3 -I ../eigen_library

compile: rootmat squaremat

rootmat: rootmat.cpp
	g++  -o rootmat $(CPPFLAGS) rootmat.cpp

squaremat: squaremat.cpp
	g++  -o squaremat $(CPPFLAGS) squaremat.cpp

clean:
	rm -rf *.o *.dSYM rootmat squaremat
