#include <iostream>
#include <cmath>
using namespace std;


float read_number(float& number){

    cout << "enter your number: " << endl;
    cin >> number;
    return number;
}

void round_number(float number){

    if (number >= (int)number + 0.5)
    {
        cout << (int)number + 1;
    }
    else
    {
        cout << (int)number ;
    }
    

}


int main(){

    float number;
    read_number(number);

    round_number(number);
}