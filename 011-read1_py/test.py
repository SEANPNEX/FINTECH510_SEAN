a = 3
b = 9
while a <= b:
    # print(a,b)
    if a % 2 == 1:
        # print("tree 1")
        print("a is", a)
    else:
        # print("tree 2")
        print("b is", b)
        for i in range(0, b-a):
            print("a * i + b =", a * i + b)
    # print("\n")
    a += 1
    b -= 1