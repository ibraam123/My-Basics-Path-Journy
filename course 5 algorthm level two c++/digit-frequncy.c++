#include <iostream>
#include <string.h>
using namespace std;
// check number if same number you want to check

int ReadPositiveNumber(string Message) 
{ 
 int Number = 0;
 do   
  {       
   cout << Message << endl;     
   cin >> Number;   
   } 
       while (Number <= 0); 
       return Number;
}

void printfrequncynumbers(int number){
    int remender = 0;
    int freq_number;
    cout << "enter number you want to check ? " << endl;
    cin >> freq_number;
    int times = 0;
    

    while (number > 0)
    {
       
       
        remender = number % 10 ;
        number = number / 10 ;
        if( freq_number == remender )
        {
           times ++ ;
        }
        

    }
     cout << "Digit " << freq_number << " frequncy is "  << times << " times"<< endl;
    
}
int main (){
    int number;
    printfrequncynumbers(ReadPositiveNumber("please enter posotive number? " ));
}