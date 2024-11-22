#include <iostream>
using namespace std;

void full_name(){
    string firstname;
    cout << "what is your first name? " << endl;
    cin >> firstname;
    string secondname;
    cout << "what is your second name? " << endl;
    cin >> secondname;
    cout << endl;
    cout << firstname << " " << secondname ;
    cout << endl;
}
int main(){
    int i = 0;
    while (i == 0)
    {
       full_name();
      
    }
    
    
}