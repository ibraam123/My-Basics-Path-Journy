#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct ClientData {
    string accountNumber;
    int pincode;
    string name;
    int phoneNumber;
    float balance;
};

ClientData client_one;

string readAccountNumber() {
    cout << "Enter Account Number: ";
    cin >> client_one.accountNumber;
    return client_one.accountNumber;
}

int readPincode() {
    cout << "Enter pincode: ";
    cin >> client_one.pincode;
    return client_one.pincode;
}

string readName() {
    cout << "Enter name: ";
    cin.ignore(); // Ignore any leftover newline characters
    getline(cin, client_one.name);
    return client_one.name;
}

int readPhoneNumber() {
    cout << "Enter Phone Number: ";
    cin >> client_one.phoneNumber;
    return client_one.phoneNumber;
}

float readBalance() {
    cout << "Enter balance: ";
    cin >> client_one.balance;
    return client_one.balance;
}

int main() {
    string separator = "  | ";
    char check = 'Y';

    fstream myFile;
    myFile.open("myfileee.txt", ios::app);

    if (!myFile.is_open()) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    while (check == 'Y' || check == 'y') {

        cout << "Please enter client data: " << "\n\n";

        string accountNum = readAccountNumber();
        int pin = readPincode();
        string name = readName();
        int phone = readPhoneNumber();
        float balance = readBalance();

        myFile << accountNum << "\t\t" << separator << pin << "\t" << separator << name << "\t\t" << separator << phone << "\t" << separator << balance << "\t" << endl;

        cout << "Client added successfully. Do you want to add more clients [Y]es, [N]o? ";
        cin >> check;
    }

    myFile.close();
    return 0;
}
