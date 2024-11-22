#include <iostream>   // Includes input-output stream library for console operations
#include <fstream>    // Includes file stream library for reading/writing files
#include <string>     // Includes string library for handling strings
#include <vector>     // Includes vector library for handling dynamic arrays (vectors)
#include <iomanip>    // Includes library for formatted output

using namespace std;  // Allows us to avoid using "std::" before standard library objects like cout, cin

// Structure to define a user in the system
struct stUser
{
    string UserName;      // Stores the username
    string Password;      // Stores the password
    int Permissions;      // Stores the permission level of the user
    bool MarkForDelete = false;  // Flag to mark user for deletion (default is false)
};

// Enum for menu options related to transactions
enum enTransactionsMenueOptions { 
    eDeposit = 1,           // Option to deposit money
    eWithdraw = 2,          // Option to withdraw money
    eShowTotalBalance = 3,   // Option to show total account balance
    eShowMainMenue = 4       // Option to return to the main menu
};

// Enum for managing users in the system (used in user management menu)
enum enManageUsersMenueOptions {
    eListUsers = 1,         // Option to list all users
    eAddNewUser = 2,        // Option to add a new user
    eDeleteUser = 3,        // Option to delete a user
    eUpdateUser = 4,        // Option to update user information
    eFindUser = 5,          // Option to find a specific user by username
    eMainMenue = 6          // Option to return to the main menu
};

// Enum for main menu options
enum enMainMenueOptions {
    eListClients = 1,         // Option to list all clients
    eAddNewClient = 2,        // Option to add a new client
    eDeleteClient = 3,        // Option to delete a client
    eUpdateClient = 4,        // Option to update client information
    eFindClient = 5,          // Option to find a client by their account number
    eShowTransactionsMenue = 6,  // Option to show the transactions menu
    eManageUsers = 7,         // Option to manage users
    eExit = 8                 // Option to exit the program
};

// Enum to define permission levels for different actions
enum enMainMenuePermissions {
    eAll = -1,               // Full access to all features (for admins)
    pListClients = 1,        // Permission to list clients
    pAddNewClient = 2,       // Permission to add new clients
    pDeleteClient = 4,       // Permission to delete clients
    pUpdateClients = 8,      // Permission to update client information
    pFindClient = 16,        // Permission to search for clients
    pTranactions = 32,       // Permission to perform transactions (deposit, withdraw, etc.)
    pManageUsers = 64        // Permission to manage users (add, delete, update)
};

// Filenames for storing client and user data in text files
const string ClientsFileName = "Clients.txt";   // Name of the file where client data is stored
const string UsersFileName = "Users.txt";       // Name of the file where user data is stored

stUser CurrentUser;  // Stores the currently logged-in user's information

// Function declarations
void ShowMainMenue();        // Function to display the main menu
void ShowTransactionsMenue(); // Function to display the transactions menu
void ShowManageUsersMenue();  // Function to display the user management menu
bool CheckAccessPermission(enMainMenuePermissions Permission);  // Function to check if the user has the required permissions for an action
void Login();  // Function to handle user login

// Structure to define a client in the system
struct sClient
{
    string AccountNumber;   // Stores the client's account number
    string PinCode;         // Stores the client's PIN code
    string Name;            // Stores the client's full name
    string Phone;           // Stores the client's phone number
    double AccountBalance;  // Stores the client's current account balance
    bool MarkForDelete = false;  // Flag to mark the client for deletion (default is false)
};


// Function to split a string based on a specified delimiter
vector<string> SplitString(string S1, string Delim)
{
    vector<string> vString;  // Vector to hold the split parts of the string
    short pos = 0;  // Variable to store the position of the delimiter
    string sWord;   // String to temporarily hold each word from the split

    // Loop to find the delimiter and split the string accordingly
    while ((pos = S1.find(Delim)) != std::string::npos)  // Find the delimiter in the string
    {
        sWord = S1.substr(0, pos);  // Extract the substring from the start until the delimiter
        if (sWord != "")  // Check if the word is not empty
        {
            vString.push_back(sWord);  // Add the word to the vector
        }

        // Erase the processed part of the string and move to the next word
        S1.erase(0, pos + Delim.length());  
    }

    // After the loop, add the last remaining part of the string (if not empty)
    if (S1 != "")
    {
        vString.push_back(S1);  // Add the last word to the vector
    }

    return vString;  // Return the vector containing all split parts
}

// Function to convert a user data line into a stUser structure
stUser ConvertUserLinetoRecord(string Line, string Seperator = "#//#")
{
    stUser User;  // Declare an empty user structure to hold the converted data
    vector<string> vUserData;  // Vector to store the split parts of the line

    // Split the line into user details using the provided separator
    vUserData = SplitString(Line, Seperator);

    // Assign split data to the respective fields of the user structure
    User.UserName = vUserData[0];    // First part is the username
    User.Password = vUserData[1];    // Second part is the password
    User.Permissions = stoi(vUserData[2]);  // Third part is the permissions (convert string to int)

    return User;  // Return the filled user structure
}

// Function to convert a client data line into an sClient structure
sClient ConvertLinetoRecord(string Line, string Seperator = "#//#")
{
    sClient Client;  // Declare an empty client structure to hold the converted data
    vector<string> vClientData;  // Vector to store the split parts of the line

    // Split the line into client details using the provided separator
    vClientData = SplitString(Line, Seperator);

    // Assign split data to the respective fields of the client structure
    Client.AccountNumber = vClientData[0];    // First part is the account number
    Client.PinCode = vClientData[1];          // Second part is the PIN code
    Client.Name = vClientData[2];             // Third part is the client's name
    Client.Phone = vClientData[3];            // Fourth part is the phone number
    Client.AccountBalance = stod(vClientData[4]);  // Fifth part is the account balance (convert string to double)

    return Client;  // Return the filled client structure
}

