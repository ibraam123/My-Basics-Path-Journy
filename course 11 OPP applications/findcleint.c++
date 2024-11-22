
//ProgrammingAdvices.com
//Mohmammed Abu-Hadhoud
#include <iostream>
#include "clsBankClient.h"

int main()

{

    clsBankClient Client1 = clsBankClient::Find("A101");
    if (!Client1.IsEmpty())
    {
        cout << "\nClient Found :-)\n";
    } 
    else
    {
        cout << "\nClient Was not Found :-(\n";
    }
    
    Client1.Print();

    clsBankClient Client2 = clsBankClient::Find("A104");
    if (!Client2.IsEmpty())
    {
        cout << "\nClient Found :-)\n";
    }
    else
    {
        cout << "\nClient Was not Found :-(\n";
    }
    Client2.Print();

    
    cout << "\nIs Client Exist? "<< clsBankClient::IsClientExist("A101");


    return 0;
}
