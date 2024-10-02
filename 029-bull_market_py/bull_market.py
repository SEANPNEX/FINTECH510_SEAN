def find_longest_period(lst):
    """
       find_longest_period returns the longest series of closing prices in
       which the prices continually rose (as determined by the number of days).
       If two more more series have the same number of days, return the first
       series found.
         
       Args:
         l(list): list of daily closing prices

      Returns:
      a list containing the series (e.g., part of the original list) that 
      has the closing stock prices in the order in which they appeared in the 
      original list 

      Raises:
      TypeError if the list contains an item that is not arithmetically 
      compatible with ints and floats
    """

    if (lst is None) or len(lst)==0:
        return []
    prev = min(lst)
    existing_longest = []
    new_longest = []
    counter = 0
    for i in lst:
        if not isNumeric(i):
            raise TypeError
        if counter==0:
            new_longest.append(i)
            counter += 1
            continue
        if i>prev:
            new_longest.append(i)
        if i<prev:
            new_longest = [i]
        if len(new_longest)>len(existing_longest):
            existing_longest = new_longest
        prev = i
        counter += 1
    return existing_longest


def isNumeric(i):
    if (type(i) is int) or (type(i) is float):
        return True
    else:
        return False