// A duplicate of the ConvertUserLinetoRecord function, likely for testing purposes
stUser ConvertUserLinetoRecord2(string Line, string Seperator = "#//#")
{
    stUser User;  // Declare an empty user structure to hold the converted data
    vector<string> vUserData;  // Vector to store the split parts of the line

    // Split the line into user details using the provided separator
    vUserData = SplitString(Line, Seperator);

    // Assign split data to the respective fields of the user structure
    User.UserName = vUserData[0];    // First part is the username
    User.Password = vUserData[1];    // Second part is the password
    User.Permissions = stoi(vUserData[2]);  // Third part is the permissions (convert string to int)

    return User;  // Return the filled user structure
}


// Function to convert a client record into a single string line with a separator
string ConvertRecordToLine(sClient Client, string Seperator = "#//#")
{
    string stClientRecord = "";

    // Append each field of the client with the separator
    stClientRecord += Client.AccountNumber + Seperator;
    stClientRecord += Client.PinCode + Seperator;
    stClientRecord += Client.Name + Seperator;
    stClientRecord += Client.Phone + Seperator;
    stClientRecord += to_string(Client.AccountBalance);  // Convert balance to string

    return stClientRecord;  // Return the formatted string
}

// Function to convert a user record into a single string line with a separator
string ConvertUserRecordToLine(stUser User, string Seperator = "#//#")
{
    string stClientRecord = "";

    // Append each field of the user with the separator
    stClientRecord += User.UserName + Seperator;
    stClientRecord += User.Password + Seperator;
    stClientRecord += to_string(User.Permissions);  // Convert permissions to string

    return stClientRecord;  // Return the formatted string
}

// Function to check if a client exists by account number in a given file
bool ClientExistsByAccountNumber(string AccountNumber, string FileName)
{
    vector<sClient> vClients;  // Vector to store the list of clients
    fstream MyFile;
    MyFile.open(FileName, ios::in);  // Open file in read mode

    if (MyFile.is_open())
    {
        string Line;
        sClient Client;

        // Loop through each line in the file
        while (getline(MyFile, Line))
        {
            // Convert the line to a client record
            Client = ConvertLinetoRecord(Line);

            // If the account number matches, return true
            if (Client.AccountNumber == AccountNumber)
            {
                MyFile.close();  // Close the file
                return true;
            }

            vClients.push_back(Client);  // Add client to vector if not found
        }

        MyFile.close();  // Close the file after processing
    }

    return false;  // Return false if client is not found
}

// Function to check if a user exists by username in a given file
bool UserExistsByUsername(string Username, string FileName)
{
    fstream MyFile;
    MyFile.open(FileName, ios::in);  // Open file in read mode

    if (MyFile.is_open())
    {
        string Line;
        stUser User;

        // Loop through each line in the file
        while (getline(MyFile, Line))
        {
            // Convert the line to a user record
            User = ConvertUserLinetoRecord(Line);

            // If the username matches, return true
            if (User.UserName == Username)
            {
                MyFile.close();  // Close the file
                return true;
            }
        }

        MyFile.close();  // Close the file after processing
    }

    return false;  // Return false if user is not found
}

// Function to read and create a new client object with user input
sClient ReadNewClient()
{
    sClient Client;

    // Prompt user to enter the account number
    cout << "Enter Account Number? ";
    getline(cin >> ws, Client.AccountNumber);  // Read input with whitespace trimming

    // Check if the account number already exists
    while (ClientExistsByAccountNumber(Client.AccountNumber, ClientsFileName))
    {
        cout << "\nClient with [" << Client.AccountNumber << "] already exists, Enter another Account Number? ";
        getline(cin >> ws, Client.AccountNumber);  // Ask for another account number if duplicate found
    }

    // Read remaining client details from the user
    cout << "Enter PinCode? ";
    getline(cin, Client.PinCode);

    cout << "Enter Name? ";
    getline(cin, Client.Name);

    cout << "Enter Phone? ";
    getline(cin, Client.Phone);

    cout << "Enter AccountBalance? ";
    cin >> Client.AccountBalance;  // Read the balance

    return Client;  // Return the filled client structure
}

// Function to read permissions from the user and set access levels
int ReadPermissionsToSet()
{
    int Permissions = 0;  // Initialize permissions to 0
    char Answer = 'n';  // Variable to store user response

    // Ask if full access should be given
    cout << "\nDo you want to give full access? y/n? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {
        return -1;  // Return -1 if full access is granted
    }

    // Ask for specific permissions and adjust the permissions variable accordingly
    cout << "\nDo you want to give access to : \n";

    cout << "\nShow Client List? y/n? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {
        Permissions += enMainMenuePermissions::pListClients;  // Add permission to list clients
    }

    cout << "\nAdd New Client? y/n? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {
        Permissions += enMainMenuePermissions::pAddNewClient;  // Add permission to add new clients
    }

    cout << "\nDelete Client? y/n? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {
        Permissions += enMainMenuePermissions::pDeleteClient;  // Add permission to delete clients
    }

    cout << "\nUpdate Client? y/n? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {
        Permissions += enMainMenuePermissions::pUpdateClients;  // Add permission to update clients
    }

    cout << "\nFind Client? y/n? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {
        Permissions += enMainMenuePermissions::pFindClient;  // Add permission to find clients
    }

    cout << "\nTransactions? y/n? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {
        Permissions += enMainMenuePermissions::pTranactions;  // Add permission for transactions
    }

    cout << "\nManage Users? y/n? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {
        Permissions += enMainMenuePermissions::pManageUsers;  // Add permission to manage users
    }

    return Permissions;  // Return the final permissions value
}

