#include <iostream>
using namespace std;

int readnumber(int &number){
    cout << "please enter number? " << endl;
    cin >> number;
    return number;
}
void readuntill(int number){
    int sum = 0;
    readnumber(number);
    while (number != -99)
    {
        
        sum += number;
        readnumber(number);
    }

    cout << sum;
    
}

int main (){
    int number;
    
    readuntill(number);
}