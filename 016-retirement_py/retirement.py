def update_stage(age, saving, rate, change):
    """
    update stage for age and savings
    """
    print(f"Age {age // 12:3d} month {age % 12:2d} you have ${saving:,.2f}")
    with open("ans.txt", 'a') as f:
        f.write(f"Age {age // 12:3d} month {age % 12:2d} you have ${saving:,.2f}\n")
    age += 1
    saving = (1 + rate / (12 * 100)) * saving + change
    return age, saving


def retirement(start_age, initial_savings, working_info, retired_info):
    """
    Prints the current status of an individual's retirement account.
    The dictionaries both have these fields: 
      "months","contribution","rate_of_return"

    Args:
      start_age (int): At what age (in months) does the individual start
      initial_savings (float): initial savings in dollars
      working_info (dict): information about working
      retired_into (dict): information about retirement

    Returns:
    None
    """
    age = start_age
    saving = initial_savings
    for m in range(WORKING_INFO["Months"]):
        age, saving = update_stage(age, saving, WORKING_INFO["Rate of Return"], WORKING_INFO["Per Month Savings"])
    for m in range(RETIRED_INFO["Months"]):
        age, saving = update_stage(age, saving, RETIRED_INFO["Rate of Return"], RETIRED_INFO["Per Month Spendings"])


WORKING_INFO={"Months": 489, "Per Month Savings": 1000, "Rate of Return": 4.5}
RETIRED_INFO={"Months": 384, "Per Month Spendings": -4000, "Rate of Return": 1}
retirement(327, 21345, WORKING_INFO, RETIRED_INFO)