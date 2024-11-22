#include <iostream>
#include <cmath>
using namespace std;

int read_ngative_number(int& number){
    do
    {
       cout << "enter ngative number: " << endl;
       cin >> number;
    } while (number >= 0);
    

    return number;
}

int abslute_function(int number){
    return number * (-1);
}

int main(){
    int number;

    read_ngative_number(number);
    cout << "My abs result: " << endl << abslute_function(number);;
    

    cout << "\n c++ abs result: \n" << abs(number);
}