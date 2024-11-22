#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

const string ClientsFileName = "Clientss.txt";
const string separator = "//##//";  // Fixed typo 'separtor' -> 'separator'

struct clientdata {
    string accountn;
    string pincode;
    string name;
    string phone;
    string balance;
};

// Function to read client data and store it in the vector
void rclient(vector<string> &clients) {  // Pass by reference
    clientdata client;

    cout << "enter client data? " << endl;

    cout << "Please enter account number: " << endl;
    getline(cin >> ws, client.accountn);  // Read input
    clients.push_back(client.accountn);   // Add to clients vector

    cout << "Please enter pincode: " << endl;
    getline(cin, client.pincode);
    clients.push_back(client.pincode);

    cout << "Please enter name: " << endl;
    getline(cin, client.name);
    clients.push_back(client.name);

    cout << "Please enter phone number: " << endl;
    getline(cin, client.phone);
    clients.push_back(client.phone);

    cout << "Please enter balance: " << endl;
    getline(cin, client.balance);
    clients.push_back(client.balance);
}

// Function to convert the record of clients to a formatted string
void convert_record_toline(string &lines, vector<string> &client) {  // Pass lines by reference

    char check = 'y';

    while (check == 'y' || check == 'Y') {
        rclient(client);  // Get client data

        // Concatenate client data with the separator
        for (int i = 0; i < client.size(); i++) {
            lines += client[i] + separator;
        }
        lines += "\n";

        client.clear();  // Clear the vector for the next client
        
        
    }

    // Print the lines after all clients are processed
    cout << "\n\n\nAll client records:" << endl;
    cout << lines << endl;
}

int main() {
    vector<string> clients;  // Vector to hold client data
    string line;  // Line to hold the concatenated client record

    convert_record_toline(line, clients);  // Call the function to process records

    return 0;
}
