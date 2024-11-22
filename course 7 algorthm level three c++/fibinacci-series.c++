#include <iostream>
#include <vector>
using namespace std;


void readvector(vector <int> &series , int count){

series.push_back(1);
series.push_back(1);
for (int i = 2; i < count; i++)
{
    series[i] = series[i - 1] + series[i - 2];
}

/** 1 1 2 3 5 8 13 21 34 55 */
}

void printvector(vector <int> &series , int count){
    for (int i = 0; i < count; i++)
    {
        cout << series[i] << "\t"; 
    }
    
}


int main(){

    vector <int> series;
    

    readvector(series , 20);

    cout << "fibnaccie series is: " << endl;
    printvector(series , 20);

    return 0;

}

/**
#include <iostream> 
#include <iomanip> 
 
using namespace std; 
 
// Problem #21 
 
void PrintFibonacciUsingLoop( short Number) 
{ 
 int  FebNumber = 0 ; 
 int Prev2 = 0, Prev1 =1; 
 
 cout << "1   "; 
 
  for (short i = 2; i <= Number; i++) 
  { 
   FebNumber = Prev1 + Prev2; 
 
   cout << FebNumber << "   "; 
 
   Prev2 = Prev1 ; 
   Prev1 = FebNumber; 
 
  } 
 
} 
 
int main() 
{ 
 // Problem #21 
 
 PrintFibonacciUsingLoop(10); 
 
 system("pause>0"); 
} */ 