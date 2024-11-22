#include<iostream>

using namespace std;


struct data_times
{
    int seconds;
    int minutes;
    int hours;
    int days;
};


bool IsLeapYear(short& Year) {

    return ((Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0 ));
}
short ReadYear() {
    short Year;
    cout << "\nPlease enter a year to check: ";
    cin >> Year;
    return Year;
}

short Readmonth() {
    short month;
    cout << "\nPlease enter a month to check: ";
    cin >> month;
    return month;
}

data_times convert(short& year , short& month){

    data_times first;

    if (month == 2)
    {
        (IsLeapYear(year))? first.days = 29 : first.days = 28;
    }
    else if (month == 1 || month == 3 || month == 12 || month == 10 || month == 8 || month == 7 || month == 5)
    {
        first.days =  31; 
    }
    else
    {
        first.days =  30; 
    }
        

    return first;
    
    
   
}

int main() {

    

for (int i = 0; i < 10; i++)
{

    short Year = ReadYear();
    short month = Readmonth();
    data_times first = convert(Year , month);
    cout << "Number of days in month [" << month <<"] is : " << first.days << endl;


}

    system("pause>0");
    return 0;
}
