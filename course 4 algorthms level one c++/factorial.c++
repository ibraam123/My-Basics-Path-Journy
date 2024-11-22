#include<iostream>
using namespace std;

int readnumber(int &number){
    cout << "enter number? " << endl;
    cin >> number;
    return number;
}

void factorial(int number){
    int factorial = 1;
    for (int i = 0; i < number; i++)
    {
        factorial = factorial * (number - i);
    } 
    cout << factorial;
    
}
int main (){
    int number;
    factorial(readnumber(number));
}