// Function to read and create a new user object with user input
stUser ReadNewUser()
{
    stUser User;

    // Prompt user to enter the username
    cout << "Enter Username? ";
    getline(cin >> ws, User.UserName);  // Read input with whitespace trimming

    // Check if the username already exists
    while (UserExistsByUsername(User.UserName, UsersFileName))
    {
        cout << "\nUser with [" << User.UserName << "] already exists, Enter another Username? ";
        getline(cin >> ws, User.UserName);  // Ask for another username if duplicate found
    }

    // Read the password and set permissions
    cout << "Enter Password? ";
    getline(cin, User.Password);

    User.Permissions = ReadPermissionsToSet();  // Read and set the permissions

    return User;  // Return the filled user structure
}

// Function to load user data from a file into a vector
vector<stUser> LoadUsersDataFromFile(string FileName)
{
    vector<stUser> vUsers;  // Vector to store the list of users
    fstream MyFile;
    MyFile.open(FileName, ios::in);  // Open file in read mode

    if (MyFile.is_open())
    {
        string Line;
        stUser User;

        // Loop through each line in the file
        while (getline(MyFile, Line))
        {
            // Convert the line to a user record and add it to the vector
            User = ConvertUserLinetoRecord(Line);
            vUsers.push_back(User);
        }

        MyFile.close();  // Close the file after processing
    }

    return vUsers;  // Return the vector containing all users
}

// Function to load client data from a file and return it as a vector of clients
vector <sClient> LoadCleintsDataFromFile(string FileName)
{
    vector <sClient> vClients; // Vector to store clients

    fstream MyFile;
    MyFile.open(FileName, ios::in); // Open file in read mode

    if (MyFile.is_open())
    {
        string Line;
        sClient Client;

        // Read file line by line
        while (getline(MyFile, Line))
        {
            // Convert line to client record
            Client = ConvertLinetoRecord(Line);
            vClients.push_back(Client); // Add client to vector
        }

        MyFile.close(); // Close file
    }

    return vClients; // Return vector of clients
}

// Function to print a single client record in a formatted manner
void PrintClientRecordLine(sClient Client)
{
    cout << "| " << setw(15) << left << Client.AccountNumber;
    cout << "| " << setw(10) << left << Client.PinCode;
    cout << "| " << setw(40) << left << Client.Name;
    cout << "| " << setw(12) << left << Client.Phone;
    cout << "| " << setw(12) << left << Client.AccountBalance;
}

// Function to print a single user record in a formatted manner
void PrintUserRecordLine(stUser User)
{
    cout << "| " << setw(15) << left << User.UserName;
    cout << "| " << setw(10) << left << User.Password;
    cout << "| " << setw(40) << left << User.Permissions;
}

// Function to print only the balance information of a client
void PrintClientRecordBalanceLine(sClient Client)
{
    cout << "| " << setw(15) << left << Client.AccountNumber;
    cout << "| " << setw(40) << left << Client.Name;
    cout << "| " << setw(12) << left << Client.AccountBalance;
}

// Function to display access denied message when permission is insufficient
void ShowAccessDeniedMessage()
{
    cout << "\n------------------------------------\n";
    cout << "Access Denied, \nYou don't Have Permission To Do this,\nPlease Contact Your Admin.";
    cout << "\n------------------------------------\n";
}

// Function to display all clients' information
void ShowAllClientsScreen()
{
    // Check if user has permission to list clients
    if (!CheckAccessPermission(enMainMenuePermissions::pListClients))
    {
        ShowAccessDeniedMessage();
        return;
    }

    // Load clients from file
    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);

    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    // Print header for the client list
    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    // Check if there are no clients
    if (vClients.size() == 0)
        cout << "\t\t\t\tNo Clients Available In the System!";
    else
        // Print each client's record
        for (sClient Client : vClients)
        {
            PrintClientRecordLine(Client);
            cout << endl;
        }

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
}

// Function to display all users' information
void ShowAllUsersScreen()
{
    // Load users from file
    vector <stUser> vUsers = LoadUsersDataFromFile(UsersFileName);

    cout << "\n\t\t\t\t\tUsers List (" << vUsers.size() << ") User(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    // Print header for the user list
    cout << "| " << left << setw(15) << "User Name";
    cout << "| " << left << setw(10) << "Password";
    cout << "| " << left << setw(40) << "Permissions";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    // Check if there are no users
    if (vUsers.size() == 0)
        cout << "\t\t\t\tNo Users Available In the System!";
    else
        // Print each user's record
        for (stUser User : vUsers)
        {
            PrintUserRecordLine(User);
            cout << endl;
        }

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
}

// Function to display all clients' balances and total balance
void ShowTotalBalances()
{
    // Load clients from file
    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);

    cout << "\n\t\t\t\t\tBalances List (" << vClients.size() << ") Client(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    // Print header for the balances
    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    double TotalBalances = 0; // Variable to store total balance

    // Check if there are no clients
    if (vClients.size() == 0)
        cout << "\t\t\t\tNo Clients Available In the System!";
    else
        // Print each client's balance and calculate total
        for (sClient Client : vClients)
        {
            PrintClientRecordBalanceLine(Client);
            TotalBalances += Client.AccountBalance;
            cout << endl;
        }

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    cout << "\t\t\t\t\t   Total Balances = " << TotalBalances; // Print total balance
}

