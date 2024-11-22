#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<iomanip>

using namespace std;
const string ClientFileName = "Client.txt";

struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool MarkForDelete = false;

};

sClient ReadClienData()
{
    sClient Info;

    cout << "Enter Account Number ? ";

    // Usage of std::ws will extract allthe whitespace character
    getline(cin >> ws, Info.AccountNumber);

    cout << "Enter PinCode ? ";
    getline(cin, Info.PinCode);

    cout << "Enter Name ? ";
    getline(cin, Info.Name);

    cout << "Enter Phone ? ";
    getline(cin, Info.Phone);

    cout << "Enter Account Balance ? ";
    cin >> Info.AccountBalance;

    return Info;
}

string ReadAccountNumber()
{
    string AccountNumber = "";
    cout << "Please Enter Account Number? ";
    cin >> AccountNumber;

    return AccountNumber;
}

vector <string> SplitString(string S1, string Delim)
{
    vector <string> vCountWord;
    short Pos = 0;
    string sWord;// define a string variable 

    // use find() function to get the position of the delimiters  
    while ((Pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, Pos);// store the word 
        if (sWord != "")
        {
            vCountWord.push_back(sWord);
        }

        /* erase() until positon and move to next word. */
        S1.erase(0, Pos + Delim.length());

    }

    if (S1 != "")
    {
        vCountWord.push_back(S1);
    }

    return vCountWord;

}

sClient ConvertLineDataToRecord(string LineRecord, string Seperator = "#//#")
{
    vector <string> vClientData;
    sClient Client;

    vClientData = SplitString(LineRecord, Seperator);

    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]); //Cast String To Double

    return Client;

}

vector <sClient> LoadClientsDataFromFile(string FileName)
{
    vector <sClient> vClients;
    fstream MyFile;
    MyFile.open(FileName, ios::in);

    if (MyFile.is_open())
    {
        string Line;
        sClient Client;

        while (getline(MyFile, Line))
        {
            Client = ConvertLineDataToRecord(Line);
            vClients.push_back(Client);
        }

        MyFile.close();
    }

    return vClients;
}

void PrintClientRecord(sClient Client)
{
    cout << "| " << left << setw(15) << Client.AccountNumber;
    cout << "| " << left << setw(10) << Client.PinCode;
    cout << "| " << left << setw(40) << Client.Name;
    cout << "| " << left << setw(15) << Client.Phone;
    cout << "| " << left << setw(20) << Client.AccountBalance;

}

void PrintAllClientsData(vector <sClient> vClients)
{
    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s)";
    cout << "\n__________________________________________________________________________________________________________________\n\n";
    cout << "| " << left << setw(15) << "Account Name";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(15) << "Phone";
    cout << "| " << left << setw(20) << "Account Balance";
    cout << "\n__________________________________________________________________________________________________________________\n\n";
    for (sClient& Client : vClients)
    {
        PrintClientRecord(Client);
        cout << endl;
    }

    cout << "\n__________________________________________________________________________________________________________________\n\n\n";


}

string ConvertRecordToLine(sClient Info, string Seperator = "#//#")
{
    string stClientRecord = "";

    stClientRecord += Info.AccountNumber + Seperator;
    stClientRecord += Info.PinCode + Seperator;
    stClientRecord += Info.Name + Seperator;
    stClientRecord += Info.Phone + Seperator;
    stClientRecord += to_string(Info.AccountBalance);

    return stClientRecord;
}


void PrintClientCard(sClient Client)
{
    cout << "The Following Are The Clients Details: \n\n";

    cout << "Account Number  : " << Client.AccountNumber << "\n";
    cout << "Pin Code        : " << Client.PinCode << "\n";
    cout << "Name            : " << Client.Name << "\n";
    cout << "Phone           : " << Client.Phone << "\n";
    cout << "Account Balance : " << Client.AccountBalance << "$\n";
}

bool MarkClientForDeleteByAccountNumber(string AccountNumber,vector <sClient>& vClient)
{
    for (sClient& C : vClient)
    {
        if (C.AccountNumber == AccountNumber)
        {
            C.MarkForDelete = true;
            return true;
        }
    }

    return false;
}

bool FindClientByAccountNumber(string AccountNumber, vector <sClient> vClients, sClient& Client)
{
    
    for (sClient C : vClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            Client = C;
            return true;

        }

    }
    return false;

}

vector <sClient> SaveClientsDataToFile(string FileName, vector <sClient> vClients)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out);//overwrite
    string DataLine;

    if (MyFile.is_open())
    {
        for (sClient C : vClients)
        {
            if (C.MarkForDelete == false)
            {
                //we only write records that are not marked for delete.
                DataLine = ConvertRecordToLine(C);
                MyFile << DataLine << endl;
            }
        }

        MyFile.close();
    }

    return vClients;
}

bool DeleteClientByAccountNumber(string AccountNumber, vector <sClient>& vClients)
{
    sClient Client;
    char Answer = 'n';

    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        PrintClientCard(Client);
        cout << "\n\nAre You Sure You Want To Delete This Client? Y/N ? ";
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            MarkClientForDeleteByAccountNumber(AccountNumber, vClients);
            SaveClientsDataToFile(ClientFileName, vClients);

            //Refresh Clients
            vClients = LoadClientsDataFromFile(ClientFileName);
            cout << "\n\nClient Deleted Successfully.";
            return true;

        }
    }
    else
    {
        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
        return false;
    }
}

void AddDataLineToFile(string FileName, string stDataLine)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out | ios::app);//Write and Add More But Not Delete

    if (MyFile.is_open())
    {
        MyFile << stDataLine << endl;

        MyFile.close();
    }
}

void AddNewClient()
{
    sClient Client;
    Client = ReadClienData();
    AddDataLineToFile(ClientFileName, ConvertRecordToLine(Client));
}

void AddClients()
{
    char AddMore = 'Y';
    cout << "do you want to add more clients? Y/N ? ";
    cin >> AddMore;

    while (toupper(AddMore) == 'Y')
    {
        system("cls");
        cout << "Add New Client:\n\n";

        AddNewClient();
        cout << "\nClient Added Successfully, do you want to add more clients? Y/N ? ";
        cin >> AddMore;
        cout << "\n\n";

    }
}

int main()
{
    AddClients();

    vector <sClient> vClients = LoadClientsDataFromFile(ClientFileName);

    PrintAllClientsData(vClients);

    string AccountNumber = ReadAccountNumber();
    DeleteClientByAccountNumber(AccountNumber, vClients);

    system("pause>0");

    return 0;
}