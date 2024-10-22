# Code Investigate
This directory contains 10 small progragrams that contain various
code fragments. Some of the fragments run successfully; others produce errors. 
Study the inputs and outputs to see why. You should make the necessary
change to have each program print "Success!" to standard output.

To stop execution of a program, use 'ctrl-c'.

For each fragment:
1. Attempt to compile the program: `g++ -std=c++17 -Wall -Werror filename.cpp`
2. Correct the any coding issues as necessary.
3. In answers.txt, list which drill numbers produced these types of 
   issues: syntax errors, type errors, or infinite loops.  Each issue type
   occurs twice.

   The resulting file should look like:
   ```text
   Syntax errors: 1, 2
   Type errors: 3, 4
   Infinite loops: 5, 6
   ```
4. Once you have corrected and successfully executed each file, 
   submit all of them to Gradecope along with `answers.txt`.

Note: modifying each file to simply execute `cout << "Success!\n";` will be considered
      an academic integrity violation. Multiple ways exist to solve each 
      problem.  From a guidance perspective, do something reasonable.

## Source: 
Adapted from Chapter 4 of 
Stroustrup, B. (2024). Programming: Principles and Practice Using C++, 3rd Ed. 
United States: Pearson Education (US).