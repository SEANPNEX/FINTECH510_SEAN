# Retirement Evaluative Assignment

In this assignment, you will write another retirement calculator, in which
your portfolio consists of investments in equities, bonds, or a combination.
Your program will read historical data, calculate rates of return, and output
the cumulative investment for each of three investment strategies to a file. 

For each portfolio option, your program should calculate the cumulative 
investment each month. Assume the monthly deposit begins at 100.00 
and increases by 2.5% each new year (in January). 

Generally, calculate the cumulative investment as follows: 
new balance = previous balance + 
              the interest it earns based on that month's rate of return +
              the monthly contribution. 
              
The rate of return will depend on the investment strategy, as described
in the portfolio options below. 

Implementation Hints:
- Ensure you use the correct units. Percentages need to be converted
  to their decimal form (i.e., divide by 100)
- When you see XXXX(t) where XXXX is some field, you can think of that as 
  the current value / record.  For XXXX(t-1), that is the previous record
- think about how to express the formulas for the rate of return as
  variables - this is part of the "generalize" step
- Look to make your solution as robust as possible -> you should validate
  the input and catch any errors that may occur.

## Portfolio Strategy 1: Invest in Equities
For this investment strategy, the cumulative portfolio and the monthly
contributions will all be invested in the S&P 500 index. For the S&P
500 investment, the rate of return (ROR) is calculated as follows:
```
    Portfolio ROR(t) = S&P ROR(t) + Div ROR(t), where
    S&P ROR(t) = S&P(t) / S&P(t-1) – 1 
    Div ROR(t) = [Div(t) / 12] / S&P(t),

    where (t) indicates the value at that time, and (t-1) indicates the
    value the previous month. 
```

As an example, if the index level of a particular month is 103.30, the
previous month was 99.17, and the dividend is 3.07, then the S&P ROR is
    103.30 / 99.17 - 1 = 4.16%,
the dividend ROR is
    [3.07 / 12] / 103.30 = 0.25%,
and the total ROR is 4.41%. 

So if the previous balance was 0.00, and the monthly contribution is
100.00, then the new balance is 
```
    0.00  + 0.00 * ( 0.0441) + 100.00 = 100.00, which simplifies to 
    0.00  * (1 + 0.0441) + 100.00 = 100.00
```

If the next month's total ROR is 2.08%, then the new balance is
```
    100.00 + 100.00 * (0.0208) + 100.00 = 202.08, which simplifies to
    100.00 * (1 + 0.0208) + 100.00 = 202.08. 
```

## Portfolio Strategy 2: Invest in Bonds
For this investment strategy, the monthly contribution will be
invested in US government bonds. For the US bond investment, the
(monthly) rate of return is calculated as follows:
```
    Bond ROR(t) = Bond(t) / 12
```
Note: this is a simplification that ignores the semiannual compounding
of interest for bonds, but this will have minimal impact on the
numerical result. 

As an example, if the (yearly) bond rate of a particular month is 5.95%, 
then the (monthly) bond ROR is
```
    5.95% / 12 = 0.50%, 
```

So if the previous balance was 0.00, and the monthly contribution is
100.00, then the new balance is
```
    0.00 + 0.00 * (0.0050) + 100.00 = 100.00, which simplifies to
    0.00 * (1 + 0.0050) + 100.00 = 100.00. 
```

If the next month's ROR is 0.51%, then the new balance is
```
   100.00 + 100.00 * ( 0.0051) + 100.00 = 200.51, which simplifies to 
   100.00 * (1 + 0.0051) + 100.00 = 200.51. 
```

## Portfolio Strategy 3: "Lifecycle" Investment
For this investment strategy, each month, you will invest the monthly
contribution in a combination of the S&P 500 and US government
bonds. The strategy assumes that the investor is comfortable with a
more volatile equity portfolio early in her working life because the
expected returns are higher over the long run. But she wants to shift
the portfolio gradually into more stable bonds as she gets closer to
retirement. Here, we will assume the investor begins the lifecycle
allocation for equities at 100% and decreases this by 2% each year (in
January).

Each month the account is automatically rebalanced based upon the current
allocation.  The new balance is then computed as the previous balance plus the gain 
of equities plus the interest from bonds, and then plus the 
monthly contribution. That is, 
```
Cumulative invest(t) =  Cumulative invest(t-1) * [1 + Portfolio ROR(t)] * lifecycle allocation(t) +
                        Cumulative invest(t-1) * [1 + Bond ROR(t)] * [1 - lifecycle allocation(t)] + 
                        Deposit(t),
where Portfolio ROR(t) matches the definition from Strategy One.
```
As an example, if the S&P ROR is 4.41%, the bond ROR is 0.50%, the
previous balance was 0.00, the lifecycle allocation is 100%, and the
monthly contribution is 100.00, then the new balance is 
```
0.00 * (1 + 0.0441) * 100% + 0.00 * (1 + 0.0050) * (1 – 100%) + 100.00
= 100.00.
```
The next year, the lifecycle allocation decreases to 98%, so (assuming
that the portfolio is worth 1309.33 at the end of the first year) the
calculation would be: 
```
1309.33 * (1 + 0.0099) * 98% + 1309.33 * (1 + 0.0054) * (1 - 98%) +
102.50 
= 1424.65.
```

