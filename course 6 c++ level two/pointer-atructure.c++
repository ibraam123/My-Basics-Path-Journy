#include <iostream>
using namespace std;

struct stemployee
{
    string firstname;
    float salary;
};



int main(){

    stemployee employee , *ptr;

    employee.firstname = "ibramm";
    employee.salary = 5000;

    cout << employee.firstname << endl;
    cout << employee.salary << endl;

    ptr = &employee;

    cout << "using pointer" << endl;

    cout << ptr->firstname << endl;
    cout << ptr->salary  << endl;

    return 0;

}
