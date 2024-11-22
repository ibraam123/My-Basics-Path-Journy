#include <iostream>
using namespace std;

// Structure to represent a date with year, month, and day
struct sDate {
    short Year;
    short Month;
    short Day;
};

// Function to check if a year is a leap year
bool isLeapYear(short Year) {
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

// Function to get the number of days in a given month
short NumberOfDaysInAMonth(short Month, short Year) {
    if (Month < 1 || Month > 12)
        return 0; // Invalid month

    int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
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
sDate ReadFullDate1() {
    sDate Date1;
    Date1.Day = ReadDay();
    Date1.Month = ReadMonth();
    Date1.Year = ReadYear();
    return Date1;
}

sDate ReadFullDate2() {
    sDate Date2;
    Date2.Day = ReadDay();
    Date2.Month = ReadMonth();
    Date2.Year = ReadYear();
    return Date2;
}

// Function to check if Date1 is before Date2
bool IsDate1BeforeDate2(sDate Date1, sDate Date2) {
    return (Date1.Year < Date2.Year) ||
           (Date1.Year == Date2.Year && Date1.Month < Date2.Month) ||
           (Date1.Year == Date2.Year && Date1.Month == Date2.Month && Date1.Day < Date2.Day);
}

// Function to increment the date by one day
sDate IncreaseDateByOneDay(sDate Date) {
    Date.Day++;
    if (Date.Day > NumberOfDaysInAMonth(Date.Month, Date.Year)) {
        Date.Day = 1;
        Date.Month++;
        if (Date.Month > 12) {
            Date.Month = 1;
            Date.Year++;
        }
    }
    return Date;
}

// Function to calculate the difference in days between two dates
int difference(sDate date1, sDate date2) {
    int days = 0;
    sDate tempDate = date1;
    
    while (IsDate1BeforeDate2(tempDate, date2)) {
        tempDate = IncreaseDateByOneDay(tempDate);
        days++;
    }
    
    return days;
}

int main() {
    sDate Date1 = ReadFullDate1();
    sDate Date2 = ReadFullDate2();
    cout << "Difference is: " << difference(Date1, Date2) << " days" << endl;
    
    // Pause the program before it closes
    system("pause>0");
    return 0;
}
