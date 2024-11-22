#pragma once

#include<iostream>
#include<string>
#include "string-library-abu.h"
#include <vector>
#include <fstream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsMainScreen.h"


class clsCurrency
{

private:

    enum enMode { EmptyMode = 0, UpdateMode = 1 };
    enum ecurrncyoptions {listcurrncy = 1 , findcurrncy = 2 , updaterate = 3 , currncycalcultor = 4 , mainmenue = 5};
    enMode _Mode;

	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;
    static float _ReadRate()
    {
        cout << "\nEnter New Rate: ";
        float NewRate = 0;

        NewRate = clsInputValidate::ReadFloatNumber();
        return NewRate;
    }

    static void _DrawScreenHeader(string Title,string SubTitle ="")
    {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";
        
        cout << "\t\t\t\t\tUser: " << CurrentUser.GetUserName() << endl;
         clsDate date1;
         cout << "\t\t\t\t\tDate: ";
         date1.Print();
         cout << endl;
    }
    static void _PrintCurrency(clsCurrency Currency)
    {
        cout << "\nCurrency Card:\n";
        cout << "_____________________________\n";
        cout << "\nCountry    : " << Currency.Country();
        cout << "\nCode       : " << Currency.CurrencyCode();
        cout << "\nName       : " << Currency.CurrencyName();
        cout << "\nRate(1$) = : " << Currency.Rate();

        cout << "\n_____________________________\n";

    }

    static clsCurrency _ConvertLinetoCurrencyObject(string Line, string Seperator = "#//#")
    {
        vector<string> vCurrencyData;
        vCurrencyData = clsString::Split(Line, Seperator);

        return clsCurrency(enMode::UpdateMode, vCurrencyData[0], vCurrencyData[1], vCurrencyData[2],
            stod(vCurrencyData[3]));

    }

    static string _ConverCurrencyObjectToLine(clsCurrency Currency, string Seperator = "#//#")
    {

        string stCurrencyRecord = "";
        stCurrencyRecord += Currency.Country() + Seperator;
        stCurrencyRecord += Currency.CurrencyCode() + Seperator;
        stCurrencyRecord += Currency.CurrencyName() + Seperator;
        stCurrencyRecord += to_string(Currency.Rate());
       
        return stCurrencyRecord;

    }
    static void PrintCurrncyRecordLine(clsCurrency currncies)
    {

        cout << setw(8) << left << "" << "| " << setw(30) << left << currncies.Country() ;
        cout << "| " << setw(8) << left << currncies.CurrencyCode();
        cout << "| " << setw(45) << left << currncies.CurrencyName();
        cout << "| " << setw(10) << left << currncies.Rate();

    }

    static  vector <clsCurrency> _LoadCurrencysDataFromFile()
    {

        vector <clsCurrency> vCurrencys;

        fstream MyFile;
        MyFile.open("Currencies.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;

            while (getline(MyFile, Line))
            {

                clsCurrency Currency = _ConvertLinetoCurrencyObject(Line);

                vCurrencys.push_back(Currency);
            }

            MyFile.close();

        }

        return vCurrencys;

    }

    static void _SaveCurrencyDataToFile(vector <clsCurrency> vCurrencys)
    {

        fstream MyFile;
        MyFile.open("Currencies.txt", ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsCurrency C : vCurrencys)
            {
                 DataLine = _ConverCurrencyObjectToLine(C);
                    MyFile << DataLine << endl;

                

            }

            MyFile.close();

        }

    }

    void _Update()
    {
        vector <clsCurrency> _vCurrencys;
        _vCurrencys = _LoadCurrencysDataFromFile();

        for (clsCurrency& C : _vCurrencys)
        {
            if (C.CurrencyCode() == CurrencyCode())
            {
                C = *this;
                break;
            }

        }

        _SaveCurrencyDataToFile(_vCurrencys);

    }

    static clsCurrency _GetEmptyCurrencyObject()
    {
        return clsCurrency(enMode::EmptyMode, "", "", "", 0);
    }

    static short ReadCurrncyOptions()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 5? ");
        return Choice;
    }


