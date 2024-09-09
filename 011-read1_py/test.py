a = 3
b = 9
while a <= b:
    if a % 2 == 1:
        print("a is", a)
    else:
        print("b is", b)
        for i in range(0, b-a):
            print("a * i + b =", a * i + b)

    a += 1
    b -= 1
print(a,b)