#pragma warning(disable : 4996)  // Disable deprecated function warnings

#include <iostream>
#include <ctime>
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

// Function to check if Date1 is before Date2
bool IsDate1BeforeDate2(sDate Date1, sDate Date2) {
    return (Date1.Year < Date2.Year) ? true :
           (Date1.Year == Date2.Year) ?
           (Date1.Month < Date2.Month ? true :
           (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) :
           false;
}

// Function to get the number of days in a given month
// It takes into account leap years when calculating days for February
short NumberOfDaysInAMonth(short Month, short Year) {
    if (Month < 1 || Month > 12) 
        return 0; // Invalid month

    int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
}

// Function to check if the date is the last day of the month
bool IsLastDayInMonth(sDate Date) {
    return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
}

// Function to check if the date is in December
bool IsLastMonthInYear(short Month) {
    return (Month == 12);
}

// Function to increase a date by one day
sDate IncreaseDateByOneDay(sDate Date) {
    if (IsLastDayInMonth(Date)) {
        if (IsLastMonthInYear(Date.Month)) {
            Date.Month = 1;
            Date.Day = 1;
            Date.Year++;
        } else {
            Date.Day = 1;
            Date.Month++;
        }
    } else {
        Date.Day++;
    }
    return Date;
}

// Function to get the difference in days between two dates
int GetDifferenceInDays(sDate Date1, sDate Date2, bool IncludeEndDay = false) {
    int Days = 0;
    while (IsDate1BeforeDate2(Date1, Date2)) {
        Days++;
        Date1 = IncreaseDateByOneDay(Date1);
    }
    return IncludeEndDay ? ++Days : Days;
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
    cout << "Please enter a Month? ";
    cin >> Month;
    return Month;
}

// Function to read the year from the user
short ReadYear() {
    short Year;
    cout << "Please enter a Year? ";
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

// Function to get the current system date
sDate GetSystemDate() {
    sDate Date;
    time_t t = time(0);
    tm* now = localtime(&t);
    Date.Year = now->tm_year + 1900;
    Date.Month = now->tm_mon + 1;
    Date.Day = now->tm_mday;
    return Date;
}


int main() {
    cout << "\nPlease Enter Your Date of Birth:\n";
    sDate Date1 = ReadFullDate();
    sDate Date2 = GetSystemDate();
    cout << "\nYour Age is: " << GetDifferenceInDays(Date1, Date2, true) << " Day(s)." << endl;
    

    // Pause the program before it closes
    system("pause>0");
    return 0;
}
