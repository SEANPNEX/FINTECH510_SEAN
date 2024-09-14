import sys
from sys import argv


def read_key_values(filename):
    """
    Reads a key-value delimited file (separated by first =) into a dictionary

    Args:
    filename(str): name of the file to read
    
    Returns:
    dictionary of the read items
    """
    result = {}
    with open(filename, "r") as f:
        for line in f.readlines():
            lst_line = line.split("=")
            result.update({lst_line[0]: lst_line[1][:-1]})
    return result
            

def create_output_filename(name):
    """
    create the output file name.  Given an input filename such as "input.txt",
    return "input.txt.counts"
    """
    return f"{name}.counts"


def process_key_file(filename,key_values):
    """
    Loads in a key file and produces a dictionary of the count of the values 
    If a key is not found in key_values use "<unknown>"

    Args:
    filename(str): file containing keys to process
    key_values(dict): existing keys to load
    """
    result = {}
    with open(filename, "r") as f:
        for key in f.readlines():
            try:
                count_key = key_values[key[:-1]]
            except KeyError:
                print(f"Missed Key: {key}")
                count_key = "<unknown>"
            try:
                count_num = result[count_key]
            except KeyError:
                print(f"Key {count_key} not recorded")
                count_num = 0
            result.update({count_key: count_num+1})
    print(result)
    return result


def write_output(filename, counts):
    """
    Writes the content of counts to a file specifed by the filename.
    The output order is by the highest count descending. If two values are
    equal, arbitrarily choose 1.
    For each line, the format is
      key: value

    Args:
    filename(str): filename to open and write the output to.
    counts(dict): existing keys to load   
    Returns: None 
    """
    with open(filename, "w") as f:
        for i in sorted(counts, key = counts.get,reverse = True):
            f.write(f"{i}: {counts.get(i)}\n")
    return


def process(args):
    """
    Implement your algorithm in this function
    """
    # print(args)   #Uncomment if you want to validate/see the command-line arguments
    print(args)
    key_values = read_key_values(args[1])
    for i in args[2:]:
        counts = process_key_file(i, key_values)
        output_name = create_output_filename(i)
        print(output_name)
        write_output(output_name, counts)


# __name__ == "__main__" and argv explained in the "modules" notebook
if __name__ == "__main__":
    if len(argv) < 3:
        print("Usage: python3 key_value.py file1_name file2_name ...")
        sys.exit(-1)
    process(argv)
