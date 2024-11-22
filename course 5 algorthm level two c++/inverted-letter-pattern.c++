#include <iostream>
#include <string>
using namespace std;

int readnumber(int &number){
    cout << "please enter posotive number? " << endl;
    cin >> number;
    return number;
}
void printinvertednumber(int number){
    for (int i = 65; i > (65 - number); i++)
    {
        for (int j = number; j > 0; j--)
        {
            cout << char(i);
        }
        cout << endl;
        
    }
    
}
int main (){
    int number;
    printinvertednumber(readnumber(number));
}