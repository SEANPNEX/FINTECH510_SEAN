DENOMINATORS = [100.00, 50.00, 20.00, 10.00, 5.00, 2.00, 1.00,
0.25, 0.10, 0.05, 0.01]

def make_change(amount):
    change = {}
    for m in DENOMINATORS:
        amount = round(amount, 2)
        num = amount // m
        if num == 0:
            continue
        else:
            change.update({f"${m}":int(num)})
            print(f"amount:{amount}")
            amount -= num * m 
    return change

def print_change(change):
    for i in change.keys():
        print(f"{i}: {change[i]}")
    return


