#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int readYear()
{
    int Year;
    cout << "\n Enter The Year Please \n";
    do
    {
        cin >> Year;
        if (Year <= 0)
        {
            cout << "\n You Are Entering A non-valied Year Try Again Later \n";
        }

    } while (Year <= 0);

    return Year;
}

int readMonth()
{
    int Month;

    cout << "\n Enter The Month Between [ 1 - 12 ] \n ";
    do
    {
        cin >> Month;
        if (Month < 1 || Month > 12)
        {
            cout << "\n You Are Entering A non-valid Month, Try Again Later \n";
        }

    } while (Month < 1 || Month > 12);
    return Month;
}

int readDay()
{
    int Day;

    cout << "\n Enter The Day Please [ 1 - 31 ] \n";
    do
    {
        cin >> Day;
        if (Day < 1 || Day > 31)
        {
            cout << "\n You Are Entering A Non Valid Value Try Again Later\n";
        }

    } while (Day < 1 || Day > 31);
    return Day;
}

bool isLeapYear(short Year)
{
    return (Year % 4 == 0 && Year % 100 != 0 || Year % 400 == 0);
}

short numberOfDaysInAMonth(short Month, short Year)
{
    int DaysOfMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

    return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : DaysOfMonth[Month - 1];
}

short numberOfDaysFromBeganingTheYear(int Day, int Month, int Year)
{
    int TotalDays = 0;

    for (int i = 1; i < Month-1; i++) 
    {
        TotalDays += numberOfDaysInAMonth(i, Year);
    }
    TotalDays += Day;

    return TotalDays;
}

void getDateByTotalNumber(short totalDays, short year)
{
    int month = 1;
    while (totalDays > numberOfDaysInAMonth(month, year))
    {
        totalDays -= numberOfDaysInAMonth(month, year); 
        month++; 
    }

    
    cout << "The date is: " << totalDays << "/" << month << "/" << year << endl;
}

int main()
{
    int year = readYear();
    int month = readMonth();
    int day = readDay();

    int totalDays = numberOfDaysFromBeganingTheYear(day, month, year);

    cout << "Number of days from the beginning of the year: " << totalDays << endl;

    
    getDateByTotalNumber(totalDays, year);

    return 0;
}