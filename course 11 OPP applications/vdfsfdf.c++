static void calculatorexchange(){
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
            cout << Amount <<  " "  << currncy1.CurrencyCode() << " = " << (usdamount * currncy2.Rate()) << " " <<
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

  } any edit?