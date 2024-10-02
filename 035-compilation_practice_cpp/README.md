# Compilation Practice 

For this assignment, we have given you a number of programs that have a variety
of different issues with the source code. You need to first attempt to compile
each program and view the error message.

Copy the error messages that the compiler generates into `errors.txt`.
There should be at least one error message for each file.  Ensure you include
the full lines of the error messages. 

You then need to correct the program such that it compiles and runs correctly.

To compile:
1. open a terminal window (Terminal -> new window in VS Code menu)
2. change to the assignment directory in the terminal window
   - `pwd` - displays/prints the current(present) working directory
   - `ls` - lists the files in that directory
   - `cd <directoryName>`  - changes to that directory
   - `cd ..` - changes to the parent directory
3. To compile hello_1.cpp: `g++ -std=c++17 hello_1.cpp`

Note: do not try to simply run these in VS Code. As multiple programs with
a `main()` function exist, VS Code will show an error message.

Only copy the first error message displayed to errors.txt. 

As you compile C++ programs,  you should only focus on fixing the first 
error message, then re-compile the program.

## Submission
Submit hello_1.cpp, hello_2.cpp, hello_3.cpp, hello_4.cpp, hello_5.cpp,
       system.cpp, weight.cpp, and erorrs.txt to Gradescope.

## Sources
Adapted from Section 1.3 of 
Stroustrup, B. (2024). Programming: Principles and Practice Using C++. 
United States: Pearson Education (US).
(Note: The support for `import std;` as demonstratred in the text 
may not work for the C++ compiler installed in your environment.)
