#include<iostream>
using namespace std;

struct stDate {
    short Year;
    short Month;
    short Day;
};

// Check if a year is a leap year
bool isLeapYear(short Year) {
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

// Check if Date1 comes before Date2
bool IsDate1BeforeDate2(stDate Date1, stDate Date2) {
    return (Date1.Year < Date2.Year) ? true : 
          ((Date1.Year == Date2.Year) ? 
          (Date1.Month < Date2.Month ? true : 
          (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

// Get the number of days in a month for a given year
short NumberOfDaysInAMonth(short Month, short Year) {
    if (Month < 1 || Month > 12) return 0;
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
}

// Check if the date is the last day in the month
bool IsLastDayInMonth(stDate Date) {
    return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
}

// Check if the month is the last month in the year (December)
bool IsLastMonthInYear(short Month) {
    return (Month == 12);
}

// Increment the date by one day
stDate IncreaseDateByOneDay(stDate Date) {
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

// Calculate the day of the week order for a given date
short DayOfWeekOrder(short Day, short Month, short Year) {
    short a, y, m;
    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + (12 * a) - 2;
    // Gregorian: 0 = Sun, 1 = Mon, 2 = Tue, ..., 6 = Sat
    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

// Overload DayOfWeekOrder for stDate type
short DayOfWeekOrder(stDate Date) {
    return DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
}

// Get short name of the day based on its order
string DayShortName(short DayOfWeekOrder) {
    string arrDayNames[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    return arrDayNames[DayOfWeekOrder];
}

// Check if a date falls on the weekend (Friday or Saturday)
bool IsWeekEnd(stDate Date) {
    short DayIndex = DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
    return (DayIndex == 5 || DayIndex == 6);
}

// Check if a date is a business day (not a weekend)
bool IsBusinessDay(stDate Date) {
    return !IsWeekEnd(Date);
}

// Read the day from the user
short ReadDay() {
    short Day;
    cout << "\nPlease enter a Day: ";
    cin >> Day;
    return Day;
}

// Read the month from the user
short ReadMonth() {
    short Month;
    cout << "Please enter a Month: ";
    cin >> Month;
    return Month;
}

// Read the year from the user
short ReadYear() {
    short Year;
    cout << "Please enter a Year: ";
    cin >> Year;
    return Year;
}

// Read the full date (day, month, and year)
stDate ReadFullDate() {
    stDate Date;
    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();
    return Date;
}

// Calculate the number of business (non-weekend) days between two dates
short CalculateVacationDays(stDate DateFrom, stDate DateTo) {
    short DaysCount = 0;
    while (IsDate1BeforeDate2(DateFrom, DateTo)) {
        if (IsBusinessDay(DateFrom)) {
            DaysCount++;
        }
        DateFrom = IncreaseDateByOneDay(DateFrom);
    }
    return DaysCount;
}

int main() {
    cout << "\nVacation Starts: ";
    stDate DateFrom = ReadFullDate();
    cout << "\nVacation Ends: ";
    stDate DateTo = ReadFullDate();

    cout << "\nVacation From: " << DayShortName(DayOfWeekOrder(DateFrom)) << " , "
         << DateFrom.Day << "/" << DateFrom.Month << "/" << DateFrom.Year << endl;
    cout << "Vacation To: " << DayShortName(DayOfWeekOrder(DateTo)) << " , "
         << DateTo.Day << "/" << DateTo.Month << "/" << DateTo.Year << endl;

    cout << "\n\nActual Vacation Days is: " << CalculateVacationDays(DateFrom, DateTo);
    
    system("pause>0");
    return 0;
}
