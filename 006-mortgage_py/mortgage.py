p = input("What is the amount borrowed?")
r = input("What is the annual interest rate - express this as a decimal such as 0.07 for 7%?")

# place your code here after this line
r = float(r) / 12
p = float(p)
n = 360
A = p * r * (1 + r) ** n / ((1 + r) ** n - 1)
payment_amount = int(A * 100) / 100
print(payment_amount)
