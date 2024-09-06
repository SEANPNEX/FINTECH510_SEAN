
def print_receipt(subtotal, tax_rate, tip_rate):
    """
    This function takes subtotal: float, tax_rate: float, tip_rate: float and prints the bill
    (subtotal: float, tax_rate: float, tip_rate: float) -> Null
    """
    
    print(f"""{"Subtotal:":>9} ${subtotal:>10.2f}""")
    print(f"""{"Tax:":>9} ${tax_rate * subtotal:>10.2f}""")
    print(f"""{"Tip:":>9} ${tip_rate * subtotal:>10.2f}""")
    print(f"""{"==========":>21}""")
    print(f"""{"Total:":>9} ${subtotal*(1 + tax_rate + tip_rate):>10.2f}""")



