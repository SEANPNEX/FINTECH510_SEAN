def power(x, y):
    """
    x, y -> x^y
    """
    if (x==0) and (y==0):
        return 1
    if y==0:
        return 1
    return x * power(x, y-1)

