#include <iostream>

using namespace std;

class clsA
{
private:
    int _Var1;

protected:
    int _Var3;

public:
    int Var2;

    clsA()
    {
        _Var1 = 10;
        Var2 = 20;
        _Var3 = 30;
    }

    // This will grant access for everything to class B
    friend class clsB; // friend class
};

class clsB
{
public:
    void Display(clsA A)
    {
        cout << "Var1 = " << A._Var1 << endl;
        cout << "Var2 = " << A.Var2 << endl;
        cout << "Var3 = " << A._Var3 << endl;
    }
};

int main()
{
    clsA A1;
    clsB B1;

    B1.Display(A1);

    return 0;
}
