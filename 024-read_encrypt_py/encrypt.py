import sys
from sys import argv

def encrypt(f, key):
    """Encrypts the contents of the file object (assumed to be ASCII text)"""
    while True:
        c = f.read(1)
        print(f"initial c: {c}")
        if not c: break     # legal syntax, useful for this situation

        if c.isalpha():
            
            c = c.lower()
            print(f"lowered c: {c}")
            c = ord(c)
            print(f"ord of c: {c}")
            c -= ord('a')
            print(f"ord of c after step 1: {c}")
            c += key
            print(f"encrypted c: {c}")
            c %= 26
            print(f"divided c: {c}")
            c += ord('a')
            print(f"final c: {c}")
            c = chr(c)
            print(f"char c: {c}")
        print("\n")
        # print(c,end="")

if __name__ == "__main__":
    if len(argv) != 3:
        print("Usage: python3 encrypt.py key input_file_name")
        sys.exit(1)
    print(type(argv))
    key = 0
    try:
        key = int(argv[1])
        if (key == 0):
            raise ValueError("invalid key: "+argv[1])
    except:
        print("Invalid key: Must be a non-zero integer")
        sys.exit(2)
    
    with open(argv[2]) as f:
        encrypt(f, key)
