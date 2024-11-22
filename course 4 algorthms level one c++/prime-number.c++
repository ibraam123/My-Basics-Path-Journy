#include <iostream>
#include <math.h>
using namespace std;


enum enprimenotprime {prime = 1 , notprime = 2};

float readpositivenumber(string message){
    float number = 0 ;
    do
    {
        cout << message << endl;
        cin >> number;
    } while (number <= 0);

    return number;
    
}

enprimenotprime checkprime(int number)
{
    int m = round(number / 2);

    for (int i = 2; i <= m; i++)
    {
        return enprimenotprime::notprime;
    }
    return enprimenotprime::prime;
}
void printnumbertype(int number){

    switch (checkprime(number))
    {
    case enprimenotprime::prime:
        cout << "the number is prime" << endl;
        break;
    
    case enprimenotprime::notprime:
        cout << "the number is not prime" << endl;
        break;
    }
}

int main(){

    printnumbertype(readpositivenumber("please enter positive number? "));
}
