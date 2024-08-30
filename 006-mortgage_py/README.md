# Mortgage Calculator

Write a Python script that scripts that implements 
[Exercise #3 from the notebook "05-BasicInputAndOutput"](https://fintechpython.pages.oit.duke.edu/jupyternotebooks/1-Core%20Python/05-BasicInputAndOutput.html#exercises)

This program will determine the monthly payment for a 30 year mortgage for an initial principal amount and interest rate that the user specifies.

The formula (below) is also available at https://en.wikipedia.org/wiki/Mortgage_loan#Principal_and_interest. 

$A = P \times \dfrac{r(1+r)^n}{(1+r)^n - 1}$

You need to compute periodic amortization payment assuming 12 payments per year.

So that we can automatically grade programs, you must follow these specific conditions:
1. The Python file must be named "mortgage.py".  We have provided an initial template for this file.
2. After the comment, you will need to add lines of code to perform  any necessary conversions and calculations.
3. You may change variable names.  However, the intention of the line
   ```python
   payment_amount = int(A*100)/100 
   ```
   is to convert the answer to whole cents (as an integer). Then to divide by 100 to take the answer back to dollars in a float value. In a few notebooks, we'll show how to use string formatting instead.
4. The final line should simply print the number. 
5. You may assume that we will provide valid input (positive numbers).

You can execute your program with
```bash
python3 mortgage.py
```

Sample Inputs and Payment:
```text
Principle Interest  Payment
200000    0.05     1073.64
100000    0.077    712.96 
10000.50  0.03     42.16
```
