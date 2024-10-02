# Hello C++

Your goal in this assignment is to compile and run the provided C++ program in your development environment. 

>The only way to learn a new programming language is by writing programs in it. 
>The first program is the same for all languages: Print the words 'hello, world' 
>
>This is the big hurdle; to leap over it you have to be able to create the program text somewhere,
>compile it successfully, load it, run it, and find out where your output went.
>
>    -- 'The C Programming Language', Kernigan and Ritchie

You need to create a file, hello.cpp, containing the following C++ code:

```c++
#include <iostream>
using namespace std;

int main() {
    cout << "Hello, World!\n";
    return 0;
}
```

To compile:
1. open a terminal window (Terminal -> new window in VS Code menu)
2. change to the assignment directory in the terminal window
   - `pwd` - displays/prints the current(present) working directory
   - `ls` - lists the files in that directory
   - `cd <directoryName>`  - changes to that directory
   - `cd ..` - changes to the parent directory
3. To compile hello.cpp: `g++ -std=c++17 hello.cpp`

To use the run icon in VS Code:
1. On Windows, ensure you are using WSL or Docker
2. Select the run icon in the upper right-hand corner
3. For the configuration, use "C/C++: g++ build and debug active file"
4. On MacOS, you may need to give permissions so that the process can access the documents folder
5. The output will show in the "Debug Console"
6. You may need to specify a specific version of C++ to use.
   In the root folder that you used to open VS Code, a .vscode directory exist 
   with a tasks.json file.  Open tasks.json.  Inside that file, find the task 
   that has a "type" of "cppbuild".  Under "args", add the following line to the
   start of the array: `-std=c++17`

## Notes:
1. Rather than using an `import` statement such as in Python, C++ uses the   
   `#include` directive to bring the contents of another file into the 
   current file before compilation. These includes allow us to access code
   written in other files or libraries. The `iostream` library is part
   of the C++ Standard Library and allows programs to perform input and 
   output operations similar to `input()` and `print()` in Python.

   If you are reading PPPv2, Stroustrup utilizes a `std_lib_facilities.h` 
   that has this include directive as well as the next statement.

   In PPPv3, Stroustrup uses `import std;` which may not be supported in
   the version of the C++ compiler that you (and the class are using).

2. The `using namespace std` line instructs the compiler to use the 
   standard namespace,  `std`.  This namespace contains common C++ standard 
   library features like cout, cin, and string. By using this statement, you 
   don't need to prefix standard library objects with std::, making the code 
   easier to read in some cases. (The counter-argument for readability comes
   in when you have a large code base, prefixing objects  clarifies their
   source.)  You can also  tell the compiler to use specific
   objects within the names, such as `using std::cout;`

3. C, C++, and Java all utilize the concept of a `main` function, which 
   defines the entry point into a program. For Python, this would be
   the `if __name__ == "main":` code block.

4. To output data to the console, we use the `<<` operator (stream insertion,
   output) to send data to the standard output, represented by `cout`.

5. `return 0;` returns 0 (i.e., "success" to the calling environment.)

## Submission
Once you have succeeded in creating, compiling, and running the code in your environment, 
submit your 'hello.cpp' file to the Gradescope assignment for evaluation.

