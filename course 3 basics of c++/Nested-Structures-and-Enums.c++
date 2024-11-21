#include <iostream>
using namespace std;

// Define enums for color, gender, and marital status
enum enColor { Red, Green, Yellow, Blue };
enum enGender { Male, Female };
enum enMaritalStatus { Single, Married };

// Structure to store address information
struct stAddress {
  string StreetName;
  string BuildingNo;
  string POBox;
  string ZipCode;
};

// Structure to store contact information
struct stContactInfo {
  string Phone;
  string Email;
  stAddress Address; // Nested structure to hold address details
};

// Structure to store information about a person
struct stPerson {
  string FirstName;
  string LastName;

  stContactInfo ContactInfo; // Nested structure for contact details

  enMaritalStatus MaritalStatus;  // Enum for marital status
  enGender Gender;               // Enum for gender
  enColor FavouriteColor;        // Enum for favorite color
};

int main() {
  // Create a person object
  stPerson Person1;

  // Assign values to Person1's member variables
  Person1.FirstName = "Mohammed";
  Person1.LastName = "Abu-Hadhoud";

  Person1.ContactInfo.Email = "xyz@xyz.com";
  Person1.ContactInfo.Phone = "+961000000999";
  Person1.ContactInfo.Address.POBox = "7777";
  Person1.ContactInfo.Address.ZipCode = "11194";
  Person1.ContactInfo.Address.StreetName = "Queen1 Street";
  Person1.ContactInfo.Address.BuildingNo = "313";

  Person1.Gender = enGender::Male;
  Person1.MaritalStatus = enMaritalStatus::Married;
  Person1.FavouriteColor = enColor::Green;

  // Print the street name from the person's address
  cout << "Street Name: " << Person1.ContactInfo.Address.StreetName << endl;

  return 0;
}
