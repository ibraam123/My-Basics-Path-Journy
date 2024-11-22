#include <iostream>
using namespace std;

short ReadYear() {
    short Year;
    cout << "\nPlease enter a year ? ";
    cin >> Year;
    return Year;
}

short Readmonth() {
    short month;
    cout << "\nPlease enter a month ? ";
    cin >> month;
    return month;
}


bool IsLeapYear(short year) {
    return ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0));
}


short Readday() {
    short day;
    cout << "\nPlease enter a day ? ";
    cin >> day;
    return day;
}

int DaysInMonth(short year, int month) {
    if (month == 2) {
        return IsLeapYear(year) ? 29 : 28;
    }
    else if (month == 1 || month == 3 || month == 12 || month == 10 || month == 8 || month == 7 || month == 5) {
        return 31;
    }
    else {
        return 30;
    }
}



int countdays(short day, short month, short year) {
    int count = 0;
    
    // Add days for all months before the given month
    for (int i = 1; i < month; i++) {
        count += DaysInMonth(year, i);
    }
    
    // Add days for the current month up to the given day
    count += day;
    
    return count; // 263 = 
}
int main(){
    short day , month , year;
    day = Readday();
    month = Readmonth();
    year = ReadYear();
    cout << "number of days from begining of the year is: " << countdays(day,month,year);

    return 0;
    

}