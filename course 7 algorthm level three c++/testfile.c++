#include <iostream>   // For input/output operations
#include <iomanip>    // For formatting output
#include <string>     // For using the string class
#include <vector>     // For using the vector container
#include <fstream>    // For file input/output operations

using namespace std;

// Function to split a string based on a delimiter
vector<string> SplitString(string S9, string Delim) {
    vector<string> vString;  // Vector to store the split parts of the string
    size_t pos = 0;          // Variable to hold the position of the delimiter
    string sWord;            // Variable to hold each split word

    // Loop to find the position of the delimiter and extract substrings
    while ((pos = S9.find(Delim)) != std::string::npos) {
        sWord = S9.substr(0, pos);  // Extract substring from start to delimiter position
        if (!sWord.empty()) {       // Check if the extracted substring is not empty
            vString.push_back(sWord); // Add the substring to the vector
        }
        // Erase the processed part of the string including the delimiter
        S9.erase(0, pos + Delim.length());
    }

    // If any remaining part of the string exists (the last word), add it to the vector
    if (!S9.empty()) {
        vString.push_back(S9);
    }

    return vString;  // Return the vector containing split parts
}

// Struct to hold client data
struct stClient {
    string AccountNumber = "";  // Client's account number
    string PinCode = "";        // Client's PIN code
    string Name = "";           // Client's name
    string Phone = "";          // Client's phone number
    double AccountBalance = 0;  // Client's account balance
};

// Function to convert a line from the file into a client record (struct)
// Takes a line and a separator string, and returns a client record
stClient ConvertLineToRecord(string Line, string Separator = "#//#") {
    stClient Client;                     // Create an empty client record
    vector<string> vClientData;          // Vector to hold the split line data
    vClientData = SplitString(Line, Separator);  // Split the line based on the separator

    // Assign the split data to the corresponding fields in the client struct
    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]);  // Convert string to double for balance

    return Client;  // Return the filled client record
}

// Function to print a client record to the console
void PrintClientRecord(stClient Client) {
    cout << "\n\nThe following is the extracted client record: \n\n";
    cout << "Account Number: " << Client.AccountNumber << endl;  // Print account number
    cout << "PinCode: " << Client.PinCode << endl;              // Print PIN code
    cout << "Name: " << Client.Name << endl;                    // Print client name
    cout << "Phone: " << Client.Phone << endl;                  // Print phone number
    cout << "Account Balance: " << Client.AccountBalance << endl;  // Print account balance
}

// Function to load client data from a file
// Takes the filename as input and returns a vector of client records
vector<stClient> LoadClientsDataFromFile(string FileName) {
    vector<stClient> vClients;  // Vector to store all client records
    fstream MyFile;             // File stream to handle file operations

    // Open the file in input mode (read mode)
    MyFile.open(FileName, ios::in);

    if (MyFile.is_open()) {     // Check if the file is successfully opened
        string Line;            // Variable to hold each line from the file
        stClient Client;        // Temporary client record to hold each client's data

        // Loop through the file and read each line
        while (getline(MyFile, Line)) {
            Client = ConvertLineToRecord(Line);  // Convert the line to a client record
            vClients.push_back(Client);          // Add the client record to the vector
        }

        MyFile.close();  // Close the file after reading
    }

    return vClients;  // Return the vector containing all client records
}

// Constant to store the name of the client file
const string ClientsFileName = "myfileee.txt";

// Function to find a client by their account number
// Takes the account number and returns true if the client is found
bool FindClientByAccountNumber(string AccountNumber, stClient& Client) {
    vector<stClient> vClients = LoadClientsDataFromFile(ClientsFileName);  // Load all clients

    // Loop through each client in the vector
    for (stClient C : vClients) {
        // If the account number matches, set the client data and return true
        if (C.AccountNumber == AccountNumber) {
            Client = C;
            return true;
        }
    }

    return false;  // Return false if no matching client is found
}

// Function to read and return the client's account number from the user
string ReadClientAccountNumber() {
    string AccountNumber;
    cout << "\nPlease enter Account Number: ";
    cin >> AccountNumber;  // Input account number from the user
    return AccountNumber;  // Return the entered account number
}

// Main function where program execution begins
int main() {
    stClient Client;                               // Declare a client object to store client details
    string AccountNumber = ReadClientAccountNumber();  // Read account number from the user

    // Check if the client with the entered account number exists
    if (FindClientByAccountNumber(AccountNumber, Client)) {
        PrintClientRecord(Client);  // If found, print the client's details
    } else {
        // If not found, display a message
        cout << "\nClient with Account Number (" << AccountNumber << ") is NOT Found!\n";
    }

    system("pause>0");  // Pause the system (specific to Windows)
    return 0;           // End the program
}
