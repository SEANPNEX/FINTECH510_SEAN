# Matrix

"Eigen is a C++ template library for linear algebra: matrices, vectors, numerical 
solvers, and related algorithms."
 - https://eigen.tuxfamily.org/

Like NumPy in the Python ecosystem, the Eigen library supports linear algebra 
operations, including those needed for the efficient frontier assignment. 

## Eigen Installation
We have provided a copy of Eigen within the student repository under the 
directory `eigen_library`.  To reference this location, you will need to 
add another compilation flag when you compile your program: -I *library_location*
```bash
g++ -std=c++17 -Wall -Werror --pedantic -ggdb3 -I ../eigen_library program.cpp
```
The provided Makefile has this library flag added. You can also add this flag
to `.vscode/tasks.json` under the `args` array.
```json
"args": [
    "-std=c++17",
    "-I",
    "..eigen_library",
    "-fdiagnostics-color=always",
    "-g",
    "*.cpp",
    "-o",
    "${fileDirname}/${fileBasenameNoExtension}"
],
```

You can also install Eigen "permanently" into your environment (i.e, laptop).
Such an install allows the package to be used more easily across multiple
projects without worrying about the specific library location.
```bash
cd /tmp/
wget https://gitlab.com/libeigen/eigen/-/archive/3.4.0/eigen-3.4.0.tar.gz
tar xvf eigen-3.4.0.tar.gz
cd eigen-3.4.0
sudo cp -R Eigen /usr/local/include
cd /tmp
rm -rf eigen-3.4.0*
```

Technically, Eigen is 100% implemented in header (include) files, and as such, 
you could simply copy the Eigen folder from a release into your project folder. 
In this scenario, you would use `#include "Eigen/Dense"` to include the library 
in your code.


## Instructions
Read [Getting Started](https://eigen.tuxfamily.org/dox/GettingStarted.html) at
the Eigen documentation site.

Once Eigen is set up,  write the following programs:

1. `squaremat.cpp` that squares each element of a two-dimensional matrix.
2. `rootmat.cpp` that computes the square root of each element of a two-dimensional matrix.

Both programs read their input from standard input (i.e., `cin`) and write their output
to standard output (i.e., `cout`).

## File Format
Both the input and output need to follow this format:

The first line contains the number of rows, whitespace, and then the number of columns
Each additional line contains the data for that respective row in the matrix
where the columns are separated by whitespace.  

For example, a two-by-two matrix is represented by the following:
```
2 2
1 2
3 4
```

## Testing
One way you can test your programs is to "pipe" the results of one program into the second.
The result should be the original input matrix.
```
./rootmat < example.txt | ./squaremat 
```


## Notes
- You may find it helpful to compile and run the 'first program' example on the
  [Getting Started](https://eigen.tuxfamily.org/dox/GettingStarted.html) page 
  to validate your setup.
- We have provided three input files: 1x1.txt, 2x2.txt, and 10x20.txt
- Each associated output either has a .root or a .square suffix.
- Use `double` as the type.
- You should not need to write your own code to iterate over the matrix.
- Eigen provides a `sqrt()` function on the Array object. Matrices can be 
  converted to Array with '.array()'
- The next assignment provides sample code to read a matrix from a file.

## Examples:
```
./squaremat < 2x2.txt
2 2
 1  4 
 9  16  
```


```
./squaremat.exe < 2x2.txt | ./rootmat.exe
2 2
1 2 
3 4  
```

## Submission
Once you have validated your programs, submit `rootmat.cpp` and `squaremat.cpp` 
to the Gradescope assignment.  The grader assumes your program includes
Eigen as a system library (i.e., `#include <Eigen/Dense>`).
