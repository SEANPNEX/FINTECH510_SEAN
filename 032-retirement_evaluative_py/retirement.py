import sys
from sys import argv
from equity import Equity
from bond import Bond
from lifecycle import Lifecycle


def process(equity_filename, bond_filename, start, end):
    """process the input and call the method"""
    equity_plan = Equity(equity_filename, start, end, 100)
    bond_plan = Bond(bond_filename, start, end, 100)
    lifecycle_plan = Lifecycle(equity_filename, bond_filename, start, end, 100)
    date_list = equity_plan.date_list
    equity_balance = equity_plan.calculate_plan()
    bond_balance = bond_plan.calculate_plan()
    lifecycle_balance = lifecycle_plan.calculate_plan()
    title = "Date,StrategyOne,StrategyTwo,StrategyThree\n"
    result = [title]
    for i in range(len(date_list)):
        line = f"{date_list[i]},{equity_balance[i]:.2f},{bond_balance[i]:.2f},{lifecycle_balance[i]:.2f}\n"
        result.append(line)
    with open("portfolio.csv", "w") as f:
        f.writelines(result)


if __name__ == "__main__":
    if len(argv) != 5:
        print("Usage: python3 retirement.py index_filename bond_filename")
        sys.exit(10)

    equity_filename = argv[1]
    bond_filename = argv[2]
    start = argv[3]
    end = argv[4]
    print(argv)
    process(equity_filename, bond_filename, start, end)