// Function to print the details of a client in a formatted card
void PrintClientCard(sClient Client)
{
    cout << "\nThe following are the client details:\n";
    cout << "-----------------------------------";
    cout << "\nAccout Number: " << Client.AccountNumber;
    cout << "\nPin Code     : " << Client.PinCode;
    cout << "\nName         : " << Client.Name;
    cout << "\nPhone        : " << Client.Phone;
    cout << "\nAccount Balance: " << Client.AccountBalance;
    cout << "\n-----------------------------------\n";
}

// Function to print the details of a user in a formatted card
void PrintUserCard(stUser User)
{
    cout << "\nThe following are the user details:\n";
    cout << "-----------------------------------";
    cout << "\nUsername    : " << User.UserName;
    cout << "\nPassword    : " << User.Password;
    cout << "\nPermissions : " << User.Permissions;
    cout << "\n-----------------------------------\n";
}

// Function to find a client by account number
bool FindClientByAccountNumber(string AccountNumber, vector <sClient> vClients, sClient& Client)
{
    // Iterate through the list of clients
    for (sClient C : vClients)
    {
        // Check if account number matches
        if (C.AccountNumber == AccountNumber)
        {
            Client = C; // Return found client
            return true;
        }
    }
    return false; // Return false if not found
}

// Function to find a user by username
bool FindUserByUsername(string Username, vector <stUser> vUsers, stUser& User)
{
    // Iterate through the list of users
    for (stUser U : vUsers)
    {
        // Check if username matches
        if (U.UserName == Username)
        {
            User = U; // Return found user
            return true;
        }
    }
    return false; // Return false if not found
}

// Function to find a user by username and password
bool FindUserByUsernameAndPassword(string Username, string Password, stUser& User)
{
    vector <stUser> vUsers = LoadUsersDataFromFile(UsersFileName); // Load users from file

    // Iterate through the list of users
    for (stUser U : vUsers)
    {
        // Check if username and password match
        if (U.UserName == Username && U.Password == Password)
        {
            User = U; // Return found user
            return true;
        }
    }
    return false; // Return false if not found
}

// Function to change client record
sClient ChangeClientRecord(string AccountNumber)
{
    sClient Client;
    Client.AccountNumber = AccountNumber; // Assign account number

    cout << "\n\nEnter PinCode? ";
    getline(cin >> ws, Client.PinCode); // Get new pin code

    cout << "Enter Name? ";
    getline(cin, Client.Name); // Get new name

    cout << "Enter Phone? ";
    getline(cin, Client.Phone); // Get new phone number

    cout << "Enter AccountBalance? ";
    cin >> Client.AccountBalance; // Get new balance

    return Client; // Return modified client
}

// Function to change an existing user record by username
stUser ChangeUserRecord(string Username) {
    stUser User; // Create a new user object

    User.UserName = Username; // Set the username for the user

    // Ask for the password
    cout << "\n\nEnter Password? ";
    getline(cin >> ws, User.Password); // Read the password input

    // Set user permissions
    User.Permissions = ReadPermissionsToSet();

    return User; // Return the updated user object
}

// Function to mark a client for deletion by their account number
bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector<sClient>& vClients) {
    // Loop through the vector of clients to find a match by account number
    for (sClient& C : vClients) {
        if (C.AccountNumber == AccountNumber) {
            C.MarkForDelete = true; // Mark client for deletion
            return true; // Return true if client is found and marked
        }
    }
    return false; // Return false if no match is found
}

// Function to mark a user for deletion by their username
bool MarkUserForDeleteByUsername(string Username, vector<stUser>& vUsers) {
    // Loop through the vector of users to find a match by username
    for (stUser& U : vUsers) {
        if (U.UserName == Username) {
            U.MarkForDelete = true; // Mark user for deletion
            return true; // Return true if user is found and marked
        }
    }
    return false; // Return false if no match is found
}

// Function to save the clients' data to a file (excluding deleted clients)
vector<sClient> SaveCleintsDataToFile(string FileName, vector<sClient> vClients) {
    fstream MyFile;
    MyFile.open(FileName, ios::out); // Open file to overwrite

    string DataLine;

    if (MyFile.is_open()) {
        // Loop through all clients
        for (sClient C : vClients) {
            if (!C.MarkForDelete) { // Only save clients not marked for deletion
                DataLine = ConvertRecordToLine(C); // Convert client record to a string
                MyFile << DataLine << endl; // Write data to file
            }
        }
        MyFile.close(); // Close the file
    }
    return vClients; // Return the updated client list
}

// Function to save the users' data to a file (excluding deleted users)
vector<stUser> SaveUsersDataToFile(string FileName, vector<stUser> vUsers) {
    fstream MyFile;
    MyFile.open(FileName, ios::out); // Open file to overwrite

    string DataLine;

    if (MyFile.is_open()) {
        // Loop through all users
        for (stUser U : vUsers) {
            if (!U.MarkForDelete) { // Only save users not marked for deletion
                DataLine = ConvertUserRecordToLine(U); // Convert user record to a string
                MyFile << DataLine << endl; // Write data to file
            }
        }
        MyFile.close(); // Close the file
    }
    return vUsers; // Return the updated user list
}

// Function to add a new data line to the file
void AddDataLineToFile(string FileName, string stDataLine) {
    fstream MyFile;
    MyFile.open(FileName, ios::out | ios::app); // Open file in append mode

    if (MyFile.is_open()) {
        MyFile << stDataLine << endl; // Write the new line to the file
        MyFile.close(); // Close the file
    }
}

