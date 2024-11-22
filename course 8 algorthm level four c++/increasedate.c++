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
sDate IncreaseDateByxDay(sDate Date , short count) {
    for (int i = 0; i < count ; i++)
    {
        
      Date.Day++;
      if (Date.Day > NumberOfDaysInAMonth(Date.Month, Date.Year)) {
          Date.Day = 1;
          Date.Month++;
          if (Date.Month > 12) {
              Date.Month = 1;
              Date.Year++;
          }
      }

    }
    return Date;
}
sDate IncreaseDateByoneweek(sDate Date) {
    for(int i = 0 ; i < 7 ; i++){

        Date = IncreaseDateByOneDay(Date);
    }
    return Date;
}

sDate IncreaseDateByxweek(sDate Date , short count) {

    for(int i = 0 ; i < count ; i++){

        Date = IncreaseDateByoneweek(Date);
    }
    return Date;
}

sDate IncreaseDateByonemonth(sDate Date) {
    
    int daybefore = Date.Day;
    Date.Day += 30;
    if (Date.Day > NumberOfDaysInAMonth(Date.Month, Date.Year)) {
        Date.Day = 1;
        Date.Month++;
        if (Date.Month > 12) {
            Date.Month = 1;
            Date.Year++;
        }
       
    }
    Date.Day += daybefore - 1;
    return Date;
}

sDate IncreaseDateByxmonth(sDate Date , short count) {

    for(int i = 0 ; i < count ; i++){

        Date = IncreaseDateByonemonth(Date);
    }
    return Date;
}

sDate IncreaseDateByoneyear(sDate Date ) {


    Date.Year++;

    return Date;
}

sDate IncreaseDateByxyear(sDate Date , short count ) {


    for (int i = 0; i < count; i++)
    {
        Date = IncreaseDateByoneyear(Date);
    }
    

    return Date;
}

sDate IncreaseDateByxyearfaster(sDate Date) {


    Date.Year += 10;

    return Date;
}


sDate IncreaseDateByOneDecade(sDate Date) {

    Date.Year += 10;
    return Date;
} 
sDate IncreaseDateByXDecades(short Decade, sDate Date) {
    
    for (short i = 1;i <= Decade * 10;i++) {
        Date = IncreaseDateByoneyear(Date);
    } 
    
    return Date;
}

// Function to increase the date by a certain number of decades
sDate IncreaseDateByXDecadesFaster(short Decade, sDate Date) {
    Date.Year += Decade * 10;
    return Date;
}

// Function to increase the date by one century
sDate IncreaseDateByOneCentury(sDate Date) {
    // Period of 100 years
    Date.Year += 100;
    return Date;
}

// Function to increase the date by one millennium
sDate IncreaseDateByOneMillennium(sDate Date) {
    // Period of 1000 years
    Date.Year += 1000;
    return Date;
}




int main() {
    sDate Date1 = ReadFullDate1();

    cout << "\n\nDate after: " << endl;

    Date1 = IncreaseDateByOneDay(Date1);
    cout << "adding one day : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

    Date1 = IncreaseDateByxDay(Date1 , 10);
    cout << "adding 10 day : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

    Date1 = IncreaseDateByoneweek(Date1);
    cout << "adding one week : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

    Date1 = IncreaseDateByxweek(Date1 , 10);
    cout << "adding 10 week : " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;


    Date1 = IncreaseDateByonemonth(Date1);
    cout << "adding one month: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

    Date1 = IncreaseDateByxmonth(Date1 , 5);
    cout << "adding 5 month: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

    Date1 = IncreaseDateByoneyear(Date1);
    cout << "adding one year: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

    Date1 = IncreaseDateByxyear(Date1 , 10);
    cout << "adding 10 year: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

    Date1 = IncreaseDateByxyearfaster(Date1);
    cout << "adding 10 year faster way: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

    Date1 = IncreaseDateByOneDecade(Date1);
    cout << "adding one decade: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

    Date1 = IncreaseDateByXDecades(10 , Date1);
    cout << "adding 10 decades: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

    Date1 = IncreaseDateByXDecadesFaster( 10 , Date1);
    cout << "adding 10 decades faster way: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

    Date1 = IncreaseDateByOneCentury(Date1);
    cout << "adding one centary: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

    Date1 = IncreaseDateByOneMillennium(Date1);
    cout << "adding one millennium: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;



    // Pause the program before it closes
    system("pause>0");
    return 0;
}

