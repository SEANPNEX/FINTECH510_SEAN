# Unit Conversion

Write a Python script that scripts that implements the following problem: 

While the standard unit of measurement for mass is the kilogram, many
different units exists for measuring mass (and weight). Create a function
called `convert_mass` that takes three parameters: 
- *value*: the number for the current mass
- *current*: the unit currently used for the mass
- *target*: the unit to convert the mass into

The function should return the number for the current mass expressed in the
target unit. Use the following conversion tables for the possible current and
target units.

| Unit Name | Kilograms |
|-----------|-----------|
| Kilogram  | 1.0       |
| Pound     | 0.453592  |
| Stone	    | 6.35029   |
| Jin       | 0.5       |
| Seer      | 1.25      |
| Gram      | 0.001     |
| Oka       | 1.2829    |

So that we can automatically grade programs, you must follow specific conditions as documented here:
1. The Python file must be named `unit.py`. The provided file is empty.
2. We will directly call your function and evaluate the result.
3. You must name the function `convert_mass`.
4. You should not have any input/output within your `unit.py` file.
   We will be directly calling your function.
5. You must provide a docstring so that others can understand what 
   your function does.

To test your program, you may use `test.py`.

This script will make a few sample calls to your program.

## Sample Execution
```bash
$ python3 test.py
10.10
10100.00
4581.28
```