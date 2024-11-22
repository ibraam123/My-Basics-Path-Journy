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
struct speriod_two
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
speriod_two readperiod_two(sDate date1 , sDate date2){
    cout << "enter period 2 :" << endl;
    cout << "Enter start date: " << endl;
    date1 = ReadFullDate1();
    cout << "\n\nEnter end date: " << endl;
    date2 = ReadFullDate2();
    speriod_two period_two;
    period_two.date1 = date1;
    period_two.date2 = date2;

    return period_two;
    
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

bool isoverlap_period(speriod_one periodone , speriod_two periodtwo , sDate date1 , sDate date2){
    periodone = readperiod_one(date1 , date2);
    periodtwo = readperiod_two(date1 , date2);

    for (int i = periodone.date1.Day; i < periodone.date2.Day; i++)
    {
        date1 = IncreaseDateByOneDay(date1);
        if (date1.Day == periodtwo.date1.Day)
        {
            return true;
        }

        
    }
    
    return false;


}



int main() {
    // Read the full date from the user
  
    sDate Date1;
    sDate Date2;
    speriod_one periodone;
    speriod_two periodtwo;

    if (isoverlap_period(periodone,periodtwo,Date1,Date2))
    {
        cout << "yes , overlap period" << endl;
    }
    else
    {
        cout << "no , not overlaping" << endl;
    }
    
    

    // Pause the program before it closes
    system("pause>0");
    return 0;
}


/**#include<iostream>
using namespace std;

struct stDate {
    short Year;
    short Month;
    short Day;
};

struct stPeriod {
    stDate StartDate;
    stDate EndDate;
};

bool IsDate1BeforeDate2(stDate Date1, stDate Date2) {
    return (Date1.Year < Date2.Year) ? true :
           (Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true :
           (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false;
}

bool IsDate1EqualDate2(stDate Date1, stDate Date2) {
    return (Date1.Year == Date2.Year) ?
           ((Date1.Month == Date2.Month) ?
           ((Date1.Day == Date2.Day) ? true : false) : false) : false;
}

bool IsDate1AfterDate2(stDate Date1, stDate Date2) {
    return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
}

enum enDateCompare { Before = -1, Equal = 0, After = 1 };

enDateCompare CompareDates(stDate Date1, stDate Date2) {
    if (IsDate1BeforeDate2(Date1, Date2))
        return enDateCompare::Before;
    if (IsDate1EqualDate2(Date1, Date2))
        return enDateCompare::Equal;
    // if (IsDate1AfterDate2(Date1, Date2)) // This is faster
    return enDateCompare::After;
}

bool IsOverlapPeriods(stPeriod Period1, stPeriod Period2) {
    if (CompareDates(Period2.EndDate, Period1.StartDate) == enDateCompare::Before ||
        CompareDates(Period2.StartDate, Period1.EndDate) == enDateCompare::After)
        return false;
    else
        return true;
}

short ReadDay() {
    short Day;
    cout << "\nPlease enter a Day? ";
    cin >> Day;
    return Day;
}

short ReadMonth() {
    short Month;
    cout << "Please enter a Month? ";
    cin >> Month;
    return Month;
}

short ReadYear() {
    short Year;
    cout << "Please enter a Year? ";
    cin >> Year;
    return Year;
}

stDate ReadFullDate() {
    stDate Date;
    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();
    return Date;
}

stPeriod ReadPeriod() {
    stPeriod Period;
    cout << "\nEnter Start Date:\n";
    Period.StartDate = ReadFullDate();
    cout << "\nEnter End Date:\n";
    Period.EndDate = ReadFullDate();
    return Period;
}

int main() {
    cout << "\nEnter Period 1:";
    stPeriod Period1 = ReadPeriod();
    cout << "\nEnter Period 2:";
    stPeriod Period2 = ReadPeriod();

    if (IsOverlapPeriods(Period1, Period2))
        cout << "\nYes, Periods Overlap\n";
    else
        cout << "\nNo, Periods do not Overlap\n";

    system("pause>0");
    return 0;
}
 */