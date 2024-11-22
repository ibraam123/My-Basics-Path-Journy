#include<iostream>
#include<string>
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

void printdigit(int number){
  int remainder = 0 ;
  while (number > 0)
  {
    remainder = number % 10;
    number = number / 10;
    cout << remainder << endl;
  }
  
}



int main(){

  printdigit(ReadPositiveNumber("plese enter positive number? "));
}