#include <iostream>
using namespace std;
 /**requirments 
  * loops to find if sum of numbers equal number or not 
  * if condition to check if number &2 == 0 or not 
  */
 int readnumber(int &number){
    cout << "please enter number? " << endl;
    cin >> number;
    return number;
 }
 void checknumber(int number){
    int sum = 0;
    for (int i = 1; i < number; i++)
    {
        if (number % i == 0)
        {
           sum += i;
        }
        
    }
    if (sum == number)
    {
    cout << number << " is perfect number" << endl;
    }
    else
    {
    cout << number << " not perfect number" << endl;
    }
    
 }

 int main (){
    int number;
    for (int i = 0; i < 5; i++)
    {
        readnumber(number);
        checknumber(number);
    }
    
    
    
 }