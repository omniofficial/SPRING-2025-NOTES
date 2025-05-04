import itertools


# Function to get stock / company details from user
def get_stock_input():
    n = int(input("How many companies do you want to choose from? "))
    companies = []
    # Loop through # of companies.
    for i in range(1, n + 1):
        print(f"Enter details for company {i}:")
        # Get the number of stocks available for this company
        num_stocks = int(input(f"  Number of stocks for company {i}: "))
        # Get the value per stock for this company
        value = int(input(f"  Value of stocks for company {i}: "))
        # Store in companies list
        companies.append([num_stocks, value])
        # Get total user investment amount $
    amount = int(input("Enter your total investment amount: "))
    # Return list and investment amount
    return companies, amount


# Function provided in project directions through stock_maximization. Determines if combination is within investment amount.
def verify_combinations(amount, items, candidate):
    # Calculate the total value of the selected stocks
    total_value = sum(
        items[i][1] * items[i][0] for i in candidate
    )  # Value of stock * # of stocks = total $ amount of a particular stock combination
    # Check if the total value is within the investment amount. Return if true.
    return total_value <= amount


# Function provided in project directions. Variables M, items, best, candidates, total_value are given. Function verify_combinations is given. Tweaked to include total $ investment return amount.
def stock_maximization(M, items):
    best = None
    best_total_value = 0  # Track the best total investment value

    # Iterate through all possible combinations
    for r in range(1, len(items) + 1):
        # Use itertools to generate all combinations
        for candidates in itertools.combinations(range(len(items)), r):
            # Check if the combination is valid using verify_combinations function
            if verify_combinations(M, items, candidates):
                # Calculate the total value for the valid combination
                total_value = sum(
                    items[i][1] * items[i][0] for i in candidates
                )  # Value * number of stocks
                # If the there is no best combination yet, then current becomes best. OR if current combination has a higher value than best, then the currect becomes best.
                if best is None or total_value > best_total_value:
                    # Company combination (like company 1, company 2, etc) becomes best
                    best = candidates
                    # Update best total value with the value of the current best combination
                    best_total_value = total_value

    return best, best_total_value


def main():
    # Get stock and company information
    companies, amount = get_stock_input()
    # stock_maximization function call
    best_combination, total_investment_value = stock_maximization(amount, companies)

    # Print results
    print("\n------------------ Result ------------------")
    if best_combination is None:
        print("No valid combination found within the given investment amount.")
    else:
        print(
            f"Best combination of companies to invest in (indexing starts at 0): {best_combination}"
        )
        print("Details of selected companies:")
        for j in best_combination:
            num_stocks, stock_value = companies[j]
            print(f"  Company {j}: {num_stocks} stocks at value {stock_value} each")

        print(f"\nTotal investment value: ${total_investment_value}")


if __name__ == "__main__":
    main()
