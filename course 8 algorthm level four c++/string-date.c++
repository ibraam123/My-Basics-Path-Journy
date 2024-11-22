#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct stDate {
    short Year;
    short Month;
    short Day;
};

// Function to split a string by a delimiter
vector<string> SplitString(string S1, string Delim) {
    vector<string> vString;
    short pos = 0;
    string sWord;

    // Use find() function to get the position of the delimiters
    while ((pos = S1.find(Delim)) != std::string::npos) {
        sWord = S1.substr(0, pos); // Store the word

        if (sWord != "") {
            vString.push_back(sWord);
        }

        S1.erase(0, pos + Delim.length());
    }

    if (S1 != "") {
        vString.push_back(S1); // Add the last word of the string
    }

    return vString;
}

// Function to convert a date structure to string format
string DateToString(stDate Date) {
    return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
}

// Function to convert a date string to a date structure
stDate StringToDate(string DateString) {
    stDate Date;
    vector<string> vDate;

    vDate = SplitString(DateString, "/");
    Date.Day = stoi(vDate[0]);
    Date.Month = stoi(vDate[1]);
    Date.Year = stoi(vDate[2]);

    return Date;
}

// Function to read a date string from the user
string ReadStringDate(string Message) {
    string DateString;
    cout << Message;
    getline(cin >> ws, DateString);
    return DateString;
}
void PrintFormatDate(stDate Date) {

    cout << "\n" << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
    cout << "\n" << Date.Year << "/" << Date.Day << "/" << Date.Month << endl;
    cout << "\n" << Date.Month << "/" << Date.Day << "/" << Date.Year << endl;
    cout << "\n" << Date.Month << "-" << Date.Day << "-" << Date.Year << endl;
    cout << "\n" << Date.Day << "-" << Date.Month << "-" << Date.Year << endl;
    cout << "\n" << "Day:"<< Date.Day << ", Month:" << Date.Month << ", Year:" << Date.Year << endl;
}
int main() {
    string DateString = ReadStringDate("\nPlease Enter Date dd/mm/yyyy? ");
    stDate Date = StringToDate(DateString);

    PrintFormatDate(Date);

    system("pause>0");
    return 0;
}
