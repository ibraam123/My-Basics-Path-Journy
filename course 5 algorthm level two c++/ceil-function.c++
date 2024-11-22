#include <iostream>
#include <cmath>
using namespace std;


float read_number(float& number){

    cout << "enter your number: " << endl;
    cin >> number;
    return number;
}

void ceil_number(float number){

    if (number > int(number))
    {
        cout << (int)number + 1 ;
    }
    else
    {
        cout << (int)number ;
    }
    

}


int main(){

    float number;
    


  for (int i = 0; i < 10; i++)
  {
    read_number(number);
    ceil_number(number);
  }
  
    
}