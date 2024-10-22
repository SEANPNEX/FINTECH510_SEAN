# Matrix Template

For this assignment, you will continue to evolve the `IntMatrix` class by
creating a templated `Matrix` class.

## Instructions
- Write a templated class `Matrix`, which works like `IntMatrix`, except for
  any type `T`, not just ints.
- Rather than using `IntArray` for each "row", use `vector<T>`.
- The new `Matrix` class should provide similar methods, constructors, 
  operators, and destructor to your `IntMatrix` class, though you may need 
  to change some types.
- As a starting point, copy the class declaration from `IntMatrix.hpp`
  into `Matrix.hpp`. As `Matrix` is a templated class, the definition must be
  written in `Matrix.hpp`. In other words, change the declarations
  to definitions.
- The stream insertion declarations have been provided in `Matrix.hpp`, you will
  need to define these methods.
- You should be able to compile and run with the provided `test.cpp` file
  without modification.

## Provided Files
| File | Purpose |
|------|---------|
| `Matrix.hpp` | Header file that contains the class definition for Matrix. Only alter this file. |
| `Makefile` | Compiles the program |
| `test.cpp` | Test driver for the program |
| `matrixTest.txt` | Expected results executing the test driver |

## Notes
This problem is primarily an exercise in working with templates, not 
designing new/complex algorithms.  You may find it easy to start with your 
`IntMatrix` code and make the required changes (which should be minimal).

Ensure your program works correctly before submission.

## Submission
Submit `Matrix.hpp` when complete to the Gradescope assignment.
