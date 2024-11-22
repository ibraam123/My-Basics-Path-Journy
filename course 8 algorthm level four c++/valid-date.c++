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


bool last_day(sDate Date1) {
    return (Date1.Day == 31 || Date1.Day == 30 || Date1.Day == 28 || Date1.Day == 29 ) ;
}
bool last_month(sDate Date1) {
    return(Date1.Month == 12) ;
}

bool validdate(sDate date1)
{
    if (date1.Month > 12 || date1.Month < 1)
    {
        return false;
    }
    else if ((date1.Month == 2) && (date1.Day != NumberOfDaysInAMonth(date1.Month , date1.Year)))
    {
        return false;
    }
    else if (NumberOfDaysInAMonth(date1.Month , date1.Year) != date1.Day)
    {
        return false;
    }
    else
    {
        return true;
    }
    
    
    
    
}





int main() {
    // Read the full date from the user
    

    for (int i = 0; i < 5; i++)
    {
        sDate Date1 = ReadFullDate1();
        if (validdate(Date1))
        {
            cout << "yes , valid date . " << endl;
        }
        else
        {
            cout << "no , not valid . ";
        }
        
        
    }
    

    // Pause the program before it closes
    system("pause>0");
    return 0;
}
