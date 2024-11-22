#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

const string ClientsFileName = "Clientss.txt";
const string separator = "//##//";  // Separator between client data

struct clientdata {
    string accountn;
    string pincode;
    string name;
    string phone;
    string balance;
};

// Function to read client data and store it in the vector
void rclient(vector<string> &clients) {  
    clientdata client;

    cout << "\nEnter client data:" << endl;
    
    cout << "Account number: ";
    getline(cin >> ws, client.accountn);  // Read input
    clients.push_back(client.accountn);   // Add to clients vector

    cout << "Pincode: ";
    getline(cin, client.pincode);
    clients.push_back(client.pincode);

    cout << "Name: ";
    getline(cin, client.name);
    clients.push_back(client.name);

    cout << "Phone number: ";
    getline(cin, client.phone);
    clients.push_back(client.phone);

    cout << "Balance: ";
    getline(cin, client.balance);
    clients.push_back(client.balance);
}

// Function to add multiple clients
void read_new_clients(vector<string> &clients) {
    char check = 'y';
    rclient(clients);
    while (check == 'y' || check == 'Y') {
        cout << "\nAdding new client " << endl;
        

        cout << "\nClient added successfully. Do you want to add another? (y/n): ";
        cin >> check;
        cin.ignore();
        rclient(clients);

    }
}

// Function to convert the record of clients to a formatted string and save it to the file
void convert_record_toline(string &lines, vector<string> &client) {  // Pass lines by reference

    char check = 'y';
    while (check == 'y' || check == 'Y') {
         // Get client data

        // Concatenate client data with the separator
        for (int i = 0; i < client.size(); i++) {
            lines += client[i] + separator;
        }
        lines += "\n";
        read_new_clients(client);

        client.clear();  // Clear the vector for the next client
        
        
    }

    // Print the lines after all clients are processed
    cout << "\n\n\nAll client records:" << endl;
    cout << lines << endl;
}


int main() {
    vector<string> clients;  // Vector to hold client data
    string line;             // Line to hold the concatenated client record

    // Read new clients and return the count of clients added
        convert_record_toline(line , clients);

    return 0;
}
