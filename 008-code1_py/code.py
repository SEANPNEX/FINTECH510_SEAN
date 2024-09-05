def my_max(num1, num2):
    """
    check if num1 is greater than num2 if so, your answer is num1
    otherwise, your answer is num2
    """
    if num1 > num2:
        return int(num1)
    else:
        return int(num2)
    
    
print("max(42, -69):", my_max(42, -69))
print("max(33, 0):", my_max(33, 0))
print("max(0x123456, 123456):", my_max(0x123456, 123456))
print("max(0x451215AF, 0x913591AF)", my_max(0x451215AF, 0x913591AF))