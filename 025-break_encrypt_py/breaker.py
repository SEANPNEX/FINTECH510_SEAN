import sys
from sys import argv

EXCEP = [' ', '\n']


def breaker(f):
    char_list = []
    while True:
        c = f.read(1)
        if not c: 
            break
        
        if c not in EXCEP:
            char_list.append(c)
        
    most_freq_char = count_most_freq(char_list)
    minus_key = get_minus_key(most_freq_char)
    for c in char_list:
        # print(c)
        c = c.lower()
        c = ord(c)
        c -= ord('a')
        c += minus_key
        c %= 26
        c += ord('a')
        c = chr(c)
        # print(c, end="")
    key = -minus_key
    if key < 0:
        print(26+key)
    else:
        print(key)


def count_most_freq(lst):
    """
    lst => most_frequent_item
    """
    st = set(lst)
    counter = {}
    for i in st:
        counter.update({i: lst.count(i)})
    freq_order = sorted(counter, key=counter.get, reverse=True)
    if counter.get(freq_order[0])==counter.get(freq_order[1]):
        return "f"
    else:
        return freq_order[0]
    

def get_minus_key(most_freq_char):
    """
    return the difference between the character and "e"
    """
    return ord('e')-ord(most_freq_char)


if __name__=="__main__":
    if len(argv) != 2:
        print("Usage: python3 breaker.py input_file_name")
        sys.exit(1)

    with open(argv[1]) as f:
        breaker(f)