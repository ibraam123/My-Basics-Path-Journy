#include <iostream>

using namespace std;

class clsA
{
public:
    int var;
    static int counter; // we cannot initialize the static data member inside the
                        // class due to class rules and the fact that we cannot
                        // assign it a value using constructor

    clsA()
    {
        counter++;
    }

    void Print()
    {
        cout << "\nvar = " << var << endl;
        cout << "counter = " << counter << endl;
    }
};

int clsA::counter = 0; // Static var Initialization Outside the class

int main()
{
    cout << "accessing static member without creating the object: " << endl; // Verifies the independency of the static data
    // member from the instances
    cout << clsA::counter << endl;

    clsA A1, A2, A3;

    A1.var = 10;
    A2.var = 20;
    A3.var = 30;

    A1.Print();
    A2.Print();
    A3.Print();

    A1.counter = 500;
    cout << "\nafter chaning the static member counter in one object:\n";
    A1.Print();
    A2.Print();
    A3.Print();

    system("pause>0");
    return 0;
}