#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsdeposite.h"
#include "clswithdraw.h"
#include "clstotalbalance.h"
#include "clsTranfer.h"


using namespace std;

class clsTransactionsScreen :protected clsScreen
{


private:
    enum enTransactionsMenueOptions { eDeposit = 1, eWithdraw = 2, 
                                      eShowTotalBalance = 3, eTransfer = 4 , eShowMainMenue = 5 };

    static short ReadTransactionsMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 5? ");
        return Choice;
    }


    static void _ShowDepositScreen()
    {
        //cout << "\n Deposit Screen will be here.\n";
        clsDepositScreen::ShowDepositScreen();
    }

    static void _ShowWithdrawScreen()
    {
        clsWithdrawScreen::ShowWithdrawScreen();
    }
   
    static void _ShowTotalBalancesScreen()
    {
        clsTotalBalancesScreen::ShowTotalBalances();
    }

    static void _ShowTranferScreen()
    {
        clsTransfer::showtranferscreen();
    }


   static void _GoBackToTransactionsMenue()
    {
        cout << "\n\nPress any key to go back to Transactions Menue...";
        system("pause>0");
        ShowTransactionsMenue();

    }

    static void _PerformTransactionsMenueOption(enTransactionsMenueOptions TransactionsMenueOption)
    {

        switch (TransactionsMenueOption)
        {
            case enTransactionsMenueOptions::eDeposit:
            {
                system("cls");
                _ShowDepositScreen();
                _GoBackToTransactionsMenue();
                break;
            }

            case enTransactionsMenueOptions::eWithdraw:
            {
                system("cls");
                _ShowWithdrawScreen();
                _GoBackToTransactionsMenue();
                break;
            }


            case enTransactionsMenueOptions::eShowTotalBalance:
            {
                system("cls");
                _ShowTotalBalancesScreen();
                _GoBackToTransactionsMenue();
                break;
            }


            case enTransactionsMenueOptions::eTransfer:
            {
                system("cls");
                _ShowTranferScreen();
                _GoBackToTransactionsMenue();
                break;
            }



            case enTransactionsMenueOptions::eShowMainMenue:
            {

               //do nothing here the main screen will handle it :-) ;


            }
        }


    }



public:


    static void ShowTransactionsMenue()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pTranactions))
        {
            return;// this will exit the function and it will not continue
        }

        system("cls");
        _DrawScreenHeader("\tTransactions Screen");
       
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Transactions Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[4] tranfer balance.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformTransactionsMenueOption((enTransactionsMenueOptions)ReadTransactionsMenueOption());
    }

};

