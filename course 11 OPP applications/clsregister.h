#include "clsglobal.h"
#include <iostream>
#include <fstream>
#include <vector>
#include "date-library.h"

/**       
cout << "\t\t\t\t\tUser: " << CurrentUser.GetUserName() << endl;
  clsDate date1;
  cout << "\t\t\t\t\tDate: ";
  date1.Print();
  cout << endl; */

class clsregister{


public:
    clsregister(){

        fstream MyFile;
        clsDate Date;

        MyFile.open("registerlogin.txt" , ios::app | ios::out);
        Date.GetSystemDate();
        string registerdate = Date.DateToString() + " - " + Date.DateinHMS() + "#//#" + CurrentUser.GetUserName() + "#//#"  + CurrentUser.GetPassword() + "#//#" + CurrentUser.GetPermissions(); 

        MyFile >> registerdate;

    }
  
};