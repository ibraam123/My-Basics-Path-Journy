#include <iostream>

using namespace std;

// Function to check if a year is a leap year
bool IsLeapYear(short year) {
    return ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0));
}

// Function to read the year from the user
short ReadYear() {
    short year;
    cout << "\nPlease enter a year to check: ";
    cin >> year;
    return year;
}

// Function to get the number of days in a month
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

// Function to print the calendar for a given year
void PrintCalendar(short year) {
    string months[12] = {"January", "February", "March", "April", "May", "June",
                         "July", "August", "September", "October", "November", "December"};
    string daysname[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

    cout << "\n\n";
    cout << "\t\t   Calendar - " << year << "\n\n";

    for (int i = 1; i <= 12; i++) {
        cout << "_______________________ " << months[i - 1] << " _______________________" << endl << endl;

        for (int j = 0; j < 7; j++) {
            cout << daysname[j] << "\t";
        }
        cout << endl;

        cout << "\t\t\t\t";
        for (int x = 1; x <= DaysInMonth(year, i); x++) {
            cout << x << "\t";
            // Adding new lines to fit the calendar format
            if (x == 3 || x == 10 || x == 17 || x == 24) {
                cout << endl;
            }
        }
        cout << endl;
        cout << "____________________________________________________" << endl << endl;
    }
}

int main() {
    short year = ReadYear();
    PrintCalendar(year);

    system("pause>0");
    return 0;
}
