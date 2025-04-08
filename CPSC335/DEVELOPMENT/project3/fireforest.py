from collections import deque


# Function to get user input for the forest grid
def get_forest_input():
    rows = int(input("Please enter the number of rows in the forest: "))
    forest = []

    print(
        "Please enter the forest grid (separated by spaces, then hit enter for new row):"
    )
    for _ in range(rows):
        row = [
            int(x) for x in input().split()
        ]  # Return list of strings by splitting via each space (0 1 2 3 ...) then convert to integer value
        forest.append(row)  # Appends our integer row to the forest list

    return forest


# FUNCTION TO CHECK UP, DOWN, LEFT, AND RIGHT
def check_adjacent_cells(row, column, rows, cols, forest, queue, day, burned_today):
    # Check up
    if row > 0 and forest[row - 1][column] == 1:  # Check upwards
        forest[row - 1][column] = 2  # Adjacent cell becomes burned (value of 2)
        queue.append(
            (row - 1, column, day + 1)
        )  # Track the newly burned tree by adding to our queue
        burned_today.append(
            (row - 1, column)
        )  # Track the burned trees for the day (for the day by day output in next function)

    # Check down (SIMILAR TO CHECK UP COMMENTS, JUST FOR DOWN)
    if row < rows - 1 and forest[row + 1][column] == 1:
        forest[row + 1][column] = 2
        queue.append((row + 1, column, day + 1))
        burned_today.append((row + 1, column))

    # Check left (SIMILAR TO CHECK UP COMMENTS, JUST FOR LEFT)
    if column > 0 and forest[row][column - 1] == 1:
        forest[row][column - 1] = 2
        queue.append((row, column - 1, day + 1))
        burned_today.append((row, column - 1))

    # Check right (SIMILAR TO CHECK UP COMMENTS, JUST FOR RIGHT)
    if column < cols - 1 and forest[row][column + 1] == 1:
        forest[row][column + 1] = 2
        queue.append((row, column + 1, day + 1))
        burned_today.append((row, column + 1))


# FUNCTION TO TRACK FIRE SPREAD
def track_fire_spread(forest):
    rows = len(forest)
    cols = len(forest[0])

    # Queue initialization
    queue = []
    # Add burned trees to queue
    for row_index in range(rows):  # Nested for loop, n^2
        for column_index in range(cols):
            if forest[row_index][column_index] == 2:  # Burned trees have a value of 2
                queue.append(
                    (
                        row_index,
                        column_index,
                        0,
                    )  # Add ALL burned trees to queue, not just single burned trees as seen in previous function
                )

    # Determine if healthy trees are unreachable
    is_healthy_trees_left = (
        sum(row.count(1) for row in forest) > 0
    )  # Healthy trees are defined by 1, bool value for is_healthy_trees_left set to TRUE;
    if not is_healthy_trees_left:
        return 0  # No healthy trees to burn

    # Initialize to track trees that were burned at the day we are tracking
    burned_today = []
    is_burned = (
        False  # We will assume nothing has been burned on DAY 0 unless specified
    )

    # Output our day by day summary
    days = -1
    while queue:
        row, column, day = queue.pop(0)

        # Call check adjacent cells function starting at the origin (up, down, left, right)
        check_adjacent_cells(row, column, rows, cols, forest, queue, day, burned_today)

        # For any trees that were burned, we log the day by incrementing the day variable. Then, output what was burned and at what position.
        if burned_today:
            days = day + 1
            print(f"At day {days}: the healthy trees at {burned_today} burn.")
            burned_today = []

    # After the loop, check if there are any remaining healthy trees
    for row_index in range(rows):
        for column_index in range(cols):
            if forest[row_index][column_index] == 1:
                is_healthy_trees_left = True
                break
        if is_healthy_trees_left:
            break

    if is_healthy_trees_left:
        return -1  # Return -1 for unreachable healthy trees

    return days  # Return the final day count when all trees are burned


# Main function
def main():
    # Get user input for the forest grid
    forest = get_forest_input()

    # Call the track_fire_spread function to determine how, where and the final day the fire burns the forest
    days = track_fire_spread(forest)

    # Output the result
    if days == -1:
        print("No healthy trees can be burned further!!")
    else:
        print(f"There are no healthy trees at all at Day 0. Cannot be burned further.")


# Run main
if __name__ == "__main__":
    main()
