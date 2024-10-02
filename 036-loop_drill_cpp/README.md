# Loop Drills

Go through this drill step by step. Do not try to speed up by skipping steps. 
Test each step by entering at least three pairs of values — more values would 
be better.

You will use a file named `loop-x.cpp` for each step, where *x* is the step number. Each step is a test in the autograder.

## Notes
- Use ctrl-c to stop the execution of a program if necessary.
- Read through the steps first before starting.

## Drills
1. Write a program that consists of a while-loop that continually reads 
   in two ints and then prints the two numbers, in the entered order, 
   on a line,  separated by a space.

   You should add a prompt message before the while loop instructing the user 
   what data to enter.  Keep this to a single line.

   Exit the program when anything besides an int is entered.

   Recall from the readings that `cin >> variable` can be used as a conditional
   expression that evaluates true if a value was read correctly or false otherwise.  
   Multiple variables may be included in a single, compound expression. 

   - Use loop-1.cpp as the starting point.
   - To compile: `g++ -std=c++17 loop-1.cpp`
   - Execute: `./a.out`
   - Validate your program works with a variety of inputs
 

2. Change the program to print to standard output:
   ```
   the smaller value is: value
   the larger value is: value
   ```
   Copy `loop-1.cpp` to a new file: `cp loop-1.cpp loop-2.cpp`

   Follow the above pattern to compile, execute, and manually validate the program.
 

3. Augment the program to write the line "the numbers are equal" (only) 
   if they are equal.

   - copy `loop-2.cpp` to a new file - `loop-3.cpp`
   - Follow the above pattern to compile, execute, and manually validate the program.
 

4. Change the program so that it uses doubles instead of ints.

   As with ints, `cin >> variable` will fail if an invalid double is entered.

   - copy `loop-3.cpp` to `loop-4.cpp`
   - Make the necessary code changes.
   - Compile, execute, and manually validate the program.
 
5. Change the program so that it writes out "the numbers are almost equal"  
   after writing out which is the larger and the smaller if the two numbers 
   differ by less than 1.0/100.  You may need to alter your logic in the if statements.

   - Copy `loop-4.cpp` to `loop-5.cpp`
   - Make the necessary code changes.
   - Compile, execute, and manually validate the program.
 
6. Now, change the loop's body to read just one double for each loop.

   Define two variables to keep track of which is the smallest and which 
   is the largest value read so far. For each loop iteration, write out 
   the value entered. If it’s the smallest so far, write " smallest so far" 
   after the number. If it is the largest so far, write the " largest so far" 
   after the number. Only one newline should be printed for each loop.

   ```
   std::numeric_limits<double>::max()
   std::numeric_limits<double>::min()
   ```
   provide values for the largest possible double and the smallest possible double.

   - Use `loop-6.cpp` for your program.
   - Make the necessary code changes.
   - Compile, execute, and manually validate the program.
 
7. Add a unit to each double entered; that is, enter values such as
   10 cm, 2.5 in, 5 ft, or 3.33 m. Accept the four units: cm, m, in, ft. 
   Use these conversion factors:
   ```
   1m == 100cm
   1in == 2.54cm
   1ft == 12in
   ```
   Read the unit indicator into a string. Consider 12 m (with a space 
   between the number and the unit) equivalent to 12m (without a space). 

   So the user needs to enter a number, followed by some whitespace, and then the unit.
   
   Print the value immediately followed by the entered unit in the loop. 
   As before, you need to continue to state whether or not it is the smallest or largest value.
   
   You may want to create a function to perform the conversions.
   
   - Use `loop-7.cpp` for your program.
   - Make the necessary code changes.
   - Compile, execute, and manually validate the program.
 
   	Sample:
      ```
      Enter a double value followed by a space then a unit (cm,m,in,ft):
      5 ft
      5ft smallest so far largest so far
      5 cm
      5cm smallest so far
      5 in
      5in
      5m
      5m largest so far
      ```


8. Reject values without units or with “illegal” representations of units, 
   such as y, yard, meter, km, and gallons.
   
   Print "bad unit: <unit>" to the standard output and repeat the loop
 
   - Use `loop-8.cpp` for your program.
   - Make the necessary code changes.
   - Compile, execute, and manually validate the program.
   

9. Now, add the ability to keep track of the sum of values entered and 
   the number of values entered. When the loop ends, print the following:
   ```
   smallest: value
   largest:  value
   number: number
   sum: number
   ```
   Note that to keep the sum, you must decide on a unit to use for 
   that sum; use meters. Assume at least one valid entry has been made.
   Only count valid values for the number of values entered.

   - Use `loop-9.cpp` for your program.
   - Make the necessary code changes.
   - Compile, execute, and manually validate the program.
 
10. Now, add the ability to Keep all the values entered (converted into meters) 
    in a vector. At the end, write out those values after the output from #9.

    Each value should be on its own line.
 
    - Use `loop-10.cpp` for your program.
    - Make the necessary code changes.
    - Compile, execute, and manually validate the program.
 
11. Before writing out the values from the vector, sort them in increasing order.  
    See section 3.6.3 in PPP or the [Vectors Notebook](https://fintechpython.pages.oit.duke.edu/jupyternotebooks/3-CPlusCPlus/07-Vectors/07-Vectors.html) for examples.
    - Use loop-11.cpp for your program.
    - Make the necessary code changes.
    - Compile, execute, and manually validate the program.

Once you have completed a step, you may want to submit your completed drill source code files to Gradescope for evaluation.

## Submission
Once you have completed all of the steps, submit the 11 drill files to Gradescope.


## Source
Adapted from Chapter 3 / Drill of 
Stroustrup, B. (2024). Programming: Principles and Practice Using C++, 3rd Ed. 
United States: Pearson Education (US).

 