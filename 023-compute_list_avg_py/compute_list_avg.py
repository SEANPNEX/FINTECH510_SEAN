def compute_average(lst):
    """
    Computes the average of list, ignoring any entries that 
    are not numbers (floats or ints)

    Args:
    l(list): list of items to compute the average
 
    returns:
    average of the numbers in the list
    
    raises:
    ValueError if the argument is not a list or if the list does not contain any numbers
    """
    # TODO: Implement function
    cleaned_list = clean_list(lst)
    print("cleaned_list: ", cleaned_list)
    return sum(cleaned_list)/len(cleaned_list)


def clean_list(lst):
    if lst is None:
        raise ValueError
    result = []
    for i in lst:
        if type(i)==int or type(i)==float:
            print(i)
            result.append(i)
    if len(result)==0:
        raise ValueError
    return result