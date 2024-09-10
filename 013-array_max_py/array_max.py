def is_numeric(x):
    """
    test if the input argument is numeric
    x:any->bool
    """
    if (type(x) is int) or (type(x) is float):
        return True
    else:
        return False
        

def array_max(array):
    """
    Finds the largest number in the list.
    Ignores elements that are not an int or a float

    Args:
        array (list): list of numbers (either float or int)

    Returns:
    Largest number in the list.  None if array is empty
    or if array is not a list.
    """
    cleaned_array = [x for x in array if is_numeric(x)]
    if len(cleaned_array) == 0:
        return None
    max = cleaned_array[0]
    for i in cleaned_array:
        if i >= max:
            max = i
    return max

