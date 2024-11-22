#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

const string filename = "train.txt";
const string separator = "//##//";

enum options_choose {
    show_client = 1,
    add_new_client = 2,
    delete_client = 3,
    update_client = 4,
    find_client = 5,
    exit_program = 6
};

struct sCleintdata {
    string accountNumber;
    string pincode;
    string name;
    string phoneNumber;
    string balance;
};

void main_menue() {
    cout << "===========================================" << endl;
    cout << "\t\tMain menu Screen" << endl;
    cout << "===========================================" << endl;
    cout << "[1] Show Client List." << endl;
    cout << "[2] Add New Client." << endl;
    cout << "[3] Delete Client." << endl;
    cout << "[4] Update Client." << endl;
    cout << "[5] Find Client." << endl;
    cout << "[6] Exit." << endl;
    cout << "===========================================" << endl;
}

// Function to check if account number already exists
bool accountExists(const string& account, const vector<string>& AN) {
    return find(AN.begin(), AN.end(), account) != AN.end();
}

// Function to read client data
void vCleintread(vector<string>& vcleint) {
    sCleintdata info;
    
    cout << "Enter Account Number: ";
    getline(cin >> ws, info.accountNumber);
    vcleint.push_back(info.accountNumber);

    cout << "Enter Pincode: ";
    getline(cin, info.pincode);
    vcleint.push_back(info.pincode);

    cout << "Enter Name: ";
    getline(cin, info.name);
    vcleint.push_back(info.name);

    cout << "Enter Phone Number: ";
    getline(cin, info.phoneNumber);
    vcleint.push_back(info.phoneNumber);

    cout << "Enter Balance: ";
    getline(cin, info.balance);
    vcleint.push_back(info.balance);
}

// Function to read client data without the account number (for updates)
void vCleintread_without_An(vector<string>& vcleint) {
    sCleintdata info;

    cout << "Enter Pincode: ";
    getline(cin >> ws, info.pincode);
    vcleint.push_back(info.pincode);

    cout << "Enter Name: ";
    getline(cin, info.name);
    vcleint.push_back(info.name);

    cout << "Enter Phone Number: ";
    getline(cin, info.phoneNumber);
    vcleint.push_back(info.phoneNumber);

    cout << "Enter Balance: ";
    getline(cin, info.balance);
    vcleint.push_back(info.balance);
}

// Function to write client data to file
void writefile(vector<string>& vcleint, vector<string>& lines, vector<string>& AN) {
    fstream myfile;
    char check = 'y';
    string all_line;

    myfile.open(filename, ios::out | ios::app); // Open file in append mode
    if (!myfile.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }

    while (check == 'y' || check == 'Y') {
        vCleintread(vcleint);

        // Check if account number already exists
        if (accountExists(vcleint[0], AN)) {
            cout << "Account number already exists! Try again with a different account number." << endl;
            vcleint.clear(); // Clear the current client details and start again
            continue;
        }

        AN.push_back(vcleint[0]);

        for (int i = 0; i < vcleint.size(); i++) {
            myfile << vcleint[i];
            all_line += vcleint[i] + separator;
            if (i < vcleint.size() - 1) {
                myfile << separator; // Add separator between fields
            }
        }
        myfile << endl; // End the line after writing one client's data
        lines.push_back(all_line);
        all_line.clear();

        vcleint.clear(); // Clear the vector for the next client

        cout << "Client added successfully. Do you want to add more clients (y/n)? ";
        cin >> check;
        cin.ignore(); // Ignore leftover newline character in input
    }
    myfile.close(); // Close the file after all entries are done
}

// Function to show the list of clients
void show_clients_list() {
    fstream MyFile;
    MyFile.open(filename, ios::in); // Open file in read mode
    if (MyFile.is_open()) {
        string Line;
        while (getline(MyFile, Line)) {
            cout << Line << endl;
        }
        MyFile.close();
    } else {
        cout << "Error opening file!" << endl;
    }
}

// Function to delete a client record
void delete_marked_line(vector<string>& lines, vector<string>& AN) {
    fstream MyFile;
    MyFile.open(filename, ios::out); // Open file in write mode
    if (!MyFile.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }

    string nacount;
    char check = 'y';

    cout << "Please enter the account number of the record you want to delete: ";
    cin >> nacount;

    for (int i = 0; i < AN.size(); i++) {
        if (nacount == AN[i]) {
            cout << "The following data will be deleted: " << endl;
            cout << lines[i] << endl;
            cout << "Are you sure you want to delete this record? (y/n) ";
            cin >> check;
            if (check == 'y' || check == 'Y') {
                lines.erase(lines.begin() + i);
                AN.erase(AN.begin() + i);
                cout << "Record deleted successfully." << endl;
                break;
            }
        }
    }

    // Write remaining lines back to the file
    for (const string& line : lines) {
        MyFile << line << endl;
    }

    MyFile.close();
}

// Function to update a client record
void update_client_function(vector<string>& lines, vector<string>& AN) {
    fstream MyFile;
    MyFile.open(filename, ios::out); // Open file in write mode
    if (!MyFile.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }

    string nacount, newline = "";
    char check = 'n';
    vector<string> client;

    cout << "Please enter the account number of the record you want to update: ";
    cin >> nacount;

    for (int i = 0; i < AN.size(); i++) {
        if (nacount == AN[i]) {
            cout << "The following data will be updated: " << endl;
            cout << lines[i] << endl;
            cout << "Are you sure you want to update this record? (y/n) ";
            cin >> check;
            if (check == 'y' || check == 'Y') {
                vCleintread_without_An(client);
                newline = AN[i] + separator; // Add account number back
                for (int j = 0; j < client.size(); j++) {
                    newline += client[j] + separator;
                }
                lines[i] = newline; // Update the line with new data
                cout << "Client updated successfully." << endl;
                break;
            }
        }
    }

    // Write updated lines back to the file
    for (const string& line : lines) {
        MyFile << line << endl;
    }

    MyFile.close();
}

// Function to find a client by account number
void find_client_function(vector<string>& lines, vector<string>& AN) {
    string nacount;
    cout << "Please enter the account number of the record you want to find: ";
    cin >> nacount;

    for (int i = 0; i < AN.size(); i++) {
        if (nacount == AN[i]) {
            cout << "The following data was found: " << endl;
            cout << lines[i] << endl;
            return;
        }
    }

    cout << "Account number not found!" << endl;
}

int main() {
    vector<string> client;
    vector<string> AN;
    vector<string> lines;

    int choice;
    while (true) {
        main_menue();
        cout << "Choose what you want to do (1-6): ";
        cin >> choice;
        cin.ignore(); // Ignore leftover newline character in input

        switch (choice) {
            case show_client:
                show_clients_list();
                break;
            case add_new_client:
                writefile(client, lines, AN);
                break;
            case delete_client:
                delete_marked_line(lines, AN);
                break;
            case update_client:
                update_client_function(lines, AN);
                break;
            case find_client:
                find_client_function(lines, AN);
                break;
            case exit_program:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid option. Please choose again." << endl;
                break;
        }
    }

    return 0;
}
