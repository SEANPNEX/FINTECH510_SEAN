TAXRATE=0.2
hours=input("How many hours did employee work?")
payrate=input("What is the employees pay rate?")
try:
    hours=float(hours)
    payrate=float(payrate)
except ValueError:
    raise ValueError("Input should be a number")
totalPay=min(hours, 40) * payrate+1.5 * payrate*max(0, hours - 40)
taxes=totalPay * TAXRATE
netPay=totalPay * (1 - TAXRATE)
print(f"Total pay: {totalPay}\nTaxes: {taxes}\nNet pay: {netPay}")