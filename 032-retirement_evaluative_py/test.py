import sys
import pandas as pd
import csv
import os


def validate_arguments():
    """Validate the command-line arguments."""
    if len(sys.argv) != 5:
        print("Incorrect number of arguments")
        sys.exit(ARGUMENT_ERROR)

    try:
        start_date = float(sys.argv[3])
        end_date = float(sys.argv[4])
        if end_date < start_date:
            print("End date cannot be earlier than start date")
            sys.exit(ARGUMENT_ERROR)
    except ValueError:
        print("Invalid date format")
        sys.exit(ARGUMENT_ERROR)

    return sys.argv[1], sys.argv[2], start_date, end_date


def read_csv(file_name, error_code):
    """Read the CSV file and handle file-related errors."""
    if not os.path.exists(file_name):
        print(f"File {file_name} not found")
        sys.exit(error_code)

    try:
        return pd.read_csv(file_name)
    except Exception as e:
        print(f"Error reading {file_name}: {str(e)}")
        sys.exit(error_code)


def calculate_cumulative_investment(sp_data, bond_data, start_date, end_date):
    """
    Calculate cumulative investment for all three strategies.

    :param sp_data: DataFrame with S&P data
    :param bond_data: DataFrame with bond data
    :param start_date: Start date for the portfolio
    :param end_date: End date for the portfolio
    :return: List of cumulative investment results for each month
    """
    cumulative_equity = 0.0
    cumulative_bond = 0.0
    cumulative_lifecycle = 0.0
    monthly_deposit = 100.00
    deposit_increase_rate = 0.025

    results = []

    # Use the correct column names from sp_data.csv
    sp_data['Index_prev'] = sp_data['Index level'].shift(1)

    for index, row in sp_data.iterrows():
        current_date = row['Date']
        if float(current_date) < start_date or float(current_date) > end_date:
            continue

        # Calculate S&P ROR and Dividend ROR using 'Index level' and 'Dividend'
        if pd.isna(row['Index_prev']):
            sp_ror = 0
        else:
            sp_ror = (row['Index level'] / row['Index_prev']) - 1
        
        div_ror = (row['Dividend'] / 12) / row['Index level']
        total_ror_equity = sp_ror + div_ror
        
        # Get bond ROR for the same date (using 'PercentageRate' from bond_data.csv)
        bond_row = bond_data[bond_data['Date'] == current_date]
        if bond_row.empty:
            # print(f"Missing bond data for date {current_date}")
            sys.exit(BOND_DATA_ERROR)

        bond_ror = bond_row.iloc[0]['PercentageRate'] / 1200

                # Adjust the monthly deposit in January
        if str(current_date).endswith(".01"):  # January of each year
            monthly_deposit *= (1 + deposit_increase_rate)
            
        # Update the cumulative investments
        print("prev_culumative",cumulative_equity,end=",")
        cumulative_equity = cumulative_equity * (1 + total_ror_equity) + monthly_deposit
        print(total_ror_equity, cumulative_equity,monthly_deposit)


        # Apply bond ROR only to the existing balance, then add the monthly deposit
        cumulative_bond = cumulative_bond * (1 + bond_ror)
        cumulative_bond += monthly_deposit

        # Lifecycle investment allocation (decrease equity allocation by 2% each year)
        lifecycle_allocation = max(0, 1 - 0.02 * (index // 12))
        cumulative_lifecycle = (
            cumulative_lifecycle * (1 + total_ror_equity) * lifecycle_allocation +
            cumulative_lifecycle * (1 + bond_ror) * (1 - lifecycle_allocation) +
            monthly_deposit
        )

        # Store results for this month
        results.append([current_date, cumulative_equity, cumulative_bond, cumulative_lifecycle])


    # print(results[0:30])

    return results


def write_to_csv(results):
    """Write the results to the portfolio.csv file."""
    with open('portfolio.csv', mode='w', newline='') as file:
        writer = csv.writer(file)
        writer.writerow(["Date", "StrategyOne", "StrategyTwo", "StrategyThree"])
        for row in results:
            writer.writerow([row[0], f"{row[1]:.2f}", f"{row[2]:.2f}", f"{row[3]:.2f}"])


if __name__ == "__main__":
    ARGUMENT_ERROR = 10
    SP_DATA_ERROR = 20
    BOND_DATA_ERROR = 30


    # print(len(sys.argv))
    sp_file, bond_file, start_date, end_date = validate_arguments()

    # Read and validate data from the files
    sp_data = read_csv(sp_file, SP_DATA_ERROR)
    bond_data = read_csv(bond_file, BOND_DATA_ERROR)
    # print(sp_data)
    # Calculate the cumulative investment for each strategy
    results = calculate_cumulative_investment(sp_data, bond_data, start_date, end_date)

    # Write the results to the output CSV
    write_to_csv(results)