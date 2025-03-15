# Convert "HH:MM" to minutes using string manipulation
def time_to_minutes(time_str):
    hours, minutes = map(int, time_str.split(":"))
    return hours * 60 + minutes


# Convert minutes back to "HH:MM"
def minutes_to_time(minutes):
    return f"{minutes // 60:02d}:{minutes % 60:02d}"


# Merge overlapping schedules without using tuples
def merge_schedules(schedules):
    # Convert all time intervals to minutes and sort them by start time
    busy_intervals = sorted(
        [[time_to_minutes(start), time_to_minutes(end)] for start, end in schedules]
    )

    merged = []

    for interval in busy_intervals:
        start, end = interval
        if merged and merged[-1][1] >= start:
            # Merge overlapping intervals by updating the end time
            merged[-1][1] = max(merged[-1][1], end)
        else:
            # No overlap, add the current interval as a new entry
            merged.append([start, end])

    return merged


# Find the common working period
def find_common_working_period(person1_DailyAct, person2_DailyAct):
    common_start = max(
        time_to_minutes(person1_DailyAct[0]), time_to_minutes(person2_DailyAct[0])
    )
    common_end = min(
        time_to_minutes(person1_DailyAct[1]), time_to_minutes(person2_DailyAct[1])
    )
    return common_start, common_end


# Function to check if the time slot is free
def is_free(prev_end, start, meeting_duration):
    free_time = start - prev_end
    return free_time >= meeting_duration


# Function to check if the available time is valid
def is_time_valid(free_time, meeting_duration):
    return free_time >= meeting_duration


# Find available slots
def find_available_slots(
    person1_Schedule,
    person2_Schedule,
    person1_DailyAct,
    person2_DailyAct,
    meeting_duration,
):
    common_start, common_end = find_common_working_period(
        person1_DailyAct, person2_DailyAct
    )

    # Merge busy schedules
    merged = merge_schedules(person1_Schedule + person2_Schedule)

    available_slots = []
    prev_end = common_start

    # Loop through merged intervals and find available slots
    for interval in merged:
        start, end = interval
        free_time = start - prev_end

        # Check if the slot is free
        is_free_slot = is_free(prev_end, start, meeting_duration)
        if is_free_slot:
            available_slots.append((minutes_to_time(prev_end), minutes_to_time(start)))

        # Update the previous end time
        prev_end = max(prev_end, end)

    # Check the final available slot after the last merged interval
    is_final_slot_valid = is_time_valid(common_end - prev_end, meeting_duration)
    if is_final_slot_valid:
        available_slots.append((minutes_to_time(prev_end), minutes_to_time(common_end)))

    return available_slots


# Function to get user input
def get_user_input():
    # Input for person 1
    size1 = int(input("Enter number of busy intervals for Person 1: "))
    person1_Schedule = []
    for i in range(size1):
        start, end = input(
            f"Enter busy interval {i+1} for Person 1 (format HH:MM HH:MM): "
        ).split()
        person1_Schedule.append((start, end))
    person1_DailyAct = input(
        "Enter daily active hours for Person 1 (format HH:MM HH:MM): "
    ).split()

    # Input for person 2
    size2 = int(input("Enter number of busy intervals for Person 2: "))
    person2_Schedule = []
    for i in range(size2):
        start, end = input(
            f"Enter busy interval {i+1} for Person 2 (format HH:MM HH:MM): "
        ).split()
        person2_Schedule.append((start, end))
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


# Main function to handle input and output
def main():
    # Get user input
    (
        person1_Schedule,
        person2_Schedule,
        person1_DailyAct,
        person2_DailyAct,
        meeting_duration,
    ) = get_user_input()

    # Get available slots
    available_slots = find_available_slots(
        person1_Schedule,
        person2_Schedule,
        person1_DailyAct,
        person2_DailyAct,
        meeting_duration,
    )

    # Output available slots
    if available_slots:
        print("\nAvailable slots:")
        for slot in available_slots:
            print(f"[{slot[0]}, {slot[1]}]")
    else:
        print("\nNo available meeting slots found.")


# Run the main function
if __name__ == "__main__":
    main()