public:

	clsCurrency(enMode Mode,string Country,string CurrencyCode,string CurrencyName,float Rate)
	{
        _Mode = Mode;
        _Country = Country;
        _CurrencyCode = CurrencyCode;
        _CurrencyName = CurrencyName;
        _Rate = Rate;
	}
    static void ShowcurrnciesList()
    {
        

        
        vector <clsCurrency> vcurrncies = clsCurrency::GetCurrenciesList();
        string Title = "\t  Currncy List Screen";
        string SubTitle ="\t    (" + to_string(vcurrncies.size()) + ") Currncie(s).";

        _DrawScreenHeader(Title, SubTitle);
        

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout <<  setw(8) << left << "" << "| " << left << setw(30) << "Country";
        cout << "| " << left << setw(8) << "Code";
        cout << "| " << left << setw(45) << "Country Name";
        cout << "| " << left << setw(10) << "Rate";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vcurrncies.size() == 0)
            cout << "\t\t\t\tNo currncies Available In the System!";
        else

            for (clsCurrency currncies : vcurrncies)
            {

                PrintCurrncyRecordLine(currncies);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }

	static vector <clsCurrency> GetAllUSDRates()
	{

        return _LoadCurrencysDataFromFile();

	}

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    string Country()
    {
        return _Country;
    }
 
    string CurrencyCode()
    {
        return _CurrencyCode;
    }
    
    string CurrencyName()
    {
        return _CurrencyName;
    }
   
    void UpdateRate(float NewRate)
    {
        _Rate = NewRate;
        _Update();
    }

    float Rate()
    {
        return _Rate;
    }
   
   static void ShowUpdateCurrencyRateScreen()
    {

        _DrawScreenHeader("\tUpdate Currency Screen");

        string CurrencyCode = "";

        cout << "\nPlease Enter Currency Code: ";
        CurrencyCode = clsInputValidate::ReadString();

        while (!clsCurrency::IsCurrencyExist(CurrencyCode))
        {
            cout << "\nCurrency is not found, choose another one: ";
            CurrencyCode = clsInputValidate::ReadString();
        }

        clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
        _PrintCurrency(Currency);

        cout << "\nAre you sure you want to update the rate of this Currency y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {

            cout << "\n\nUpdate Currency Rate:";
            cout << "\n____________________\n";

            Currency.UpdateRate( _ReadRate());

            cout << "\nCurrency Rate Updated Successfully :-)\n";
            _PrintCurrency(Currency);
          

        }

    }
    static   clsCurrency FindByCode(string CurrencyCode)
    {
     
        CurrencyCode = clsString::UpperAllString(CurrencyCode);

        fstream MyFile;
        MyFile.open("Currencies.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsCurrency Currency = _ConvertLinetoCurrencyObject(Line);
                if (Currency.CurrencyCode() == CurrencyCode)
                {
                    MyFile.close();
                    return Currency;
                }
            }

            MyFile.close();

        }

        return _GetEmptyCurrencyObject();

    }

  static   clsCurrency FindByCountry(string Country)
  {
      Country = clsString::UpperAllString(Country);

      fstream MyFile;
      MyFile.open("Currencies.txt", ios::in);//read Mode

      if (MyFile.is_open())
      {
          string Line;
          while (getline(MyFile, Line))
          {
              clsCurrency Currency = _ConvertLinetoCurrencyObject(Line);
              if (clsString::UpperAllString(Currency.Country()) == Country)
              {
                  MyFile.close();
                  return Currency;
              }

          }

          MyFile.close();

      }

      return _GetEmptyCurrencyObject();

  }

  static void findcurrncybycodeorname(){
    _DrawScreenHeader("Find Currncy Screen");
    short choise;
    cout << "Find By: [1] Code or [2] Name ? ";
    cin >> choise;
    string userchoise;


        if(choise == 1){
        cout << "Please enter Code name? " << endl;
        cin >> userchoise;
        clsCurrency currncy1 = FindByCode(clsString::UpperAllString(userchoise));
        _PrintCurrency(currncy1);
        }
        else if(choise == 2){
        cout << "Please enter Country name? " << endl;
        cin >> userchoise;
        clsCurrency currncy2 = FindByCountry(userchoise);
        _PrintCurrency(currncy2);
        }
  }

 /* static void calculatorexchange() {
    // Display calculator screen header
    _DrawScreenHeader("Calculator Screen");

    char check = 'y';
    while (check == 'y' || check == 'Y') {
        double Amount = 0;
        double usdamount;
        string userchoice;

        // Get the first currency code from the user
        cout << "Please enter currency1 Code: ";
        cin >> userchoice;

        // Convert to uppercase and find the corresponding currency
        clsCurrency currency1 = FindByCode(clsString::UpperAllString(userchoice));

        // Error handling for invalid currency
        if (currency1.CurrencyCode() == "") {
            cout << "Invalid currency code for currency1. Please try again." << endl;
            continue;  // Start loop again if invalid
        }

        // Get the second currency code from the user
        cout << "Please enter currency2 Code: ";
        cin >> userchoice;

        clsCurrency currency2 = FindByCode(clsString::UpperAllString(userchoice));

        // Error handling for invalid currency
        if (currency2.CurrencyCode() == "") {
            cout << "Invalid currency code for currency2. Please try again." << endl;
            continue;  // Start loop again if invalid
        }

        // Get the amount to exchange
        cout << "Enter amount to exchange: ";
        while (!(cin >> Amount) || Amount <= 0) {
            cin.clear();  // Clear the error flag
            cout << "Please enter a valid positive number for the amount: ";
        }

        // Perform exchange calculations
        if (currency2.CurrencyCode() != "USD") {
            _PrintCurrency(currency1);
            usdamount = (Amount / currency1.Rate());
            cout << Amount << " " << currency1.CurrencyCode() << " = " 
                 << (usdamount * currency2.Rate()) << " " << currency2.CurrencyCode() << endl;
        } else {
            _PrintCurrency(currency1);
            cout << Amount << " " << currency1.CurrencyCode() << " = " 
                 << (Amount / currency1.Rate()) << " USD" << endl;
        }

        // Ask the user if they want to perform another calculation
        cout << "\nDo you want to make another calculation? (Y/N): ";
        cin >> check;
    }
}*/
    static void calculatorexchangee(){
    _DrawScreenHeader("Calculator Screen");

    char check = 'y';
        while(check == 'y' || check == 'Y'){
          double Amount = 0;
          double usdamount;
     
          string userchoise;
          cout << "Please enter currncy1 Code? " << endl;
          cin >> userchoise;
          clsCurrency currncy1 = FindByCode(clsString::UpperAllString(userchoise));
     
          cout << "Please enter currncy2 Code? " << endl;
          cin >> userchoise;
          clsCurrency currncy2 = FindByCode(clsString::UpperAllString(userchoise));

          cout << "Enter amount to exchange? " ;
          cin >> Amount;


          if (currncy2.CurrencyCode() != "USD")
          {
            _PrintCurrency(currncy1); 
            usdamount = (Amount/currncy1.Rate());
            cout << Amount <<  " "  << currncy1.CurrencyCode() << " = " << (usdamount*currncy2.Rate()) << " " <<
            currncy2.CurrencyCode() << endl;
          }
          else
          {
          
          _PrintCurrency(currncy1);     
          cout << Amount <<  " "  << currncy1.CurrencyCode() << " = " << (Amount/currncy1.Rate()) << " " <<
          currncy2.CurrencyCode() << endl; 

          } 
          


     
          cout << "\nYou want to make a calculation again?Y/N? " << endl;
          cin >> check;
        }

  } 
  static bool IsCurrencyExist(string CurrencyCode)
    {
        clsCurrency C1 = clsCurrency::FindByCode(CurrencyCode);
        return (!C1.IsEmpty());

    }

  static vector <clsCurrency> GetCurrenciesList()
  {
      return _LoadCurrencysDataFromFile();
  }

    static void ShowCurrncyMainScreen()
    {
        system("cls");
        _DrawScreenHeader("\t\tMain Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List currncies.\n";
        cout << setw(37) << left << "" << "\t[2] find currncy.\n";
        cout << setw(37) << left << "" << "\t[3] update rate.\n";
        cout << setw(37) << left << "" << "\t[4] currncy calculator.\n";
        cout << setw(37) << left << "" << "\t[5] main menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";
        _PerformcurrnciesMenueOption((ecurrncyoptions)ReadCurrncyOptions());


    }

    static void _PerformcurrnciesMenueOption(ecurrncyoptions ecurrncyoptions )
    {

        switch (ecurrncyoptions)
        {
            case ecurrncyoptions::listcurrncy:
            {
                system("cls");
                ShowcurrnciesList();
                return;
                break;
            }

            case ecurrncyoptions::findcurrncy:
            {
                system("cls");
                findcurrncybycodeorname();
                return;
                break;
            }


            case ecurrncyoptions::updaterate:
            {
                system("cls");
                ShowUpdateCurrencyRateScreen();
                return;
                break;
            }


            case ecurrncyoptions::currncycalcultor:
            {
                system("cls");
                calculatorexchangee();
                return;
                break;
            }



            case ecurrncyoptions::mainmenue:
            {

               //do nothing here the main screen will handle it :-) ;


            }
        }

    }
};
