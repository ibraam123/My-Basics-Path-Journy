// This code snippet demonstrates the use of enums (enumerations) in C++.

#include <iostream>  // Include library for input/output operations

using namespace std;  // Avoids repeatedly using `std::` (use with caution in larger projects)

// Define enums (user-defined data types) for different categories
enum Color { red, green, yellow, black };  // Color constants
enum Direction { north, south, east, west };  // Direction constants
enum week { sat, sun, mon, tue, wed, thu, fri };  // Weekday constants (corrected typo)
enum gender { male, female };  // Gender constants
enum status { single, married };  // Relationship status constants

int main() {
  // Declare variables of enum types
  Color myColor;
  Direction myDirection;
  week today;  // Corrected typo
  status myStatus;

  // Assign enum values explicitly (recommended for clarity)
  myColor = Color::black;
  myDirection = Direction::east;

  // Print the assigned color (incomplete statement completed)
  cout << "My color is: " << myColor << endl;

  // (This section can be further expanded to demonstrate other enum functionalities)

  return 0;
}
