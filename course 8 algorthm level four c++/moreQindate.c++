#include <iostream>
#include <ctime>
using namespace std;


struct sDate
{
    int Year;
    int Month;
    int Day;
};
bool isLeapYear(short Year) {
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

enum dayes_of_week {sunday = 0 , monday = 1 , tuesday = 2 ,
                     wedensday = 3 , thursdaay = 4 , 
                     friday = 5 , saturday = 6};


sDate GetSystemDate() {
    sDate Date;
    time_t t = time(0);
    tm* now = localtime(&t);
    Date.Year = now->tm_year + 1900;
    Date.Month = now->tm_mon + 1;
    Date.Day = now->tm_mday;
    return Date;
}

short NumberOfDaysInAMonth(short Month, short Year) {
    if(Month < 1 || Month > 12)
        return 0; // Invalid month

    int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];
}
dayes_of_week today(){
    sDate Date;
    Date = GetSystemDate();

    dayes_of_week today;
    int a , y , m , i;
    a = ((14 - Date.Month)/12);
    y = Date.Year - a;
    m = Date.Month +(12 * a) - 2;
    i = (Date.Day + y + (y/4) - (y/100) + (y/400) + ((31 * m)/12)) % 7;


    switch (i)
    {
    case 0:
        today = sunday;
        break;
    case 1:
        today = monday;
        break;
    case 2:
        today = tuesday;
        break;
    case 3:
        today = wedensday;
        break;
    case 4:
        today = thursdaay;
        break;
    case 5:
        today = friday;
        break;
    case 6:
        today = saturday;
        break;
     
    default:
    cout << "invalid day";
        break;
    }

    return today;
}
void printdate(sDate Date){
   
    int day = today();

    switch (day)
    {
    case 0:
        cout << "today is sunday , ";
        break;
    case 1:
        cout << "today is monday , ";
        break;
    case 2:
        cout << "today is tuesday , ";
        break;
    case 3:
        cout << "today is wednsday , ";
        break;
    case 4:
        cout << "today is thursday , ";
        break;
    case 5:
        cout << "today is friday , ";
        break;
    case 6:
        cout << "today is saturday , ";
        break;   
    default:
        break;
    }
    

    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;


}

bool isendofweek(){
    int day = today();

    if (day == 6)
    {
        return true;
    }

    return false;
    
}
bool isweekend(){
    int day = today();

    if (day == 6 || day == 5)
    {
        return true;
    }

    return false;
    
}
bool isbusinsday(){
    int day = today();

    if (day < 5)
    {
        return true;
    }

    return false;
    
}

int daysuntilendofmonth(sDate Date)
{
    int i;
    int count = 1;
    for (i = Date.Day; i < NumberOfDaysInAMonth(Date.Month, Date.Year) ; i++)
    {
        count ++;
    }
    return count;
    
}

    
int daysuntilendofweek(sDate Date) {
    int day = today(); // Get current day of the week
    return 6 - day;    // Days left until Saturday (6 is Saturday)
}

int countdays(sDate Date) {
    int count = 0;
    
    // Add days for all months before the given month
    for (int i = 1; i < Date.Month; i++) {
        count += NumberOfDaysInAMonth( i , Date.Year );
    }
    
    // Add days for the current month up to the given day
    count += Date.Day;
    
    return count; 
}
int daysuntilendofyear(sDate Date)
{
    int i;
    int dayesofyear;
    int count = 0;
    if (isLeapYear(Date.Year))
    {
        dayesofyear = 366;
    }
    else
    {
        dayesofyear = 365;
    }
    
    
    for (i = countdays(Date); i < dayesofyear; i++)
    {
        count ++;
    }
    return count;
    
}

int main(){
    sDate Date;
    Date = GetSystemDate();
    printdate(Date);
    cout << "is end of week? " << endl;
    if (isendofweek())
    {
        cout << "yes,is end of week" << endl;
    }
    else
    {
        cout << "no,not end of week" << endl;
    }
    cout << "is today is weekend? " << endl;
    if (isweekend())
    {
        cout << "yes,is weekend" << endl;
    }
    else
    {
        cout  << "no,not weekend" << endl;
    }
    cout << "it is bussines day? " << endl;
    if (isbusinsday())
    {
        cout << "yes , is bussins day" << endl;
    }
    else
    {
        cout << "no, not bussines day" << endl;
    }
    cout << "\n";
    cout << "days until end of week :" << daysuntilendofweek(Date) << endl;
    cout << "days until end of month :" << daysuntilendofmonth(Date) << endl;
    cout << "days until end of year :" << daysuntilendofyear(Date) << endl;
    
    return 0;
    

}



