#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"

void ReadClientInfo(clsBankClient& Client)
{
    cout << "\nEnter FirstName: ";
    Client.GetFirstName() = clsInputValidate::ReadString();

    cout << "\nEnter LastName: ";
    Client.GetLastName() = clsInputValidate::ReadString();

    cout << "\nEnter Email: ";
    Client.GetEmail() = clsInputValidate::ReadString();

    cout << "\nEnter Phone: ";
    Client.GetPhone() = clsInputValidate::ReadString();

    cout << "\nEnter PinCode: ";
    Client.GetPinCode() = clsInputValidate::ReadString();

    cout << "\nEnter Account Balance: ";
    Client.AccountNumber() = clsInputValidate::ReadFloatNumber();
}

void UpdateClient()
{
    string AccountNumber = "";

    cout << "\nPlease Enter client Account Number: ";
    AccountNumber = clsInputValidate::ReadString();
    
    while (!clsBankClient::IsClientExist(AccountNumber))
    {
        cout << "\nAccount number is not found, choose another one: ";
        AccountNumber = clsInputValidate::ReadString();
    }

    clsBankClient Client1 = clsBankClient::Find(AccountNumber);
    Client1.Print();

    cout << "\n\nUpdate Client Info:";
    cout << "\n____________________\n";

  
    ReadClientInfo(Client1);

    clsBankClient::enSaveResults SaveResult;

    SaveResult = Client1.Save();

    switch (SaveResult)
    {
    case  clsBankClient::enSaveResults::svSucceeded:
    {
        cout << "\nAccount Updated Successfully :-)\n";
        Client1.Print();
        break;
    }
    case clsBankClient::enSaveResults::svFaildEmptyObject:
    {
        cout << "\nError account was not saved because it's Empty";
        break;

    }

    }
}

int main()

{
    UpdateClient();
    system("pause>0");
    return 0;
}