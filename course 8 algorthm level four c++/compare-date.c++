#include<iostream>
using namespace std;

// Structure to represent a date with year, month, and day
struct sDate {
    short Year;
    short Month;
    short Day;
};

enum state {equal = 0 , before = -1 , after = 1};

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
bool IsDate1BeforeDate2(sDate Date1, sDate Date2) {
    return (Date1.Year < Date2.Year) ? true :
           (Date1.Year == Date2.Year && Date1.Month < Date2.Month) ? true :
           (Date1.Year == Date2.Year && Date1.Month == Date2.Month && Date1.Day < Date2.Day);
}
bool IsDate1equalDate2(sDate Date1, sDate Date2) {
    return (Date1.Year == Date2.Year) ?
           ((Date1.Month == Date2.Month) ? 
           ((Date1.Day == Date2.Day)? true :false) : false) : false;
}
bool IsDate1afterDate2(sDate Date1, sDate Date2) {
    return (Date1.Year > Date2.Year) ? true :
           (Date1.Year == Date2.Year && Date1.Month > Date2.Month) ? true :
           (Date1.Year == Date2.Year && Date1.Month == Date2.Month && Date1.Day > Date2.Day);
}

int returnstate(sDate Date1, sDate Date2){

    if (IsDate1equalDate2(Date1,Date2))
    {
        return 0;
    }
    else if (IsDate1BeforeDate2(Date1,Date2))
    {
        return -1;
    }
    else
    {
        return 1;
    }
    
}


int main() {
    // Read the full date from the user
    for (int i = 0; i < 3; i++)
    {    
    sDate Date1 = ReadFullDate1();
    sDate Date2 = ReadFullDate2();
    cout << "\ncompare result = " << returnstate(Date1,Date2) << "\n\n";
    }
    // Pause the program before it closes
    system("pause>0");
    return 0;
}
