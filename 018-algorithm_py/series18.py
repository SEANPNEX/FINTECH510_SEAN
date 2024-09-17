def series18(n):
    """Implement your function below"""
    counter = 0
    line = f"{-n ** 2} "
    prev = -n ** 2
    while counter < (3 * n - 1):
        prev += (2 * counter + 1)
        line += f"{prev} "
        counter += 1
    print(line)

