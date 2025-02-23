## Hamiltonian Algorithm: PSEUDOCODE

Function parseInputToArray(input_string, array[], size):
For each element from 0 to size-1:
Convert string value to array type double

Function findPreferredStart(fuel[], city_distances[], mpg, number_cities):
Initialize start = 0
Initialize current_fuel = 0
Initialize starting_city_found = false

    While start < number_cities:
        Reset current_fuel to 0
        Set can_make_it to true

        Print the message: "Trying to start from city {start}"

        For each city (i) in the range from 0 to number_cities:
            Calculate current_city = (start + i) % number_cities

            Add the fuel from current_city to current_fuel

            Print the current fuel, max distance, and required distance for the current city

            Calculate fuel_needed = city_distances[current_city] / mpg

            Print the fuel used for this trip to the next city

            If current_fuel >= fuel_needed:
                Subtract fuel_needed from current_fuel
                Print "Can make it to the next city. Remaining fuel = {current_fuel}"
            Else:
                Set can_make_it to false
                Print "Cannot make it to the next city from city {current_city}"
                Break the loop

        If can_make_it is true:
            Set starting_city_found to true
            Print "Journey completed successfully starting from city {start}"
            Break the outer loop

        Increment start
        Print "Moving to the next starting city..."

    If starting_city_found is false:
        Print "No valid starting city found. The journey is impossible."
        Return -1

    Return start

int Main ()
{
Print "Enter the number of cities"
cin number_cities

Initialize city_distances array of size number_cities
Initialize fuel array of size number_cities

Clear the input buffer because of /n
Print "Enter the city distances (space-separated)"
Read city_distances_input as string
Call parseInputToArray with city_distances_input, city_distances, and number_cities

Print the contents of city_distances

Print "Enter the fuel available at each city (space-separated)"
Read fuel_input as string
Call parseInputToArray with fuel_input, fuel, and number_cities

Print fuel based on city

Print "Enter the miles per gallon (MPG)"
cin mpg

Call findPreferredStart with fuel, city_distances, mpg, and number_cities
Print the preferred starting city index

}