// Function to add a new client to the file
void AddNewClient() {
    sClient Client = ReadNewClient(); // Read new client data
    AddDataLineToFile(ClientsFileName, ConvertRecordToLine(Client)); // Add the client to the file
}

// Function to add a new user to the file
void AddNewUser() {
    stUser User = ReadNewUser(); // Read new user data
    AddDataLineToFile(UsersFileName, ConvertUserRecordToLine(User)); // Add the user to the file
}

// Function to keep adding new clients until the user decides to stop
void AddNewClients() {
    char AddMore = 'Y';
    do {
        cout << "Adding New Client:\n\n";
        AddNewClient(); // Call the function to add a client
        cout << "\nClient Added Successfully, do you want to add more clients? Y/N? ";
        cin >> AddMore; // Ask if the user wants to add more clients
    } while (toupper(AddMore) == 'Y'); // Continue while the user enters 'Y'
}

// Function to keep adding new users until the user decides to stop
void AddNewUsers() {
    char AddMore = 'Y';
    do {
        cout << "Adding New User:\n\n";
        AddNewUser(); // Call the function to add a user
        cout << "\nUser Added Successfully, do you want to add more Users? Y/N? ";
        cin >> AddMore; // Ask if the user wants to add more users
    } while (toupper(AddMore) == 'Y'); // Continue while the user enters 'Y'
}

// Function to delete a client by their account number
bool DeleteClientByAccountNumber(string AccountNumber, vector<sClient>& vClients) {
    sClient Client;
    char Answer = 'n';

    if (FindClientByAccountNumber(AccountNumber, vClients, Client)) {
        PrintClientCard(Client); // Display client details
        cout << "\n\nAre you sure you want delete this client? y/n ? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y') {
            MarkClientForDeleteByAccountNumber(AccountNumber, vClients); // Mark the client for deletion
            SaveCleintsDataToFile(ClientsFileName, vClients); // Save changes to file
            vClients = LoadCleintsDataFromFile(ClientsFileName); // Refresh client list
            cout << "\n\nClient Deleted Successfully.";
            return true;
        }
    } else {
        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
        return false;
    }
}

// Function to delete a user by their username
bool DeleteUserByUsername(string Username, vector<stUser>& vUsers) {
    if (Username == "Admin") {
        cout << "\n\nYou cannot Delete This User."; // Prevent deleting admin
        return false;
    }

    stUser User;
    char Answer = 'n';

    if (FindUserByUsername(Username, vUsers, User)) {
        PrintUserCard(User); // Display user details
        cout << "\n\nAre you sure you want delete this User? y/n ? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y') {
            MarkUserForDeleteByUsername(Username, vUsers); // Mark the user for deletion
            SaveUsersDataToFile(UsersFileName, vUsers); // Save changes to file
            vUsers = LoadUsersDataFromFile(UsersFileName); // Refresh user list
            cout << "\n\nUser Deleted Successfully.";
            return true;
        }
    } else {
        cout << "\nUser with Username (" << Username << ") is Not Found!";
        return false;
    }
}

// Function to update a client's information by their account number
bool UpdateClientByAccountNumber(string AccountNumber, vector<sClient>& vClients) {
    sClient Client;
    char Answer = 'n';

    if (FindClientByAccountNumber(AccountNumber, vClients, Client)) {
        PrintClientCard(Client); // Display client details
        cout << "\n\nAre you sure you want update this client? y/n ? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y') {
            // Find and update the client record
            for (sClient& C : vClients) {
                if (C.AccountNumber == AccountNumber) {
                    C = ChangeClientRecord(AccountNumber); // Change client record
                    break;
                }
            }
            SaveCleintsDataToFile(ClientsFileName, vClients); // Save changes to file
            cout << "\n\nClient Updated Successfully.";
            return true;
        }
    } else {
        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
        return false;
    }
}

// Function to update a user's information by their username
bool UpdateUserByUsername(string Username, vector<stUser>& vUsers) {
    stUser User;
    char Answer = 'n';

    if (FindUserByUsername(Username, vUsers, User)) {
        PrintUserCard(User); // Display user details
        cout << "\n\nAre you sure you want update this User? y/n ? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y') {
            // Find and update the user record
            for (stUser& U : vUsers) {
                if (U.UserName == Username) {
                    U = ChangeUserRecord(Username); // Change user record
                    break;
                }
            }
            SaveUsersDataToFile(UsersFileName, vUsers); // Save changes to file
            cout << "\n\nUser Updated Successfully.";
            return true;
        }
    } else {
        cout << "\nUser with Username (" << Username << ") is Not Found!";
        return false;
    }
}


// Function to deposit balance to a client's account using the account number
bool DepositBalanceToClientByAccountNumber(string AccountNumber, double Amount, vector <sClient>& vClients)
{
    char Answer = 'n';  // Variable to store user confirmation
    cout << "\n\nAre you sure you want to perform this transaction? y/n ? ";
    cin >> Answer;

    // If user confirms the transaction
    if (Answer == 'y' || Answer == 'Y')
    {
        // Iterate through the list of clients to find the matching account number
        for (sClient& C : vClients)
        {
            if (C.AccountNumber == AccountNumber)
            {
                // Update client's account balance
                C.AccountBalance += Amount;

                // Save updated client data to file
                SaveCleintsDataToFile(ClientsFileName, vClients);
                cout << "\n\nTransaction completed successfully. New balance is: " << C.AccountBalance;

                return true; // Transaction successful
            }
        }

        return false;  // If no matching account number is found
    }

    return false;  // If user does not confirm the transaction
}

