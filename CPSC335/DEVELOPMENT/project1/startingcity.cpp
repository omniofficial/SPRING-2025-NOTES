#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// Covert our user input string into an array of double values. MUST be kept double due to MPG being decimal specific.
void parseInputToArray(const string &input, double arr[], int size)
{
  stringstream ss(input);
  for (int i = 0; i < size; i++)
  {
    ss >> arr[i];
  }
}

// Function to find the preferred starting city
int findPreferredStart(double fuel[], double city_distances[], double mpg, int number_cities)
{
  int start = 0;                    // Start initialized to 0.
  double current_fuel = 0;          // Fuel initializes to 0, until we start from a start city (with its own fuel provided).
  bool starting_city_found = false; // Bool value to determine if we found a valid starting city. Defaults to false until proven true.

  // Outer loop that attempts to make a city a start city by retrieving the index.
  while (start < number_cities)
  {
    current_fuel = 0;        // Everytime we start from a new city (meaning the whole path starts all over again at a new city), the trip is reset and we have no fuel.
    bool can_make_it = true; // Bool value to determine if we can travel from one city to the next. Assume we can unless proven false.

    cout << "\n---------- Trying to start from city " << start << " ---------- \n";

    // Inner loop that attempts to loop through every city and determine if our path (starting at our start city) can be completed
    for (int i = 0; i < number_cities; i++)
    {
      int current_city = (start + i) % number_cities; // Equation for sequential indexing. Allows us to go from city 5 to 0.
      current_fuel += fuel[current_city];             // Fuel from current city is added to our previous leftover fuel. Fuel only resets when starting fresh (a new start city).

      // Output
      cout << "City " << current_city << ": Fuel = " << current_fuel << ", Max distance = "
           << current_fuel * mpg << ", Required = " << city_distances[current_city] << endl;

      // Fuel needed to travel to the next city. Done by distance / mpg.
      double fuel_needed = city_distances[current_city] / mpg;

      // Output
      cout << "Fuel used for this trip to city " << (current_city + 1) % number_cities << ": " << fuel_needed << " gallons." << endl;

      // Determine if we can reach next city. Compare our current fuel to the fuel required of us to make trip to next city.
      if (current_fuel >= fuel_needed)
      {
        // Because the above condition satisfies, we have to decrease the amount of fuel required by our current fuel, since we waste fuel by traveling.
        current_fuel -= fuel_needed;
        // Output
        cout << "Can make it to the next city. Remaining fuel = " << current_fuel << endl;
      }
      else
      {
        // If we can't make it to the next city, start over by using a new start city.
        cout << "Cannot make it to the next city from city " << current_city << endl;
        can_make_it = false;
        break; // Exit the inner loop.
      }
    }

    // If we completed the entire journey when starting from our start city (which is defined by can_make_it remaing true), then the below condition executes.
    if (can_make_it)
    {
      starting_city_found = true; // Successful start city was found. If this remained false due to the above condition not executing, then we would receieve an error.
      cout << "\nJourney completed successfully starting from city " << start << endl;
      break; // Exit the outer loop due to finding a valid starting city.
    }

    // Executes once inner loop is broken due to not being able to make it to the next city.
    cout << "Moving to the next starting city...\n";
    start++; // Increment so that we can use a new starting city. EX: Instead of 0, we use 1.
  }

  // IF we cannot complete the path using any starting city:
  if (!starting_city_found)
  {
    cout << "No valid starting city found. The journey is impossible." << endl;
    return -1;
  }

  return start; // ELSE, return index of starting city.
}

int main()
{
  // User Input
  cout << "Enter the number of cities: ";
  int number_cities;
  cin >> number_cities;

  // Array Declarations
  double city_distances[number_cities];
  double fuel[number_cities];

  // Clear input buffer in the event there is a space or /n after entering # of cities.
  cin.ignore();

  // Get user input for city distances (separated by spaces). This is acquired in a string.
  cout << "Enter the city distances (space-separated): ";
  string city_distances_input;
  getline(cin, city_distances_input);
  parseInputToArray(city_distances_input, city_distances, number_cities); // Function call to convert space separated string to array.

  // Output
  cout << "City Distances: ";
  for (int i = 0; i < number_cities; i++)
  {
    cout << city_distances[i] << " ";
  }
  cout << endl;

  // Get user input for fuel available at each city (separated by spaces). This is acquired in a string.
  cout << "Enter the fuel available at each city (space-separated): ";
  string fuel_input;
  getline(cin, fuel_input);                           // Read the whole line
  parseInputToArray(fuel_input, fuel, number_cities); // Function call to convert space separated string to array.

  // Output
  cout << "Fuel at each city: ";
  for (int i = 0; i < number_cities; i++)
  {
    cout << fuel[i] << " ";
  }
  cout << endl;

  // Get user input for MPG.
  cout << "Enter the miles per gallon: ";
  double mpg; // MUST be a type double due to the possibility of fuel being 0.5, 0.75, 0.2 gallons etc.
  cin >> mpg;

  // Print index of starting city
  int start_city = findPreferredStart(fuel, city_distances, mpg, number_cities);
  cout << "The preferred starting city for the sample above is city " << start_city << endl;

  return 0;
}
