#include <iostream>
#include <string>
using namespace std;

int readnumber(int &number){
    cout << "please enter posotive number? " << endl;
    cin >> number;
    return number;
}
void printinvertednumber(int number){
    for (int i = number; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            cout << i;
        }
        cout << endl;
        
    }
    
}
int main (){
    int number;
    printinvertednumber(readnumber(number));
}