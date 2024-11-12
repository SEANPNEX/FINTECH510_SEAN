## Inputs
The system will read an input file specified as a command-line argument.
This file is a CSV (comma-separated values) file with a header row.  The first column in the header row is the label for the “time index” field. The remaining columns are asset names. (A variable number of assets may be present. At least one asset name will be present.)

The remaining rows specify the “time index”, followed by the price of each asset at that time. You may assume that there are no missing rows. Note in year.csv that some of the prices are null. Your program should handle null or non-numeric data in some fields by repeating the previous valid price for that asset. (Of course, if there is no valid data in a column, that is an error – print a message to stderr and exit with EXIT_FAILURE.)

```
Time,A,B
0,2193.03,24848.53
1,2291.72,25723.20
2,2349.01,26955.34
3,2373.67,27963.47
4,2297.72,28385.72
```
Sample Input File: `small.csv`

## Processing
For each change in the “time index” (i.e., row - it does not matter if the data is daily, monthly, or something else), you should compute the rate of return.  The rate of return can be calculated as

$
R_t = \begin{Bmatrix}
\text{ not valid for initial record }
\\ 
\frac{asset_t}{asset_{t-1}} -1 \text{ if t > 1}
\end{Bmatrix} 
$

Rates of returns for `A` in the sample input file: `0.04500166, 0.02499869, 0.01049804, -0.0319969`

Once you have the rates of return, compute the average return and standard deviation for that asset. The standard deviation is calculated as follows: 
(N = # of changes in the time index, which is 1 less than the number of data records (excluding first row))

$ R_{\bar{x}} = \frac{\sum_{t=1}^{N}R_t}{N} $ = average(mean) rate of return for asset $x$

$\sigma_x = \sqrt{\frac{\sum_{t=1}^{N}(R_t- R_{\bar{x}})^2}{N-1}}$ = standard deviation of those rates of return for asset $x$



For asset A:
- $ R_{\bar{x}} =0.01212538 $
- $ \sigma_x = 0.03263941 $

Next, you’ll need to create the covariance matrix, where each element is the covariance of two assets at that row and column.  So the covariance for assets a and b:

$ cov_{a,b} = \frac{1}{N}\sum_{t=1}^{N} (R_{A,t} - R_{A,\bar{x}})(R_{B,t}-R_{B,\bar{x}}) $

Covariance Matrix = 
$
\begin{bmatrix}
cov_{1,1} & cov_{1,2} & \cdots & cov_{1,n} \\ 
cov_{2,1} & cov_{2,2} & \cdots & cov_{2,n} \\ 
\cdots    & \cdots    & \cdots & \cdots    \\ 
cov_{n,1} & cov_{n,2} & \cdots & cov_{n,n} 
\end{bmatrix}
$

Finally, you will need to compute the correlation matrix. 
$\rho_{a,b} = \frac{cov_{a,b}}{\sigma_a\sigma_b} $

Correlation Matrix = 
$
\begin{bmatrix}
\ 1         & \rho_{1,2} & \cdots & \rho_{1,n} \\ 
\rho_{1,2} & 1          & \cdots & \rho_{2,n} \\ 
\cdots     & \cdots     & \cdots & \cdots    \\ 
\rho_{1,n} & \rho_{2,n} & \cdots & 1 
\end{bmatrix}
$

Recall that $-1 < \rho_(a,b) < 1$, where positive correlation means assets change in the same direction, and negative correlation means assets change in opposite directions. Therefore, the correlation of an asset with itself should be exactly 1. Note, however, that these formulas will not give you exactly $\rho_(a,a) =1 $ but will approach 1 for large time series of data. For this project, let $\rho_(a,a)$  be exactly 1 instead of doing the correlation computation.

## Output
Your program should print the result to stdout as follows:
- list of assets, separated by newlines
- [correlation matrix]

Note: The matrix must be formatted with open and closed square brackets and comma-delimited values, such that each floating-point number has 7 spaces and four digits after the decimal point. See ios_base::width, setprecision, and fixed in the C++ library.

The files `small.out` and `year.out` contain sample output.

## Implementation Requirements
1. Create a Makefile that compiles your code to an executable named “correl_matrix”.
2. Your executable takes exactly 1 command-line argument – the name of the file to read. The specification is described in the input section. Two sample files have been provided: `small.csv` and `year.csv`

For full credit, your program must valgrind cleanly - i.e., not have any memory leaks or invalid memory reads. Of course, you should test your program on many more inputs than those provided. You will also be graded on code quality. This means your code should make good use of abstraction, have good variable, function, and class names, be well commented and formatted, and have at least one class definition. 