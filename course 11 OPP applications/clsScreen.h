#pragma once
#include <iostream>
#include "clsUser.h"
#include "clsglobal.h"
#include "date-library.h"

using namespace std;

class clsScreen : public clsUser
{
protected :
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

    static bool CheckAccessRights(clsUser::enPermissions Permission)
    {
     
            if (!CurrentUser.CheckAccessPermission(Permission))
            {
                cout << "\t\t\t\t\t______________________________________";
                cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";   
                cout << "\n\t\t\t\t\t______________________________________\n\n";
                return false;
            }
            else
            {
                return true;
            }

    }

};

