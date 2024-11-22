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
sDate ReadFullDate() {
    sDate Date;
    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();
    return Date;
}

// Function to decrement the date by one day
sDate DecreaseDateByOneDay(sDate Date) {
    Date.Day--;
    if (Date.Day == 0) {
        Date.Month--;
        if (Date.Month == 0) {
            Date.Month = 12;
            Date.Year--;
        }
        Date.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
    }
    return Date;
}

sDate DecreaseDateByXDay(sDate Date, short count) {
    for (int i = 0; i < count; i++) {
        Date = DecreaseDateByOneDay(Date);
    }
    return Date;
}

sDate DecreaseDateByOneWeek(sDate Date) {
    for (int i = 0; i < 7; i++) {
        Date = DecreaseDateByOneDay(Date);
    }
    return Date;
}

sDate DecreaseDateByXWeek(sDate Date, short count) {
    for (int i = 0; i < count; i++) {
        Date = DecreaseDateByOneWeek(Date);
    }
    return Date;
}

sDate DecreaseDateByOneMonth(sDate Date) {
    for (int i = 0; i < 30; i++) {
        Date = DecreaseDateByOneDay(Date);
    }
    return Date;
}

sDate DecreaseDateByXMonth(sDate Date, short count) {
    for (int i = 0; i < count; i++) {
        Date = DecreaseDateByOneMonth(Date);
    }
    return Date;
}

sDate DecreaseDateByOneYear(sDate Date) {
    Date.Year--;
    return Date;
}

sDate DecreaseDateByXYear(sDate Date, short count) {
    for (int i = 0; i < count; i++) {
        Date = DecreaseDateByOneYear(Date);
    }
    return Date;
}

sDate DecreaseDateByXYearFaster(sDate Date) {
    Date.Year -= 10;
    return Date;
}

sDate DecreaseDateByOneDecade(sDate Date) {
    Date.Year -= 10;
    return Date;
}

sDate DecreaseDateByXDecades(short Decade, sDate Date) {
    for (short i = 1; i <= Decade * 10; i++) {
        Date = DecreaseDateByOneYear(Date);
    }
    return Date;
}

// Function to decrease the date by a certain number of decades
sDate DecreaseDateByXDecadesFaster(short Decade, sDate Date) {
    Date.Year -= Decade * 10;
    return Date;
}

// Function to decrease the date by one century
sDate DecreaseDateByOneCentury(sDate Date) {
    // Period of 100 years
    Date.Year -= 100;
    return Date;
}

// Function to decrease the date by one millennium
sDate DecreaseDateByOneMillennium(sDate Date) {
    // Period of 1000 years
    Date.Year -= 1000;
    return Date;
}

int main() {
    sDate Date = ReadFullDate();

    cout << "\n\nDate after: " << endl;

    Date = DecreaseDateByOneDay(Date);
    cout << "decreasing one day : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByXDay(Date, 10);
    cout << "decreasing 10 days : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByOneWeek(Date);
    cout << "decreasing one week : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByXWeek(Date, 10);
    cout << "decreasing 10 weeks : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByOneMonth(Date);
    cout << "decreasing one month: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByXMonth(Date, 5);
    cout << "decreasing 5 months: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByOneYear(Date);
    cout << "decreasing one year: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByXYear(Date, 10);
    cout << "decreasing 10 years: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByXYearFaster(Date);
    cout << "decreasing 10 years faster way: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByOneDecade(Date);
    cout << "decreasing one decade: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByXDecades(10, Date);
    cout << "decreasing 10 decades: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByXDecadesFaster(10, Date);
    cout << "decreasing 10 decades faster way: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByOneCentury(Date);
    cout << "decreasing one century: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByOneMillennium(Date);
    cout << "decreasing one millennium: " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    // Pause the program before it closes
    system("pause>0");
    return 0;
}
