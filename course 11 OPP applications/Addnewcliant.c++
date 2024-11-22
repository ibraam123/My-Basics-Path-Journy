#include <iostream>
#include "clsPerson.h"
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

void AddNewClient()
{
    string AccountNumber = "";

    cout << "\nPlease Enter Account Number: ";
    AccountNumber = clsInputValidate::ReadString();
    while (clsBankClient::IsClientExist(AccountNumber))
    {
        cout << "\nAccount Number Is Already Used, Choose another one: ";
        AccountNumber = clsInputValidate::ReadString();
    }

    clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);


    ReadClientInfo(NewClient);

    clsBankClient::enSaveResults SaveResult;

    SaveResult = NewClient.Save();

    switch (SaveResult)
    {
    case  clsBankClient::enSaveResults::svSucceeded:
    {
        cout << "\nAccount Addeded Successfully :-)\n";
        NewClient.Print();
        break;
    }
    case clsBankClient::enSaveResults::svFaildEmptyObject:
    {
        cout << "\nError account was not saved because it's Empty";
        break;

    }
    case clsBankClient::enSaveResults::svFaildAccountNumberExists:
    {
        cout << "\nError account was not saved because account number is used!\n";
        break;

    }
    }
}


int main()

{
    AddNewClient();
    system("pause>0");
    return 0;
}