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
    rclient(clients);
}

// Function to convert the record of clients to a formatted string and save it to the file
void convert_record_toline(string &lines, vector<string> &client) {  // Pass lines by reference

    char check = 'y';

    read_new_clients(client);
    while (check == 'y' || check == 'Y') {
         // Concatenate client data with the separator
        for (int i = 0; i < client.size(); i++) {
            lines += client[i] + separator;
        }
        lines += "\n";

        cout << "Added successfully. Do you want to add more clients? (y/n): ";
        cin >> check;
        cin.ignore();  // Ignore newline after reading char input

        if (check == 'n' || check == 'N') {
            break;  // Exit the loop if the user doesn't want to add more clients
        }

        client.clear();  // Clear the vector for the next client
        read_new_clients(client);
    }

    // Print the lines after all clients are processed
    cout << "\n\n\nAll client records:" << endl;
    cout << lines << endl;
}

// Function to save client records to a file
void save_to_file(const string &lines) {
    fstream file;
    file.open(ClientsFileName, ios::app | ios::out);  // Open in append mode
    if (file.is_open()) {
        file << lines;  // Write lines to file
        file.close();
        cout << "Client records saved to file successfully." << endl;
    } else {
        cout << "Error opening file!" << endl;
    }
}


void showclient_list(){

}

int main() {
    vector<string> clients;  // Vector to hold client data
    string line;             // Line to hold the concatenated client record

    // Read new clients and return the count of clients added
    convert_record_toline(line, clients);

    // Save the data to the file
    save_to_file(line);

    return 0;
}
