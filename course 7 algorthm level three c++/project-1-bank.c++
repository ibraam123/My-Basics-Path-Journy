#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

const string filename = "train.txt";
const string separator = "//##//";

// Enum to define menu options
enum options_choose {
    show_client = 1,
    add_new_client = 2,
    delete_client = 3,
    update_client = 4,
    find_client = 5,
    transction_menue = 6, 
    exit_program = 7
};

enum transction
{
    edoposit = 1 , 
    ewithdraw = 2 ,
    etotal_balance = 3,
    emain_menue = 4
};

// Structure to hold client data
struct sCleintdata {
    string accountNumber;
    string pincode;
    string name;
    string phoneNumber;
    string balance;
};

// Function to display the main menu
void main_menu() {
    cout << "===========================================" << endl;
    cout << "\t\tMain Menu Screen" << endl;
    cout << "===========================================" << endl;
    cout << "[1] Show Client list." << endl;
    cout << "[2] Add new Client." << endl;
    cout << "[3] Delete Client." << endl;
    cout << "[4] Update Client." << endl;
    cout << "[5] Find Client." << endl;
    cout << "[6] transction menue." << endl;
    cout << "[7] Exit." << endl;
    cout << "===========================================" << endl;
}


void main_menu_transction() {
    cout << "===========================================" << endl;
    cout << "\t\ttransction menue" << endl;
    cout << "===========================================" << endl;
    cout << "[1] deposite." << endl;
    cout << "[2] withdraw." << endl;
    cout << "[3] total balance." << endl;
    cout << "[4] main menue." << endl;
    cout << "===========================================" << endl;
}


// Function to read a client's data and push it into a vector
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

// Function to read the client list from the file at the beginning of the program
void loadClientsFromFile(vector<string>& lines, vector<string>& AN) {
    fstream MyFile;
    MyFile.open(filename, ios::in); // Open file in read mode

    if (MyFile.is_open()) {
        string Line;
        while (getline(MyFile, Line)) {
            lines.push_back(Line);
            AN.push_back(Line.substr(0, Line.find(separator))); // Extract account number
        }
        MyFile.close();
    } else {
        cout << "Error loading client data!" << endl;
    }
}

// Function to write a new client to the file
void writefile(vector<string>& vcleint, vector<string>& lines, vector<string>& AN ,vector<string>& balance) {
    fstream myfile;
    myfile.open(filename, ios::out | ios::app); // Open file in append mode

    if (!myfile.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }

    char check = 'y';
    string all_line;

    while (check == 'y' || check == 'Y') {
        vCleintread(vcleint);
        AN.push_back(vcleint[0]); // Add the account number to the vector
        balance.push_back(vcleint[4]); // add the balance number to vector

        // Build the line to write to the file
        for (int i = 0; i < vcleint.size(); i++) {
            all_line += vcleint[i] + separator;
        }
        lines.push_back(all_line); // Store the entire line in the vector
        myfile << all_line << endl; // Write to file
        all_line.clear();
        vcleint.clear(); // Clear the vector for the next client

        // Ask if the user wants to add more clients
        cout << "Client Added Successfully. Do you want to add more clients (y/n)? ";
        cin >> check;
        cin.ignore();
    }


    myfile.close(); // Close the file
}

// Function to show the list of clients from the file
void show_clients_list(vector<string>& lines) {
    for (const string& line : lines) {
        cout << line << endl;
    }
}

// Function to delete a client based on the account number
void delete_marked_line(vector<string>& lines, vector<string>& AN) {
    string account;
    char check = 'y';
    fstream MyFile;
    MyFile.open(filename, ios::out); // Open file in write mode

    cout << "Please enter the account number of the record you want to delete: ";
    cin >> account;

    for (int i = 0; i < AN.size(); i++) {
        if (account == AN[i]) {
            cout << "The following data will be deleted: " << endl;
            cout << lines[i] << endl;
            cout << "Are you sure you want to delete this record? (y/n): ";
            cin >> check;

            if (check == 'y' || check == 'Y') {
                lines.erase(lines.begin() + i);
                AN.erase(AN.begin() + i);
                cout << "Record deleted successfully!" << endl;
            }
            break;
        }
    }

    // Rewrite the remaining data to the file
    for (const string& line : lines) {
        MyFile << line << endl;
    }
    MyFile.close();
}

// Function to update a client's information
void update_client_function(vector<string>& lines, vector<string>& AN) {
    string account, newline;
    vector<string> client;
    char check = 'n';

    cout << "Please enter the account number of the record you want to update: ";
    cin >> account;

    for (int i = 0; i < AN.size(); i++) {
        if (account == AN[i]) {
            cout << "The following data will be updated: " << endl;
            cout << lines[i] << endl;
            cout << "Are you sure you want to update this record? (y/n): ";
            cin >> check;

            if (check == 'y' || check == 'Y') {
                vCleintread(client); // Read the updated information
                for (int j = 0; j < client.size(); j++) {
                    newline += client[j] + separator;
                }
                lines[i] = newline;
                cout << "Client updated successfully!" << endl;
            }
            break;
        }
    }

    // Write the updated data back to the file
    fstream MyFile;
    MyFile.open(filename, ios::out); // Open file in write mode
    for (const string& line : lines) {
        MyFile << line << endl;
    }
    MyFile.close();
}

