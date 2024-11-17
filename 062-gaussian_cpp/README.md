# Gaussian Elimination: Solving systems of linear equations.

The Eigen library provides a set of methods for solving linear equations.
See this tutorial: https://eigen.tuxfamily.org/dox/group__TutorialLinearAlgebra.html

Write a program that takes two command-line arguments:
1. a matrix filename
2. a vector filename

The program then reads in the data from those two files, solves the system
of linear equations and prints the solution vector to standard out.

We've included a starter `main.cpp`, example data files, and a `Makefile`.

## Driver program
The driver program, gaussian, reads in files containing A and B, solves the
equation, and prints the output.

Usage: ./gaussian A.txt B.txt 

Note: The input files use the same input format as the matrix_cpp assignment.

Your code should be added to the provided source file, main.cpp.
We have provided a function that reads Eigen matrices of arbitrary dimensions.

## Example: 
For example, consider the following system of equations:
```
2x + 3y = 6
 x -  y = 1/2
```
These equations translate to the following A matrix (in file A1.txt):
```
2 2
2 3
1 -1
```

and the following B vector (in file B1.txt):
(stored as as 1 by 2 matrix)
```
1 2
6 .5
```

running './gaussian EA1.txt EB1.txt' produces:
```
1 2
1.5   1 
```

## Suggested steps: 
1. As with matrix_cpp, you may need to edit the provided Makefile to adjust 
   the Eigen pathname for your local environment.
2. While you can use the provided `read_from_file()` function to read B,
   you'll need to convert the matrix to a vector.
3. You'll need to convert the solution back into a 1 x *n* matrix.
4. Test your solver with the example given above, stored in A1.txt and B1.txt.

Once your code is complete and verified, submit your updated `main.cpp` 
to the Gradescope assignment.
