# File Recursion

One of the more interesting Linux commands is "du" which displays disk usage statistics.

You can see details of this command by running "man du" in a terminal window.  You will see something like 
```text
    DU(1)                                                                General Commands Manual                                                                DU(1)
    
    NAME
         du – display disk usage statistics
    
    SYNOPSIS
         du [-Aclnx] [-H | -L | -P] [-g | -h | -k | -m] [-a | -s | -d depth] [-B blocksize] [-I mask] [-t threshold] [file ...]
    
    DESCRIPTION
         The du utility displays the file system block usage for each file argument and for each directory in the file hierarchy rooted in each directory argument.
         If no file is specified, the block usage of the hierarchy rooted in the current directory is displayed.
    
         The options are as follows:
    
         -A      Display the apparent size instead of the disk usage.  This can be helpful when operating on compressed volumes or sparse files.
    
         -B blocksize
                 Calculate block counts in blocksize byte blocks.  This is different from the -h, -k, -m, --si and -g options or setting BLOCKSIZE and gives an
                 estimate of how much space the examined file hierarchy would require on a filesystem with the given blocksize.  Unless in -A mode, blocksize is
                 rounded up to the next multiple of 512.
```
in the window.  You can type "q" to exit the man page.  "space" moves the documentation forward by a page, "b" moves it back by a page. You can get more details on man by typing "man man".

For this assignment, we will implement a portion of the "du" command. 
```bash
% du -ac .
592	./therac25.pdf
216	./python_overloading.pdf
808	.
808	total
% ls -l
total 808
-rw-r--r--   1 jbslanka  staff  110084 Aug 24 14:42 python_overloading.pdf
-rw-r--r--   1 jbslanka  staff  299363 Aug 24 14:42 therac25.pdf
```

However, rather than showing the file size in the number of disk blocks, 
we will display the file size in bytes:
```bash
(classenv) % python du.py .
110084 	 ./python_overloading.pdf
299363 	 ./therac25.pdf
128 	 .
409575 	 total
```

You will also need to deal with subdirectories.  Here's the solution against
the "notebooks" directory in a prior year's student github repository 
(the ... indicates lines that have been removed):
```bash
(classenv) % python du.py notebooks
7836 	 notebooks/00-Preliminaries.ipynb
..
38088 	 notebooks/28-RegularExpressions.ipynb
1731 	 notebooks/answers/03-Answers
..
6241 	 notebooks/answers/28-RegularExpressions-Answers.ipynb
544 	 notebooks/answers
...
98 	 notebooks/requirements.txt
110084 	 notebooks/resources/python_overloading.pdf
299363 	 notebooks/resources/therac25.pdf
128      notebooks/resources
1280 	 notebooks
4867930 	 total
```

## Instructions
1.  Use the template file `du.py` as your starting point
2.  When you execute du.py (e.g., `python3 du.py`), you will also need to 
    get the starting directory from a command-line argument.  We have provided 
    this code in `du.py`.
3.  You need to write a recursive function called `du()`.  The function 
    "recursives"/descends through the directories.  The return value should 
    be the total file size of the file/directory passed to it, including all
    subdirectories and files. Determine what should be your base case and your
    recursive case. Also, are you using tail or head recursion?
4.  You can print the "total" line outside of the `du()` function.
5.  A "tab" character separates the size from the name in the output.
6.  Once you've validate your program produces the correct output, submit for grading.

## Useful Python functions:
You'll need to use the following methods in your program.  We have included the appropriate import statements in the template file.

### `os.path.isdir(filename)`

Returns `True` if the given filename is a directory, `False`Otherwise

### `os.path.join(file,dir_file)`

Joins two parts of a full pathname together with the appropriate file separator. For example, `os.path.join("resources","therac-25.pdf")` returns "resources/therac-25.pdf"

### `os.path.getsize(filename)`

Return the space used in bytes by the given filename, which can be either a directory or a file

### `os.listdir(file)`

Returns a list of all of the files in a directory.