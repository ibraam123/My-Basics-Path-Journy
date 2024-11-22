#pragma once

#include <iostream>
#include <string>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include <fstream>

class clsTransfer : protected clsScreen
{

private:
    
    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nBalance     : " << Client.GetAccountBalance();
        cout << "\n___________________\n";

    }

    static string _ReadAccountNumberfrom()
    {
        string AccountNumber = "";
        cout << "\nPlease enter AccountNumber transfer from? ";
        cin >> AccountNumber;
        return AccountNumber;
    }


    static string _ReadAccountNumberto()
    {
        string AccountNumber = "";
        cout << "\nPlease enter AccountNumber transfer to? ";
        cin >> AccountNumber;
        return AccountNumber;
    }

public:

    static void showtranferscreen()
    {
        _DrawScreenHeader("\t   transfer screen");

        string AccountNumberfrom = _ReadAccountNumberfrom();
        clsBankClient Client1 = clsBankClient::Find(AccountNumberfrom);
        _PrintClient(Client1);
   
   
        string AccountNumberto = _ReadAccountNumberto();
        clsBankClient Client2 = clsBankClient::Find(AccountNumberto);
        _PrintClient(Client2);

        while (!clsBankClient::IsClientExist(AccountNumberfrom) && !clsBankClient::IsClientExist(AccountNumberto))
        {
            cout << "\nClient with [" << AccountNumberfrom << "] and " << AccountNumberto << "does not exist.\n";
            AccountNumberfrom = _ReadAccountNumberfrom();
            AccountNumberto = _ReadAccountNumberto();


        }

        double Amount = 0;
        cout << "\n enter a transfer amount? ";
        Amount = clsInputValidate::ReadDblNumber();
        while (stoi(Client1.GetAccountBalance()) < Amount)
        {
            cout  << "Amount excceds the available balanace , please enter another amount? \n" ;
            Amount = clsInputValidate::ReadDblNumber();
        }
        

        cout << "\nAre you sure you want to perform this transaction? ";
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
            Client1.tranferfrom(Amount);
            Client2.transferto(Amount);

            cout << "Transsfer done successfully " << endl;
            _PrintClient(Client1);
            _PrintClient(Client2);

        }
        else
        {
            cout << "\nOperation was cancelled.\n";
        }

        fstream Myfile;
        Myfile.open("TranferLog.txt" , ios::out | ios::app);

        Myfile << clsDate::GetSystemDateTimeString() << "#//#" << Client1.AccountNumber() << "#//#" << Client2.AccountNumber()
        << "#//#" << Amount << "#//#" << Client1.GetAccountBalance() << "#//#" << Client2.GetAccountBalance() <<
        "#//#" << CurrentUser.GetUserName() << endl;

    }

};


/**4000
 * 3000
 * 1000
 * 3000
 * 4000
 */
