#include <iostream> 
using namespace std;


class clsperson{
    struct stAddress
    {
        string Adressline1;
        string Adressline2;
        string City;
        string Country;
    };

public:
    string Fullname;
    stAddress Address;

    clsperson(){
        Fullname = "ibraam magdy";
        Address.Adressline1 = "building 10";
        Address.Adressline2 = "queen";
        Address.City = "amman";
        Address.Country = "jordon";
        
    }

    void print(){
        cout << Fullname << endl;
        cout << Address.Adressline1 << endl;
        cout << Address.Adressline2 << endl;
        cout << Address.City << endl;
        cout << Address.Country << endl;
    }
    
};

int main(){
    clsperson person;
    person.print();

    return 0;
}