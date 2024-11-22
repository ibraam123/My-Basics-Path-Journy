#include <iostream>
#include <string>
using namespace std;

void printname (string& name){
    cout << "what is your name? " << endl;
    cin >> name;
    cout << "my name is: " << name << endl;


}

int main (){
    string name;

    printname(name);
}
