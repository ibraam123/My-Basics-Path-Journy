#include <iostream>
#include <string>
using namespace std;

int ReadPositiveNumber(string Message)
  {
    int Number = 0;
   do    
   {       
             cout << Message << endl;
             cin >> Number;    
   } while (Number <= 0);
     return Number; 
  } 

void printsumdigit(int Number){
  int remainder = 0 ;
  int sum = 0 ;
  int check_number;
  cout << "enter number you want to check ? " << endl;

  cin >> check_number;
  cout << endl;
  while (Number > 0)
  {
    remainder = Number % 10; 
    Number = Number / 10;
    if (remainder == check_number)
    {
        sum++;
    }
    
    
  }
     cout << "Digit " << check_number << " frequncy is "  << sum << " times"<< endl;
  

  
}
int main(){
    printsumdigit(ReadPositiveNumber("please enter number ? "));
}
