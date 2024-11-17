# Random Story in C++

In this assignment, you will develop a C++ program that reads a story template 
from a file, replaces placeholders with randomly selected words from predefined 
lists, and outputs a generated random story. The template file, random seed, 
word categories, and word lists will be provided as command line arguments.

## Instructions:

1. **Command Line Arguments:**
   The program requires the following command-line arguments:
   - Path to the story template file (e.g., `story_template.txt`)
   - Path to the word categories file (e.g., `word_categories.txt`)
   - Random seed, an integer value

   If these are not present, print an error message to standard error and
   exit the program with a non-zero error code.

   ```bash
   ./random story_template.txt word_categories.txt 42
   ```

2. **Template File:**
   The template file will contain a story with placeholders such as `<noun>`, 
   `<verb>`, `<adjective>`. Your program will read this file and replace each 
   placeholder with a randomly selected word from the corresponding category.
   This file will have multiple lines, but the placeholders will never cross
   lines.  

   ```txt
   Once upon a time, there was a <adjective> <noun> who loved to <verb> <adverb>. 
   One day, the <noun> decided to <verb> all the way to the <adjective> mountain,
   where they found a <adjective> <noun>.
   ```

3. **Word Categories File:**
   The word categories file will list categories and their associated words 
   in the following format:
   ``` 
   noun:dog,cat,wizard,knight
   verb:run,jump,fly
   adjective:happy,tall,mysterious
   adverb:quickly,gracefully
   ```

   A word category must have at least one word associated with it.

4. **Random Word Selection:**
   The program will randomly select words from the word lists using the 
   provided function `generate_random_number(int max, int seed)` to produce
   the indices into those word lists.

   As random numbers are utilized, a consistent mechanism must be used
   to ensure words are selected in a similar manner between your program
   and the grader.  As such, that function has been constructed to re-seed 
   itself upon every call rather than using a "random device" to generate
   the seed value and to recreate the pseudo-random number generator (PRNG)
   in each call rather than re-using the PRNG.

5. **Output:**
   The program will output the generated story to the console.

6. **Compilation**
   While you are free to structure this program in any way you see fit, 
   you must provide a `Makefile` that creates an executable named
   `random_story` as its default target   

## Provided Files
| File | Purpose |
|------|---------|
| random_story.cpp | Initial starting point.  Contains `generate_random_number` |
| Makefile | Produces the necessary executable, random_story |
| template.txt | Sample templated story file |
| categories.txt | Sample word categories file |
| result.txt | Sample result file generated with a random seed of 42


## Testing
As this is a formative assignment, we are not rigorously testing your 
program, but rather ensuring that the logic has been implemented correctly.

Specific test cases:
1. Validate that the number of command-line arguments is correct.
2. The program handles the provided categories.txt and template.txt
   file correctly.
3. Validate that the program can handle a templated file where the same category
   exists multiple times on the same line.
4. The program functions correctly when no changes need to be made.

As you develop this program, think about other errors that could arise.

## Submission
Once you program can handle those test cases, submit `Makefile` and the necessary
source files to the Gradscope assignment.
