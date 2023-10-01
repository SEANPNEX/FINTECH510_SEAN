# Triangles
Open the triangles.cpp file you have in this directory.
You will see two functions:  `printTriangle` and `main`.

The `printTriangle` function has an algorithm written as comments, but without code.
Translate this algorithm to code.

`main` contains three output statements which print out a triangle
with height 4, and the total number of stars in that triangle (returned
by the `printTriangle` function).

`main` also contains a comment asking you to write a few more statements
to do the same thing for a triangle of height 7.
Add the code to do this.

When you have done this, compile your program: `g++ -std=c++17 -o triangles triangles.cpp`

You can then execute your program: `./triangles`

You can also re-directed the output of your program to a file by using the ">"
operator in the command-line:
```
./triangles > mine.txt
``` 

You can then compare your output to the expected output with the 
command "diff". To see more details on how run diff, execute: `man diff`
```
    diff expected.txt mine.txt
```
expected.txt and mine.txt should be in the same directory. If not, 
you must use the correct relative or absolute pathnames.

If the files are the same, nothing will be printed to the console.

Once your output is correct, submit your triangles.cpp to Gradescope.