// Function to read and return the client's account number
string ReadClientAccountNumber()
{
    string AccountNumber = "";
    cout << "\nPlease enter AccountNumber? ";
    cin >> AccountNumber;
    return AccountNumber;
}

// Function to read and return the username
string ReadUserName()
{
    string Username = "";
    cout << "\nPlease enter Username? ";
    cin >> Username;
    return Username;
}

// Function to show the list of all users
void ShowListUsersScreen()
{
    ShowAllUsersScreen();  // Calls function to display users
}

// Function to show the screen for adding a new user
void ShowAddNewUserScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tAdd New User Screen";
    cout << "\n-----------------------------------\n";

    AddNewUsers();  // Calls the function to add a new user
}

// Function to show the screen for deleting a user
void ShowDeleteUserScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tDelete Users Screen";
    cout << "\n-----------------------------------\n";

    vector <stUser> vUsers = LoadUsersDataFromFile(UsersFileName);  // Load user data from file

    string Username = ReadUserName();  // Read the username to be deleted
    DeleteUserByUsername(Username, vUsers);  // Delete user by username
}

// Function to show the screen for updating user details
void ShowUpdateUserScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tUpdate Users Screen";
    cout << "\n-----------------------------------\n";

    vector <stUser> vUsers = LoadUsersDataFromFile(UsersFileName);  // Load user data from file
    string Username = ReadUserName();  // Read the username to be updated

    UpdateUserByUsername(Username, vUsers);  // Update user details by username
}

// Function to show the screen for deleting a client
void ShowDeleteClientScreen()
{
    // Check if the current user has permission to delete a client
    if (!CheckAccessPermission(enMainMenuePermissions::pDeleteClient))
    {
        ShowAccessDeniedMessage();  // Show access denied message if no permission
        return;
    }

    cout << "\n-----------------------------------\n";
    cout << "\tDelete Client Screen";
    cout << "\n-----------------------------------\n";

    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);  // Load clients from file
    string AccountNumber = ReadClientAccountNumber();  // Read the account number to delete
    DeleteClientByAccountNumber(AccountNumber, vClients);  // Delete the client
}

// Function to show the screen for updating a client's information
void ShowUpdateClientScreen()
{
    // Check if the current user has permission to update client info
    if (!CheckAccessPermission(enMainMenuePermissions::pUpdateClients))
    {
        ShowAccessDeniedMessage();  // Show access denied message if no permission
        return;
    }

    cout << "\n-----------------------------------\n";
    cout << "\tUpdate Client Info Screen";
    cout << "\n-----------------------------------\n";

    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);  // Load client data
    string AccountNumber = ReadClientAccountNumber();  // Read the client's account number
    UpdateClientByAccountNumber(AccountNumber, vClients);  // Update the client by account number
}

// Function to show the screen for adding new clients
void ShowAddNewClientsScreen()
{
    // Check if the current user has permission to add new clients
    if (!CheckAccessPermission(enMainMenuePermissions::pUpdateClients))
    {
        ShowAccessDeniedMessage();  // Show access denied message if no permission
        return;
    }

    cout << "\n-----------------------------------\n";
    cout << "\tAdd New Clients Screen";
    cout << "\n-----------------------------------\n";

    AddNewClients();  // Call the function to add new clients
}

// Function to show the screen for finding a client
void ShowFindClientScreen()
{
    // Check if the current user has permission to find a client
    if (!CheckAccessPermission(enMainMenuePermissions::pFindClient))
    {
        ShowAccessDeniedMessage();  // Show access denied message if no permission
        return;
    }

    cout << "\n-----------------------------------\n";
    cout << "\tFind Client Screen";
    cout << "\n-----------------------------------\n";

    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);  // Load client data
    sClient Client;
    string AccountNumber = ReadClientAccountNumber();  // Read the account number to find

    // Check if the client with the account number is found
    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
        PrintClientCard(Client);  // Print the client details
    else
        cout << "\nClient with Account Number[" << AccountNumber << "] is not found!";
}

// Function to show the screen for finding a user
void ShowFindUserScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tFind User Screen";
    cout << "\n-----------------------------------\n";

    vector <stUser> vUsers = LoadUsersDataFromFile(UsersFileName);  // Load user data
    stUser User;
    string Username = ReadUserName();  // Read the username to find

    // Check if the user with the username is found
    if (FindUserByUsername(Username, vUsers, User))
        PrintUserCard(User);  // Print the user details
    else
        cout << "\nUser with Username [" << Username << "] is not found!";
}

// Function to show the program end screen
void ShowEndScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tProgram Ends :-)";
    cout << "\n-----------------------------------\n";
}

// Function to show the deposit screen for a client
void ShowDepositScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tDeposit Screen";
    cout << "\n-----------------------------------\n";

    sClient Client;
    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);  // Load client data
    string AccountNumber = ReadClientAccountNumber();  // Read the account number for deposit

    // Check if the client with the account number is found
    while (!FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
        AccountNumber = ReadClientAccountNumber();  // Read again if not found
    }

    PrintClientCard(Client);  // Print client details

    double Amount = 0;
    cout << "\nPlease enter deposit amount? ";
    cin >> Amount;  // Read deposit amount

    DepositBalanceToClientByAccountNumber(AccountNumber, Amount, vClients);  // Deposit to account
}

