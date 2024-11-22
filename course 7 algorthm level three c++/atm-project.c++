#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

const string filename = "train.txt";
const string separator = "//##//";


enum transction
{
    equick_withdraw = 1,
    enormal_withdraw = 2,
    edeposite = 3,
    echeck_balance = 4,
    elog_out = 5
};

enum withdrawamounts
{
    twinty = 20,
    fifty = 50,
    handred = 100,
    twohundred = 200,
    fourhundred = 400,
    sixhundred = 600,
    eighthundred = 800,
    thounsand = 1000
};

void Atm_Main_Menue() {
    cout << "===========================================" << endl;
    cout << "\t\tAtm Menu Screen" << endl;
    cout << "===========================================" << endl;
    cout << "[1] quick withdraw." << endl;
    cout << "[2] normal draw." << endl;
    cout << "[3] deposite." << endl;
    cout << "[4] check balance." << endl;
    cout << "[5] log out." << endl;
    cout << "===========================================" << endl;

}


void loginscreen() {

    cout << "===========================================" << endl;
    cout << "\t\t login screen" << endl;
    cout << "===========================================" << endl;

}

void loadClientsFromFile(vector<string>& lines, vector<string>& pin, vector<string>& AN, vector <string>& balance) {
    fstream MyFile;
    MyFile.open(filename, ios::in); // Open file in read mode

    if (MyFile.is_open()) {
        string Line;
        while (getline(MyFile, Line)) {

            AN.push_back(Line.substr(0, Line.find(separator))); // Extract account number
            lines.push_back(Line);
            pin.push_back(Line.substr(8, 3));
            balance.push_back(Line.substr(38, 5));
        }
        MyFile.close();
    }
    else {
        cout << "Error loading client data!" << endl;
    }
}
void withdraw(vector<string>& lines, vector<string>& AN, vector<string>& balance, string& acount, string& pincode, vector<string>& pin, int& Nclient) {
    int draw_amount;
    int current_balance;
    string line;
    int count = 0;


    cout << "===========================================" << endl;
    cout << "\tnormal withdraw Screen" << endl;
    cout << "===========================================" << endl;


    // Find the client by account number
    for (int i = 0; i < AN.size(); i++) {
        line = lines[i]; // Get the client data line

        cout << "Please enter withdraw amount: ";
        cin >> draw_amount;

        if (draw_amount % 5 == 0)
        {


            // Look for the 8th '#' separator to find the balance
            for (int x = 0; x < line.length(); x++) {
                if (line[x] == '#') {
                    count++;
                    if (count == 8) { // Assuming the balance is after the 8th '#'
                        // Convert current balance to integer, update with deposit, and update line
                        current_balance = stod(balance[i]) - draw_amount;
                        balance[i] = to_string(current_balance); // Update balance vector

                        // Replace the balance in the line
                        size_t start_pos = x + 3; // Move position to where balance starts
                        size_t balance_length = balance[i].length();
                        line.replace(start_pos, balance_length, to_string(current_balance));

                        // Update the line in the lines vector
                        lines[i] = line;
                        break;
                    }
                }
            }
        }
    }



    // Display updated client data (for debugging purposes)
    // Save updated data back to the file
    fstream MyFile;
    MyFile.open(filename, ios::out); // Open file in write mode to overwrite with new data

    if (!MyFile.is_open()) {
        cout << "Error opening file for writing!" << endl;
        return;
    }

    // Write updated client data to the file
    for (const string& line : lines) {
        MyFile << line << endl;
    }

    MyFile.close(); // Close the file
    cout << "withdraw completed and data saved successfully!" << endl;
}

void quick_withdraw(vector<string>& lines, vector<string>& AN, vector<string>& balance, string& account, string& pincode, vector<string>& pin, int& Nclient) {
    int draw_amount = 0;
    int current_balance = 0;
    string line;
    int count = 0;
    int choice = 0;
    char check;


    // Display the quick withdraw screen
    cout << "===========================================" << endl;
    cout << "\tQuick Withdraw Screen" << endl;
    cout << "===========================================" << endl;
    cout << "\t[1] 20   \t[2] 50" << endl;
    cout << "\t[3] 100  \t[4] 200" << endl;
    cout << "\t[5] 400  \t[6] 600" << endl;
    cout << "\t[7] 800  \t[8] 1000" << endl;
    cout << "\t[9] Exit" << endl;
    cout << "===========================================" << endl;
    cout << "Your balance = " << balance[Nclient] << endl;
    cout << "Choose which withdraw option you need from 1 to 8: ";
    cin >> choice;

    if (choice < 9 && choice > 0) {
        // Confirm the withdraw action
        cout << "\n\nAre you sure you want to do this action? y/n: ";
        cin >> check;

        if (check == 'y' || check == 'Y') {
            // Predefined withdrawal amounts
            switch (choice) {
            case 1: draw_amount = 20; break;
            case 2: draw_amount = 50; break;
            case 3: draw_amount = 100; break;
            case 4: draw_amount = 200; break;
            case 5: draw_amount = 400; break;
            case 6: draw_amount = 600; break;
            case 7: draw_amount = 800; break;
            case 8: draw_amount = 1000; break;
            }

            // Get the client data line
            line = lines[Nclient];

            // Find the 8th '#' separator to locate the balance
            for (int x = 0; x < line.length(); x++) {
                if (line[x] == '#') {
                    count++;
                    if (count == 8) { // Assuming balance is after the 8th '#'
                        current_balance = stod(balance[Nclient]) - draw_amount;

                        // Check if enough balance is available
                        if (current_balance < 0) {
                            cout << "Insufficient balance!" << endl;
                            return;
                        }

                        balance[Nclient] = to_string(current_balance); // Update balance vector

                        // Replace the balance in the line
                        size_t start_pos = x + 3; // Position where balance starts
                        size_t balance_length = balance[Nclient].length();
                        line.replace(start_pos, balance_length, to_string(current_balance));

                        // Update the line in the lines vector
                        lines[Nclient] = line;
                        cout << "Withdrawal completed successfully! Your new balance is: " << current_balance << endl;
                        break;
                    }
                }
            }
        }
        else {
            cout << "Withdrawal cancelled." << endl;
            return;
        }
    }
    else if (choice == 9) {
        cout << "Exit selected. No withdrawal performed." << endl;
        return;
    }
    else {
        cout << "Invalid choice. Please try again." << endl;
        return;
    }


    // Save updated data back to the file
    fstream MyFile;
    MyFile.open(filename, ios::out); // Open file in write mode

    if (!MyFile.is_open()) {
        cout << "Error opening file for writing!" << endl;
        return;
    }

    // Write updated client data to the file
    for (const string& line : lines) {
        MyFile << line << endl;
    }

    MyFile.close(); // Close the file
    cout << "Withdrawal completed and data saved successfully!" << endl;
}

