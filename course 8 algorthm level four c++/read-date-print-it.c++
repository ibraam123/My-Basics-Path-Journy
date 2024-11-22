#include<iostream>

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

short Readday() {
    short day;
    cout << "\nPlease enter a day ? ";
    cin >> day;
    return day;
}


void printdate(){
    short Year = ReadYear();
    short month = Readmonth();
    short day = Readday();
    int a , y , m , i;
    a = ((14 - month)/12);
    y = Year - a;
    m = month +(12 * a) - 2;
    i = (day + y + (y/4) - (y/100) + (y/400) + ((31 * m)/12)) % 7;

    string daysname[7] = {"sun" , "mon" , "tue" , "wed" , "thurs" , "fri" , "sat" };
    

    cout << "date \t: " << day << "/" << month << "/" << Year << endl;
    cout << "day order \t: " << i << endl;
    cout << "day name \t: " << daysname[i] << endl;
    
}


int main() {

    printdate();


    system("pause>0");
    return 0;
}
