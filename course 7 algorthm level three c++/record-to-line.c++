#include <iostream>
#include <string>
using namespace std;

struct cleint_data
{
    string Anum;
    int pincode;
    string name;
    int Pnum;
    float Abalance;
};
cleint_data cleint_one;

string readAnum(){
    cout << "Enter Account Number?";
    cin >>  cleint_one.Anum;
    return cleint_one.Anum;
}
int readpincode(){
    cout << "Enter pincode?";
    cin >>  cleint_one.pincode;
    return cleint_one.pincode;
}
string readname(){
    cout << "Enter name?";
    cin >>  cleint_one.name;
    return cleint_one.name;
}
int phonenumber(){
    cout << "Enter Phone?";
    cin >>  cleint_one.Pnum;
    return cleint_one.Pnum;
}
int readbalance(){
    cout << "Enter balance?";
    cin >>  cleint_one.Abalance;
    return cleint_one.Abalance;
}

int main(){
    cout << "Please enter client data: " << "\n\n" ;
    string acountnum = readAnum();
    int pin = readpincode();
    string name = readname();
    int phone = phonenumber();
    float balance = readbalance();
    string separtor = "#//#";


    cout << "\n\n client record for saving is: "<< endl;
    cout << acountnum << separtor << pin << separtor << name << separtor << phone << separtor << balance;

    return 0;  
}
/**sing namespace std;
// Problem #45
struct stClient
{
string AccountNumber = "";
string PinCode = "";
string Name = "";
string Phone = "";
int AccountBalance = 0;
};
stClient ReadNewClient()
{
stClient Client;
cout << "Enter Account Number ? ";
// Usage of std::ws will extract all the whitespace character
// whitespace عند تكرار الإدخال - في بعض الأحيان
يتم تجاوز الإدخال لأنه قد يخزن
getline(cin >> ws, Client.AccountNumber);
cout << "Enter PinCode ? ";
getline(cin, Client.PinCode);
cout << "Enter Name ? ";
getline(cin, Client.Name);
cout << "Enter Phone ? ";
getline(cin, Client.Phone);
cout << "Enter Account Balance ? ";
cin >> Client.AccountBalance;
return Client;
}
string CounvertRecordToLine(stClient Client, string Separator = "#//#")
{
string stClientRecord = "";
stClientRecord += Client.AccountNumber + Separator;
stClientRecord += Client.PinCode + Separator;
stClientRecord += Client.Name + Separator;
stClientRecord += Client.Phone + Separator;
stClientRecord += to_string(Client.AccountBalance);
return stClientRecord;
} */