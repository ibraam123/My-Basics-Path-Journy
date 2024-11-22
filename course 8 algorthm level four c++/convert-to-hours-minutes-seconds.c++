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

data_times convert(short& year){

    data_times first;

    if (IsLeapYear(year))
    {
         first.days =  366;
         first.hours = first.days * 24;
         first.minutes = first.hours * 60;
         first.seconds = first.minutes * 60;
    }else
    {
         first.days =  365;
         first.hours = first.days * 24;
         first.minutes = first.hours * 60;
         first.seconds = first.minutes * 60;
    }

    return first;
    
    
   
}

int main() {

    

for (int i = 0; i < 10; i++)
{

    short Year = ReadYear();
    data_times first = convert(Year);
    cout << "Number of days in year [" << Year <<"] is : " << first.days << endl;
    cout << "Number of hours in year [" << Year <<"] is : " << first.hours << endl;
    cout << "Number of minutes in year [" << Year <<"] is : " << first.minutes << endl;
    cout << "Number of seconds in year [" << Year <<"] is : " << first.seconds << endl;


}

    system("pause>0");
    return 0;
}
