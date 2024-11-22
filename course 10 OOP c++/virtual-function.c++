#include <iostream>
using namespace std;

class clsPerson{
public:

    virtual void Print(){
        cout << "HI , i'm a person!\n ";
    }

};

class clsEmployee : public clsPerson
{
public:
    void Print(){
        cout << "HI , i'm a employee!\n";
    }
};

class clsStudent : public clsEmployee
{
public:
    void Print(){
        cout << "HI , i'm an student!\n";
    }
};


int main(){

    clsEmployee employee1;
    clsStudent student1;

    clsPerson * person1 = &employee1;
    clsPerson * person2 = &student1;
    
    cout << "after pointer: \n";
    person1->Print();
    person2->Print();
    cout << "\n\n\n";

    employee1.Print();
    student1.Print();

    return 0;

}