#include <iostream>
using namespace std;

void func()
{
    int number = 1 ; // local variable damage after end of function
    static int lifenumber = 1; // static varaible mean always have value and not damage 

    cout << "local nummber is: " << number << endl;
    cout << "static number is: " << lifenumber << endl;
    number ++ ;
    lifenumber ++ ;
}

int main()
{
    func();
    func();
    func();
    func();

    return 0;
}