void deposite(vector<string>& lines, vector<string>& AN, vector<string>& balance, string& acount, string& pincode, vector<string>& pin, int& Nclient) {
    int draw_amount;
    int current_balance;
    string line;
    int count = 0;


    cout << "===========================================" << endl;
    cout << "\t deposite Screen" << endl;
    cout << "===========================================" << endl;


    // Find the client by account number
    for (int i = 0; i < AN.size(); i++) {
        line = lines[i]; // Get the client data line

        cout << "Please enter deposite amount: ";
        cin >> draw_amount;

        if (draw_amount % 5 == 0)
        {


            // Look for the 8th '#' separator to find the balance
            for (int x = 0; x < line.length(); x++) {
                if (line[x] == '#') {
                    count++;
                    if (count == 8) { // Assuming the balance is after the 8th '#'
                        // Convert current balance to integer, update with deposit, and update line
                        current_balance = stod(balance[i]) + draw_amount;
                        balance[i] = to_string(current_balance); // Update balance vector

                        // Replace the balance in the line
                        size_t start_pos = x + 3; // Move position to where balance starts
                        size_t balance_length = balance[i].length();
                        line.replace(start_pos, balance_length, to_string(current_balance));

                        // Update the line in the lines vector
                        lines[i] = line;
                        break;
                    }
                }
            }
        }
    }



    // Display updated client data (for debugging purposes)
    // Save updated data back to the file
    fstream MyFile;
    MyFile.open(filename, ios::out); // Open file in write mode to overwrite with new data

    if (!MyFile.is_open()) {
        cout << "Error opening file for writing!" << endl;
        return;
    }

    // Write updated client data to the file
    for (const string& line : lines) {
        MyFile << line << endl;
    }

    MyFile.close(); // Close the file
    cout << "withdraw completed and data saved successfully!" << endl;
}

void checkblance(vector <string>& balance, vector <string>& AN, vector <string>& pin, string& account, string& pincode) {

    for (int i = 0; i < balance.size(); i++) {
        if (pin[i] == pincode && AN[i] == account) {

            cout << "===========================================" << endl;
            cout << "\t\t check balance Screen" << endl;
            cout << "===========================================" << endl;
            cout << "your balance is :  " << balance[i];
        }
    }

}



int main() {
    vector<string> pin;
    vector<string> AN;
    vector<string> lines;
    vector<string> balance;
    string acount;
    string pincode;


    loadClientsFromFile(lines, pin, AN, balance);


    while (true) {


        cout << "===========================================" << endl;
        cout << "\t\t login screen" << endl;
        cout << "===========================================" << endl;
        cout << "enter acount number?";
        getline(cin >> ws, acount);
        cout << "enter pincode?";
        getline(cin, pincode);

        for (int i = 0; i < AN.size(); i++)
        {
            if (AN[i] == acount && pin[i] == pincode)
            {

                int choice;

                Atm_Main_Menue();


                cout << "Choose what you want to do (1-5): ";
                cin >> choice;
                cin.ignore(); // Ignore leftover newline character in input

                switch (choice) {
                case equick_withdraw:
                    system("cls");
                    quick_withdraw(lines, AN, balance, acount, pincode, pin, i);
                    break;
                case enormal_withdraw:
                    system("cls");
                    withdraw(lines, AN, balance, acount, pincode, pin, i);
                    break;
                case edeposite:
                    system("cls");
                    deposite(lines, AN, balance, acount, pincode, pin, i);
                    break;
                case echeck_balance:
                    system("cls");
                    checkblance(balance, AN, pin, acount, pincode);
                    break;
                case elog_out:
                    system("cls");
                    cout << "Exiting the program." << endl;
                    return 0;
                default:
                    cout << "Invalid option. Please choose again." << endl;
                    break;
                }
            }

        }

    }



    return 0;
}