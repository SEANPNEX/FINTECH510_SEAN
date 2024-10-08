# Money Change
Write a Python script that scripts that implements the following:

Physical money comes in many different denominations. Write a function named
`make_change` that, for a given amount, returns a dictionary containing the
smallest number of bills and coins that add up to that number. Do not place
any entries in the dictionary that are zero.

The possible denominations are 100.00, 50.00, 20.00, 10.00, 5.00, 2.00, 1.00,
0.25, 0.10, 0.05, and 0.01.

You may assume that the amount will not be specified with a portion smaller 
than .01. For example, 10.454 will not be passed to your program, while 10.45
is a valid argument.

You will also need to write a function `print_change` that prints the change 
in order of the descending denomination and their corresponding amount. The 
parameter to this function will be the dictionary that is the result of 
`make_change`.

So that we can automatically grade programs, you must these conditions:

1. The Python file must be named `money_change.py`.
2. We will directly call your function and evaluate the result.
3. You must name/define the functions as
   ```python
   def make_change(amount):
   def print_change(change):
   ```
4. You may write other functions within your `money_change`.py as needed.
   You may find that you have duplicative code, using a function to contain
   that code may make your code easier to write. We will only call 
   `make_change()` and `print_change()` in our testing.

5. For both functions, you should provide at least a one-line docstring. 
   Just describe what the function does.

You may run into precision issues with floating-point numbers. For instance
testing the change for $0.99, may only return 3 for $0.01 rather than the
expected 4 cents.

A number of possible solutions exist:
1. Convert the amount to cents and only use the `int` types
2. Use the built-in function `round()`. Examine the help text for this.
3. Represent the data using the `Decimal` class.

To test your program, you may use `test.py`

This file will call your two functions. You may additional code 
into this file to test your work. We will not use test.py in grading your
submission.

## Sample Execution
```text
$ python3 test.py
$100.00: 4
$20.00: 2
$2.00: 1
$1.00: 1
$0.10: 2
```