## Technical Instructions
Your program will take four command line arguments: 
1. the name of a file from which to read the S&P 500 index levels
2. the name of a file from which to read US government bond rates
3. the date the portfolio starts,
4. the date the portfolio ends. 

Dates will represent the year and month with the year before a decimal point, 
and the month as an integer (01-12) after the decimal point, such that 1971.12 
is December 1971, and 2017.01 is January 2017. 

Your program should read the historical data from each file and
calculate the rates of return for the S&P 500 and for US
bonds. No restrictions exist on how you may represent the data in your
program.

Next, your program should do the portfolio calculations for each
investment strategy. Look for opportunities for abstraction here! 

Finally, write the results to a file `portfolio.csv`, where each line
is the date followed by the three investment strategies' cumulative
investments at that date, separated by commas. You should start
the file with this header row "Date,StrategyOne,StrategyTwo,StrategyThree".
Providing others clear ideas on what is in a file is important.
Numeric values must be written with two decimal places.

Your Python file must be named `retirement.py`.

For example, if you execute the program as
```bash
python3 retirement.py sp_data.csv bond_data.csv 1971.12 2017.12
```
it should produce identical output to that found in example.csv.

Look to see how you can reduce code duplication by abstracting
duplicated code into a function.  Don't Repeat Yourself (DRY)

## Testing
We provide a pregrader that will run your tests against our reference
implementation. Before the deadline, when you do 'grade', the
pregrader will validate your current `retirement.py` implementation

While we check for some validation issues in the pregrader, the
final grader will be more exhaustive to see how well you have handled
a multitude of different issues. 

If you find an error (bad data, missing records, missing command-line
arguments, etc.), you should stop print an error message and then exit
with one of these three status codes:
```
  10: Issue with command-line arguments
  20: Issue with the S&P data file
  30: Issue with the Bonds data file
```

You are free to make your own unittest cases as well as data files.

You may make the following assumptions:
- The first line of the S&P data file and the Bonds data file will 
  always be the header line in the correct format.
- You should first validate command-line arguments
  (that the dates are in the correct format, that end date occurs on or 
   after the the start date)
- You should not make any attempt to correct data files.
- Any errors in the S&P data file should be reported before any 
  issues in the Bonds data file.
- You may also assume that missing records by date in the Bonds data file
  are a Bonds file data issue.  

As you validate data files, keep in mind that you need to check that
they have the correct number of fields are on each line and then that each
field is of the correct type and expected range.

## Submission
When you are satisfied with your testing, submit your assignment for grading.

Don't try to complete all of this at once.  Get small pieces of the code 
working and validated, then continue to add more functionality.

## Grading
This assignment will be graded in three parts:

- *Pre-grader*: This portion tests the sample files and is worth 80% of the grade. This includes 5% for passing the Python style guidelines with no issues.
- *Post-grader*: This portion runs after the due date with some additional test cases and is worth 15%.  This portion focuses more on specialized conditions that may occur.  You need to rigorously test for error conditions - missing files, bad data, etc.
- *Code Review*: This review will be performed by the instructor and TAs and is worth 5%
    - appropriate variable and function names
    - well-formatted code  (doesn't have to pass the Python style guidelines)
    - appropriate logic
    - docstrings for functions

## Clarifications:
- You are welcome to use any standard built-in Python package as well as Pandas.  
  However, you may find such libraries problematic when performing 
  the necessary input validation.  The Course Jupyter Notebooks have provided 
  sufficient code examples for you to complete this assignment. 
- For file not found errors with the S&P or Bond data files, use the error codes 
  of 20 or 30, respectively (the autograder enforces these values).

## Academic Integrity - Evaluative Assignment

- Your work must be your own!
- You may NOT consult with other students about:
  - high level approaches,
  - how to implement your algorithm in code, or
  - how to debug your code.
  
  Basically, you may not discuss anything particular to this assignment.

- You may NOT look at another student's code, nor show your code to
  anyone else.
- You are responsible for keeping your code private.
- You may not look for solutions to this or similar problems online.
- You may not use code from any other source.

- You MAY consult any of the course Jupyter notebooks
- You MAY consult any Python book on the O'Reilly Learning Platform
- You MAY consult any Python documentation on https://www.python.org/doc/
- You MAY consult notes you wrote in your notebook.
- You MAY consult the man pages.
- You MAY consult any of your prior assignments/exercises in this class.
- You MAY ask the professor or TAs for clarification.