// Function to show the withdraw screen for a client
void ShowWithDrawScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tWithdraw Screen";
    cout << "\n-----------------------------------\n";

    sClient Client;
    vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);  // Load client data
    string AccountNumber = ReadClientAccountNumber();  // Read the account number for withdrawal

    // Check if the client with the account number is found
    while (!FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
        AccountNumber = ReadClientAccountNumber();  // Read again if not found
    }

    PrintClientCard(Client);  // Print client details

    double Amount = 0;
    cout << "\nPlease enter withdraw amount? ";
    cin >> Amount;  // Read withdrawal amount

    // Validate that the amount does not exceed the balance
    while (Amount > Client.AccountBalance)
    {
        cout << "\nAmount exceeds the balance, you can withdraw up to: " << Client.AccountBalance << endl;
        cout << "Please enter another amount? ";
        cin >> Amount;  // Read a valid amount
    }

    DepositBalanceToClientByAccountNumber(AccountNumber, Amount * -1, vClients);  // Withdraw amount
}


// Function to show the total balances screen
void ShowTotalBalancesScreen()
{
    ShowTotalBalances();  // Call function to display the total balances
}

// Function to check if the current user has the required permission
bool CheckAccessPermission(enMainMenuePermissions Permission)
{
    // If the current user has all permissions, grant access
    if (CurrentUser.Permissions == enMainMenuePermissions::eAll)
        return true;

    // Check if the user has the specific permission required
    if ((Permission & CurrentUser.Permissions) == Permission)
        return true;
    else
        return false;
}

// Function to go back to the main menu
void GoBackToMainMenue()
{
    cout << "\n\nPress any key to go back to Main Menue...";
    system("pause>0");  // Wait for the user to press a key
    ShowMainMenue();     // Call function to display the main menu
}

// Function to go back to the transactions menu
void GoBackToTransactionsMenue()
{
    cout << "\n\nPress any key to go back to Transactions Menue...";
    system("pause>0");  // Wait for the user to press a key
    ShowTransactionsMenue();  // Call function to display the transactions menu
}

// Function to go back to the manage users menu
void GoBackToManageUsersMenue()
{
    cout << "\n\nPress any key to go back to Manage Users Menue...";
    system("pause>0");  // Wait for the user to press a key
    ShowManageUsersMenue();  // Call function to display the manage users menu
}

// Function to read the user's choice from the transactions menu
short ReadTransactionsMenueOption()
{
    cout << "Choose what do you want to do? [1 to 4]? ";
    short Choice = 0;
    cin >> Choice;  // Read the user's choice
    return Choice;
}

// Function to perform the selected transactions menu option
void PerfromTranactionsMenueOption(enTransactionsMenueOptions TransactionMenueOption)
{
    switch (TransactionMenueOption)
    {
        case enTransactionsMenueOptions::eDeposit:
        {
            system("cls");  // Clear the screen
            ShowDepositScreen();  // Call function to display the deposit screen
            GoBackToTransactionsMenue();  // Go back to the transactions menu
            break;
        }

        case enTransactionsMenueOptions::eWithdraw:
        {
            system("cls");  // Clear the screen
            ShowWithDrawScreen();  // Call function to display the withdraw screen
            GoBackToTransactionsMenue();  // Go back to the transactions menu
            break;
        }

        case enTransactionsMenueOptions::eShowTotalBalance:
        {
            system("cls");  // Clear the screen
            ShowTotalBalancesScreen();  // Call function to display total balances
            GoBackToTransactionsMenue();  // Go back to the transactions menu
            break;
        }

        case enTransactionsMenueOptions::eShowMainMenue:
        {
            ShowMainMenue();  // Call function to display the main menu
            break;
        }
    }
}

// Function to display the transactions menu
void ShowTransactionsMenue()
{
    // Check if the user has permission to access the transactions menu
    if (!CheckAccessPermission(enMainMenuePermissions::pTranactions))
    {
        ShowAccessDeniedMessage();  // Display access denied message
        GoBackToMainMenue();  // Go back to the main menu
        return;
    }

    system("cls");  // Clear the screen
    cout << "===========================================\n";
    cout << "\t\tTransactions Menue Screen\n";
    cout << "===========================================\n";
    cout << "\t[1] Deposit.\n";
    cout << "\t[2] Withdraw.\n";
    cout << "\t[3] Total Balances.\n";
    cout << "\t[4] Main Menue.\n";
    cout << "===========================================\n";

    // Perform the selected transactions menu option
    PerfromTranactionsMenueOption((enTransactionsMenueOptions)ReadTransactionsMenueOption());
}

// Function to read the user's choice from the main menu
short ReadMainMenueOption()
{
    cout << "Choose what do you want to do? [1 to 8]? ";
    short Choice = 0;
    cin >> Choice;  // Read the user's choice
    return Choice;
}

// Function to perform the selected manage users menu option
void PerfromManageUsersMenueOption(enManageUsersMenueOptions ManageUsersMenueOption)
{
    switch (ManageUsersMenueOption)
    {
        case enManageUsersMenueOptions::eListUsers:
        {
            system("cls");  // Clear the screen
            ShowListUsersScreen();  // Call function to list all users
            GoBackToManageUsersMenue();  // Go back to the manage users menu
            break;
        }

        case enManageUsersMenueOptions::eAddNewUser:
        {
            system("cls");  // Clear the screen
            ShowAddNewUserScreen();  // Call function to add a new user
            GoBackToManageUsersMenue();  // Go back to the manage users menu
            break;
        }

        case enManageUsersMenueOptions::eDeleteUser:
        {
            system("cls");  // Clear the screen
            ShowDeleteUserScreen();  // Call function to delete a user
            GoBackToManageUsersMenue();  // Go back to the manage users menu
            break;
        }

        case enManageUsersMenueOptions::eUpdateUser:
        {
            system("cls");  // Clear the screen
            ShowUpdateUserScreen();  // Call function to update a user
            GoBackToManageUsersMenue();  // Go back to the manage users menu
            break;
        }

        case enManageUsersMenueOptions::eFindUser:
        {
            system("cls");  // Clear the screen
            ShowFindUserScreen();  // Call function to find a user
            GoBackToManageUsersMenue();  // Go back to the manage users menu
            break;
        }

        case enManageUsersMenueOptions::eMainMenue:
        {
            ShowMainMenue();  // Call function to display the main menu
            break;
        }
    }
}

