#include<iostream>

using namespace std;

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

int days(short& year , short& month){
   
    if (month == 2)
    {
        if(IsLeapYear(year)){ 
            return 29;
        }
        else
        {
            return 28;
        }
          
    }
    else if (month == 1 || month == 3 || month == 12 || month == 10 || month == 8 || month == 7 || month == 5)
    {
        return  31; 
    }
    else
    {
        return  30; 
    }
        
    
}

int main() {

    

     short Year = ReadYear();
     short month = Readmonth();
     
    string months[12] = {"January", "February", "March", "April", "May", "June", 
                         "July", "August", "September", "October", "November", "December"};
        
    string daysname[7] = {"sun" , "mon" , "tue" , "wed" , "thurs" , "fri" , "sat" };



    


    cout << "_______________________ " << months[month-1] << " _______________________"  << endl << endl;

    for (int i = 0; i < 7; i++)
    {
        cout << daysname[i] << "\t" ;
    }
    cout << endl;
    cout << "\t\t\t\t";
    for (int i = 1; i <= days(Year , month); i++)
    {
        cout << i << "\t";
        if (i == 3)
        {
            cout << endl;
        }
        else if (i == 10)
        {
            cout << endl;
        }
        else if (i == 17)
        {
            cout << endl;
        }
        else if (i == 24)
        {
            cout << endl;
        }
        
        
        
        
    }
    cout << endl;
    cout << "____________________________________________________"  << endl << endl;

    system("pause>0");
    return 0;
}
