#include <iostream>
using namespace std;


int readnumber(int &number){
    cout << "enter your number: " << endl ;
    cin >> number;
    return number;
}

void checknumberoddoreven (int number){
    int i =0;
    while (i == 0)
    {
        if (number%2 == 0)
        {
            cout << "number " << number << " is even" << endl;
            break;
        }
        else if (number%2 != 0)
        {
            cout << "number " << number << " is odd" << endl;
            break;
        }
        else
        {
            cout << "number not even or odd" << endl;
            break;
        }
        
        
        
    }
    
}
int main (){
    int number;
    readnumber(number);
    checknumberoddoreven(number);
}
