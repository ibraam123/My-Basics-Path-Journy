#include <iostream>

using namespace std;

class clsPerson
{
public:
    string FullName;

    // This is Construcor, will be called when object is Built
    clsPerson()
    {
        FullName = "Mohammed Abu-Hadhoud";
        cout << "\nHi, I'm Constructor";
    }

    // This is Destructor, will be called when object is Destroyed.
    ~clsPerson()
    {
        cout << "\nHi, I'm Destructor";
    }
};

void Func1()
{
    clsPerson clsPerson1;
    // After exiting from function, person1 will be destroyed and destructor will be called
}

void Func2()
{
    // Pointers won't release destructor automatically because it's a runtime object
    clsPerson *Person2 = new clsPerson;
    // ALWAYS use delete whenever you use new, otherwise object will remain in memory
    delete Person2;
}

int main()
{
    Func1();
    Func2();

    system("pause>0");
    return 0;
}