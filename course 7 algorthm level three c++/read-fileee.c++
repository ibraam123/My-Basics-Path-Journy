#include <iostream>
#include <fstream>
using namespace std;



void PrintFileContenet()
{
fstream MyFile;
MyFile.open("myfileee.txt", ios::in ); // Read Mode
if (MyFile.is_open())
{
    string Line;
    while (getline(MyFile, Line))
    {
       cout << Line << endl;
    }
    MyFile.close();
}
}
int main()
{
    string separator = "  | ";
    cout << "\t\t\tclents list (3) cleint(s)" << "\n" ;
    cout << "_____________________________________________________________________________________\n";
    cout << "Acount numbers" << "\t" << separator << "pin code"  << "\t" << separator << "cleint name" << "\t\t" << separator << "Phone" << "\t" << separator << "balance" << "\t" << endl;
    cout << "_____________________________________________________________________________________\n";



    PrintFileContenet();

    return 0;
}