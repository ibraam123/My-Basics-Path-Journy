#include<iostream>
using namespace std;

// Structure to represent a date with year, month, and day
struct sDate {
    short Year;
    short Month;
    short Day;
};

struct speriod_one
{
    sDate date1;
    sDate date2;
};


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

speriod_one readperiod_one(sDate date1 , sDate date2){
    cout << "enter period 1 :" << endl;
    cout << "Enter start date: " << endl;
    date1 = ReadFullDate1();
    cout << "\n\nEnter end date: " << endl;
    date2 = ReadFullDate2();
    speriod_one period_one;
    period_one.date1 = date1;
    period_one.date2 = date2;

    return period_one;
    
}
bool isLeapYear(short Year)
{
    return (Year % 4 == 0 && Year % 100 != 0 || Year % 400 == 0);
}
short NumberOfDaysInAMonth(short Month, short Year) {
    if (Month < 1 || Month > 12) 
        return 0; // Invalid month

    int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
}
bool IsLastDayInMonth(sDate Date) {
    return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
}

bool IsLastMonthInYear(short Month) {
    return (Month == 12);
}

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
bool IsDate1BeforeDate2(sDate Date1, sDate Date2) {
    return (Date1.Year < Date2.Year) ? true :
           (Date1.Year == Date2.Year && Date1.Month < Date2.Month) ? true :
           (Date1.Year == Date2.Year && Date1.Month == Date2.Month && Date1.Day < Date2.Day);
}

int period_lengths(speriod_one period ){

    int count = 0;
    for (int i = period.date1.Day; i < period.date2.Day; i++)
    {
        count ++;
    }

    return count;
    

}
int period_lengths_includingendday(speriod_one period){

    int count = 0;
    for (int i = period.date1.Day; i <= period.date2.Day; i++)
    {
        count ++;
    }
    return count;
    

}


int main() {
    // Read the full date from the user
  
    sDate Date1;
    sDate Date2;
    speriod_one periodone;
    periodone = readperiod_one(Date1,Date2);

    cout << "period length = " << period_lengths(periodone) << endl;
    cout << "period length including end day = " << period_lengths_includingendday(periodone) << endl; 


    

    // Pause the program before it closes
    system("pause>0");
    return 0;
}
