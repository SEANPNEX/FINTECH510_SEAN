# Key Values

This assignment is a bit longer than the assignments you have seen
so far. It is designed to give you practice on similar type of problem 
that you will see in your first evaluative assignment.

For this assignment, you will need to read two types of files.
The files will be specified as command-line arguments. So to start your
program, you will use a command such as - 
```bash
python3 key_value.py fileName1 fileName2
```

We have provided a file, `key_value.py` as a starting point. It contains
the code to validate the command-line arguments and place them into 
variables. Details on how that works will be present in the "Modules"
notebook.

The first input file will utilize a key-value format, where `=` separates
the two fields on each line:
```
key1=value1
key2=value2
....
keyN=valueN
```

Example File:
```
Jean Luc Picard=Captain
Will Riker=Commander
Beverly Crusher=Commander
Data=Lt. Commander
Geordi LaForge=Lt. Commander
Worf=Lt. Commander
Deanna Troi=Commander
```

Note that the division between the key and the value is the first equals
sign (the values could have = in them, but the keys cannot.  So "a=b=c", 
would have a key of "a", and a value of "b=c").

We'll read this file into a dictionary.

The second type of input file will contain a list of lines (which will 
typically match the keys from the first input file).  Your program will 
read one or more of this type of file.  For example, it might contain:
```
Jean Luc Picard
Will Riker
Worf
Deanna Troi
Q
```

For each file of the second type, you will create a new output file
using the same name as the input file, but with ".counts" appended.  In
this file, the program will print out the counts of the values for the 
corresponding keys (or "<unknown>" for anything that did not match any 
known key from the first input file)

Sample output:
```
Captain: 1
Commander: 2
Lt. Commander: 1
<unknown> : 1
```

As we think about this program, we might come up with the following
high-level algorithm:

Input:
  - file containing key-value pairs, separated by the first =
  - one or more following files. each containing a key per line

Output:
  - foreach of the 2nd type of input files, output a count file

Algorithm:
  - get the filename of first argument
  - load the contents in a dictionary
  - for each of the remaining files
    - create a new dictionary to store the "value" and number of occurrences
    - read the file
    - foreach line
       -- get the corresponding value from the first dictionary
       -- update the counts dictionary
    - output counts file

As you read that algorithm, realize that we still have more steps to do
to break it down into more easily translatable steps.  What does 
"output counts file" entail?

To implement this program, you need to implement these functions.
(You are welcome to implement others, but we will test with these.)

- `read_key_values(filename)`: reads in the key values from the first 
  input file and returns a dictionary
- `process_key_file(filename, key_value_dict)`: reads in the second 
  type of file and produces a dictionary of the value counts
- `write_output(filename, counts_dict)`.  The filename should be the result of 
  calling `creating_output_filename()`.  `write_output()` writes the output file.
- `create_output_filename(name)` creates the output filename for writing 
  the results
- `process(args)`: brings together the entire program to run.

We have provided some sample data for testing. Don't try to create this
all at once.  Get pieces of your program working. Focus first on just reading 
the first input file and echoing the input back to the console. Then work on 
putting data into a dictionary.  Then print the dictionary and validate its 
correct.  Keep building upon small successes.

The first test case:
```bash
python key_value.py kvs1.txt list1a.txt list1b.txt
```
should produce two output files (`list1a.txt.counts` and `list1b.txt.counts`).
The correct contents can be found in `list1a.txt.ans` and `list1b.txt.ans`.

The second test case:
```bash
python key_value.py kvs2.txt list2a.txt list2b.txt list2c.txt
```
should produce three files (named appropriately) and the answers can be found in
similarly named .ans files.

You can compare two files with most shells, using "diff":
```diff
diff list1a.txt.counts list1a.txt.ans
```
If the output is empty, the two files are the same.

Submit `key_value.py` to the Gradescope assignment.