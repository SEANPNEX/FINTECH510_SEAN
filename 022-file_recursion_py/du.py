import sys
import os


def du(file, layer=0):
    """
    From the given directory produce output similar to the linux command: du -ac
    However rather than the number of blocks the size of the files and directories
    should be printed
    
    returns: size of the given directory and all of its subdirectories/files
    """
    dir_now = os.listdir(file)
    total_size = 0
    for f in dir_now:
        full_path = os.path.join(file, f)
        if os.path.isdir(full_path):
            dir_size = du(full_path, layer + 1)
            print(f"{os.path.getsize(full_path)}\t{full_path}")
            total_size += dir_size + os.path.getsize(full_path)
        # base case
        else:
            total_size += os.path.getsize(full_path)
            print(f"{os.path.getsize(full_path)}\t{full_path}")
    if layer == 0:
        print(f"{os.path.getsize(file)}\t{file}")
        total_size += os.path.getsize(file)
        print(f'{total_size}\ttotal')
    return total_size


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python du.py directory")
        sys.exit(2)
    total_size = du(sys.argv[1])
    # print the total line

