#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

const string filename = "extintion.txt";
const string separator = "//##//";
const string filenameuser = "users.txt";



enum enMainMenuePermissions {
    pfullaccess =  -1 ,
    pListClients = 1 ,
    pAddNewClient = 2 ,
    pDeleteClient = 4 ,
    pUpdateClients = 8 ,
    pFindClient = 16 ,
    pTranactions = 32 ,
    pManageUsers = 64 
};

enum options_choose {
    eshow_client = 1,
    eadd_new_client = 2,
    edelete_client = 3,
    eupdate_client = 4,
    efind_client = 5,
    etransction_menue = 6, 
    emanage_users = 7 ,
    eexit_program = 8
};

enum transction
{
    edoposit = 1 , 
    ewithdraw = 2 ,
    etotal_balance = 3,
    emain_menue = 4
};

enum usermenue
{
    elist_users = 1 ,
    eAdd_new_user = 2 ,
    eDelete_user = 3 ,
    eudate_user = 4 , 
    efind_user = 5 ,
    umain_menue = 6
};


// Structure to hold client data
struct sCleintdata {
    string accountNumber;
    string pincode;
    string name;
    string phoneNumber;
    string balance;
};
struct sUserdata {
    string username;
    string password;
    int permissions;
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
    cout << "[7] manage menue users." << endl;
    cout << "[8] logout." << endl;
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

void login_screen(){
    cout << "===========================================" << endl;
    cout <<"\t\tlogin user" << endl;
    cout << "===========================================" << endl;

}
void manage_users_menue(){
    cout << "===========================================" << endl;
    cout << "\t\tManage Users Menue" << endl;
    cout << "===========================================" << endl;
    cout << "[1] Show users list." << endl;
    cout << "[2] Add new user." << endl;
    cout << "[3] Delete user." << endl;
    cout << "[4] Update user." << endl;
    cout << "[5] Find user." << endl;
    cout << "[6] return to main menue." << endl;
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


void vUserread(vector<string>& vUsers) {
    sUserdata userinfo;

    cout << "Enter username: " << endl;
    getline(cin >> ws , userinfo.username);
    vUsers.push_back(userinfo.username);

    cout << "Enter password: " << endl;
    getline(cin , userinfo.password);
    vUsers.push_back(userinfo.password);


}

void loaduserFromFile(vector<string>& ulines, vector<string>& upass ,vector <string>& usna) {
    fstream MyFile;
    MyFile.open(filenameuser, ios::in); // Open file in read mode

    if (MyFile.is_open()) {
        string Line;
        while (getline(MyFile, Line)) {
            ulines.push_back(Line);
            usna.push_back(Line.substr(0 , Line.find(separator)));
        }
        MyFile.close();
    } else {
        cout << "Error loading client data!" << endl;
    }
}



bool check_user(vector<string>& usna, vector<string>& upass) {
    string uline;
    string pass;
    
    cout << "Enter username: " << endl;
    getline(cin, uline);
    
    cout << "Enter password: " << endl;
    getline(cin, pass);

    // Loop through the usernames
    for (int i = 0; i < usna.size(); i++) {
        // Compare the entered username and password with the stored ones
        if (usna[i] == uline ) {
            return true; // User authenticated successfully
        }
    }

    return false; // Username or password incorrect
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
void addnewuser(vector<string>& vUser,vector<string>& ulines, vector<string>& usna ,  vector<string>& upass ) {
    fstream myfile;
    myfile.open(filenameuser, ios::out | ios::app); // Open file in append mode

    if (!myfile.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }

    char check = 'y';
    string all_line;


    while (check == 'y' || check == 'Y') {
        vUserread(vUser);
        usna.push_back(vUser[0]); // Add the account number to the vector
        // Build the line to write to the file
        for (int i = 0; i < vUser.size(); i++){
            all_line += vUser[i] + separator;
        }
        ulines.push_back(all_line); // Store the entire line in the vector
        myfile << all_line << endl; // Write to file
        all_line.clear();
        vUser.clear(); // Clear the vector for the next client

        // Ask if the user wants to add more clients
        cout << "users Added Successfully. Do you want to add more users (y/n)? ";
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
void show_users(vector<string>& ulines) {
    for (const string& line : ulines) {
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
void delete_user(vector<string>& ulines, vector<string>& usna) {
    string account;
    char check = 'y';
    fstream MyFile;
    MyFile.open(filenameuser, ios::out); // Open file in write mode

    cout << "Please enter the username of the record you want to delete: ";
    cin >> account;

    for (int i = 0; i < usna.size(); i++) {
        if (account == usna[i]) {
            cout << "The following data will be deleted: " << endl;
            cout << ulines[i] << endl;
            cout << "Are you sure you want to delete this record? (y/n): ";
            cin >> check;

            if (check == 'y' || check == 'Y') {
                ulines.erase(ulines.begin() + i);
                usna.erase(usna.begin() + i);
                cout << "Record deleted successfully!" << endl;
            }
            break;
        }
    }

    // Rewrite the remaining data to the file
    for (const string& line : ulines) {
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

void update_user(vector<string>& ulines, vector<string>& usna) {
    string account, newline;
    vector<string> client;
    char check = 'n';

    cout << "Please enter the username of the record you want to update: ";
    cin >> account;

    for (int i = 0; i < usna.size(); i++) {
        if (account == usna[i]) {
            cout << "The following data will be updated: " << endl;
            cout << ulines[i] << endl;
            cout << "Are you sure you want to update this record? (y/n): ";
            cin >> check;

            if (check == 'y' || check == 'Y') {
                vUserread(client); // Read the updated information
                for (int j = 0; j < client.size(); j++) {
                    newline += client[j] + separator;
                }
                ulines[i] = newline;
                cout << "record updated successfully!" << endl;
            }
            break;
        }
    }

    // Write the updated data back to the file
    fstream MyFile;
    MyFile.open(filenameuser, ios::out); // Open file in write mode
    for (const string& line : ulines) {
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

void find_user(vector<string>& ulines, vector<string>& usna) {
    string account;

    cout << "Please enter the username of the user you want to find: ";
    cin >> account;

    for (int i = 0; i < usna.size(); i++) {
        if (account == usna[i]) {
            cout << "user data found: " << endl;
            cout << ulines[i] << endl;
            
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

            // Convert current balance and add the deposit
            current_balance = deposit_amount + stod(balance[i]);
            balance[i] = to_string(current_balance); // Update balance vector

            // Update the balance in the line by finding the right position
            size_t start_pos = line.rfind(separator); // Find the last separator for balance
            line.replace(start_pos + separator.length(), string::npos, balance[i]);

            lines[i] = line; // Update the line with the new balance
            cout << "Deposit completed. New balance: " << balance[i] << endl;
        }
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
    cout << "\tWithdraw Screen" << endl;
    cout << "===========================================" << endl;

    cout << "Please enter the account number of the client you want to withdraw from: ";
    cin >> account;

    // Find the client by account number
    for (int i = 0; i < AN.size(); i++) {
        if (account == AN[i]) {
            cout << "Client data details: " << endl;
            cout << lines[i] << endl;
            line = lines[i]; // Get the client data line

            cout << "Please enter withdrawal amount: ";
            cin >> draw_amount;

            // Convert current balance and subtract the withdrawal
            current_balance = stod(balance[i]) - draw_amount;
            balance[i] = to_string(current_balance); // Update balance vector

            // Update the balance in the line by finding the right position
            size_t start_pos = line.rfind(separator); // Find the last separator for balance
            line.replace(start_pos + separator.length(), string::npos, balance[i]);

            lines[i] = line; // Update the line with the new balance
            cout << "Withdrawal completed. New balance: " << balance[i] << endl;
        }
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
    cout << "Withdrawal completed and data saved successfully!" << endl;
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
void manage_users(vector<string>& vUser,vector<string>& ulines, vector<string>& usna ,  vector<string>& upass ) {
    int choice;
    while (true) {
        manage_users_menue();
        cout << "Choose what you want to do (1-6): ";
        cin >> choice;
        cin.ignore(); // Ignore leftover newline character in input

        switch (choice) {
            case elist_users:
                system("cls");
                show_users(ulines);
                break;
            case eAdd_new_user:
                system("cls");
                addnewuser(vUser,ulines,usna,upass);
                break;
            case eDelete_user:
                system("cls");
                delete_user(ulines,usna);
                break;
            case eudate_user:
                system("cls");
                update_user(ulines , usna);
                break;
            case efind_user:
                system("cls");
                find_user(ulines,usna);
                break;
            case umain_menue:
                return; // Go back to the main menu
            default:
                cout << "Invalid option. Please choose again." << endl;
                break;
        }
    }
}


int main() {
    vector <string> ulines;
    vector <string> upass;
    vector <string> client;
    vector <string> AN;
    vector <string> lines;
    vector <string> balance;
    vector <string> vUser;
    vector <string> usna;

    // Load the existing clients from the file
    loadClientsFromFile(lines, AN);
    loaduserFromFile(ulines , upass , usna);
    login_screen();
    if (check_user(usna,upass))
    {
    
    int choice;
    while (true) {
        main_menu();
        cout << "Choose what you want to do (1-8): ";
        cin >> choice;
        cin.ignore(); // Ignore leftover newline character in input

        switch (choice) {
            case eshow_client:
                system("cls");
                show_clients_list(lines);
                break;
            case eadd_new_client:
                system("cls");
                writefile(client, lines, AN ,balance);
                break;
            case edelete_client:
                system("cls");
                delete_marked_line(lines, AN);
                break;
            case eupdate_client:
                system("cls");
                update_client_function(lines, AN);
                break;
            case efind_client:
                system("cls");
                find_client_function(lines, AN);
                break;
            case etransction_menue:
                system("cls");
                transaction(lines,AN,balance);
                break;    
            case emanage_users:
                system("cls");
                manage_users(vUser , ulines , usna , upass);
                break;
            case eexit_program:
                system("cls");
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid option. Please choose again." << endl;
                break;
        }
    }
   }

    


    system("pause>0");
}


