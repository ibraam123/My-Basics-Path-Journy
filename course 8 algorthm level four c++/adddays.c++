#include<iostream>
using namespace std;

// Structure to represent a date with year, month, and day
struct sDate {
    short Year;
    short Month;
    short Day;
};

// Function to check if a year is a leap year
// A leap year occurs every 4 years, except for years divisible by 100, 
// unless they are also divisible by 400.
bool isLeapYear(short Year) {
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

// Function to get the number of days in a given month
// It takes into account leap years when calculating days for February
short NumberOfDaysInAMonth(short Month, short Year) {
    if (Month < 1 || Month > 12) 
        return 0; // Invalid month

    // Array representing the number of days in each month (Jan to Dec)
    int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    // If the month is February, check if it's a leap year
    return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
}

// Function to calculate the total number of days from the beginning of the year
// up to a specific date (day/month/year)
short NumberOfDaysFromTheBeginingOfTheYear(short Day, short Month, short Year) {
    short TotalDays = 0;

    // Loop through each month up to the given month and sum up the days
    for (int i = 1; i <= Month - 1; i++) {
        TotalDays += NumberOfDaysInAMonth(i, Year);
    }

    // Add the days of the current month
    TotalDays += Day;
    return TotalDays;
}

// Function to add a certain number of days to a given date
// It adjusts for month and year changes if the added days exceed the current month
sDate DateAddDays(short Days, sDate Date) {
    // Calculate total days from the beginning of the year plus the added days
    short RemainingDays = Days + NumberOfDaysFromTheBeginingOfTheYear(Date.Day, Date.Month, Date.Year);
    short MonthDays = 0;
    Date.Month = 1; // Reset month to January

    // Loop to find the correct month and day after adding days
    while (true) {
        // Get the number of days in the current month
        MonthDays = NumberOfDaysInAMonth(Date.Month, Date.Year);

        // Check if the remaining days exceed the days in the current month
        if (RemainingDays > MonthDays) {
            RemainingDays -= MonthDays; // Subtract current month's days
            Date.Month++; // Move to the next month

            // If the month exceeds December, reset to January and increase the year
            if (Date.Month > 12) {
                Date.Month = 1;
                Date.Year++;
            }
        } else {
            // If remaining days fit within the current month, set the date
            Date.Day = RemainingDays;
            break;
        }
    }

    return Date; // Return the updated date
}

// Function to read the day from the user
short ReadDay() {
    short Day;
    cout << "\nPlease enter a Day? ";
    cin >> Day;
    return Day;
}

// Function to read the month from the user
short ReadMonth() {
    short Month;
    cout << "\nPlease enter a Month? ";
    cin >> Month;
    return Month;
}

// Function to read the year from the user
short ReadYear() {
    short Year;
    cout << "\nPlease enter a Year? ";
    cin >> Year;
    return Year;
}

// Function to read the full date (day, month, and year) from the user
sDate ReadFullDate() {
    sDate Date;
    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();
    return Date;
}

// Function to read the number of days the user wants to add to the date
short ReadDaysToAdd() {
    short Days;
    cout << "\nHow many days to add? ";
    cin >> Days;
    return Days;
}

int main() {
    // Read the full date from the user
    sDate Date = ReadFullDate();

    // Read how many days to add to the date
    short Days = ReadDaysToAdd();

    // Add the days to the date
    Date = DateAddDays(Days, Date);

    // Output the updated date after adding the specified number of days
    cout << "\nDate after adding [" << Days << "] days is: ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

    // Pause the program before it closes
    system("pause>0");
    return 0;
}
