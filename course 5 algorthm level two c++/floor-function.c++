#include <iostream>
#include <cmath>
using namespace std;


float read_number(float& number){

    cout << "enter your number: " << endl;
    cin >> number;
    return number;
}

void floor_number(float number){

    if (number > 0)
    {
        cout << (int)number ;
    }
    else
    {
        cout << (int)number - 1 ;
    }
    

}


int main(){

    float number;
    


  for (int i = 0; i < 10; i++)
  {
    read_number(number);
    floor_number(number);
  }
  
    
}