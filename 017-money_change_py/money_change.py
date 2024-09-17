DENOMINATORS = [100.00, 50.00, 20.00, 10.00, 5.00, 2.00, 1.00, 0.25, 0.10, 0.05, 0.01]


def make_change(amount):
    """
    produce the change dict
    """
    change = {}
    for m in DENOMINATORS:
        amount = round(amount, 2)
        num = amount // m
        if num == 0:
            continue
        else:
            change.update({m: int(num)})
            amount -= num * m 
    return change


def print_change(change):
    """
    print out the change dict
    """
    for i in change.keys():
        print(f"${i:.2f}: {change[i]}")
    return