// Function to find a client by account number
void find_client_function(vector<string>& lines, vector<string>& AN) {
    string account;

    cout << "Please enter the account number of the client you want to find: ";
    cin >> account;

    for (int i = 0; i < AN.size(); i++) {
        if (account == AN[i]) {
            cout << "Client data found: " << endl;
            cout << lines[i] << endl;
            
        }
    }


}


void deposite(vector<string>& lines, vector<string>& AN, vector<string>& balance) {
    string account;
    int deposit_amount;
    int current_balance;
    string line;
    int count = 0;

    cout << "===========================================" << endl;
    cout << "\t\tDeposit Screen" << endl;
    cout << "===========================================" << endl;

    cout << "Please enter the account number of the client you want to deposit to: ";
    cin >> account;

    // Find the client by account number
    for (int i = 0; i < AN.size(); i++) {
        if (account == AN[i]) {
            cout << "Client data details: " << endl;
            cout << lines[i] << endl;
            line = lines[i]; // Get the client data line

            cout << "Please enter deposit amount: ";
            cin >> deposit_amount;

            // Look for the 8th '#' separator to find the balance
            for (int x = 0; x < line.length(); x++) {
                if (line[x] == '#') {
                    count++;
                    if (count == 8) { // Assuming the balance is after the 8th '#'
                        // Convert current balance to integer, update with deposit, and update line
                        current_balance = deposit_amount + stod(balance[i]);
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
    for (int i = 0; i < lines.size(); i++) {
        cout << "Line " << i << ": " << lines[i] << endl;
    }

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
    cout << "Deposit completed and data saved successfully!" << endl;
}


void withdraw(vector<string>& lines, vector<string>& AN, vector<string>& balance) {
    string account;
    int draw_amount;
    int current_balance;
    string line;
    int count = 0;

    cout << "===========================================" << endl;
    cout << "\twithdraw Screen" << endl;
    cout << "===========================================" << endl;

    cout << "Please enter the account number of the client you want to withdraw to: ";
    cin >> account;

    // Find the client by account number
    for (int i = 0; i < AN.size(); i++) {
        if (account == AN[i]) {
            cout << "Client data details: " << endl;
            cout << lines[i] << endl;
            line = lines[i]; // Get the client data line

            cout << "Please enter deposit amount: ";
            cin >> draw_amount;

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
    for (int i = 0; i < lines.size(); i++) {
        cout << "Line " << i << ": " << lines[i] << endl;
    }

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

double totbalance(vector<string>& balance)
{
    double total = 0;

    for (int i = 0; i < balance.size(); i++)
    {
        total = total + stod(balance[i]);
    }

    return total;
    

}


void transaction(vector<string>& lines, vector<string>& AN, vector<string>& balance) {
    int choice;
    while (true) {
        main_menu_transction();
        cout << "Choose what you want to do (1-4): ";
        cin >> choice;
        cin.ignore(); // Ignore leftover newline character in input

        switch (choice) {
            case edoposit:
                system("cls");
                deposite(lines, AN, balance);
                break;
            case ewithdraw:
                system("cls");
                withdraw(lines, AN, balance);
                break;
            case etotal_balance:
                system("cls");
                show_clients_list(lines);
                cout << "\n\n totala balance = " << totbalance(balance);
                break;
            case emain_menue:
                return; // Go back to the main menu
            default:
                cout << "Invalid option. Please choose again." << endl;
                break;
        }
    }
}


int main() {
    vector<string> client;
    vector<string> AN;
    vector<string> lines;
    vector<string> balance;

    // Load the existing clients from the file
    loadClientsFromFile(lines, AN);
    int choice;
    while (true) {
        main_menu();
        cout << "Choose what you want to do (1-7): ";
        cin >> choice;
        cin.ignore(); // Ignore leftover newline character in input

        switch (choice) {
            case show_client:
                system("cls");
                show_clients_list(lines);
                break;
            case add_new_client:
                system("cls");
                writefile(client, lines, AN ,balance);
                break;
            case delete_client:
                system("cls");
                delete_marked_line(lines, AN);
                break;
            case update_client:
                system("cls");
                update_client_function(lines, AN);
                break;
            case find_client:
                system("cls");
                find_client_function(lines, AN);
                break;
            case transction_menue:
                system("cls");
                transaction(lines,AN,balance);
                break;    
            case exit_program:
                system("cls");
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid option. Please choose again." << endl;
                break;
        }
    }



    system("pause>0");
}
