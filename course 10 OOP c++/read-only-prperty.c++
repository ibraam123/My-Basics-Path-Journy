
#include <iostream>
using namespace std;

class clsperson
{
private:
    int _ID = 10;
    string _firstname;
    string _secondname;

public:



    // property get , this is read only property because we dont use set property
    int ID(){
        return _ID;
    }

    //Property Set to edit on private varibale
    void setFirstname(string firstname){
        _firstname = firstname;
    }

    //Property get to print variable
    string firstname(){
        return _firstname;
    }

    void setSecond(string secondname){
        _secondname = secondname;
    }

    //Property get
    string secondname(){
        return _secondname;
    }

    string fullname(){
        return _firstname + " " + _secondname;
    }
    

};

int main()
{
    clsperson person1;

    person1.setFirstname("ibraam");
    person1.setSecond("magdy");


    cout << "ID: " << person1.ID() << endl;
    cout << "first name: " << person1.firstname() << endl;
    cout << "first name: " << person1.secondname() << endl;
    cout << "first name: " << person1.fullname() << endl;
    

    return 0;
}