// Function to read the user's choice from the manage users menu
short ReadManageUsersMenueOption()
{
    cout << "Choose what do you want to do? [1 to 6]? ";
    short Choice = 0;
    cin >> Choice;  // Read the user's choice
    return Choice;
}

// Function to display the manage users menu
void ShowManageUsersMenue()
{
    // Check if the user has permission to access the manage users menu
    if (!CheckAccessPermission(enMainMenuePermissions::pManageUsers))
    {
        ShowAccessDeniedMessage();  // Display access denied message
        GoBackToMainMenue();  // Go back to the main menu
        return;
    }

    system("cls");  // Clear the screen
    cout << "===========================================\n";
    cout << "\t\tManage Users Menue Screen\n";
    cout << "===========================================\n";
    cout << "\t[1] List Users.\n";
    cout << "\t[2] Add New User.\n";
    cout << "\t[3] Delete User.\n";
    cout << "\t[4] Update User.\n";
    cout << "\t[5] Find User.\n";
    cout << "\t[6] Main Menue.\n";
    cout << "===========================================\n";

    // Perform the selected manage users menu option
    PerfromManageUsersMenueOption((enManageUsersMenueOptions)ReadManageUsersMenueOption());
}

// Function to perform the selected option from the main menu
void PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
{
    switch (MainMenueOption)
    {
    case enMainMenueOptions::eListClients:
    {
        system("cls");  // Clear the screen
        ShowAllClientsScreen();  // Call function to show all clients
        GoBackToMainMenue();  // Go back to the main menu
        break;
    }
    case enMainMenueOptions::eAddNewClient:
        system("cls");  // Clear the screen
        ShowAddNewClientsScreen();  // Call function to add a new client
        GoBackToMainMenue();  // Go back to the main menu
        break;

    case enMainMenueOptions::eDeleteClient:
        system("cls");  // Clear the screen
        ShowDeleteClientScreen();  // Call function to delete a client
        GoBackToMainMenue();  // Go back to the main menu
        break;

    case enMainMenueOptions::eUpdateClient:
        system("cls");  // Clear the screen
        ShowUpdateClientScreen();  // Call function to update client information
        GoBackToMainMenue();  // Go back to the main menu
        break;

    case enMainMenueOptions::eFindClient:
        system("cls");  // Clear the screen
        ShowFindClientScreen();  // Call function to find a specific client
        GoBackToMainMenue();  // Go back to the main menu
        break;

    case enMainMenueOptions::eShowTransactionsMenue:
        system("cls");  // Clear the screen
        ShowTransactionsMenue();  // Call function to show the transactions menu
        break;

    case enMainMenueOptions::eManageUsers:
        system("cls");  // Clear the screen
        ShowManageUsersMenue();  // Call function to show the manage users menu
        break;

    case enMainMenueOptions::eExit:
        system("cls");  // Clear the screen
        // ShowEndScreen();  // Optional: Call function to show end screen if needed
        Login();  // Log out and return to the login screen
        break;
    }
}

// Function to display the main menu
void ShowMainMenue()
{
    system("cls");  // Clear the screen
    cout << "===========================================\n";
    cout << "\t\tMain Menue Screen\n";
    cout << "===========================================\n";
    cout << "\t[1] Show Client List.\n";  // Option to show all clients
    cout << "\t[2] Add New Client.\n";  // Option to add a new client
    cout << "\t[3] Delete Client.\n";  // Option to delete a client
    cout << "\t[4] Update Client Info.\n";  // Option to update client information
    cout << "\t[5] Find Client.\n";  // Option to find a specific client
    cout << "\t[6] Transactions.\n";  // Option to access transactions menu
    cout << "\t[7] Manage Users.\n";  // Option to access manage users menu
    cout << "\t[8] Logout.\n";  // Option to log out
    cout << "===========================================\n";

    // Perform the option chosen by the user
    PerfromMainMenueOption((enMainMenueOptions)ReadMainMenueOption());
}

// Function to load user information based on the username and password
bool LoadUserInfo(string Username, string Password)
{
    // Check if the username and password match any user in the system
    if (FindUserByUsernameAndPassword(Username, Password, CurrentUser))
        return true;  // If found, load the user information
    else
        return false;  // If not found, return false
}

// Function to handle the login process
void Login()
{
    bool LoginFaild = false;  // Flag to track if login failed

    string Username, Password;  // Variables to store user input

    do
    {
        system("cls");  // Clear the screen

        // Display the login screen
        cout << "\n---------------------------------\n";
        cout << "\tLogin Screen";
        cout << "\n---------------------------------\n";

        // If the login failed previously, show an error message
        if (LoginFaild)
        {
            cout << "Invalid Username/Password!\n";
        }

        // Prompt the user for their username
        cout << "Enter Username? ";
        cin >> Username;

        // Prompt the user for their password
        cout << "Enter Password? ";
        cin >> Password;

        // Try to load the user info with the provided username and password
        LoginFaild = !LoadUserInfo(Username, Password);

    } while (LoginFaild);  // Repeat until login is successful

    // If login is successful, display the main menu
    ShowMainMenue();
}

int main()

{
    Login();

    system("pause>0");
    return 0;
}