
#include <iostream>
#include <string>
using namespace std;

struct strinfo
{
    string firstname; // first name vairable
    string secondname; // second name
    int age ; // number of age
    int phone; // phone number
};

void readinfo(strinfo &info){

    cout << "please enter your first name: " << endl;
    cin >> info.firstname; // take first name from user

    cout << "please enter your second name: " << endl;  
    cin >> info.secondname; // take second name from user 

    cout << "please enter your age: " << endl;
    cin >> info.age;  // take age number from user 

    cout << "please enter your phone: " << endl;  
    cin >> info.phone; // take phone number from user

}

void printinfo(strinfo info){

cout << "first name: " << info.firstname << endl;
cout << "second name: " << info.secondname << endl;
cout << "age: " << info.age << endl;
cout << "phone: " << info.phone << endl;    

}

int main(){
    strinfo person1;
    readinfo(person1);
    printinfo(person1);

    strinfo person2;
    readinfo(person2);
    printinfo(person2);
}