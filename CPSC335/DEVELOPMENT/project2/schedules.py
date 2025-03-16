# Convert HH:MM to minutes using string manipulation
def time_to_minutes(time_str):
    hours, minutes = map(int, time_str.split(":"))
    return hours * 60 + minutes


# Convert minutes back to HH:MM
def minutes_to_time(minutes):
    return f"{minutes // 60:02d}:{minutes % 60:02d}"


# Merge schedules function
def merge_schedules(schedules):
    # Convert all military time to minutes. Sort by ASCENDING order.
    busy_intervals = sorted(
        [[time_to_minutes(start), time_to_minutes(end)] for start, end in schedules]
    )

    # List
    merged = []

    # Loops through each interval within busy_intervals
    for interval in busy_intervals:
        start, end = interval
        # If current interval overlaps with the last merged interval:
        if merged and merged[-1][1] >= start:
            # Merge overlapping intervals by updating the end time
            merged[-1][1] = max(merged[-1][1], end)
        # If there is no overlap, then add the current interval as a new entry
        else:
            merged.append([start, end])
    # Return list
    return merged


# Function to find the common working period (min and max time when both are available)
# Earliest both are available
def find_common_working_period(person1_DailyAct, person2_DailyAct):
    common_start = max(
        time_to_minutes(person1_DailyAct[0]), time_to_minutes(person2_DailyAct[0])
    )
    # Latest both are available
    common_end = min(
        time_to_minutes(person1_DailyAct[1]), time_to_minutes(person2_DailyAct[1])
    )
    return common_start, common_end


# Function to check if the time slot is free
def is_free(prev_end, start, meeting_duration):
    # Determines the free time available between the end of the previous event and the start of the next.
    free_time = start - prev_end
    # If the available free time is greater or equal to the given meeting duration, then return TRUE. Else, return FALSE.
    return free_time >= meeting_duration


# Function to check if the available time is valid
def is_time_valid(free_time, meeting_duration):
    # If specific time slot has free time greater than or equal to the meeting duration, then return TRUE. Else, return FALSE.
    return free_time >= meeting_duration


# Function to find available time slots given the meeting duration and schedules.
def find_available_slots(
    person1_Schedule,
    person2_Schedule,
    person1_DailyAct,
    person2_DailyAct,
    meeting_duration,
):
    # First, find min and max times both can meet (start and end)
    common_start, common_end = find_common_working_period(
        person1_DailyAct, person2_DailyAct
    )

    # Then, merge schedules to prep for comparison
    merged = merge_schedules(person1_Schedule + person2_Schedule)

    # Initialize empty list. Will store all valid time slots where meetings can be held.
    available_slots = []

    # Tracks the end time of most recently scheduled event (or last event).
    prev_end = common_start

    # Loop through merged intervals and find available slots
    for interval in merged:
        start, end = interval
        free_time = start - prev_end

        # Calls is_free function to check if time slot is free
        is_free_slot = is_free(prev_end, start, meeting_duration)
        if is_free_slot:
            # Adds a new available time slot to the available_slots list. EX: 10:30, 12:20.
            available_slots.append((minutes_to_time(prev_end), minutes_to_time(start)))

        # Update the previous end time
        prev_end = max(prev_end, end)

    # Calls is_time_valid function to determine if time slot is valid given the meeting duration.
    is_final_slot_valid = is_time_valid(common_end - prev_end, meeting_duration)
    if is_final_slot_valid:
        # Adds a new available time slot to the available_slots list.
        available_slots.append((minutes_to_time(prev_end), minutes_to_time(common_end)))

    return available_slots


# Function to get user input
def get_user_input():
    # Input for person 1
    size1 = int(input("Enter number of busy intervals for Person 1: "))
    person1_Schedule = []

    # Loop to get user input for busy intervals.
    for i in range(size1):
        start, end = input(
            f"Enter busy interval {i+1} for Person 1 (format HH:MM HH:MM): "
        ).split()
        person1_Schedule.append((start, end))

    # Enter daily active hours, split input strings
    person1_DailyAct = input(
        "Enter daily active hours for Person 1 (format HH:MM HH:MM): "
    ).split()

    # Input for person 2
    size2 = int(input("Enter number of busy intervals for Person 2: "))
    person2_Schedule = []

    # Loop to get user input for busy intervals
    for i in range(size2):
        start, end = input(
            f"Enter busy interval {i+1} for Person 2 (format HH:MM HH:MM): "
        ).split()
        person2_Schedule.append((start, end))

    # Enter daily active hours, split input strings
    person2_DailyAct = input(
        "Enter daily active hours for Person 2 (format HH:MM HH:MM): "
    ).split()

    # Input for meeting duration
    meeting_duration = int(input("Enter duration of meeting (minutes): "))

    return (
        person1_Schedule,
        person2_Schedule,
        person1_DailyAct,
        person2_DailyAct,
        meeting_duration,
    )


# Main function
def main():
    # Call get_user_input function
    (
        person1_Schedule,
        person2_Schedule,
        person1_DailyAct,
        person2_DailyAct,
        meeting_duration,
    ) = get_user_input()

    # Call find_available_slots function
    available_slots = find_available_slots(
        person1_Schedule,
        person2_Schedule,
        person1_DailyAct,
        person2_DailyAct,
        meeting_duration,
    )

    # Output result of available slots (preferred meeting times)
    if available_slots:
        print("\nAvailable slots:")
        for slot in available_slots:
            print(f"[{slot[0]}, {slot[1]}]")
    else:
        print("\nNo times found. They cannot meet due to scheduling conflicts.")


# Run main
if __name__ == "__main__":
    main()
